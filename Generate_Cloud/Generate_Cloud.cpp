// Code to generate point clouds for the data skeletonization dataset.

// Inclusions.

#include "Write_Input.h"
#include "Read_Input.h"
#include "Generate_Graph.h"
#include "Generate_Cloud.h"
#include "Write_Cloud.h"
#include "Write_Image.h"
#include "Print_Info.h"

// Global variables.

bool write_input = true;

vector<int> wheel_range = { 3, 4, 5, 6, 7, 8, 9, 10 };
vector<int> lattice_range = { 1, 2, 3, 4, 5 };
vector<int> row_range = { 1, 2, 3, 4, 5 };
vector<int> concentric_squares_range = { 2, 3, 4, 5 };

bool graph_dependent_cloud_size = true;
int cloud_size_parameter = 100;

string noise_type = "Gaussian";
vector<double> noise_parameter_range = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1 };

int repetitions = 100;

Run_Input run_input( wheel_range, lattice_range, row_range, concentric_squares_range, graph_dependent_cloud_size, cloud_size_parameter, noise_type, noise_parameter_range, repetitions );

// Global constants.

const Scalar white = CV_RGB( 255, 255, 255 );
const Scalar black = CV_RGB( 0, 0, 0 );

// Directories.

const string root_directory = "/Users/philsmith/Documents/Xcode Projects/Cloud_Skeletonization/";
const string input_file = root_directory + "Input/Input.txt";
const string cloud_directory = root_directory + "Clouds/";
const string image_directory = root_directory + "Images/Clouds/";

int main( int, char*[] )
{
	clock_t start_time = clock(); // Starts the stopwatch that measures the duration of the code.

	// Seeding the random number generator.

	srand( (int)time( 0 ) );
    
    // Write input.
    
    if (write_input) Write_Input( input_file, run_input );
    
    // Looping over lines in the input file.
    
    ifstream ifs( input_file );
    
    string line_data;
    getline( ifs, line_data );
    
    int experiment_iter = 0; // Counter for the number of experiments performed.
    
    while (getline( ifs, line_data ))
    {
        clock_t start_experiment = clock(); // Starts the stopwatch that measures the duration of the experiment.
        
        ++experiment_iter;
        
        // Reading the input.

        Input input;
        
        Read_Input( line_data, input );

        for (int iteration = 0; iteration < input.repetitions; ++iteration) // Loop to produce multiple clouds.
        {
            clock_t start_iter = clock(); // Starts the stopwatch that measures the duration of the iteration.

            // Generating the graph.

            Graph g;
            size_t Betti_num;
            
            Generate_Graph( input, Betti_num, g );

            // Generating the cloud.

            vector<Data_Pt> cloud;
            double graph_length = 0;
            
            Generate_Cloud( g, input, graph_length, cloud );
            
            // Writing the cloud to a txt file.

            Write_Cloud( cloud_directory, input, iteration, Betti_num, graph_length, cloud );
            
            // Writing the image to a png file.
            
            const Point image_sizes( 800, 800 );
            Mat image( image_sizes, CV_8UC3, white );
            
            if (iteration % 20 == 0) Write_Image( image_directory, input, iteration, image_sizes, black, cloud, image );

            // Printing to cout information about the iteration. Ie. duration.

            Print_Iter_Summary( start_iter, iteration );
        }
        
        // Printing to cout information about the experiment. Ie. duration.
        
        Print_Experiment_Summary( start_experiment, experiment_iter, input.repetitions );
    }
    
    ifs.close();

	// Printing to cout informaion about the run. Ie. duration.

	Print_Summary( start_time, experiment_iter );

	return 0;
}
