#pragma once

#include <string>

using namespace std;

class Input
{
    public:
    
    
    string pattern_type, noise_type;
    bool graph_dependent_cloud_size;
    int pattern_size, cloud_size_parameter, repetitions;
    double noise_parameter;
    
    Input ( string const& p_t, int p_s, bool g_d_c_s, int c_s_p, string const& n_t, double n_p, int r );
    
    Input();
    
    ~Input();
};
