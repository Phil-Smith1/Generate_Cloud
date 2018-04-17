#pragma once

#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void Generate_Uniform_Pt ( Point2d unit_edge_direction, double noise_parameter, Point2d& pt )
{
    double rand_num = ((rand() % 1000) * 2 * noise_parameter / (double)1000) - noise_parameter;
    
    Point2d parallel_shift = rand_num * unit_edge_direction;
    
    rand_num = ((rand() % 1000) * 2 * noise_parameter / (double)1000) - noise_parameter;
    
    Point2d normal_shift = rand_num * Point2d( -unit_edge_direction.y, unit_edge_direction.x );
    
    Point2d shift = parallel_shift + normal_shift;
    
    pt += shift;
}
