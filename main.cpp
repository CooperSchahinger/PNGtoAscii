#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

bool load_image(std::vector<unsigned char>& image, const std::string& filename, int& x, int&y)
{
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 4);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 4);
    }
    stbi_image_free(data);
    return (data != nullptr);
}

int main() {
    std::string filename = "image6.png";
    
    int width, height;
    std::vector<unsigned char> image;
    bool success = load_image(image, filename, width, height);
    if (!success)
    {
        std::cout << "Error loading image\n";
        return 1;
    }
    
    const size_t RGBA = 4;

    std::string asciiChars = "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[] {}?j|()=~!-/<>\"^_';,:`. ";
    std::vector<std::string> asciiImage;
    
    for(int i=0; i<height; i++) {

        std::string temp = "";
        
        for(int j=0; j<width; j++) {

            size_t index = RGBA * (i * width + j);

            int ave = (static_cast<int>(image[index + 0]) + static_cast<int>(image[index + 1]) + static_cast<int>(image[index + 2]) + static_cast<int>(image[index + 3]))/4;
            // average rba/rgba 

            // std::cout << ave << std::endl;

            temp += asciiChars[95-ave%95];
        }
        asciiImage.push_back(temp);
    }

    // int x = 3;
    // int y = 4;
    // size_t index = RGBA * (y * width + x);
    // std::cout << "RGBA pixel @ (x=3, y=4): " 
    //           << static_cast<int>(image[index + 0]) << " "
    //           << static_cast<int>(image[index + 1]) << " "
    //           << static_cast<int>(image[index + 2]) << " "
    //           << static_cast<int>(image[index + 3]) << '\n';
    
    // for(int i=0; i<height; i++) {

    //     std::string temp = "";
        
    //     for(int j=0; j<width; j++) {

    //         int ave;
    //         // average rba/rgba 
    //         temp += asciiChars[40-ave%40];
    //     }
    //     asciiImage.push_back(temp);
    // }
    
    std::ofstream myfile;
    myfile.open("output.txt");
    if(myfile.is_open()) {
        for(int i=0; i<height; i++) {
            std::string temp = "";
            for(int j=0; j<width; j++) {

                if(asciiImage[i][j] != NULL) {
                    temp += asciiImage[i][j];
                    temp += " ";
                } else {
                    temp+= "  ";
                }


            }
            myfile << temp << std::endl;
        }

        myfile.close();

    } else {
        std::cout << "could not open output.txt" << std::endl;
    }


    // std::cout << asciiChars.size() << std::endl;

    return 0;
}