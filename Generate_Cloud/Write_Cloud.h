#pragma once

#include<fstream>

#include "Data_Pt.h"
#include "Cloud_File_Name.h"

void Write_Cloud ( string const& cloud_directory, Pattern const& pat, int iteration, vector<Data_Pt>const& cloud )
{
	string cloud_file;
	Cloud_File_Name( cloud_directory, pat, iteration, cloud_file );

	ofstream ofs(cloud_file);
    
    ofs << "Cloud_Size Noise_Type Noise_Parameter Pattern_Type Pattern_Size" << endl;

	ofs << pat.cloud_size << " " << pat.noise_type << " " << pat.noise_parameter << " " << pat.pattern_type << " " << pat.pattern_size << endl;

	for (auto iter = cloud.begin(); iter != cloud.end(); ++iter)
	{
		ofs << iter->pt.x << " " << iter->pt.y << endl;
	}

	ofs.close();
}
