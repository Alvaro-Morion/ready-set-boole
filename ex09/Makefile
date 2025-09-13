SRCS		=	evaluate_set.cpp main.cpp ../ex04/print_truth_table.cpp ../ex03/eval_formula.cpp ../ex05/negation_normal_form.cpp

INCL 		= rsb.h

OBJS		=	${SRCS:.cpp=.o}

NAME		=	set_eval

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror

%.o: %.cpp
				$(CC) $(CFLAGS) $< -c -o ${<:.cpp=.o}

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			
clean:
				rm -f ${OBJS} 

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
