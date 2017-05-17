# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/07 02:15:44 by tifuzeau          #+#    #+#              #
#    Updated: 2016/10/27 19:12:52 by tifuzeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

LIB_PATH= ./libft/
INC_PATH= ./includes/
OBJ_PATH= ./obj/
MOD_PATH= env/ builtins/
SRC_PATH= ./src/

# **************************************************************************** #
#									NAME                                       #
# **************************************************************************** #

LIB_NAME= libft
OBJ_NAME= $(SRC_NAME:.c=.o)
SRC_NAME= main.c loop.c parseur.c ft_makearg.c ft_error.c\
		  ft_get_path.c ft_is_indir.c\
		  ft_new_process.c\
		  ft_putstr_free.c \
		  cmd.c ft_runenv.c ft_free_cmd.c\
		  env/ft_env.c env/ft_envget.c env/ft_envlen.c\
		  env/ft_new_env.c env/ft_initenv.c env/ft_getenv.c env/ft_putenv.c\
		  env/ft_envdump.c\
		  builtins/ft_echo.c builtins/ft_cd.c builtins/ft_exit.c\



# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

LIB_SRC = $(addprefix $(LIB_PATH),$(LIB_NAME).a)
INC		= $(addprefix -I,$(INC_PATH))
SRC		= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
MOD		= $(addprefix $(OBJ_PATH),$(MOD_PATH))
# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

CC		= gcc 

# **************************************************************************** #
#									FLAGS                                      #
# **************************************************************************** #

CC_FLAG	= -Wall -Werror -Wextra 
#-fsanitize=address

# **************************************************************************** #
#									COLOR STR VAR                              #
# **************************************************************************** #

START	=\033[0;32mStart\033[0m\n
END		=\033[0;32mEnd\033[0;0m\n\n
OK		=\033[0;33mOK\033[0;0m\n\n

# **************************************************************************** #
#									REGLE                                      #
# **************************************************************************** #

all: $(LIB_SRC) $(OBJ_PATH) $(NAME)
	@printf "make OK\n"

$(NAME): $(OBJ)
	@printf "Creation de $(NAME):"
	@$(CC) $(CC_FLAG) $(LIB_SRC) $^ -o $@
	@printf " $(OK)"

$(LIB_SRC): $(LIB_PATH)
	@printf "Creation de $(LIB_NAME).a: $(START)"
	@make -C $(LIB_PATH) all
	@printf "Creation de $(LIB_NAME).a: $(END)"

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(MOD) 2> /dev/null
	@printf " $(OK)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)
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
