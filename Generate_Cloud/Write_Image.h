#pragma once

#include <boost/filesystem.hpp>

#include "Scaling_Parameters.h"
#include "Draw_Cloud.h"
#include "Image_Directory.h"
#include "Image_File_Name.h"

void Write_Image ( string const& image_directory, Pattern const& pat, int iteration, Point const& image_sizes, Scalar const& colour, vector<Data_Pt>const& cloud, Mat& image )
{
    double scale;
    Point2d shift;
    
    Scaling_Parameters( cloud, image_sizes, scale, shift );
    
    Draw_Cloud( cloud, scale, shift, colour, image );
    
    string directory;
    Image_Directory( image_directory, pat, directory );
    
    if(!boost::filesystem::is_directory( directory ))
    {
        boost::filesystem::create_directories( directory );
    }
    
    string image_file;
    Image_File_Name( directory, pat, iteration, image_file );
    
    imwrite( image_file, image );
}
