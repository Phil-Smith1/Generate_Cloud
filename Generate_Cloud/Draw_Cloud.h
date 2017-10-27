#pragma once

#include <opencv2/imgproc/imgproc.hpp>

#include "Data_Pt.h"

using namespace std;

void Draw_Cloud ( vector<Data_Pt>const& cloud, double const& scale, Point2d const& shift, Scalar const& colour, Mat& image )
{
    for (auto p : cloud)
    {
        circle( image, Point(scale * p.pt + shift), 1, colour, 1);
    }
}
