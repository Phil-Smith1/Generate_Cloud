#pragma once

#include "Graph.h"

const double pi = 3.14159265359;

void Wheel_Graph ( int num_spokes, Graph& g )
{
	int num_vertices = num_spokes + 1;

	vector<Graph::vertex_descriptor> v;
	vector<pair<Graph::edge_descriptor, bool>> e;
    v.clear();
    e.clear();

	v.push_back( boost::add_vertex( g ) );
	g[v[0]].pt = Point2d(0, 0);

	double angle = 2 * pi / (double)num_spokes;

	for (int counter = 1; counter < num_vertices; ++counter)
	{
		v.push_back( boost::add_vertex( g ) );
		g[v[counter]].pt = Point2d(cos( (counter - 1) * angle ), sin( (counter - 1) * angle ));
	}

	int num_edges = 0;

	for (int counter = 1; counter < num_vertices; ++counter)
	{
		e.push_back( boost::add_edge( v[0], v[counter], g ) );
		Point2d source = g[boost::source( e[num_edges].first, g )].pt;
		Point2d target = g[boost::target( e[num_edges].first, g )].pt;
        double length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e[num_edges].first, length );
		++num_edges;
	}

	for (int counter = 1; counter < num_vertices - 1; ++counter)
	{
		e.push_back( boost::add_edge( v[counter], v[counter + 1], g ) );
		Point2d source = g[boost::source( e[num_edges].first, g )].pt;
		Point2d target = g[boost::target( e[num_edges].first, g )].pt;
        double length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e[num_edges].first, length );
		++num_edges;
	}

	e.push_back( boost::add_edge( v[num_vertices - 1], v[1], g ) );
	Point2d source = g[boost::source( e[num_edges].first, g )].pt;
	Point2d target = g[boost::target( e[num_edges].first, g )].pt;
    double length = norm( target - source );
    boost::put( boost::edge_weight_t(), g, e[num_edges].first, length );
}
