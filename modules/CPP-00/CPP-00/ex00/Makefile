# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 13:44:24 by gpico-co          #+#    #+#              #
#    Updated: 2025/06/19 16:04:42 by gpico-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone
CPP = c++
FLAGS = -Werror -Wall -Wextra -std=c++98 -pedantic
RM = rm -fr

SRC := megaphone.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp Makefile
		$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re