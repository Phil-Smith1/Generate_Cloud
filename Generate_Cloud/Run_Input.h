#pragma once

#include <string>
#include <vector>

using namespace std;

class Run_Input
{
    public:
    
    bool graph_dependent_cloud_size;
    int cloud_size_parameter, repetitions;
    string noise_type;
    vector<int> wheel_range, lattice_range, row_range, concentric_squares_range;
    vector<double> noise_parameter_range;
    
    Run_Input ( vector<int>const& w_r, vector<int>const& l_r, vector<int>const& r_r, vector<int>const& c_s_r, bool g_d_c_s, int c_s_p, string const& n_t, vector<double> n_p_r, int r );
    
    Run_Input();
    ~Run_Input();
};
