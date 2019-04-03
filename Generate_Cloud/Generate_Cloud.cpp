// Code to generate point clouds for the data skeletonization dataset.

// Inclusions.

#include "Write_Input.h"
#include "Read_Input.h"
#include "Diagonal_Edges.h"
#include "Generate_Graph.h"
#include "Draw_Graph.h"
#include "Generate_Cloud.h"
#include "Write_Cloud.h"
#include "Write_Graph_Image.h"
#include "Write_Cloud_Image.h"
#include "Print_Info.h"

// Global variables.

bool write_input = true;

vector<int> wheel_range = { /*3, 4, 5, 6, 7, 8, 9*/ };
vector<int> grid_cols_range = { /*1, 2, 3*/ };
vector<int> grid_rows_range = { /*1, 2, 3*/ };

bool regular = true;

vector<int> triangles_range = { 1, 2, 3, 4, 5, 6, 7, 8 };
vector<int> squares_range = { /*2, 3, 4, 5, 6, 7, 8, 9*/ };

bool graph_dependent_cloud_size = true;
int cloud_size_parameter = 100;

string noise_type = "gaussian";
vector<double> noise_parameter_range = { /*0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4*/ 0.02, 0.04, 0.06, 0.08, 0.1, 0.12, 0.14, 0.16, 0.18, 0.2 };

int repetitions = 200;

Run_Input run_input( wheel_range, grid_cols_range, grid_rows_range, regular, triangles_range, squares_range, graph_dependent_cloud_size, cloud_size_parameter, noise_type, noise_parameter_range, repetitions );

// Global constants.

const Scalar white = CV_RGB( 255, 255, 255 );
const Scalar black = CV_RGB( 0, 0, 0 );

// Directories.

const string root_directory = "/Users/philsmith/Documents/Xcode Projects/Cloud_Skeletonization/";
const string input_file = root_directory + "Input/Input.txt";
const string cloud_directory = root_directory + "Clouds/";
const string cloud_txtfile_directory = cloud_directory + "Txt_Files/";
const string cloud_image_directory = cloud_directory + "Images/Clouds/";
const string graph_image_directory = cloud_directory + "Images/Graphs/";

int main( int, char*[] )
{
	clock_t start_time = clock(); // Start stopwatch.

	srand( (int)time( 0 ) ); // Seeding the random number generator.
    
    if (write_input) Write_Input( input_file, run_input ); // Writing input.
    
    int experiment_iter = 0; // Counter for the number of experiments performed.
    
    ifstream ifs( input_file );
    string line_data;
    getline( ifs, line_data );
    
    while (getline( ifs, line_data )) // Looping over lines in the input file.
    {
        ++experiment_iter;

        Input input;
        
        Read_Input( line_data, input ); // Reading the input.
        
        int Betti_num;
        double graph_length = 0;
        vector<bool> diagonal_edges( 8 );
        Graph g;
        
        Generate_Graph( input, Betti_num, graph_length, diagonal_edges, g ); // Generating the graph.

        for (int iteration = 0; iteration < input.repetitions; ++iteration) // Loop to produce multiple clouds.
        {
            vector<Data_Pt> cloud;
            
            Generate_Cloud( g, input, graph_length, cloud ); // Generating the cloud.

            Write_Cloud( cloud_txtfile_directory, input, diagonal_edges, iteration, Betti_num, graph_length, cloud ); // Writing the cloud to a txt file.
            
            const Point image_sizes( 800, 800 );
            
            if (iteration == 0)
            {
                Mat graph_image( image_sizes, CV_8UC3, white );
                
                Draw_Graph( g, 3, -1, 1, black, graph_image );
                
                Write_Graph_Image( graph_image_directory, input, Betti_num, diagonal_edges, g, graph_image ); // Writing the graph image to a png file.
            }
            
            if (iteration % 50 == 0)
            {
                Mat cloud_image( image_sizes, CV_8UC3, white );
                
                Write_Cloud_Image( cloud_image_directory, input, Betti_num, diagonal_edges, iteration, image_sizes, black, cloud, cloud_image ); // Writing the cloud image to a png file.
            }
        }
        
        cout << "Experiment " << experiment_iter << "." << endl;
    }
    
    ifs.close();
    
    cout << endl;

	Print_Summary( start_time, experiment_iter ); // Printing to cout informaion about the run. Ie. duration.

	return 0;
}
