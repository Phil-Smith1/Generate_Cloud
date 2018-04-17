#pragma once

#include "Graph.h"

void Lattice_Graph ( int rows, int cols, Graph& g )
{
	vector<Graph::vertex_descriptor> v;
	vector<pair<Graph::edge_descriptor, bool>> e;

	for (int iter_1 = 0; iter_1 < rows + 1; ++iter_1)
	{
		for (int iter_2 = 0; iter_2 < cols + 1; ++iter_2)
		{
			v.push_back( boost::add_vertex( g ) );
			g[v.back()].pt = Point2d( iter_2, iter_1 );
		}
	}

	for (int iter_1 = 0; iter_1 < rows + 1; ++iter_1)
	{
		for (int iter_2 = 0; iter_2 < cols; ++iter_2)
		{
			int vertex_1 = iter_2 + iter_1 * (cols + 1);
			int vertex_2 = iter_2 + 1 + iter_1 * (cols + 1);

			e.push_back( boost::add_edge( v[vertex_1], v[vertex_2], g ) );
			Point2d source = g[boost::source( e.back().first, g )].pt;
			Point2d target = g[boost::target( e.back().first, g )].pt;
            double length = norm( target - source );
            boost::put( boost::edge_weight_t(), g, e.back().first, length );
		}
	}

	for (int iter_1 = 0; iter_1 < cols + 1; ++iter_1)
	{
		for (int iter_2 = 0; iter_2 < rows; ++iter_2)
		{
			int vertex_1 = iter_1 + iter_2 * (cols + 1);
			int vertex_2 = iter_1 + (iter_2 + 1) * (cols + 1);

			e.push_back( boost::add_edge( v[vertex_1], v[vertex_2], g ) );
            Point2d source = g[boost::source( e.back().first, g )].pt;
            Point2d target = g[boost::target( e.back().first, g )].pt;
            double length = norm( target - source );
            boost::put( boost::edge_weight_t(), g, e.back().first, length );
		}
	}
}
