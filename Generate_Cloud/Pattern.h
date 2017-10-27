#pragma once

#include<string>

using namespace std;

class Pattern
{
    public:
    
    string noise_type, pattern_type, algorithm;
    int cloud_size, pattern_size;
    double noise_parameter, epsilon, alpha;
    
    Pattern ( int c_s, string const& n_t, double n_p, string const& p_t, int p_s, string const& a, double e, double al );
    
    Pattern();
    
    ~Pattern();
};
