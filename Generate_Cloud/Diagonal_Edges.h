#pragma once

#include <vector>

using namespace std;

void Diagonal_Edges ( pair<int, int>& squares_iter, vector<bool>& diagonal_edges )
{
    vector<vector<bool>> diagonal_edges_2( 5 );
    
    diagonal_edges_2[0] = { true, false, false, false };
    diagonal_edges_2[1] = { true, true, false, false };
    diagonal_edges_2[2] = { true, false, true, false };
    diagonal_edges_2[3] = { true, true, true, false };
    diagonal_edges_2[4] = { true, true, true, true };
    
    vector<vector<bool>> diagonal_edges_3( 10 );
    
    diagonal_edges_3[0] = { true, false, false, false, false, true, false, false };
    diagonal_edges_3[1] = { true, false, true, false, true, false, false, false };
    diagonal_edges_3[2] = { true, false, true, false, true, true, false, false };
    diagonal_edges_3[3] = { true, true, true, false, false, false, false, true };
    diagonal_edges_3[4] = { true, false, true, false, true, true, true, false };
    diagonal_edges_3[5] = { true, true, true, true, true, false, false, false };
    diagonal_edges_3[6] = { true, true, true, true, true, false, true, false };
    diagonal_edges_3[7] = { true, false, true, false, true, true, true, true };
    diagonal_edges_3[8] = { true, true, true, true, true, true, true, false };
    diagonal_edges_3[9] = { true, true, true, true, true, true, true, true };
    
    if (squares_iter.first == 2)
    {
        diagonal_edges = diagonal_edges_2[squares_iter.second];
        if (squares_iter.second < 4) ++squares_iter.second;
        else squares_iter.second = 0;
    }
    
    else if (squares_iter.first == 3)
    {
        diagonal_edges = diagonal_edges_3[squares_iter.second];
        if (squares_iter.second < 9) ++squares_iter.second;
        else squares_iter.second = 0;
    }
}
