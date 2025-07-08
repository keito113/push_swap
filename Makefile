# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 10:33:21 by keitabe           #+#    #+#              #
#    Updated: 2025/07/08 10:51:58 by keitabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC        = cc
CFLAGS    = -Wall -Wextra -Werror

NAME      = push_swap

SRCS      = operations.c \
            parse_args.c \
            push_swap.c \
            sort_small.c \
            utils.c \
            wrapper.c \
            wrapper_rotate.c

OBJS      = $(SRCS:.c=.o)

LIBFT_DIR = libft_submit
LIBFT     = $(LIBFT_DIR)/libft.a

INCLUDES  = -I$(LIBFT_DIR) -I.

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@if [ -n "$?" ]; then \
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME); \
	fi

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS) -I.. -I."

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
