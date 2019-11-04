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

LIBS = libft

all: $(LIBS)

$(LIBS):
	make -C 

clean:

fclean:

re:	 fclean all
