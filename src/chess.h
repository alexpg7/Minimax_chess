#include "../lib/Libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define X 800
#define Y 800
#define B1 0x16283D
#define B2 0x1F3358
#define W1 0xAECEFF
#define W2 0xD8EFFF
#define MC1 0xFFF0DF
#define MC2 0x78889C
#define SC 0xFFE500
#define AC 0x1AFF00
#define WHITE 0xE0E1DD
#define BLACK 0x415A77
#define MSIZE 75

typedef struct s_obj
{
	char	mat[16][15];
	char	mat2[19][12];
}	t_obj;

typedef struct s_tex
{
	t_obj	*rook;
	t_obj	*horse;
	t_obj	*bishop;
	t_obj	*queen;
	t_obj	*king;
	t_obj	*pawn;
	t_obj	*mouse;
}	t_tex;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	t_tex	*tex;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	board[8][9];
	char	board2[8][9];
	int		lastx;
	int		lasty;
	int		sx;
	int		sy;
	char	mode; //f: free, s: selected, w: wait
}	t_vars;

// UTILS
int	ft_lim(int x);

// HOOKS
int	exit_chess(t_vars *vars, int ex);
int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int code, int x, int y, t_vars *vars);
int	mouse_move(int x, int y, t_vars *vars);

// PRINTS
void	ft_putmouse(int x, int y, t_vars *vars);
void	pixel_put(t_vars *vars, int x, int y, int color);
void	pixel_put2(t_vars *vars, int x, int y, int color);
void	print_full_board(t_vars *vars);
void	print_square(int x, int y, t_vars *vars);
void	print_board(int x, int y, t_vars *vars);

// TEXTURES
void	ft_rook(t_vars *vars);
void	ft_horse(t_vars *vars);
void	ft_bishop(t_vars *vars);
void	ft_queen(t_vars *vars);
void	ft_king(t_vars *vars);
void	ft_pawn(t_vars *vars);
void	ft_mouse(t_vars *vars);

// FILL TILES
void	fill_pawn(int x, int y, t_vars *vars);
void	fill_king(int x, int y, t_vars *vars);

// SELECTION
void	ft_blank(t_vars *vars);
void	ft_select(int x, int y, t_vars *vars);
