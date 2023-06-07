# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/05/16 10:51:04 by ale-boud         ###   ########.fr        #
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

CFLAGS := -c $(CWARN)

# ---
# Lib information
# ---

NAME := libft.a

SRCS := ft_toupper.c ft_putchar_fd.c ft_isalnum.c ft_strlcpy.c ft_memset.c \
	ft_calloc.c ft_strmapi.c ft_putendl_fd.c ft_strlcat.c ft_strchr.c \
	ft_memmove.c ft_striteri.c ft_substr.c ft_putnbr_fd.c ft_strdup.c \
	ft_strjoin.c ft_isdigit.c ft_strnstr.c ft_split.c ft_memcmp.c ft_isascii.c \
	ft_strlen.c ft_strrchr.c ft_putstr_fd.c ft_itoa.c ft_memcpy.c ft_isalpha.c \
	ft_strtrim.c ft_memchr.c ft_tolower.c ft_isprint.c ft_strncmp.c ft_bzero.c \
	ft_atoi.c ft_printf/ft_printf_arg.c ft_printf/ft_printf_conv2.c \
	ft_printf/ft_printf_itoa.c ft_printf/ft_printf.c \
	ft_printf/ft_printf_conv.c ft_printf/ft_printf_minmaxabs.c \
	ft_printf/ft_print_pad.c

OBJS := $(SRCS:%.c=%.o)
SRCS_BONUS := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)

# ---
#  General targets
# ---

# Build everything

all: bonus

# Mostly clean (clean everything without the end result)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

# Clean everything

fclean: clean
	$(RM) $(NAME)

# Rebuild

re: fclean all

# Bonus

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^
	
.PHONY: all clean fclean re bonus

# ---
# Build targets
# ---

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ $<
