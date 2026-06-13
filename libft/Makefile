# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 14:05:34 by jkarras           #+#    #+#              #
#    Updated: 2024/10/23 14:11:06 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variablen
NAME        = libft.a
CFLAGS      = -Wall -Wextra -Werror
CC          = cc
ARFLAGS     = -rcs
RM          = rm -rf
OBJ_DIR     = obj

# Quellverzeichnisse
SRC_LIBFT_DIR    = libft
SRC_GNL_DIR      = get_next_line
SRC_PRINTF_DIR   = printf

# Quelldateien
SRCS = $(SRC_LIBFT_DIR)/ft_strlen.c \
       $(SRC_LIBFT_DIR)/ft_strrchr.c \
       $(SRC_LIBFT_DIR)/ft_strdup.c \
       $(SRC_LIBFT_DIR)/ft_substr.c \
       $(SRC_LIBFT_DIR)/ft_strjoin.c \
       $(SRC_LIBFT_DIR)/ft_strtrim.c \
       $(SRC_LIBFT_DIR)/ft_strlcpy.c \
       $(SRC_LIBFT_DIR)/ft_itoa.c \
       $(SRC_LIBFT_DIR)/ft_strmapi.c \
       $(SRC_LIBFT_DIR)/ft_striteri.c \
       $(SRC_LIBFT_DIR)/ft_putchar_fd.c \
       $(SRC_LIBFT_DIR)/ft_putstr_fd.c \
       $(SRC_LIBFT_DIR)/ft_putendl_fd.c \
       $(SRC_LIBFT_DIR)/ft_putnbr_fd.c \
       $(SRC_LIBFT_DIR)/ft_isdigit.c \
       $(SRC_LIBFT_DIR)/ft_isalnum.c \
       $(SRC_LIBFT_DIR)/ft_isascii.c \
       $(SRC_LIBFT_DIR)/ft_isprint.c \
       $(SRC_LIBFT_DIR)/ft_memset.c \
       $(SRC_LIBFT_DIR)/ft_bzero.c \
       $(SRC_LIBFT_DIR)/ft_memcpy.c \
       $(SRC_LIBFT_DIR)/ft_memmove.c \
       $(SRC_LIBFT_DIR)/ft_strlcat.c \
       $(SRC_LIBFT_DIR)/ft_toupper.c \
       $(SRC_LIBFT_DIR)/ft_tolower.c \
       $(SRC_LIBFT_DIR)/ft_free_int_arr.c \
       $(SRC_LIBFT_DIR)/ft_strchr.c \
       $(SRC_LIBFT_DIR)/ft_strncmp.c \
       $(SRC_LIBFT_DIR)/ft_memchr.c \
       $(SRC_LIBFT_DIR)/ft_memcmp.c \
       $(SRC_LIBFT_DIR)/ft_strnstr.c \
       $(SRC_LIBFT_DIR)/ft_atoi.c \
       $(SRC_LIBFT_DIR)/ft_calloc.c \
       $(SRC_LIBFT_DIR)/ft_isalpha.c \
       $(SRC_LIBFT_DIR)/ft_split.c \
	$(SRC_LIBFT_DIR)/ft_putchar_array.c \
	$(SRC_LIBFT_DIR)/ft_freechar_array.c \
       $(SRC_LIBFT_DIR)/ft_lstnew_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstadd_front_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstsize_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstlast_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstadd_back_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstdelone_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstclear_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstiter_bonus.c \
       $(SRC_LIBFT_DIR)/ft_lstmap_bonus.c \
       $(SRC_LIBFT_DIR)/ft_print_list.c \
       $(SRC_GNL_DIR)/get_next_line.c \
       $(SRC_GNL_DIR)/get_next_line_utils.c \
       $(SRC_PRINTF_DIR)/ft_phex_p.c \
       $(SRC_PRINTF_DIR)/ft_printf.c \
       $(SRC_PRINTF_DIR)/ft_putchar_p.c \
       $(SRC_PRINTF_DIR)/ft_putnbr_p.c \
       $(SRC_PRINTF_DIR)/ft_putstr_p.c \
       $(SRC_PRINTF_DIR)/ft_putu_p.c \
       $(SRC_PRINTF_DIR)/ft_putvoidhex_p.c

# Objektdateien
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Standardziel
all: $(NAME)

# Bibliothek erstellen
$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "Compiling $(NAME)..."
	@ar $(ARFLAGS) $@ $(OBJS)
	@echo "$(NAME) created successfully!"

# Objektdateien kompilieren
$(OBJ_DIR)/%.o: $(SRC_LIBFT_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_GNL_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_PRINTF_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Objektverzeichnis erstellen
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Aufräumen der Objektdateien und Bibliothek
clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Removing $(NAME)..."
	@$(RM) $(NAME)

# Alles neu erstellen
re: fclean all

.PHONY: all clean fclean re
