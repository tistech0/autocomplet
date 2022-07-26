##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC     =	test_errorHandling.cpp	\
			test_gps.cpp	\
			test_algo.cpp	\
			test_static.cpp	\
			../sources/adress.cpp	\
			../sources/loadFile.cpp	\
			../sources/gps.cpp	\
			../sources/coreLoop.cpp	\
			../sources/firstPropal.cpp	\
			../sources/formatString.cpp	\
			../sources/utils.cpp	\
			../sources/errorHandling.cpp

OBJ     =	$(SRC:.cpp=.o)

NAME    =	unit_tests

LDFLAGS	=

TESTFLAGS	=	-lcriterion

CXXFLAGS	=	-Wall -Wextra -Wshadow -I ../includes -I ../sources --coverage

CXX	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(TESTFLAGS) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)
	rm *.gcno
	rm *.gcda

re:	fclean  all