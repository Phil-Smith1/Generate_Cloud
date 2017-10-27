#include "Pattern.h"

Pattern::Pattern ( int c_s, string const& n_t, double n_p, string const& p_t, int p_s, string const& a, double e, double al )
{
	cloud_size = c_s;
	noise_type = n_t;
	noise_parameter = n_p;
	pattern_type = p_t;
    pattern_size = p_s;
    algorithm = a;
    epsilon = e;
    alpha = al;
}

Pattern::Pattern(){}

Pattern::~Pattern(){}
