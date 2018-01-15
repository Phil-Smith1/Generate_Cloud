#pragma once

#include <string>

#include "Graph.h"
#include "Generate_Noise_Uniform_Pt.h"
#include "Generate_Gaussian_Pt.h"

void Generate_Pt ( Graph& g, double graph_length, string const& noise_type, double noise_parameter, Point2d& pt )
{
	double rand_num = (rand() % 1000) * graph_length / (double)1000;

	double cumulative_length = 0, dist;
    Weight weight = get( boost::edge_weight, g );
    Graph::edge_iterator edge;

	for (auto EdgePair = boost::edges( g ); EdgePair.first != EdgePair.second; ++EdgePair.first)
	{
		cumulative_length += weight[*EdgePair.first];

		if (rand_num < cumulative_length)
		{
			edge = EdgePair.first;
			break;
		}
	}
    
    cumulative_length -= weight[*edge];
    dist = rand_num - cumulative_length;

	Point2d unit_edge_direction = g[boost::target( *edge, g )].pt - g[boost::source( *edge, g )].pt;
	unit_edge_direction = unit_edge_direction / (double)sqrt( pow( unit_edge_direction.x, 2 ) + pow( unit_edge_direction.y, 2 ) );

	pt = g[boost::source( *edge, g )].pt + unit_edge_direction * dist;
    
    if (noise_type == "Noise_Uniform")
    {
        Generate_Noise_Uniform_Pt( unit_edge_direction, noise_parameter, pt );
    }
    
    else if (noise_type == "Gaussian")
    {
        Generate_Gaussian_Pt( unit_edge_direction, noise_parameter, pt );
    }
}
