/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2023/03/06 09:50:58 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../libft/includes/libft.h"

# ifdef __linux__
#   include "../mlx-linux/mlx.h"
#  elif __APPLE__
#   include "../mlx-mms/mlx.h"
# endif

# define WINDOW_TITLE "so_long"
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# define NB_LIFE 7
# define HUD_LM 920

/*
BPX : bloc px
MPX : movement px
GPX : ground px
JPX : jump px
HPX : hitbox px
EHPX : extra hitbox
*/
# define BPX 100
# define MPX 8
# define GPX 14
# define DPX 20
# define JPX 40
# define HPX 15
# define EHPX 25

/// @brief Structure for the player
/*
pp : pixel position (pp[0] : x, pp[1] : y)
lpp : last pixel position (lpp[0] : x, lpp[1] : y)
a : top left		(a[0] : x, a[1] : y)
b : top right		(b[0] : x, b[1] : y)
c : bottom left 	(c[0] : x, c[1] : y)
d : bottom right 	(d[0] : x, d[1] : y)
js : jump state
ac : actions code
di : diagonal (1 : left, 2 : right)
tl : tick life
nl : life number
direction : (0 left, 1 right)
*/
typedef struct s_player
{
	int	pp[2];
	int	lpp[2];
	int	a[2];
	int	b[2];
	int	c[2];
	int	d[2];
	int	js;
	int	ac[3];
	int	di;
	int	tl;
	int	nl;
	int	direction;
}	t_player;

/// @brief Enemy structure
/*
pp : pixel position (pp[0] : x, pp[1] : y)
init_p : initial position (init_p[0] : x, init_p[1] : y)
a : top left		(a[0] : x, a[1] : y)
b : top right		(b[0] : x, b[1] : y)
c : bottom left 	(c[0] : x, c[1] : y)
d : bottom right 	(d[0] : x, d[1] : y)
alive : dead or alive
move : move or not
ta : tick attack
td : tick dead
direction : direction (0 left, 1 right)
la : last annimation
ap : annimation position
ai : annimation interval
mi : move interval
*/
typedef struct s_monster
{
	int	pp[2];
	int	init_p[2];
	int	a[2];
	int	b[2];
	int	c[2];
	int	d[2];
	int	alive;
	int	move;
	int	ta;
	int	td;
	int	direction;
	int	la;
	int	ap;
	int	ai;
	int	mi;
}	t_monster;

/// @brief Struct that contains all the data of the game
/*
mlx : mlx pointer
window : window pointer
gw : game width
gh : game height
map_fd : map file descriptor
lst_map : linked list that contains datas map
map : map (2D array)
ps : player sprite
gs : gate sprite
ms : monster sprite
cs : collectable sprite
os : other sprite
lm : last millitimestamp
fps : frame per second
po : player offset
go : global offset
nc : number collectable
nm : number movements
player : player struct
monster : monster struct
*/
typedef struct s_so_long {
	void		*mlx;
	void		*window;
	int			gw;
	int			gh;
	int			map_fd;
	t_list		*lst_map;
	char		**map;
	int			dbg;
	void		*ps[54];
	void		*gs[5];
	void		*ms[22];
	void		*cs[5];
	void		*os[7];
	long long	lm;
	int			fps;
	int			po[2];
	int			go[2];
	int			nc;
	int			nm;
	t_player	*player;
	t_list		*monsters;
}	t_so_long;

// core
void		init_s_so_long(char *argv[], t_so_long *so_long);
int			init_map(int argc, char *argv[], t_so_long *so_long);
void		init_sprites(t_so_long *so_long);
int			init_player(t_so_long *so_long);
void		init_camera(t_so_long *so_long);

// tools and debug
long long	millitimestamp(void);
void		fps(t_so_long *so_long);
void		show_fps(t_so_long *so_long);
void		show_action(t_so_long *so_long);
void		show_debug(t_so_long *so_long);
int			limit_args(int argc, char *argv[]);
int			open_map(char *relative_path, t_so_long *so_long);
int			fill_lst(t_so_long *so_long);
int			convert_lst(t_so_long *so_long);
int			size_check(t_so_long *so_long);
int			allowed_char(t_so_long *so_long);
int			required_char(t_so_long *so_long);
int			sides_is_wall(t_so_long *so_long);
void		show_debug_map(t_so_long *so_long);
void		show_debug_map2(t_so_long *so_long);
void		sl_error(int error_n, t_so_long *so_long);
void		draw_block(int x, int y, void *sprite, t_so_long *so_long);

// actions & hooks
void		set_action(int keycode, t_so_long *so_long);
void		unset_action(int keycode, t_so_long *so_long);
int			keydown_hook(int keycode, t_so_long *so_long);
int			keyup_hook(int keycode, t_so_long *so_long);
int			close_hook(int keycode, t_so_long *so_long);

// wall & background
void		wall(t_so_long *so_long);
void		background(t_so_long *so_long);

// player
void		player(t_so_long *so_long);
int			get_plwc(t_so_long *so_long);
int			get_prwc(t_so_long *so_long);
int			get_pgwc(t_so_long *so_long);
int			get_pdwc(t_so_long *so_long);
int			get_pjwc(t_so_long *so_long);
void		player_position(t_so_long *so_long);
void		player_move_y(t_so_long *so_long);
void		player_move_z(t_so_long *so_long);
void		player_move_d(t_so_long *so_long);
void		player_jump(t_so_long *so_long);
void		player_gravity(t_so_long *so_long);
void		player_count_movement(t_so_long *so_long);
void		player_draw(t_so_long *so_long);
int			*get_player_sprite(t_so_long *so_long);
int			player_stay_sprite(int *last_anim, t_so_long *so_long);
int			player_failling_sprite(int *last_anim, t_so_long *so_long);
int			player_down_sprite(int *last_anim, t_so_long *so_long);
int			player_hurt_sprite(int *last_anim, t_so_long *so_long);
int			player_walk_sprite(int *last_anim, t_so_long *so_long);
int			player_attack_sprite(int *last_anim, t_so_long *so_long);
int			player_jumb_sprite(int *last_anim, t_so_long *so_long);

// item
void		item(t_so_long *so_long);

// monster
void		monster(t_so_long *so_long);
int			get_mrwc(t_monster *monster, t_so_long *so_long);
int			get_mlwc(t_monster *monster, t_so_long *so_long);
void		analyse_monster(t_so_long *so_long);
void		monster_position(t_monster *monster);
void		monster_interaction(t_so_long *so_long);
void		monster_move(t_so_long *so_long);
int			*get_monster_sprite(t_monster *m, t_so_long *so_long);

// gate
void		gate(t_so_long *so_long);

// hud
void		show_hud(t_so_long *so_long);

#endif