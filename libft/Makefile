#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 12:38:38 by jheeresm      #+#    #+#                  #
#    Updated: 2019/12/16 15:50:50 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME =		libft.a

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -c

CHAR-FUNCTIONS	=	isalnum isalpha isascii isdigit isint isprint iswhitespace \
					tolower toupper

LIST-FUNCTIONS	=	lstadd lstaddend lstaddend lstdel lstdelone lstiter lstmap \
					lstnew

MATH-FUNCTIONS	=	abs count_digits modulo nroot power primes pythagoras sqrt\
					max min bcd lcm

MEM-FUNCTIONS	= 	bzero memalloc memccpy memchr memcmp memcpy memdel memmove \
					memset

PUT-FUNCTIONS	=	putbase_fd putbase	putchar_fd	putchar	putendl_fd\
					putendl	putllbase_fd	putllnbr_fd	putllnbr	putnbr_fd\
					putnbr	putstr_fd	putstr	putullbase_fd	putullnbr_fd\
					putullnbr

STR-FUNCTIONS	=	skip_whitespace stradd skipstr\
					strcat strchr strclr strcmp strcount strcpy strdel strdup \
					strequ striter striteri strjoin strlcat strlen strmap \
					strmapi strncat strncmp strncpy strnequ strnew strnstr \
					strrchr strsplit strstr strsub strtoupper strtrim strrepeat

MISC-FUNCTIONS	=	atoi atoullbase error free_array get_next_line itoa \
					itoabase lltoabase lstlen ulltoabase

SOURCES			=	$(CHAR-FUNCTIONS:%=srcs/char-functions/ft_%) \
					$(LIST-FUNCTIONS:%=srcs/list-functions/ft_%) \
					$(MATH-FUNCTIONS:%=srcs/math-functions/ft_%) \
					$(MEM-FUNCTIONS:%=srcs/mem-functions/ft_%) \
					$(PUT-FUNCTIONS:%=srcs/put-functions/ft_%) \
					$(STR-FUNCTIONS:%=srcs/str-functions/ft_%) \
					$(MISC-FUNCTIONS:%=srcs/misc-functions/ft_%)

CFILE =		$(SOURCES:%=%.c)

OBJECTS =	$(SOURCES:%=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@ ar rc $(NAME) $(OBJECTS)
		@ ranlib $(NAME)
		@ echo "\033[36mLIBFT: COMPILED\033[0m"

%.o: %.c
		@ $(CC) $(CFLAGS) $< -o $@

clean:
		@ rm -f $(OBJECTS)
		@ echo "\033[33mLIBFT: CLEANED\033[0m"

fclean:
		@ rm -f $(NAME)
		@ rm -f $(OBJECTS)
		@ echo "\033[91mLIBFT: FULL CLEANED\033[0m"

re:	 fclean all
