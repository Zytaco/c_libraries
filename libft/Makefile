#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 12:38:38 by jheeresm      #+#    #+#                  #
#    Updated: 2019/10/31 12:38:39 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME =		libft.a

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -c

CHAR_FUNCTIONS	=	isalnum isalpha isascii isdigit isint isprint iswhitespace \
					tolower toupper

LIST-FUNCTIONS	=	lstadd lstaddend lstdel lstdelone lstiter lstmap lstnew

MATH-FUNCTIONS	=	abs count_digits modulo nroot power primes pythagoras sqrt

MEM-FUNCTIONS	= 	bzero memalloc memccpy memchr memcmp memcpy memdel memmove \
					memset

PUT-FUNCTIONS	=	putchar putchar_fd putendl putendl_fd putllnbr putnbr \
					putnbr_fd putstr putstr_fd putullnbr

STR-FUNCTIONS	=	strcat strchr strclr strcmp strcount strcpy strdel strdup \
					strequ striter striteri strjoin strlcat strlen strmap \
					strmapi strncat strncmp strncpy strnequ strnew strnstr \
					strrchr strsplit strstr strsub strtoupper strtrim

MISC-FUNCTIONS	=	atoi error free_array get_next_line itoa itoabase \
					lstaddlast lstlen power_of

SOURCES			=	$(CHAR_FUNCTIONS:%=srcs/char-functions/ft_%) \
					$(LIST_FUNCTIONS:%=srcs/list-functions/ft_%) \
					$(MATH_FUNCTIONS:%=srcs/math-functions/ft_%) \
					$(MEM_FUNCTIONS:%=srcs/mem-functions/ft_%) \
					$(PUT_FUNCTIONS:%=srcs/put-functions/ft_%) \
					$(STR_FUNCTIONS:%=srcs/str-functions/ft_%) \
					$(MISC_FUNCTIONS:%=srcs/misc-functions/ft_%)

CFILE =		$(SOURCES:%=%.c)

OBJECTS =	$(SOURCES:%=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@ ar rc $(NAME) $(OBJECTS)
		@ ranlib $(NAME)
		@ echo "\033[36mLIBFT LIBRARY COMPILED\033[0m"

%.o: %.c
		@ $(CC) $(CFLAGS) $< -o $@

clean:
		@ rm -f $(OBJECTS)
		@ echo "\033[33mCLEAN COMPLETED\033[0m"

fclean:
		@ rm -f $(NAME)
		@ rm -f $(OBJECTS)
		@ echo "\033[91mFULL CLEAN COMPLETED\033[0m"

re:	 fclean all
