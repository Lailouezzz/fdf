# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/06/07 00:11:02 by ale-boud         ###   ########.fr        #
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

CPPFLAGS := -I./libft -I./minilibx -I./ 

# Linker

LD := gcc
LDLIBS := -lmlx -lm -lX11 -lXext -lft
LIBS := libft/libft.a minilibx/libmlx.a
LDFLAGS := -Llibft -Lminilibx

# ---
# Lib information
# ---

NAME := fdf
LIBFT := libft.a

SRCS := main.c mlx_color.c
OBJS := $(SRCS:%.c=%.o)
SRCS_BONUS := 
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)

# ---
#  General targets
# ---

# Build everything

all: $(NAME)

# Mostly clean (clean everything without the end result)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIBFT)
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

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
