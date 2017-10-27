#pragma once

#include<fstream>
#include<sstream>

#include "Pattern.h"

void Read_Pattern ( string const& line_data, Pattern& pat )
{
	stringstream stream;
    string noise_type, pattern_type, algorithm;
    int cloud_size, pattern_size;
    double noise_parameter, epsilon, alpha;
    
	stream << line_data;
	stream >> cloud_size >> noise_type >> noise_parameter >> pattern_type >> pattern_size >> algorithm >> epsilon >> alpha;

	Pattern patt(cloud_size, noise_type, noise_parameter, pattern_type, pattern_size, algorithm, epsilon, alpha);

	pat = patt;
}
