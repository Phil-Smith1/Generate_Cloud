#pragma once

#include "Scaling_Parameters.h"
#include "Draw_Cloud.h"
#include "Image_File_Name.h"

void Write_Image ( string const& image_directory, Pattern const& pat, int iteration, Point const& image_sizes, Scalar const& colour, vector<Data_Pt>const& cloud, Mat& image )
{
    double scale;
    Point2d shift;
    
    Scaling_Parameters( cloud, image_sizes, scale, shift );
    
    Draw_Cloud( cloud, scale, shift, colour, image );
    
    string image_file;
    Image_File_Name( image_directory, pat, iteration, image_file );
    
    imwrite( image_file, image );
}
