##
## Makefile for Makefile in /home/noahl/piscine/delivery/CPool_Day10/lib/my
##
## Made by Lothaire Noah
## Login   <noahl@epitech.net>
##
## Started on  Mon Oct 17 19:10:30 2016 Lothaire Noah
## Last update Mon Apr  3 19:34:13 2017 Quentin Sonnefraud
## Started on  Tue Jan 31 14:48:48 2017 Quentin Sonnefraud
## Last update Fri Feb 24 16:42:23 2017 Vatoth
##

CC    	=    gcc

RM    	=    rm -f

CFLAGS	+= -Wall -Wextra -Werror

CPPFLAGS += -I./include

LDFLAGS =    $(CFLAGS)

SRCS    =	./asm/main.c			\
		./asm/parse_instruction.c	\
		./my_printf/my_puterror.c	\
		./asm/get_name.c		\
		./asm/init_parser_and_label.c	\
		./asm/get_addr.c		\
		./asm/my_getnbr.c		\
		./asm/my_strstr.c		\
		./asm/clear_file.c		\
		./asm/check_file.c		\
		./asm/write_instruction.c	\
		./asm/get_next_line.c		\
		./asm/parser.c			\
		./asm/tools.c			\
		./asm/init_header.c		\
		./asm/help.c			\
		./asm/label_exist.c		\
		./asm/my_str_to_wordtab.c 	\
		./asm/get_for_write.c		\
		./my_printf/my_putchar.c 	\
		./my_printf/my_strlen.c 	\
		./my_printf/my_printable.c 	\
		./my_printf/my_putstr.c 	\
		./my_printf/my_put_nbr.c 	\
		./my_printf/my_put_long.c 	\
		./my_printf/my_printf.c 	\
		./my_printf/my_base.c 		\
		./my_printf/my_put_pointers.c 	\
		./my_printf/my_put_unsigned.c

OBJS    =    $(SRCS:.c=.o)

LIBS	=    $(OBJS)

NAME    =    ./asm/asm

all:    $(NAME)

$(NAME):    $(OBJS)
	gcc -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:    fclean all

.PHONY: all clean fclean re
