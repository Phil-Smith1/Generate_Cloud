#pragma once

#include "Graph.h"

void Add_Edge ( Graph::vertex_descriptor const& v1, Graph::vertex_descriptor const& v2, vector<pair<Graph::edge_descriptor, bool>>& e, Graph& g )
{
    double length;
    Point2d source, target;
    
    e.push_back( boost::add_edge( v1, v2, g ) );
    source = g[v1].pt;
    target = g[v2].pt;
    length = norm( target - source );
    boost::put( boost::edge_weight_t(), g, e.back().first, length );
}

void Hexagonal_Graph( int num_hexagons, Graph& g )
{
    vector<Graph::vertex_descriptor> v;
    vector<pair<Graph::edge_descriptor, bool>> e;
    
    if (num_hexagons >= 1)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[0]].pt = Point2d( 0, -1 );
        g[v[1]].pt = Point2d( -0.5 * sqrt( (double)3 ), -0.5 );
        g[v[2]].pt = Point2d( -0.5 * sqrt( (double)3 ), 0.5 );
        g[v[3]].pt = Point2d( 0, 1 );
        g[v[4]].pt = Point2d( 0.5 * sqrt( (double)3 ), 0.5 );
        g[v[5]].pt = Point2d( 0.5 * sqrt( (double)3 ), -0.5 );
        
        Add_Edge( v[0], v[1], e, g );
        Add_Edge( v[1], v[2], e, g );
        Add_Edge( v[2], v[3], e, g );
        Add_Edge( v[3], v[4], e, g );
        Add_Edge( v[4], v[5], e, g );
        Add_Edge( v[5], v[0], e, g );
    }
    
    if (num_hexagons >= 2)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[6]].pt = Point2d( 0, 2 );
        g[v[7]].pt = Point2d( 0.5 * sqrt( (double)3 ), 2.5 );
        g[v[8]].pt = Point2d( sqrt( (double)3 ), 2 );
        g[v[9]].pt = Point2d( sqrt( (double)3 ), 1 );
        
        Add_Edge( v[3], v[6], e, g );
        Add_Edge( v[6], v[7], e, g );
        Add_Edge( v[7], v[8], e, g );
        Add_Edge( v[8], v[9], e, g );
        Add_Edge( v[9], v[4], e, g );
    }
    
    if (num_hexagons >= 3)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[10]].pt = Point2d( 1.5 * sqrt( (double)3 ), 0.5 );
        g[v[11]].pt = Point2d( 1.5 * sqrt( (double)3 ), -0.5 );
        g[v[12]].pt = Point2d( sqrt( (double)3 ), -1 );
        
        Add_Edge( v[9], v[10], e, g );
        Add_Edge( v[10], v[11], e, g );
        Add_Edge( v[11], v[12], e, g );
        Add_Edge( v[12], v[5], e, g );
    }
    
    if (num_hexagons >= 4)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[13]].pt = Point2d( sqrt( (double)3 ), -2 );
        g[v[14]].pt = Point2d( 0.5 * sqrt( (double)3 ), -2.5 );
        g[v[15]].pt = Point2d( 0, -2 );
        
        Add_Edge( v[12], v[13], e, g );
        Add_Edge( v[13], v[14], e, g );
        Add_Edge( v[14], v[15], e, g );
        Add_Edge( v[15], v[0], e, g );
    }
    
    if (num_hexagons >= 5)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[16]].pt = Point2d( -0.5 * sqrt( (double)3 ), -2.5 );
        g[v[17]].pt = Point2d( -sqrt( (double)3 ), -2 );
        g[v[18]].pt = Point2d( -sqrt( (double)3 ), -1 );
        
        Add_Edge( v[15], v[16], e, g );
        Add_Edge( v[16], v[17], e, g );
        Add_Edge( v[17], v[18], e, g );
        Add_Edge( v[18], v[1], e, g );
    }
    
    if (num_hexagons >= 6)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[19]].pt = Point2d( -1.5 * sqrt( (double)3 ), -0.5 );
        g[v[20]].pt = Point2d( -1.5 * sqrt( (double)3 ), 0.5 );
        g[v[21]].pt = Point2d( -sqrt( (double)3 ), 1 );
        
        Add_Edge( v[18], v[19], e, g );
        Add_Edge( v[19], v[20], e, g );
        Add_Edge( v[20], v[21], e, g );
        Add_Edge( v[21], v[2], e, g );
    }
    
    if (num_hexagons == 7)
    {
        v.push_back( boost::add_vertex( g ) );
        v.push_back( boost::add_vertex( g ) );
        
        g[v[22]].pt = Point2d( -sqrt( (double)3 ), 2 );
        g[v[23]].pt = Point2d( -0.5 * sqrt( (double)3 ), 2.5 );
        
        Add_Edge( v[21], v[22], e, g );
        Add_Edge( v[22], v[23], e, g );
        Add_Edge( v[23], v[6], e, g );
    }
}
