#pragma once

#include <fstream>
#include <iomanip>

#include <boost/filesystem.hpp>

#include "Data_Pt.h"
#include "Directory.h"
#include "File_Name.h"

void Write_Cloud ( string const& cloud_directory, Input const& input, vector<bool>const& diagonal_edges, int iteration, int Betti_num, double graph_length, vector<Data_Pt>const& cloud )
{
    string directory;
    
    Directory( cloud_directory, input, Betti_num, directory );
    
    if (!boost::filesystem::is_directory( directory ))
    {
        boost::filesystem::create_directories( directory );
    }
    
	string cloud_file_name;
    
	File_Name( directory, input, diagonal_edges, "cloud", iteration, ".txt", cloud_file_name );

	ofstream ofs( cloud_file_name );
    
    ofs << "Pattern_Type Pattern_Size_1 Pattern_Size_2 Graph_Dependent_Cloud_Size Cloud_Size_Parameter Noise_Type Noise_Parameter Betti_Number Graph_Length";
    
    if (input.pattern_type == "squares") ofs << " Diagonals" << endl;
    
    else ofs << endl;

    ofs << left << setw( 13 ) << input.pattern_type << setw( 15 ) << input.pattern_size_1 << setw( 15 ) << input.pattern_size_2 << setw( 27 ) << input.graph_dependent_cloud_size << setw( 21 ) << input.cloud_size_parameter << setw( 11 ) << input.noise_type << setw( 16 ) << input.noise_parameter << setw( 13 ) << Betti_num << setw( 13 ) << graph_length;
    
    if (input.pattern_type == "squares")
    {
        for (auto d : diagonal_edges) ofs << d;
    }
    
    ofs << endl << endl;
    
    ofs << "Points (x, y):" << endl << endl;

	for (auto iter = cloud.begin(); iter != cloud.end(); ++iter)
	{
		ofs << iter->pt.x << " " << iter->pt.y << endl;
	}

	ofs.close();
}
