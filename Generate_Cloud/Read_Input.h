#pragma once

#include <fstream>
#include <sstream>

#include "Input.h"

void Read_Input ( string const& line_data, Input& input )
{
	stringstream stream;
    string p_t, n_t;
    bool g_d_c_s;
    int p_s, c_s_p, r;
    double n_p;
    
	stream << line_data;
    stream >> p_t >> p_s >> g_d_c_s >> c_s_p >> n_t >> n_p >> r;

    Input inp( p_t, p_s, g_d_c_s, c_s_p, n_t, n_p, r );

    input = inp;
}
