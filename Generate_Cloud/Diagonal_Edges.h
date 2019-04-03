#pragma once

#include <vector>

using namespace std;

void Diagonal_Edges ( int Betti_num, vector<bool>& diagonal_edges )
{
    if (Betti_num == 2) diagonal_edges = { true, false, false, false, false, false, false, false };
    else if (Betti_num == 3) diagonal_edges = { true, false, true, false, false, false, false, false };
    else if (Betti_num == 4) diagonal_edges = { true, true, true, false, false, false, false, false };
    else if (Betti_num == 5) diagonal_edges = { true, true, true, true, false, false, false, false };
    else if (Betti_num == 6) diagonal_edges = { true, true, true, true, true, false, false, false };
    else if (Betti_num == 7) diagonal_edges = { true, true, true, true, true, false, true, false };
    else if (Betti_num == 8) diagonal_edges = { true, true, true, true, true, true, true, false };
    else if (Betti_num == 9) diagonal_edges = { true, true, true, true, true, true, true, true };
}
