/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:05:16 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/10 15:27:48 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "FDF"

# define DEFAULT_COLOR 0xFFFFFF

# define ANGLE_30 0.523599
# define Z_SCALE_FACTOR 0.25
# define DEFAULT_ZOOM 20.0
# define MIN_ZOOM 0.5
# define MAX_ZOOM 500.0
# define ZOOM_STEP 1.1

# ifdef __linux__
#  define KEY_ESC 65307
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# else
#  define KEY_ESC 53
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# endif

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}	t_point;

typedef struct s_line_drawer
{
	int		delta_x;
	int		delta_y;
	int		step_x;
	int		step_y;
	int		error;
	int		error_temp;
}	t_line_drawer;

typedef struct s_map
{
	int			width;
	int			height;
	t_point		**points;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	double		zoom_factor;
	int			shift_x;
	int			shift_y;
}	t_map;

void	initialize_map(t_map *map);
void	terminate_program(t_map *map, char *message, int exit_code);
void	load_map_file(char *filename, t_map *map);
int		count_line_elements(char *line);
void	parse_coordinates(t_point *points, char *line, int row, int width);
void	render_wireframe(t_map *map);
void	draw_line(t_map *map, t_point start, t_point end, int color);
void	set_pixel(t_map *map, int x, int y, int color);
t_point	project_to_screen(t_point point, t_map *map);
int		handle_keypress(int keycode, t_map *map);
int		handle_mouse(int button, int x, int y, t_map *map);
int		handle_window_close(t_map *map);

#endif
