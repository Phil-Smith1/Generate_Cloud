#pragma once

#include <fstream>

#include "Run_Input.h"

void Write_Input ( string const& input_file, Run_Input const& run_input )
{
    ofstream ofs( input_file );
    
    ofs << "Pattern_Type Regular Pattern_Size_1 Pattern_Size_2 Graph_Dependent_Cloud_Size Cloud_Size_Parameter Noise_Type Noise_Parameter Repetitions" << endl;
    
    for (auto it_1 = run_input.noise_parameter_range.begin(); it_1 != run_input.noise_parameter_range.end(); ++it_1)
    {
        for (auto it_2 = run_input.wheel_range.begin(); it_2 != run_input.wheel_range.end(); ++it_2)
        {
            ofs << "wheel " << run_input.regular << " " << *it_2 << " " << 0 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
        
        for (auto it_2 = run_input.grid_cols_range.begin(); it_2 != run_input.grid_cols_range.end(); ++it_2)
        {
            for (auto it_3 = run_input.grid_rows_range.begin(); it_3 != run_input.grid_rows_range.end(); ++it_3)
            {
                if (*it_3 < *it_2) continue;
                
                ofs << "grid " << run_input.regular << " " << *it_2 << " " << *it_3 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
            }
        }
        
        for (auto it_2 = run_input.triangles_range.begin(); it_2 != run_input.triangles_range.end(); ++it_2)
        {
            ofs << "triangles " << run_input.regular << " " << *it_2 << " " << 0 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
        
        for (auto it_2 = run_input.hexagonal_range.begin(); it_2 != run_input.hexagonal_range.end(); ++it_2)
        {
            ofs << "hexagonal " << run_input.regular << " " << *it_2 << " " << 0 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
        
        for (auto it_2 = run_input.squares_range.begin(); it_2 != run_input.squares_range.end(); ++it_2)
        {
            ofs << "squares " << run_input.regular << " " << *it_2 << " " << 0 << " " << run_input.graph_dependent_cloud_size << " " << run_input.cloud_size_parameter << " " << run_input.noise_type << " " << *it_1 << " " << run_input.repetitions << endl;
        }
    }
    
    ofs.close();
}
