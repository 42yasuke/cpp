# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:41:32 by jralph            #+#    #+#              #
#    Updated: 2024/04/08 12:07:21 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -c -g

RM = rm -f

INC = -I includes/

CPP_FILES =	main.cpp ScalarConverter.cpp

SRC = $(addprefix src/, $(CPP_FILES))

OBJ = $(SRC:.cpp=.o)

NAME = convert

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