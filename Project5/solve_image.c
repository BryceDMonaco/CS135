#include <stdio.h>
#include "image_to_array.h"

int main (int argc, char **argv)
{
	printf("***If a core dump occurs, it is because the file name argument is invalid***\n");
	printf("DEBUG: File name is: %s\n", argv[1]);
	
	char fileName[50];
	
	printf("***The following input must be less than 48 characters***\n");
	printf("Enter output file name (include the .ppm extension): ");
	scanf(" %48s", fileName);
	
	ImageData newImage;
	
	newImage = image_to_array(argv[1], 0);
	
	int imageWidth = newImage.width, imageHeight = newImage.height;
	
	for (int i = 0; i < imageHeight; i++)
	{
		for (int ii = 0; ii < imageWidth; ii++)
		{
			int pixel = newImage.data[i][ii];
			
			if (pixel % 2 == 0) //pixel is hiding black
			{
				pixel = 0;
			
			} else if (pixel % 2 == 1) //pixel is hiding white
			{
				pixel = 255;
			
			}
			
			newImage.data[i][ii] = pixel;
		
		}
	
	}
	
	array_to_image(newImage, "Hidden Image");
	
	IplImage* res_img = array_to_image(newImage,"Hidden Image");
	cvSaveImage( fileName, res_img, 0 );
	
	cvWaitKey(0);

}
