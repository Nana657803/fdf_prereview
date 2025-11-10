# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 19:11:11 by ndobashi          #+#    #+#              #
#    Updated: 2025/09/30 19:11:18 by ndobashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
INCLUDE = include/
SRC_DIR = src/
OBJ_DIR = src/
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I
RM      = rm -f
AR      = ar rcs

SRC_LIBFT = \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii \
	ft_isprint ft_strlen ft_memset ft_toupper ft_tolower \
	ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
	ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
	ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
	ft_strjoin ft_strtrim ft_itoa ft_split ft_strmapi ft_striteri \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	\
	ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus \
	ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus \
	ft_lstiter_bonus ft_lstmap_bonus

SRC_PRINTF = ft_printf ft_printf_hex ft_printf_utils

SRC_GNL = get_next_line get_next_line_utils

LIBFT_DIR  = libft/
PRINTF_DIR = ft_printf/
GNL_DIR    = get_next_line/

SRC_FILES += $(addprefix $(LIBFT_DIR),  $(SRC_LIBFT))
SRC_FILES += $(addprefix $(PRINTF_DIR), $(SRC_PRINTF))
SRC_FILES += $(addprefix $(GNL_DIR),    $(SRC_GNL))

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
