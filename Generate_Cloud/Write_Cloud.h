#pragma once

#include <fstream>

#include <boost/filesystem.hpp>

#include "Data_Pt.h"
#include "Directory.h"
#include "File_Name.h"

void Write_Cloud ( string const& cloud_directory, Input const& input, int iteration, size_t Betti_num, double graph_length, vector<Data_Pt>const& cloud )
{
    string directory;
    Directory( cloud_directory, input, directory );
    
    if (!boost::filesystem::is_directory( directory ))
    {
        boost::filesystem::create_directories( directory );
    }
    
	string cloud_file;
	File_Name( directory, "Cloud", iteration, ".txt", cloud_file );

	ofstream ofs( cloud_file );
    
    ofs << "Pattern_Type Pattern_Size Graph_Dependent_Cloud_Size Cloud_Size_Parameter Noise_Type Noise_Parameter Betti_Number Graph_Length" << endl;

	ofs << input.pattern_type << " " << input.pattern_size << " " << input.graph_dependent_cloud_size << " " << input.cloud_size_parameter << " " << input.noise_type << " " << input.noise_parameter << " " << Betti_num << " " << graph_length << endl;

	for (auto iter = cloud.begin(); iter != cloud.end(); ++iter)
	{
		ofs << iter->pt.x << " " << iter->pt.y << endl;
	}

	ofs.close();
}
