#pragma once

#include "Pattern.h"
#include "Num_To_String.h"

void Image_Directory ( string const& image_directory, Pattern const& pat, string& directory )
{
    directory = image_directory + pat.pattern_type + "/Size_" + Num_To_String(pat.pattern_size) + "/Cloud_" + Num_To_String(pat.cloud_size) + "/" + pat.noise_type + "/Bound_" + Num_To_String(pat.noise_parameter);
}
