#include "minirt.h"

static void	init_image(void	*mlx, t_image *image)
{
	image->img = mlx_new_image(mlx, 500, 500);
	image->addr = mlx_get_data_addr(
			image->img,
			&(image)->bits_per_pixel,
			&(image)->line_length,
			&(image)->endian);

}

void	init_mlx(t_mlx	*mlx)
{
	mlx->mlx_instance = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_instance, 500, 500, "miniRT!");
	mlx->width = 500;
	mlx->height = 500;
	init_image(mlx->mlx_instance, &(mlx)->image);
}
