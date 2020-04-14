# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusehair <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 14:35:48 by lusehair          #+#    #+#              #
#    Updated: 2020/04/14 16:53:41 by lucasseha        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = 
FLAG = -Wall -Werror -Wextra

LIBC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	   ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putnbr_fd.c ft_putendl_fd.c ft_strrev.c ft_split.c \
	   ft_strtrim.c ft_strmapi.c ft_strjoin.c ft_strncat.c  ft_substr.c\
	   get_next_line.c get_next_line_utils.c ft_putchar.c ft_putstr.c \
	   ft_putnbr.c \

LIBCPRINTF = ft_printf/ft_adress.c ft_printf/ft_char_init.c ft_printf/ft_hexa.c\
			 ft_printf/ft_int.c ft_printf/ft_int_dashcase.c \
			 ft_printf/ft_int_standcase.c ft_printf/ft_itoa.c \
			 ft_printf/ft_itoabase.c ft_printf/ft_letter.c \
			 ft_printf/ft_printf.c ft_printf/ft_printf_init.c \
			 ft_printf/ft_str_dashcase.c ft_printf/ft_str_standcase.c \
			 ft_printf/ft_unsign.c ft_printf/ft_unsign_dashcase.c \
			 ft_printf/ft_unsign_standcase.c

INCLIBC =  libft.h get_next_line.h ft_printf/ft_printf.h

OBJ = $(patsubst %.c,%.o, $(LIBC) $(LIBCPRINTF))
.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME)


all : $(NAME) 

$(NAME) : $(LIBC) $(LIBCPRINTF) $(INCLIB) $(OBJ)
		echo "\033[1;33mLIBFTV2 compiling...\033[0m"
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		echo "\033[32mLIBFTV2 compilation done !\033[0m"

%.o : %.c
	@gcc -I. -o $@ -c $<

clean :
	echo "\033[1;33mCleaning LIBFTV2 ...\033[0m"
	rm -f $(OBJ)
	echo "\033[0;35m.o removed.\033[0m"

fclean: clean
	    rm -f $(NAME)
		echo "\033[0;35m$(NAME) removed.\033[0m"
re: fclean all

