#include "Run_Input.h"

Run_Input::Run_Input ( vector<int>const& w_r, vector<int>const& l_r, vector<int>const& r_r, vector<int>const& c_s_r, bool g_d_c_s, int c_s_p, string const& n_t, vector<double> n_p_r, int r )
{
    wheel_range = w_r;
    lattice_range = l_r;
    row_range = r_r;
    concentric_squares_range = c_s_r;
    graph_dependent_cloud_size = g_d_c_s;
    cloud_size_parameter = c_s_p;
    noise_type = n_t;
    noise_parameter_range = n_p_r;
    repetitions = r;
}

Run_Input::Run_Input(){}
Run_Input::~Run_Input(){}
