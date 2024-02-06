# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 03:12:56 by jose              #+#    #+#              #
#    Updated: 2024/02/06 03:13:22 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -c -g

RM = rm -f

INC = -I includes/

CPP_FILES =	main.cpp

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

NAME = exec

all : $(NAME)

%.o : %.cpp
			$(CPP) $(CPP_FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
			$(CPP) $(OBJ) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re