/*
	Bryce Monaco
	CS135-1201
	
	make_steg.c - Project 5
	
	This program hides one image in another using steganography. Use .ppm image files.
	
*/

#include <stdio.h>
#include "image_to_array.h"

int main (void)
{
	char baseImage[50], hideImage[50];
	
	printf("***The following file names MUST be less than 48 characters***\n");
	printf("***The images must be of equal dimensions***\n");
	printf("Enter the name of the base image (will be seen)(include extension): ");
	scanf(" %48s", baseImage);
	
	printf("Enter the name of the hidden image (will be hidden)(include extension): ");
	scanf(" %48s", hideImage);
	
	printf("DEBUG: %s will be the base and %s will be hidden.\n", baseImage, hideImage);
	
	ImageData baseImageData, hideImageData;
	
	baseImageData = image_to_array(baseImage, 0);
	hideImageData = image_to_array(hideImage, 0);
	
	int baseWidth, baseHeight, hideWidth, hideHeight;
	
	baseWidth = baseImageData.width;
	baseHeight = baseImageData.height;
	hideWidth = hideImageData.width;
	hideHeight = hideImageData.height;
	
	printf("DEBUG: Base is %d pixels wide and %d pixels tall.\n", baseWidth, baseHeight);
	printf("DEBUG: Hide is %d pixels wide and %d pixels tall.\n", hideWidth, hideHeight);
	
	for (int i = 0; i < baseHeight; i++)
	{
		for (int ii = 0; ii < baseWidth; ii++)
		{
			int pixel = baseImageData.data[i][ii];
			//printf("DEBUG: pixel[%d][%d] is %d -> ", i, ii, pixel); (uncommenting this will increase compute time)
			pixel >>= 1;
			pixel <<= 1;
			
			/*
				The following:
					-	Checks if the value in the hidden image is black (0) or white (255)
					-	If it is white, the pixel in the base image is given a binary value ending in 1, if it is black the pixel in the base image is given a binary value ending in 0
			
			*/
			if (hideImageData.data[i][ii] == 255) //The pixel is white
			{
				//Any even number's binary value ends in 0, 1 for odd numbers
				if (pixel % 2 == 0) //The binary number ends in 0
				{
					pixel += 1;
				
				} else if (pixel % 2 == 1) //The binary number ends in 1
				{	
					//Do nothing	
				
				}
			
			} else if (hideImageData.data[i][ii] == 0) //The pixel is black
			{
				if (pixel % 2 == 0) //The binary number ends in 0
				{
					//Do nothing
				
				} else if (pixel % 2 == 1) //The binary number ends in 1
				{	
					pixel += 1;
				
				}
			
			
			} else
			{
				//The lest sig. bit will default to 0 (black)
			
			}
			
			
			//printf("%d\n", pixel); (uncommenting this will increase compute time)
			
			baseImageData.data[i][ii] = pixel;
		
		}
	
	}
	
	char encodeImage[50];
	
	printf("***The following input must be less than 48 characters***\n");
	printf("Enter the name of the newly encoded image (will save with this name)(include the .ppm extension): ");
	scanf(" %48s", encodeImage);
	
	IplImage* res_img = array_to_image(baseImageData, "Encrypted Image");

	cvSaveImage( encodeImage, res_img, 0 );
	
	cvWaitKey(0);
	
	return 0;

}
