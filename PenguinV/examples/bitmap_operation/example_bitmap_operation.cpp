// Example application of library utilization for bitmaps
#include <iostream>
#include "../../Library/image_buffer.h"
#include "../../Library/image_function.h"
#include "../../Library/FileOperation/bitmap.h"

void method1();
void method2();

int main()
{
    // This example application is made to show how to use bitmap file operations
    // as well as basic image processing operations.
    // Conditions:
    // - "Houston, we received the image of Mercury!"
    // We have an image of Mercury (24-bit color image). We want to load it,
    // convert to gray-scale, extract the planet on image by applying thresholding and
    // save image on storage

    try // <---- do not forget to put your code into try.. catch block!
    {
        // First way to do
        method1();
        // Second way to do
        method2();
    }
    catch( imageException & ex ) {
        // uh-oh, something went wrong!
        std::cout << "Exception " << ex.what() << " raised. Do your black magic to recover..." << std::endl;
        // your magic code must be here to recover from bad things
        return 0;
    }
    catch( ... ) {
        // uh-oh, something terrible happen!
        std::cout << "Something very terrible happen. Do your black magic to recover..." << std::endl;
        // your magic code must be here to recover from terrible things
        return 0;
    }

    std::cout << "Everything went fine." << std::endl;

    return 0;
}

void method1()
{
    // Load an image from storage
    // Please take note that the image must be in the same folder as this application or project (for Visual Studio)
    // Otherwise you can change the path where the image stored
    Bitmap_Image::Image image = Bitmap_Operation::Load( "mercury.bmp" );

    // If the image is empty it means that the image doesn't exist or the file is not readable
    if( image.empty() )
        throw imageException( "Cannot load the image" );

    // Convert to gray-scale image if it's not
    if( image.colorCount() != Bitmap_Image::GRAY_SCALE )
        image = Image_Function::ConvertToGrayScale( image );

    // Threshold image with calculated optimal threshold
    image = Image_Function::Threshold( image, Image_Function::GetThreshold( Image_Function::Histogram( image ) ) );

    // Save result
    Bitmap_Operation::Save( "result1.bmp", image );
}

void method2()
{
    // Load an image from storage
    // Please take note that the image must be in the same folder as this application or project (for Visual Studio)
    // Otherwise you can change the path where the image stored
    Bitmap_Image::Image image = Bitmap_Operation::Load( "mercury.bmp" );

    // If the image is empty it means that the image doesn't exist or the file is not readable
    if( image.empty() )
        throw imageException( "Cannot load the image" );

    // Convert to gray-scale image if it's not
    if( image.colorCount() != Bitmap_Image::GRAY_SCALE )
        image = Image_Function::ConvertToGrayScale( image );

    // Threshold image with calculated optimal threshold and directly save result in file
    Bitmap_Operation::Save( "result2.bmp",
                            image = Image_Function::Threshold(
                                image, Image_Function::GetThreshold(
                                    Image_Function::Histogram( image ) ) ) );
}
