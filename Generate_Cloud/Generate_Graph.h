#pragma once

#include "Input.h"
#include "Wheel_Graph.h"
#include "Lattice_Graph.h"
#include "Concentric_Squares_Graph.h"
#include "Betti_Num.h"

void Generate_Graph ( Input const& input, size_t& Betti_num, Graph& g )
{
	if (input.pattern_type == "Wheel")
	{
		Wheel_Graph( input.pattern_size, g );
	}

	else if (input.pattern_type == "Lattice")
	{
		Lattice_Graph( input.pattern_size, input.pattern_size, g );
	}
    
    else if (input.pattern_type == "Row")
    {
        Lattice_Graph( 1, input.pattern_size, g );
    }
    
    else if (input.pattern_type == "Concentric_Squares")
    {
        Concentric_Squares_Graph( input.pattern_size, g );
    }
    
    Betti_num = Betti_Num( g );
}
