#pragma once

#include "Pattern.h"
#include "Wheel_Graph.h"
#include "Lattice_Graph.h"
#include "Row_Graph.h"

void Generate_Graph ( Pattern const& pat, Graph& g )
{
	if (pat.pattern_type == "Wheel")
	{
		Wheel_Graph( pat.pattern_size, g );
	}

	else if (pat.pattern_type == "Lattice")
	{
		Lattice_Graph( pat.pattern_size, g );
	}
    
    else if (pat.pattern_type == "Row")
    {
        Row_Graph( pat.pattern_size, g );
    }
}
