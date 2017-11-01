#pragma once

#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void Generate_Noise_Uniform_Pt ( double noise_parameter, Point2d& pt )
{
    double random_x_shift = ((rand() % 1000) * 2 * noise_parameter / (double)1000) - noise_parameter;
    double random_y_shift = ((rand() % 1000) * 2 * noise_parameter / (double)1000) - noise_parameter;
    
    pt += Point2d(random_x_shift, random_y_shift);
}
