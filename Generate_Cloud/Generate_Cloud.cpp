// Code to generate clouds.

// Inclusions.

#include <ctime>
#include <iostream>

#include "Read_Pattern.h"
#include "Generate_Graph.h"
#include "Generate_Cloud.h"
#include "Write_Cloud.h"
#include "Write_Image.h"

// Global variables.

const int repetitions = 100; // Number of iterations in each experiment.

const bool var_cloud_size = true; // If true, cloud size becomes dependent on graph length.

const int pts_per_unit_length = 100; // Number of points per unit length is var_cloud_size is true.

// Global constants.

const Scalar white = CV_RGB(255, 255, 255);
const Scalar black = CV_RGB(0, 0, 0);

// Directories.

const string input_file = "/Users/philsmith/Documents/Xcode Projects/Input.txt";
const string cloud_directory = "/Users/philsmith/Documents/Xcode Projects/Clouds/";
const string image_directory = "/Users/philsmith/Documents/Xcode Projects/Images/Clouds/";

// Functions.

void Print_Iter_Summary ( clock_t start_iter, int iteration )
{
	clock_t end_iter = clock();
	double elapsed_time = (end_iter - start_iter) * 1000 / (double)(CLOCKS_PER_SEC);

	cout << "Iteration " << iteration + 1 << ":" << endl;
	cout << "  Duration: " << elapsed_time << " ms." << endl << endl;
}

void Print_Experiment_Summary ( clock_t start_experiment, int experiment_iter, int repetitions )
{
    clock_t end_experiment = clock();
    double elapsed_time = (end_experiment - start_experiment) * 1000 / (double)(CLOCKS_PER_SEC);
    double mean_iter_time = elapsed_time / (double)repetitions;
    
    cout << "Experiment "  << experiment_iter << ":" << endl;
    cout << "  Experiment duration: " << elapsed_time << " ms." << endl;
    cout << "  Mean iteration time: " << mean_iter_time << " ms." << endl << endl;
}

void Print_Summary ( clock_t start_time, int experiment_iter )
{
	clock_t end_time = clock();
	double elapsed_time = (end_time - start_time) * 1000 / (double)(CLOCKS_PER_SEC);
    double mean_experiment_time = elapsed_time / (double)experiment_iter;

	cout << "Summary:" << endl;
	cout << "  Code duration: " << elapsed_time << " ms." << endl;
    cout << "  Number of experiments: " << experiment_iter << "." << endl;
	cout << "  Mean experiment time: " << mean_experiment_time << " ms." << endl << endl;
}

int main( int, char*[] )
{
	clock_t start_time = clock(); // Starts the stopwatch that measures the duration of the code.

	// Seeding the random number generator.

	srand( time( 0 ) );
	int test_rand_num = rand();
    
    // Looping over lines in the input file.
    
    ifstream ifs(input_file);
    
    string line_data;
    getline( ifs, line_data );
    
    int experiment_iter = 0;
    
    while (getline( ifs, line_data ))
    {
        clock_t start_experiment = clock(); // Starts the stopwatch that measures the duration of the experiment.
        
        ++experiment_iter;
        
        // Reading the pattern. Ie. the type of graph, size of cloud etc.

        Pattern pat;
        Read_Pattern( line_data, pat );

        for (int iteration = 0; iteration < repetitions; ++iteration) // Looping the algorithm.
        {
            clock_t start_iter = clock(); // Starts the stopwatch that measures the duration of the iteration.

            // Generating the graph according to the pattern read.

            Graph g;
            g.clear();
            Generate_Graph( pat, g );

            // Generating randomly the cloud according to the graph g.

            vector<Data_Pt> cloud;
            cloud.clear();
            Generate_Cloud( g, pat.cloud_size, pat.noise_type, pat.noise_parameter, var_cloud_size, pts_per_unit_length, cloud );

            // Writing the cloud to a txt file.

            Write_Cloud( cloud_directory, pat, iteration, cloud );
            
            // Writing the cloud image to a png file.
            
            const Point image_sizes(800, 800);
            Mat image(image_sizes, CV_8UC3, white);
            
            if (iteration % 20 == 0) Write_Image( image_directory, pat, iteration, image_sizes, black, cloud, image );

            // Printing to cout information about the iteration. Ie. duration.

            Print_Iter_Summary( start_iter, iteration );
        }
        
        // Printing to cout information about the experiment. Ie. duration.
        
        Print_Experiment_Summary( start_experiment, experiment_iter, repetitions );
    }
    
    ifs.close();

	// Printing to cout informaion about the run. Ie. duration.

	Print_Summary( start_time, experiment_iter );

	return 0;
}
