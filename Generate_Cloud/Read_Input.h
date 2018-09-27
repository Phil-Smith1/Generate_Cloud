#pragma once

#include <fstream>
#include <sstream>

#include "Input.h"

void Read_Input ( string const& line_data, Input& input )
{
    bool g_d_c_s, reg;
    int p_s_1, p_s_2, c_s_p, r;
    double n_p;
    string p_t, n_t;
    stringstream stream;
    
	stream << line_data;
    stream >> p_t >> reg >> p_s_1 >> p_s_2 >> g_d_c_s >> c_s_p >> n_t >> n_p >> r;

    Input inp( p_t, reg, p_s_1, p_s_2, g_d_c_s, c_s_p, n_t, n_p, r );
    
    input = inp;
}
