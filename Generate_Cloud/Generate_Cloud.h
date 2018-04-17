#pragma once

#include "Input.h"
#include "Data_Pt.h"
#include "Generate_Pt.h"

void Generate_Cloud ( Graph& g, Input& input, double& graph_length, vector<Data_Pt>& cloud )
{
    Weight weight = get( boost::edge_weight, g );

	for (auto EdgePair = boost::edges( g ); EdgePair.first != EdgePair.second; ++EdgePair.first)
	{
		graph_length += weight[*EdgePair.first];
	}
    
    int cloud_size;
    
    if (input.graph_dependent_cloud_size)
    {
        cloud_size = graph_length * input.cloud_size_parameter;
    }
    
    else cloud_size = input.cloud_size_parameter;
    
	Point2d pt;
    
	for (int counter = 0; counter < cloud_size; ++counter)
	{
		Generate_Pt( g, graph_length, input.noise_type, input.noise_parameter, pt );
		cloud.push_back( Data_Pt( pt ) );
	}
}
