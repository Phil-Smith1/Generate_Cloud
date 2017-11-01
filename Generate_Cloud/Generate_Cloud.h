#pragma once

#include <string>

#include "Data_Pt.h"
#include "Generate_Pt.h"

void Generate_Cloud ( Graph& g, int& cloud_size, string const& noise_type, double noise_parameter, vector<Data_Pt>& cloud )
{
	double total_length = 0;
    
    Weight weight = get( boost::edge_weight, g );

	for (auto EdgePair = boost::edges( g ); EdgePair.first != EdgePair.second; ++EdgePair.first)
	{
		total_length += weight[*EdgePair.first];
	}
    
    bool variable_cloud_size = true;
    int points_per_unit_length = 100;
    
    if (variable_cloud_size)
    {
        cloud_size = total_length * points_per_unit_length;
    }

	Point2d pt;

	for (int counter = 0; counter < cloud_size; ++counter)
	{
		Generate_Pt( g, total_length, noise_type, noise_parameter, pt );
		cloud.push_back( Data_Pt(pt) );
	}
}
