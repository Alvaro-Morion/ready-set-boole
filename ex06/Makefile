SRCS		=	../ex03/eval_formula.cpp\
				../ex04/print_truth_table.cpp\
				../ex05/negation_normal_form.cpp\
				conjuntive_normal_form.cpp\
				main.cpp

INCL 		= rsb.h

OBJS		=	${SRCS:.cpp=.o}

NAME		=	cnf

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