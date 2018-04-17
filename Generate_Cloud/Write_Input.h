#pragma once

#include <fstream>

#include "Run_Input.h"

void Write_Input ( string const& input_file, Run_Input const& run_input )
{
    ofstream ofs( input_file );
    
    ofs << "Pattern_Type Pattern_Size Graph_Dependent_Cloud_Size Cloud_Size_Parameter Noise_Type Noise_Parameter Repetitions" << endl;
    
    for (auto it_1 = run_input.noise_parameter_range.begin(); it_1 != run_input.noise_parameter_range.end(); ++it_1)
    {
        for (auto it_2 = run_input.wheel_range.begin(); it_2 != run_input.wheel_range.end(); ++it_2)
        {
            ofs << "Wheel " << *it_2 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
        
        for (auto it_2 = run_input.lattice_range.begin(); it_2 != run_input.lattice_range.end(); ++it_2)
        {
            ofs << "Lattice " << *it_2 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
        
        for (auto it_2 = run_input.row_range.begin(); it_2 != run_input.row_range.end(); ++it_2)
        {
            ofs << "Row " << *it_2 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
        
        for (auto it_2 = run_input.concentric_squares_range.begin(); it_2 != run_input.concentric_squares_range.end(); ++it_2)
        {
            ofs << "Concentric_Squares " << *it_2 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
    }
    
    ofs.close();
}
