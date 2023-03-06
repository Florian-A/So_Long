# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:33:02 by f██████           #+#    #+#              #
#    Updated: 2023/03/06 09:50:58 by f██████          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# minimal color codes
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

OBJS_SL = $(SRCS_SL:.c=.o)
SRCS_SL = $(addprefix $(SRC_DIR)/, \
core/main.c core/init.c core/draw.c core/error.c core/hook.c core/sprite.c \
parsing/parsing1.c parsing/parsing2.c \
tools/debug.c tools/fps.c tools/hud.c \
player/player.c player/player_position.c player/player_action.c player/player_distance.c player/player_mouvement.c \
player/player_gravity.c player/player_draw.c player/player_count_movement.c player/player_sprite1.c player/player_sprite2.c \
monster/monster.c monster/monster_distance.c monster/monster_position.c monster/monster_interaction.c monster/monster_movement.c monster/monster_sprite1.c \
other/wall.c other/background.c other/item.c other/gate.c \
)

OBJS_UTEST = $(SRC_UTEST:.c=.o)
SRC_UTEST = $(addprefix ./.utests/, \
main.c \
)

SRC_DIR	= ./sources
INC_DIR	= ./includes/
CC = gcc
MF = Makefile

ifeq ($(DEBUG), 1)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else
CFLAGS = -Wall -Wextra -Werror
endif

NAME = so_long
LIBFT_PATH = ./libft/libft.a
LIBTEST_PATH = ./libft/libtest.a
SL_HEADER_FILE = $(INC_DIR)/so_long.h
UTEST_NAME = utest
UTEST_HEADER_FILE = $(INC_DIR)/utest.h


ifeq ($(OS),Darwin)
  GFLAGS = -framework OpenGL -framework Appkit -l z
  GPATH = ./mlx-mms/
  MLX_PATH = $(GPATH)/libmlx.dylib
else
  GFLAGS = -lXext -lX11 -lm -lbsd
  GPATH = ./mlx-linux/
  MLX_PATH = $(GPATH)/libmlx.a
endif


all : _libft _mlx $(NAME)

$(NAME) : $(MF) $(OBJS_SL) $(LIBFT_PATH) $(MLX_PATH)
	@$(CC) $(CFLAGS) $(OBJS_SL) $(LIBFT_PATH) $(MLX_PATH) $(GFLAGS) -o $(NAME) 
	@echo "\n${GREEN}> Compilation of so_long is success 🎉${END}"

./.utests/%.o : ./.utests/%.c $(UTEST_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_DIR) 

%.o : %.c $(SL_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	@make clean -C ./libft
	@make clean -C $(GPATH)
	@rm -f $(OBJS_SL)
	@rm -f $(OBJS_UTEST)
	@echo "${YELLOW}> All objects files of so_long have been deleted ❌${END}"

fclean : clean
	@make fclean -C ./libft
	@make clean -C $(GPATH)
	@rm -f $(NAME)
	@rm -f $(UTEST_NAME)
	@echo "${YELLOW}> Cleaning of so_long has been done ❌${END}"

re: fclean all

_libft :
	@make -C ./libft DEBUG=$(DEBUG)

_test :
	@make test -C ./libft DEBUG=$(DEBUG)

_mlx :
	make -C $(GPATH)

test: _libft _mlx _test $(UTEST_NAME)

$(UTEST_NAME) : $(MF) $(OBJS_UTEST) $(LIBTEST_PATH) $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS_UTEST) $(LIBTEST_PATH) $(LIBFT_PATH) $(MLX_PATH) -o $(UTEST_NAME)
	@echo "\n${GREEN}> Compilation of unit tests is success 🎉${END}"

.PHONY:	all clean fclean re lib