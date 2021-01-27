# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 16:32:26 by abenouda          #+#    #+#              #
#    Updated: 2019/12/16 01:22:46 by abenouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	printchar.c printnbr.c printstr.c tools.c\
		tools2.c flags.c check_conversion.c print_c.c\
		ft_printf.c print_u.c print_prcnt.c print_int.c\
		print_int2.c print_int3.c print_s.c print_s2.c print_x.c\
		print_x2.c print_p.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	
fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
