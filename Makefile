# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 11:57:56 by ktashbae          #+#    #+#              #
#    Updated: 2022/09/02 18:01:01 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	src

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	microshell
SRC		=	microshell.c execution.c parser.c signals_simple.c
OBJ		=	$(addprefix obj/,$(notdir $(SRC:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ -lreadline
	@echo "microshell is complied"

obj/%.o : %.c obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
