# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdony <hdony@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:53:49 by hdony             #+#    #+#              #
#    Updated: 2023/02/13 11:57:01 by hdony            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

#-------------------SOURCES PATH----------------------

PARSING		=	./srcs/parsing/
SOURCES		=	./srcs/

#-------------------COMPILATION----------------------

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -g
# FLAGS		=	-Wall -Werror -Wextra -fsanitize=address
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

#-------------------SOURCES FILES----------------------

SRCS		=	$(SOURCES)main.c \
				$(SOURCES)clean.c \
				$(SOURCES)graph_utils.c \
				$(SOURCES)hooks.c \
				$(SOURCES)topview.c \
				$(SOURCES)init.c \
				$(SOURCES)init_utils.c \
				$(SOURCES)raycast1.c \
				$(SOURCES)raycast2.c \
				$(SOURCES)render.c \
				$(SOURCES)movement1.c \
				$(SOURCES)movement2.c
				

SRCS_UTILS	=	$(PARSING)checkFileExt.c \
				$(PARSING)initStruct.c \
				$(PARSING)browseMap.c \
				$(PARSING)browseMapUtils.c \
				$(PARSING)allocateMap.c \
				$(PARSING)free.c \
				$(PARSING)checkMap.c \
				$(PARSING)checkMapWalls.c

#-------------------OBJECTS----------------------

OBJS		=	$(SRCS:.c=.o)

OBJS_UTILS	=	$(SRCS_UTILS:.c=.o)

LIBFT		=	./libft/libft.a

#-------------------COLORS----------------------

RED			=	\x1b[31m

YELLOW		=	\x1b[33m

GREEN		=	\x1b[32m

NO_COLOR	=	\x1b[0m


#-------------------RULES-----------------------
%.o: %.c
		@printf "$(YELLOW)Generating cub3d objects... %-33.33s\r$(NO_COLOR)" $@
		@$(CC) $(FLAGS) -Imlx -I ./includes -c $< -o $@

$(NAME):	$(OBJS) $(OBJS_UTILS)
			@echo "\n"
			@make -C ./libft
			@echo "$(GREEN)\nCompiling mlx...\n$(NO_COLOR)"
			@make -C minilibx
#			@cp ./minilibx/libmlx.dylib ./
			@echo "$(GREEN)\nCompiling cub3d...$(NO_COLOR)"
			@$(CC) $(FLAGS) -L ./minilibx $(MLX_FLAGS) $(OBJS) $(OBJS_UTILS) $(LIBFT) -o $(NAME)
			@echo "\nEnjoy!"

all:	$(NAME)

bonus:	$(NAME)

clean:
		@echo "$(RED)Deleting objects...\n$(NO_COLOR)"
		@make clean -C ./libft
		@make clean -C minilibx
		@rm -f $(OBJS) $(OBJS_UTILS)

fclean:	clean
		@echo "$(RED)Deleting executables...\n$(NO_COLOR)"
		@rm -rf $(LIBFT)
		@rm -rf $(LIB_MLX)
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re