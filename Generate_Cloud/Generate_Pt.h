#pragma once

#include <string>

#include "Graph.h"
#include "Generate_Noise_Uniform_Pt.h"
#include "Generate_Gaussian_Pt.h"

void Generate_Pt ( Graph& g, double total_length, string const& noise_type, double noise_parameter, Point2d& pt )
{
	double rand_num = (rand() % 1000) * total_length / (double)1000;

	double cumulative_length = 0, dist;
	Graph::edge_iterator edge;
    Weight weight = get( boost::edge_weight, g );

	for (auto EdgePair = boost::edges( g ); EdgePair.first != EdgePair.second; ++EdgePair.first)
	{
		cumulative_length += weight[*EdgePair.first];

		if (rand_num < cumulative_length)
		{
			edge = EdgePair.first;
			break;
		}
	}

	Point2d unit_edge_direction = g[boost::target( *edge, g )].pt - g[boost::source( *edge, g )].pt;
	unit_edge_direction = unit_edge_direction / (double)sqrt( pow( unit_edge_direction.x, 2 ) + pow( unit_edge_direction.y, 2 ) );

	cumulative_length -= weight[*edge];
	dist = rand_num - cumulative_length;

	pt = g[boost::source( *edge, g )].pt + unit_edge_direction * dist;
    
    if (noise_type == "Noise_Uniform")
    {
        Generate_Noise_Uniform_Pt( noise_parameter, pt );
    }
    
    else if (noise_type == "Gaussian")
    {
        Generate_Gaussian_Pt( unit_edge_direction, noise_parameter, pt );
    }
}
