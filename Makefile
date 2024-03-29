# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/09/18 19:42:00 by ale-boud         ###   ########.fr        #
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

CWARN := all extra error
CWARN := $(CWARN:%=-W%)

CFLAGS := $(CWARN)

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
SRCS := main.c fdf_vecmat1.c fdf_vecmat2.c fdf_vecmat3.c \
			fdf_render1.c fdf_render2.c fdf_utils.c fdf_map.c \
			bind/fdf_binding.c bind/fdf_bind_zoom.c bind/fdf_binding_cb.c \
			bind/fdf_bind_rot.c bind/fdf_bind_z.c bind/fdf_bind_trans.c \
			fdf_render3.c bind/fdf_bind_proj.c

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

bonus: all

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
