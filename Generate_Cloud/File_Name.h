#pragma once

#include "Input.h"
#include "Num_To_String.h"

void File_Name ( string const& directory, Input const& input, vector<bool>const& diagonal_edges, string const& item, int iteration, string const& ext, string& file_name )
{
    if (input.pattern_type == "grid")
    {
        file_name = directory + "/" + input.pattern_type + Num_To_String( input.pattern_size_1 ) + "," + Num_To_String( input.pattern_size_2 ) + "_" + input.noise_type + Num_To_String( input.noise_parameter ) + "_" + item + Num_To_String_2( iteration + 1 ) + ext;
    }
    
    else if (input.pattern_type == "squares")
    {
        file_name = directory + "/" + input.pattern_type + Num_To_String( diagonal_edges[0] ) + Num_To_String( diagonal_edges[1] ) + Num_To_String( diagonal_edges[2] ) + Num_To_String( diagonal_edges[3] );
        for (int counter = 1; counter < input.pattern_size_1 - 1; ++counter)
        {
            file_name += "," + Num_To_String( diagonal_edges[counter * 4] )  + Num_To_String( diagonal_edges[counter * 4 + 1] ) + Num_To_String( diagonal_edges[counter * 4 + 2] ) + Num_To_String( diagonal_edges[counter * 4 + 3] );
        }
        file_name += "_" + input.noise_type + Num_To_String( input.noise_parameter ) + "_" + item + Num_To_String_2( iteration + 1 ) + ext;
    }
    
    else
    {
        file_name = directory + "/" + input.pattern_type + Num_To_String( input.pattern_size_1 ) + "_" + input.noise_type + Num_To_String( input.noise_parameter ) + "_" + item + Num_To_String_2( iteration + 1 ) + ext;
    }
}
