#pragma once

#include <string>

#include "Data_Pt.h"
#include "Generate_Pt.h"

void Generate_Cloud ( Graph& g, int cloud_size, string const& noise_type, double noise_parameter, vector<Data_Pt>& cloud )
{
	double total_length = 0;
    
    Weight weight = get( boost::edge_weight, g );

	for (auto EdgePair = boost::edges( g ); EdgePair.first != EdgePair.second; ++EdgePair.first)
	{
		total_length += weight[*EdgePair.first];
	}

	Point2d pt;

	for (int counter = 0; counter < cloud_size; ++counter)
	{
		Generate_Pt( g, total_length, noise_type, noise_parameter, pt );
		cloud.push_back( Data_Pt(pt) );
	}
}
