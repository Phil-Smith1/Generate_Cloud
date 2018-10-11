#pragma once

#include "Graph.h"

int Betti_Num ( Graph const& g )
{
	int Betti_num = 1 - (int)boost::num_vertices( g ) + (int)boost::num_edges( g );

	return Betti_num;
}
