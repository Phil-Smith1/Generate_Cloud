#include "Custom.h"

Custom::Custom ( vector<int>const& w_r, vector<int>const& l_r, vector<int>const& r_r, vector<int>const& c_s_r, bool g_d_c_s, int c_s_p, string const& n_t, double n_p, int r )
{
    wheel_range = w_r;
    lattice_range = l_r;
    row_range = r_r;
    concentric_squares_range = c_s_r;
    graph_dependent_cloud_size = g_d_c_s;
    cloud_size_parameter = c_s_p;
    noise_type = n_t;
    noise_parameter = n_p;
    repetitions = r;
}

Custom::Custom(){}
Custom::~Custom(){}
