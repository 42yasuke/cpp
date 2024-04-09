# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:41:32 by jralph            #+#    #+#              #
#    Updated: 2024/04/09 00:41:27 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -c -g

RM = rm -f

INC = -I includes/

CPP_FILES =	main.cpp BitcoinExchange.cpp

SRC = $(addprefix src/, $(CPP_FILES))

OBJ = $(SRC:.cpp=.o)

NAME = btc

all : $(NAME)

%.o : %.cpp
			$(CPP) $(CPP_FLAGS) -c $< $(INC) -o $@

$(NAME) : $(OBJ)
			$(CPP) $(OBJ) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re