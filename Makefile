# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 12:55:39 by jrinna            #+#    #+#              #
#    Updated: 2022/08/18 09:46:06 by njaros           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#### LIST ####
LST_SRC := atof.c calloc.c camera.c change_object_1.c change_object_2.c color.c color_2.c error.c get_file.c imput_1.c imput_2.c init.c inter.c inter_checker.c inter_cylinder.c inter_cylinder2.c light.c light_2.c light_3.c matrix.c miniRT.c parsing.c parsing_check_object_1.c parsing_check_object_2.c parsing_check_str_1.c parsing_check_str_2.c parsing_init_object_1.c parsing_init_object_2.c pixel_render.c reflexion_formula.c setUsefullMatrix.c split.c thread_manager.c thread_routine.c utils_1.c utils_2.c vec_operation.c vector_formula.c vector_formula3.c vector_formula_2.c 
LST_OBJ := $(LST_SRC:.c=.o)
LST_INC := miniRT.h 
LST_MLX := libmlx.a
#### LSIT ####

#### DIRECTORY ####
DIR_SRC := source
DIR_OBJ := .object
DIR_INC := include
DIR_BIN := binary
DIR_MLX := mlx
#### DIRECTORY ####

#### COMPLETE_PATH ####
SRC := $(addprefix $(DIR_SRC)/,$(LST_SRC))
OBJ := $(addprefix $(DIR_OBJ)/,$(LST_OBJ))
INC := $(addprefix $(DIR_INC)/,$(LST_INC))
MLX := $(addprefix $(DIR_MLX)/,$(LST_MLX))
#### COMPLETE_PATH ####

#### OTHER ####
CC := gcc
CFLAGS := -O3 -Wall -Werror -Wextra
CFRAM := -framework OpenGL -framework AppKit
NAME := $(DIR_BIN)/miniRT
#### OTHER ####

#### STANDARD_RULE ####
all : $(NAME)

re : fclean all

clean :
	rm -rf $(DIR_OBJ)

fclean : clean
	rm -rf $(DIR_BIN)
#### STANDARD_RULE ####

### CUSTOM_RULE ####
$(NAME) : $(OBJ) | $(DIR_BIN) $(MLX)
	$(CC) $(CFLAGS) $(CFRAM) $(MLX) $^ -o $(NAME)

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(INC) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC) -I $(DIR_MLX)

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

$(DIR_BIN) :
	mkdir -p $(DIR_BIN)

$(MLX) :
	$(MAKE) -C $(DIR_MLX)
#### CUSTOM_RULE ####

#### UTILS ####
.PHONY : all re clean fclean
#### UTILS ####
