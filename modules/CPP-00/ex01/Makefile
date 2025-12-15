# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 12:11:21 by gpico-co          #+#    #+#              #
#    Updated: 2025/12/10 12:11:22 by gpico-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-    COLOURS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR   = \033[0;39m
YELLOW      = \033[0;93m
CYAN        = \033[0;96m
GREEN       = \033[0;92m
BLUE        = \033[0;94m
RED         = \033[0;91m

# -=-=-=-=-    NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

NAME        := phonebook

# -=-=-=-=-    FLAG -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

CPP          = c++
FLAGS       = -Werror -Wall -Wextra -std=c++98

# -=-=-=-=-    PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RM          = rm -fr

# -=-=-=-=-    FILES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC         := main.cpp	\
				PhoneBook.cpp	\
				Contact.cpp

OBJS		= $(SRC:.cpp=.o)

# -=-=-=-=-    TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: $(NAME)

%.o: %.cpp Makefile
	$(CPP) $(FLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)!$(DEF_COLOR)"
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

clean:
	@$(RM) $(OBJS) 
	@echo "$(RED)Cleaned object files$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re