#pragma once

#include "Pattern.h"
#include "Num_To_String.h"

void Cloud_File_Name ( string const& directory, Pattern const& pat, int iteration, string& file_name )
{
    file_name = directory + "/" + pat.pattern_type + Num_To_String(pat.pattern_size) + "_points" + Num_To_String(pat.cloud_size) + "_cloud" + Num_To_String(iteration + 1) + ".txt";
}
