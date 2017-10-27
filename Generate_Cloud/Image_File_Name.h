#pragma once

#include "Pattern.h"
#include "Num_To_String.h"

void Image_File_Name ( string const& directory, Pattern const& pat, int iteration, string& file_name )
{
    file_name = directory + pat.pattern_type + "/Size_" + Num_To_String(pat.pattern_size) + "/Cloud_" + Num_To_String(pat.cloud_size) + "/" + pat.noise_type + "/Bound_" + Num_To_String(pat.noise_parameter) + "/" + pat.pattern_type + Num_To_String(pat.pattern_size) + "_points" + Num_To_String(pat.cloud_size) + "_image" + Num_To_String(iteration + 1) + ".png";
}
