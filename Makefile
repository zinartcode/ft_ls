# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 19:05:46 by azinnatu          #+#    #+#              #
#    Updated: 2017/12/19 19:44:53 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	main.o 					\
		permissions.o 			\
		usage.o					\
		sort.o					\
		print_opts.o			\
		ft_print.o				

LIBFT= libft/libft.a
LIBS = $(LIBFT)

HEADERS = ft_ls.h ./libft/includes/libft.h

CFLAGS +=  -g

NAME = ft_ls

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all