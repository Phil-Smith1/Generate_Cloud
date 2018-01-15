#pragma once

#include <fstream>

#include "Custom.h"

void Write_Input ( string const& input_file, Custom const& custom )
{
    ofstream ofs( input_file );
    
    ofs << "Pattern_Type Pattern_Size Graph_Dependent_Cloud_Size Cloud_Size_Parameter Noise_Type Noise_Parameter Repetitions" << endl;
    
    for (auto it = custom.wheel_range.begin(); it != custom.wheel_range.end(); ++it)
    {
        ofs << "Wheel " << *it << " " << custom.graph_dependent_cloud_size << " " << custom.cloud_size_parameter << " " << custom.noise_type << " " << custom.noise_parameter << " " << custom.repetitions << endl;
    }
    
    for (auto it = custom.lattice_range.begin(); it != custom.lattice_range.end(); ++it)
    {
        ofs << "Lattice " << *it << " " << custom.graph_dependent_cloud_size << " " << custom.cloud_size_parameter << " " << custom.noise_type << " " << custom.noise_parameter << " " << custom.repetitions << endl;
    }
    
    for (auto it = custom.row_range.begin(); it != custom.row_range.end(); ++it)
    {
        ofs << "Row " << *it << " " << custom.graph_dependent_cloud_size << " " << custom.cloud_size_parameter << " " << custom.noise_type << " " << custom.noise_parameter << " " << custom.repetitions << endl;
    }
    
    for (auto it = custom.concentric_squares_range.begin(); it != custom.concentric_squares_range.end(); ++it)
    {
        ofs << "Concentric_Squares " << *it << " " << custom.graph_dependent_cloud_size << " " << custom.cloud_size_parameter << " " << custom.noise_type << " " << custom.noise_parameter << " " << custom.repetitions << endl;
    }
    
    ofs.close();
}
