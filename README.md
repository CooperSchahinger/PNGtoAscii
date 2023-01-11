# PNGtoAscii

I saw this idea somewhere on youtube using javascript and thought it would be a fun project to attempt to recreate it using c++. 

The program works by using stb_image to open and read a png. Then the program iterates over all pixels in the image and averages out they're RGBA vales to get a value which represents how dark/light each pixel is. Then the program calculates how which ascii value from the grayscale array is closest to the colour. This is stored in a vector of strings which is later written into the output.txt file. 

**External Libraries** 
- stb_image (https://github.com/nothings/stb)

