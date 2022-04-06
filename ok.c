#include <mlx.h>

int	main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 900, "fuck");
	mlx_string_put(mlx, win, 10, 11, 0xFFFFFF, "hicham");
	//while (x < 1000)
	//{
	//	mlx_pixel_put(mlx, win, x, 11, 0xFFFFFF);
	//	x++;
	//}
	mlx_loop(win);
}

