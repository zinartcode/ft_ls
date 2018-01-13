# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 19:05:46 by azinnatu          #+#    #+#              #
#    Updated: 2018/01/12 00:25:05 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	main.o \
		usage.o \
		sort.o \
		process_args.o \
		process_file.o \
		process_dir.o \
		ft_error.o \
		ft_print.o				

LIBFT= libft/libft.a
LIBS = $(LIBFT)

HEADERS = ft_ls.h ./libft/includes/libft.h

CFLAGS += -Wall -Wextra -Werror -g

NAME = ft_ls

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	@make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
