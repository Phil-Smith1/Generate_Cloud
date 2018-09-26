#include "Input.h"

Input::Input ( string const& p_t, bool reg, int p_s_1, int p_s_2, bool g_d_c_s, int c_s_p, string const& n_t, double n_p, int r )
{
    pattern_type = p_t;
    regular = reg;
    pattern_size_1 = p_s_1;
    pattern_size_2 = p_s_2;
    graph_dependent_cloud_size = g_d_c_s;
    cloud_size_parameter = c_s_p;
    noise_type = n_t;
    noise_parameter = n_p;
    repetitions = r;
}

Input::Input(){}
Input::~Input(){}
