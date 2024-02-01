# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 12:57:29 by jose              #+#    #+#              #
#    Updated: 2024/02/01 09:26:29 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -c -g

RM = rm -f

INC = -I includes/

CPP_FILES =	main.cpp Contact.cpp PhoneBook.cpp

SRC = $(addprefix src/, $(CPP_FILES))

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

all : $(NAME)

%.o : %.cpp
			$(CPP) $(CPP_FLAGS) -c $(INC) $< -o $@

$(NAME) : $(OBJ)
			$(CPP) $(OBJ) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re