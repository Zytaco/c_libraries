#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/08 11:25:51 by jheeresm      #+#    #+#                  #
#    Updated: 2019/11/08 11:25:52 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME =		libftsort.a

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -c


SOURCES			=	sort_cpy_array\
					sort_divide_into_parts\
					sort_divide_into_size\
					sort_dup_array\
					sort_free_array\
					sort_insert_sort\
					sort_join_arrays\
					sort_make_sub_array\
					sort_merge_order\
					sort_move\
					sort_new_array\
					sort_shuffle_sort


CFILE =		$(SOURCES:%=%.c)

OBJECTS =	$(SOURCES:%=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@ ar rc $(NAME) $(OBJECTS)
		@ ranlib $(NAME)
		@ echo "\033[36mLIBSORT: COMPILED\033[0m"

%.o: %.c
		@ $(CC) $(CFLAGS) $< -o $@

clean:
		@ rm -f $(OBJECTS)
		@ echo "\033[33mLIBSORT: CLEANED\033[0m"

fclean:
		@ rm -f $(NAME)
		@ rm -f $(OBJECTS)
		@ echo "\033[91mLIBSORT: FULL CLEANED\033[0m"

re:	 fclean all
