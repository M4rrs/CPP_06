# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 14:24:47 by nnorazma          #+#    #+#              #
#    Updated: 2023/07/14 14:24:49 by nnorazma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Base

CC = c++
FLAGS = -Wall -Werror -Wextra -I -fsanitize=address

RM = rm -rf

SRCS = Base.cpp main.cpp
INC = Base.hpp

OBJS = ${SRCS:%.cpp=%.o}

%.o: %.cpp ${INC}
		@printf "\033[38;5;121mCompiling $<...\033[0m\r"
		@${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
		@echo "\n\033[38;5;204mBase.\033[0m"
		@${CC} ${FLAGS} ${OBJS} -o $@

clean:
		@echo "\033[38;5;227mRemoving Objects\033[0m"
		@${RM} ${OBJS}

fclean:	clean
		@echo "\033[38;5;81mRemoving Executable\033[0m"
		@${RM} ${NAME}

re: fclean all