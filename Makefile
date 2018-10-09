# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 02:03:14 by gcaixeta          #+#    #+#              #
#    Updated: 2018/09/07 02:07:33 by gcaixeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract\'ol

CC = gcc

FLAGS = -Wall -Werror -Wextra -g -Ofast

SRC_PATH = ./sources/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
MLX_PATH = ./minilibx_macos/
LFT_PATH = ./libft/

SRC_NAME = main.c\
			prints.c\
			keys.c\
			mouse.c\
			images.c\
			color.c\
			complex.c\
			scaling.c\
			zoom.c\
			plot_image.c\
			fractals.c\
			color_ext.c\
			julia_ext.c

INC_NAME = fractol.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx \
	-framework OpenGL -framework AppKit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

simple: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(INC) -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx \
	-framework OpenGL -framework AppKit -lpthread

o: clean all

.PHONY: clean $(NAME) fclean all re simple o
