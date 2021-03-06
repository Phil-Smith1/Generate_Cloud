#pragma once

#include <string>

using namespace std;

class Input
{
    public:
    
    bool graph_dependent_cloud_size, regular;
    int pattern_size_1, pattern_size_2, cloud_size_parameter, repetitions;
    double noise_parameter;
    string pattern_type, noise_type;
    
    Input ( string const& p_t, bool reg, int p_s_1, int p_s_2, bool g_d_c_s, int c_s_p, string const& n_t, double n_p, int r );
    
    Input();
    ~Input();
};
