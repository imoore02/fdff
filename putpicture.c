#include "mlx.h"
#include <math.h>

void	pixel_put(char *imgstr, int pixel, int colour);

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void 	*img_ptr;
	char 	*imgstr;
	int 	pixel_bits;
	int		line_bytes;
	int 	endian;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 360, "adjnsfbvpuiwaebf[ober!");
	img_ptr = mlx_new_image(mlx_ptr, 640, 360); //creates a new image in mem - returns void* needed to manipulate the image later - NULL if fail
		//user caxn draw inside image - can put the image in a specified window at any time using next func vvv
		//img_ptr stores its return value
	imgstr = mlx_get_data_addr(img_ptr, &pixel_bits, &line_bytes, &endian);//buffer will store the actual char* that represents the image
		//returns information about the created image (char * (address that represents the begining of the mem area where the image is stored)) - allows user to manipulate it later
			//bits per pixel/bit-depth value
				//number of bits used to define/represent a pixel colour = its bit-depth (24 bit colour)
				//from the char* address returned - first bits_per_pixel represents the colour of the first pixel in the first line of the image
				//second bits_per_pixel represents the 2nd pixel of the first line etc
			//size_line
				//number of bytes used to store one line of the image in mem - needed to move from one line to another in the image (GNL)
				//add size_line (int) to the char*address to get the begining of the second line
			//endian
				//tells you whether the pixel colour in the image needs to be stored in little endian (== 0) or big endian (== 1)
	int y = 0;
	int x = 0;

	while (y < 360)
	{
		while(x < 640)
		{
		int pixel = (y * line_bytes) + (x * 4);
		pixel_put(imgstr, pixel, 0xFF0000);
		x++;
		}
		++y;
		int pixel = (y * line_bytes) + (x * 4);
		pixel_put(imgstr, pixel, 0xFF0000);
		x = 0;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0); //xy coordinates define where image should be placed in window
	//mlx_destroy_image(mlx_ptr, img_ptr);
	mlx_loop(mlx_ptr); 
	return (0);
}

//pixel position = (y + 4 * x) : 4 characters ~ the position in the char * is 20 , 21, 22, 23 for the coords (5,0)
//Y axis movement? = x + (4 * linesize * Y) ~ the position of pixel at (0,2) of a window size 800x600, is held in the char* at 6400, 6401, 6402, 6403

void	pixel_put(char *imgstr, int pixel, int colour)	
{
	imgstr[pixel + 0] = (colour) & 0xFF;
    imgstr[pixel + 1] = (colour >> 8) & 0xFF;
    imgstr[pixel + 2] = (colour >> 16) & 0xFF;
    imgstr[pixel + 3] = (colour >> 24);	
}