# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 19:05:46 by azinnatu          #+#    #+#              #
#    Updated: 2018/01/17 17:48:04 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	main.o \
		usage.o \
		sort.o \
		process_args.o \
		process_file.o \
		process_dir.o \
		utilities.o \
		ft_print.o				

LIBFT= libft/libft.a
LIBS = $(LIBFT)

HEADERS = ft_ls.h ./libft/includes/libft.h

CFLAGS += -Wall -Wextra -Werror

NAME = ft_ls

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	@make -C libft/ fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
