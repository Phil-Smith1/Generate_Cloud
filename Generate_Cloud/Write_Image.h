#pragma once

#include <boost/filesystem.hpp>

#include "Scaling_Parameters.h"
#include "Draw_Cloud.h"
#include "Directory.h"
#include "File_Name.h"

void Write_Image ( string const& image_directory, Input const& input, int iteration, Point const& image_sizes, Scalar const& colour, vector<Data_Pt>const& cloud, Mat& image )
{
    double scale;
    Point2d shift;
    
    Scaling_Parameters( cloud, image_sizes, scale, shift );
    
    Draw_Cloud( cloud, scale, shift, colour, image );
    
    string directory;
    Directory( image_directory, input, directory );
    
    if(!boost::filesystem::is_directory( directory ))
    {
        boost::filesystem::create_directories( directory );
    }
    
    string image_file;
    File_Name( directory, "Image", iteration, ".png", image_file );
    
    imwrite( image_file, image );
}
