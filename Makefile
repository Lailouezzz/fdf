# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/06/15 15:35:53 by ale-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---
# Tools
# ---

MKDIR := mkdir
RM := rm -f

# ---
# Build variables
# ---

# Compiler

CC := gcc

CWARN := all extra
CWARN := $(CWARN:%=-W%)

CFLAGS := -g $(CWARN)

# Preprocessor flag

CPPFLAGS := -I./libft -I./minilibx -I./include 

# Linker

LD := gcc
LDLIBS := -lmlx -lm -lX11 -lXext -lft
LIBS := libft/libft.a minilibx/libmlx.a
LDFLAGS := -Llibft -Lminilibx

# ---
# Lib information
# ---

NAME := fdf

SRC_DIR := ./src
SRCS := main.c mlx_color.c fdf_vecmat1.c fdf_vecmat2.c fdf_vecmat3.c \
			fdf_render1.c fdf_render2.c fdf_utils.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJ_DIR := ./build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS := 
SRCS_BONUS := $(SRCS_BONUS:%=$(SRC_DIR)/%)
OBJS_BONUS := $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ---
#  General targets
# ---

# Build everything

all: $(NAME)

# Mostly clean (clean everything without the end result)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C libft

# Clean everything

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) clean -C minilibx

# Rebuild

re: clean all

# Bonus

bonus: all
	
.PHONY: all clean fclean re bonus

# ---
# Build targets
# ---

libft/libft.a:
	$(MAKE) -C libft all

minilibx/libmlx.a:
	$(MAKE) -C minilibx all

$(NAME): $(OBJS) $(LIBS)
	$(LD) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
