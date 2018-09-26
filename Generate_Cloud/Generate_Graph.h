#pragma once

#include "Input.h"
#include "Wheel_Graph.h"
#include "Grid_Graph.h"
#include "Squares_Graph.h"
#include "Betti_Num.h"

void Generate_Graph ( Input const& input, size_t& Betti_num, vector<bool>& diagonal_edges, Graph& g )
{
	if (input.pattern_type == "wheel")
	{
		Wheel_Graph( input.pattern_size_1, g );
	}

	else if (input.pattern_type == "grid")
	{
		Grid_Graph( input.pattern_size_1, input.pattern_size_2, input.regular, g );
	}
    
    else if (input.pattern_type == "squares")
    {
        Squares_Graph( input.pattern_size_1, diagonal_edges, g );
    }
    
    Betti_num = Betti_Num( g );
}
