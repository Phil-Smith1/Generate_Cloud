#pragma once

#include "Input.h"
#include "Num_To_String.h"

void Directory ( string const& input_directory, Input const& input, int Betti_num, string& directory )
{
    if (input.pattern_type == "grid")
    {
        if (input.regular)
        {
            directory = input_directory + "Graph_Dependent_Cloud_Size/" + Num_To_String( input.cloud_size_parameter ) + "/" + input.noise_type + "/" + Num_To_String( input.noise_parameter ) + "/" + input.pattern_type + "/Regular/" + Num_To_String( input.pattern_size_1 ) + "," + Num_To_String( input.pattern_size_2 );
        }
        
        else
        {
            directory = input_directory + "Graph_Dependent_Cloud_Size/" + Num_To_String( input.cloud_size_parameter ) + "/" + input.noise_type + "/" + Num_To_String( input.noise_parameter ) + "/" + input.pattern_type + "/Varied/" + Num_To_String( input.pattern_size_1 ) + "," + Num_To_String( input.pattern_size_2 );
        }
    }
    
    else
    {
        directory = input_directory + "Graph_Dependent_Cloud_Size/" + Num_To_String( input.cloud_size_parameter ) +
        "/" + input.noise_type + "/" + Num_To_String( input.noise_parameter ) + "/" + input.pattern_type + "/" + Num_To_String( input.pattern_size_1 );
    }
}
