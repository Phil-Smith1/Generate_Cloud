#pragma once

#include "Input.h"
#include "Num_To_String.h"

void Directory ( string const& input_directory, Input const& input, string& directory )
{
    if (input.graph_dependent_cloud_size)
    {
        directory = input_directory + "Graph_Dependent_Cloud_Size/" + Num_To_String( input.cloud_size_parameter ) +
        "/" + input.noise_type + "/" + Num_To_String( input.noise_parameter ) + "/" + input.pattern_type + "/Size_" + Num_To_String( input.pattern_size );
    }
    
    else
    {
        directory = input_directory + "/Cloud_" + Num_To_String( input.cloud_size_parameter ) + "/" + input.noise_type + "/" + Num_To_String( input.noise_parameter ) + "/" + input.pattern_type + "/Size_" + Num_To_String( input.pattern_size );
    }
}
