#pragma once

#include "Graph.h"

void Squares_Graph ( int num_squares, vector<bool>& diagonal_edges, Graph& g )
{
    vector<Graph::vertex_descriptor> v;
    vector<pair<Graph::edge_descriptor, bool>> e;
    
    for (int counter_1 = 0; counter_1 < num_squares; ++counter_1)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[4 * counter_1]].pt = Point2d( -0.5 - counter_1, -0.5 - counter_1 );
        g[v[4 * counter_1 + 1]].pt = Point2d( -0.5 - counter_1, 0.5 + counter_1 );
        g[v[4 * counter_1 + 2]].pt = Point2d( 0.5 + counter_1, 0.5 + counter_1 );
        g[v[4 * counter_1 + 3]].pt = Point2d( 0.5 + counter_1, -0.5 - counter_1 );
        
        for (int counter_2 = 0; counter_2 < 3; ++counter_2)
        {
            e.push_back( boost::add_edge( v[4 * counter_1 + counter_2], v[4 * counter_1 + counter_2 + 1], g ) );
            Point2d source = g[boost::source( e.back().first, g )].pt;
            Point2d target = g[boost::target( e.back().first, g )].pt;
            double length = norm( target - source );
            boost::put( boost::edge_weight_t(), g, e.back().first, length );
        }
        
        e.push_back( boost::add_edge( v[4 * counter_1 + 3], v[4 * counter_1], g ) );
        Point2d source = g[boost::source( e.back().first, g )].pt;
        Point2d target = g[boost::target( e.back().first, g )].pt;
        double length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    /*for (int counter_1 = 0; counter_1 < num_squares - 1; ++counter_1)
    {
        int num_connecting_edges = rand() % 4 + 1;
        
        bool edges[4] = { false, false, false, false };
        
        for (int counter_2 = 0; counter_2 < num_connecting_edges; ++counter_2)
        {
            int edge = rand() % 4;
            
            while(edges[edge])
            {
                edge = rand() % 4;
            }
            
            edges[edge] = true;
            diagonal_edges[4 * counter_1 + edge] = true;
            
            e.push_back( boost::add_edge( v[4 * counter_1 + edge], v[4 * counter_1 + 4 + edge], g ) );
            Point2d source = g[boost::source( e.back().first, g )].pt;
            Point2d target = g[boost::target( e.back().first, g )].pt;
            double length = norm( target - source );
            boost::put( boost::edge_weight_t(), g, e.back().first, length );
        }
    }*/
    
    int counter = 0;
    
    for (auto it = diagonal_edges.begin(); it != diagonal_edges.end(); ++it, ++counter)
    {
        if (*it == true)
        {
            int edge = counter % 4;
            int square = (counter - counter % 4) / 4;
            
            e.push_back( boost::add_edge( v[4 * square + edge], v[4 * square + 4 + edge], g ) );
            Point2d source = g[boost::source( e.back().first, g )].pt;
            Point2d target = g[boost::target( e.back().first, g )].pt;
            double length = norm( target - source );
            boost::put( boost::edge_weight_t(), g, e.back().first, length );
        }
    }
}
