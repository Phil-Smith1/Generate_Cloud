#pragma once

#include <string>
#include <vector>

using namespace std;

class Custom
{
    public:
    
    string noise_type;
    bool graph_dependent_cloud_size;
    int cloud_size_parameter, repetitions;
    double noise_parameter;
    vector<int> wheel_range, lattice_range, row_range, concentric_squares_range;
    
    Custom ( vector<int>const& w_r, vector<int>const& l_r, vector<int>const& r_r, vector<int>const& c_s_r, bool g_d_c_s, int c_s_p, string const& n_t, double n_p, int r );
    
    Custom();
    ~Custom();
};
