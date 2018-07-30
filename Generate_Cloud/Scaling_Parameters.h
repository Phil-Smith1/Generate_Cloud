#pragma once

#include "Data_Pt.h"

const double big_constant = 1e+64;

void Bounding_Box ( vector<Data_Pt>const& cloud, pair<Point2d, Point2d>& cloud_box )
{
	cloud_box.first = Point2d( big_constant, big_constant );
	cloud_box.second = Point2d( -big_constant, -big_constant );

	for (auto p : cloud)
	{
		if (cloud_box.first.x > p.pt.x) cloud_box.first.x = p.pt.x;
		if (cloud_box.first.y > p.pt.y) cloud_box.first.y = p.pt.y;
		if (cloud_box.second.x < p.pt.x) cloud_box.second.x = p.pt.x;
		if (cloud_box.second.y < p.pt.y) cloud_box.second.y = p.pt.y;
	}
}

void Bounding_Box ( Graph const& g, pair<Point2d, Point2d>& cloud_box )
{
    cloud_box.first = Point2d( big_constant, big_constant );
    cloud_box.second = Point2d( -big_constant, -big_constant );
    
    for (auto VertexPair = boost::vertices( g ); VertexPair.first != VertexPair.second; ++VertexPair.first)
    {
        if (cloud_box.first.x > g[*VertexPair.first].pt.x) cloud_box.first.x = g[*VertexPair.first].pt.x;
        if (cloud_box.first.y > g[*VertexPair.first].pt.y) cloud_box.first.y = g[*VertexPair.first].pt.y;
        if (cloud_box.second.x < g[*VertexPair.first].pt.x) cloud_box.second.x = g[*VertexPair.first].pt.x;
        if (cloud_box.second.y < g[*VertexPair.first].pt.y) cloud_box.second.y = g[*VertexPair.first].pt.y;
    }
}

void Scaling_Parameters ( vector<Data_Pt>const& cloud, Point image_sizes, double& scale, Point2d& shift )
{
	pair<Point2d, Point2d> box;
	Bounding_Box(cloud, box);

	Point2d cloud_sizes( box.second.x - box.first.x, box.second.y - box.first.y );
	Point2d cloud_center( box.second.x + box.first.x, box.second.y + box.first.y );
	cloud_center /= 2;

	Point2d image_center( image_sizes.x / 2, image_sizes.y / 2 );

	scale = min( (image_sizes.x - 20) / cloud_sizes.x, (image_sizes.y - 20) / cloud_sizes.y );

	// transformation: point -> scale * (point - cloud_center) + image_center. 

	shift = image_center - scale * cloud_center;
}

void Scaling_Parameters ( Graph const& g, Point image_sizes, double& scale, Point2d& shift )
{
    pair<Point2d, Point2d> box;
    
    Bounding_Box( g, box );
    
    Point2d cloud_sizes( box.second.x - box.first.x, box.second.y - box.first.y );
    Point2d cloud_center( box.second.x + box.first.x, box.second.y + box.first.y );
    cloud_center /= 2;
    
    Point2d image_center( image_sizes.x / 2, image_sizes.y / 2 );
    
    scale = min( (image_sizes.x - 20) / cloud_sizes.x, (image_sizes.y - 20) / cloud_sizes.y );
    
    // transformation: point -> scale * (point - cloud_center) + image_center.
    
    shift = image_center - scale * cloud_center;
}
