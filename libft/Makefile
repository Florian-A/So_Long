# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 11:45:53 by f██████           #+#    #+#              #
#    Updated: 2023/03/08 18:51:30 by f██████          ###   ########.fr        #
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

# character
OBJS_CHAR = $(SRC_CHAR:.c=.o)
SRC_CHAR = $(addprefix $(SRC_DIR)/char/, \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c \
ft_toupper.c \
)

# chained list
OBJS_LST = $(SRC_LST:.c=.o)
SRC_LST	= $(addprefix $(SRC_DIR)/lst/, \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstfirst.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lst_push.c \
)

# memory
OBJS_MEM = $(SRC_MEM:.c=.o)
SRC_MEM	= $(addprefix $(SRC_DIR)/mem/, \
ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_mint_free.c ft_dmalloc.c \
)

# conversion
OBJS_CONV = $(SRC_CONV:.c=.o)
SRC_CONV = $(addprefix $(SRC_DIR)/conv/, \
ft_atoi.c ft_atol.c ft_itoa.c \
)

# character string
OBJS_STR = $(SRC_STR:.c=.o)
SRC_STR	= $(addprefix $(SRC_DIR)/str/, \
ft_split.c ft_strchr_i.c ft_strchr.c ft_strdup.c ft_strndup.c \
ft_striteri.c ft_strjoin.c ft_strnjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
ft_strnstr_i.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_isnbr.c ft_str_repl.c \
)

# file descriptor
OBJS_PUT = $(SRC_PUT:.c=.o)
SRC_PUT	= $(addprefix $(SRC_DIR)/put/, \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putunbr_fd.c \
)

# array
OBJS_ARR = $(SRC_ARR:.c=.o)
SRC_ARR	= $(addprefix $(SRC_DIR)/arr/, \
ft_arr2dfree.c ft_arr2dlen.c ft_arradd_str.c \
)

# printf
OBJS_PRINTF = $(SRC_PRINTF:.c=.o)
SRC_PRINTF = $(addprefix $(SRC_DIR)/printf/, \
ft_printf.c i_to_hex.c putc_fd.c putdi_fd.c putp_fd.c puts_fd.c putu_fd.c \
putx1_fd.c putx2_fd.c ull_to_hex.c \
)

# get next line
OBJS_GNL = $(SRC_GNL:.c=.o)
SRC_GNL	= $(addprefix $(SRC_DIR)/gnl/, \
get_next_line.c \
)

# test
OBJS_TEST = $(SRC_TEST:.c=.o)
SRC_TEST = $(addprefix $(SRC_DIR)/test/, \
utest.c test_show_start.c test_show_result.c test_init_struct.c  \
)

# unit tests
OBJS_UTEST = $(SRC_UTEST:.c=.o)
SRC_UTEST = $(addprefix $(SRC_DIR)/.utests/, \
main.c test_ft_strlen.c test_ft_atoi.c test_ft_atol.c test_ft_bzero.c \
test_ft_calloc.c test_ft_isalnum.c test_ft_arradd_str.c test_ft_str_repl.c \
)

SRC_DIR	= .
INC_DIR	= ./includes/
CC = gcc
AR = ar
MF = Makefile

ifeq ($(DEBUG), 1)
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else
FLAGS = -Wall -Wextra -Werror
endif

LIBFT_NAME = libft.a
LIBFT_HEADER_FILE	= $(INC_DIR)/libft.h
LIBTEST_NAME = libtest.a
LIBTEST_HEADER_FILE	= $(INC_DIR)/libtest.h
UTEST_NAME = utest
UTEST_HEADER_FILE = $(INC_DIR)/utest.h

all : $(LIBFT_NAME)

$(LIBFT_NAME) : $(MF) $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(AR) -rcs $(LIBFT_NAME) $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)
	@echo "\n${GREEN}> Compilation of the libft is success 🎉${END}"

test : $(MF) $(LIBFT_NAME) $(LIBTEST_NAME) $(UTEST_NAME)

$(LIBTEST_NAME) : $(MF) $(LIBFT_NAME)  $(OBJS_TEST)
	@$(AR) -rcs $(LIBTEST_NAME) $(OBJS_TEST)
	@echo "\n${GREEN}> Compilation of the libtest is success 🎉${END}"

$(UTEST_NAME) : $(MF) $(OBJS_UTEST) $(LIBTEST_NAME)
	@$(CC) $(FLAGS) $(OBJS_UTEST) $(LIBTEST_NAME) $(LIBFT_NAME) -o $(UTEST_NAME)
	@echo "\n${GREEN}> Compilation of unit tests is success 🎉${END}"

clean :
	@rm -f $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_TEST) $(OBJS_UTEST)
	@echo "${YELLOW}> All objects files of libft have been deleted ❌${END}"

fclean : clean
	@rm -f $(LIBFT_NAME)
	@rm -f $(LIBTEST_NAME)
	@rm -f $(UTEST_NAME)
	@echo "${YELLOW}> Cleaning of libft has been done ❌${END}"

re : fclean all

./test/%.o : ./test/%.c $(LIBTEST_HEADER_FILE) Makefile
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

./.utests/%.o : ./.utests/%.c $(UTEST_HEADER_FILE) Makefile
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

%.o : %.c $(LIBFT_HEADER_FILE) Makefile
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

.PHONY: all clean fclean re test