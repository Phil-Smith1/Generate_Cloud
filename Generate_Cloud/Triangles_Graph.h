#pragma once

#include "Graph.h"

void Triangles_Graph( int num_triangles, Graph& g )
{
    double length;
    Point2d source;
    Point2d target;
    vector<Graph::vertex_descriptor> v;
    vector<pair<Graph::edge_descriptor, bool>> e;
    
    if (num_triangles >= 1)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[0]].pt = Point2d( 0, 0 );
        g[v[1]].pt = Point2d( 0.5, 0.5 * sqrt( (double)3 ) );
        g[v[2]].pt = Point2d( 1, 0 );
        
        e.push_back( boost::add_edge( v[0], v[1], g ) );
        source = g[v[0]].pt;
        target = g[v[1]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[1], v[2], g ) );
        source = g[v[1]].pt;
        target = g[v[2]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[0], v[2], g ) );
        source = g[v[0]].pt;
        target = g[v[2]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles >= 2)
    {
        v.push_back( boost::add_vertex( g ) );
        
        g[v[3]].pt = Point2d( 1.5, 0.5 * sqrt( (double)3 ) );
        
        e.push_back( boost::add_edge( v[1], v[3], g ) );
        source = g[v[1]].pt;
        target = g[v[3]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[2], v[3], g ) );
        source = g[v[2]].pt;
        target = g[v[3]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles >= 3)
    {
        v.push_back( boost::add_vertex( g ) );
        
        g[v[4]].pt = Point2d( 2, 0 );
        
        e.push_back( boost::add_edge( v[3], v[4], g ) );
        source = g[v[3]].pt;
        target = g[v[4]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[2], v[4], g ) );
        source = g[v[2]].pt;
        target = g[v[4]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles >= 4)
    {
        v.push_back( boost::add_vertex( g ) );
        
        g[v[5]].pt = Point2d( 2.5, 0.5 * sqrt( (double)3 ) );
        
        e.push_back( boost::add_edge( v[3], v[5], g ) );
        source = g[v[3]].pt;
        target = g[v[5]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[4], v[5], g ) );
        source = g[v[4]].pt;
        target = g[v[5]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles >= 5)
    {
        v.push_back( boost::add_vertex( g ) );
        
        g[v[6]].pt = Point2d( 1, sqrt( (double)3 ) );
        
        e.push_back( boost::add_edge( v[1], v[6], g ) );
        source = g[v[1]].pt;
        target = g[v[6]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[3], v[6], g ) );
        source = g[v[3]].pt;
        target = g[v[6]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles >= 6)
    {
        v.push_back( boost::add_vertex( g ) );
        
        g[v[7]].pt = Point2d( 2, sqrt( (double)3 ) );
        
        e.push_back( boost::add_edge( v[6], v[7], g ) );
        source = g[v[6]].pt;
        target = g[v[7]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[3], v[7], g ) );
        source = g[v[3]].pt;
        target = g[v[7]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles >= 7)
    {
        e.push_back( boost::add_edge( v[5], v[7], g ) );
        source = g[v[5]].pt;
        target = g[v[7]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
    
    if (num_triangles == 8)
    {
        v.push_back( boost::add_vertex( g ) );
        
        g[v[8]].pt = Point2d( 3, sqrt( (double)3 ) );
        
        e.push_back( boost::add_edge( v[5], v[8], g ) );
        source = g[v[5]].pt;
        target = g[v[8]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
        
        e.push_back( boost::add_edge( v[7], v[8], g ) );
        source = g[v[7]].pt;
        target = g[v[8]].pt;
        length = norm( target - source );
        boost::put( boost::edge_weight_t(), g, e.back().first, length );
    }
}
