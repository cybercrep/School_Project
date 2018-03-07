# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/07 02:15:44 by tifuzeau          #+#    #+#              #
#    Updated: 2017/12/04 14:42:58 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

LIB_PATH= ./libft/
INC_PATH= ./includes/
OBJ_PATH= ./obj/
SRC_PATH= ./src/

# **************************************************************************** #
#									NAME                                       #
# **************************************************************************** #

LIB_NAME= libft
OBJ_NAME= $(SRC_NAME:.c=.o)
SRC_NAME= main.c parseur.c\
		  init.c\
		  fdf_hook.c\
		  trace_map.c ft_trace_seg.c change_img.c finil_pos.c\
		  ft_putzoom.c free_all.c

# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

LIB_SRC = $(addprefix $(LIB_PATH),$(LIB_NAME).a)
INC		= $(addprefix -I,$(INC_PATH))
SRC		= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

CC		= gcc 

# **************************************************************************** #
#									FLAGS                                      #
# **************************************************************************** #

CC_FLAG	= -Wall -Werror -Wextra

# **************************************************************************** #
#									COLOR STR VAR                              #
# **************************************************************************** #

START	=\033[0;32mStart\033[0m\n
END		=\033[0;32mEnd\033[0;0m\n\n
OK		=\033[0;33mOK\033[0;0m\n\n

# **************************************************************************** #
#									REGLE                                      #
# **************************************************************************** #

all: $(LIB_SRC) $(LIB_MLX) $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	@printf "Creation de $(NAME):"
	@$(CC) $(CC_FLAG) ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit $(LIB_SRC) $^ -o $@
	@printf " $(OK)"

$(LIB_SRC): $(LIB_PATH)
	@printf "Creation de $(LIB_NAME).a: $(START)"
	@make -C $(LIB_PATH) all
	@printf "Creation de $(LIB_NAME).a: $(END)"

$(LIB_MLX): $(MLX_PAT)

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null 
	@printf " $(OK)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./includes/fdf.h
	@printf "Creation de $@:"
	@$(CC) $(CC_FLAG) $(INC) -o $@ -c $<
	@printf " done\n"

clean:
	@printf "Clean des obj:"
	@rm -f $(OBJ)
	@printf " done\n"
	@printf "Clean $(OBJ_PATH):"
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@printf " done\n\n"

clean_lib:
	@printf "Clean $(LIB_NAME): $(START)"
	@make -C $(LIB_PATH) clean
	@printf "Clean $(LIB_PATH): $(END)"

clean_all: clean_lib clean

fclean: clean
	@printf "Clean de $(NAME):"
	@rm -rf $(NAME)
	@printf " $(OK)"

fclean_lib: clean_lib
	@printf "Fclean $(LIB_NAME): $(START)"
	@make -C $(LIB_PATH) fclean
	@printf "Fclean $(LIB_NAME): $(END)"

fclean_all: fclean_lib fclean

re: fclean all

re_all: fclean_all all

norme:
	@printf "\tNorme de $(LIB_PATH)$(LIB_NAME)\n"
	@make -C $(LIB_PATH) norme
	@printf "\tNorme de $(SRC)\n"
	@norminette $(SRC)
	@printf "\tNorme de $(INC_PATH)\n"
	@norminette $(INC_PATH)
