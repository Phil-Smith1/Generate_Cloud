#pragma once

#include <random>

#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void Generate_Gaussian_Pt ( Point2d direction_vector, double noise_parameter, Point2d& pt )
{
    default_random_engine generator;
    random_device rd;
    generator.seed( rd() );
    normal_distribution<double> distribution( 0, noise_parameter );
    
    double rand = distribution( generator );
    
    Point2d parallel_shift = rand * direction_vector;
    
    rand = distribution( generator );
    
    Point2d normal_shift = rand * Point2d( -direction_vector.y, direction_vector.x );
    
    Point2d shift = parallel_shift + normal_shift;
    
    pt += shift;
}
