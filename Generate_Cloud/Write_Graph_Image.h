#pragma once

#include <vector>

#include <boost/filesystem.hpp>

#include "Input.h"
#include "Graph.h"
#include "Num_To_String.h"

void Write_Graph_Image ( string const& graph_image_directory, Input const& input, int Betti_num, vector<bool>const& diagonal_edges, Graph const& g, Mat& image )
{
    string directory;
    
    if (input.pattern_type == "grid")
    {
        if (input.regular)
        {
            directory = graph_image_directory + input.pattern_type + "/Regular/" + Num_To_String( input.pattern_size_1 ) + "," + Num_To_String( input.pattern_size_2 );
        }
        
        else
        {
            directory = graph_image_directory + input.pattern_type + "/Varied/" + Num_To_String( input.pattern_size_1 ) + "," + Num_To_String( input.pattern_size_2 );
        }
    }
    
    else if (input.pattern_type == "squares")
    {
        directory = graph_image_directory + input.pattern_type + "/" + Num_To_String( input.pattern_size_1 ) + "/" + Num_To_String( Betti_num );
    }
    
    else directory = graph_image_directory + input.pattern_type + "/" + Num_To_String( input.pattern_size_1 );
    
    if(!boost::filesystem::is_directory( directory ))
    {
        boost::filesystem::create_directories( directory );
    }
    
    string file_name;
    
    if (input.pattern_type == "grid")
    {
        file_name = directory + "/" + input.pattern_type + Num_To_String( input.pattern_size_1 ) + "," + Num_To_String( input.pattern_size_2 ) + "_graph.png";
    }
    
    else if (input.pattern_type == "squares")
    {
        file_name = directory + "/" + input.pattern_type + Num_To_String( diagonal_edges[0] ) + Num_To_String( diagonal_edges[1] ) + Num_To_String( diagonal_edges[2] ) + Num_To_String( diagonal_edges[3] );
        for (int counter = 1; counter < input.pattern_size_1 - 1; ++counter)
        {
            file_name += "," + Num_To_String( diagonal_edges[counter * 4] )  + Num_To_String( diagonal_edges[counter * 4 + 1] ) + Num_To_String( diagonal_edges[counter * 4 + 2] ) + Num_To_String( diagonal_edges[counter * 4 + 3] );
        }
        file_name += "_graph.png";
    }
    
    else
    {
        file_name = directory + "/" + input.pattern_type + Num_To_String( input.pattern_size_1 ) + "_graph.png";
    }
    
    imwrite( file_name, image );

}
