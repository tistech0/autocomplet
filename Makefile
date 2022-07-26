##
## EPITECH PROJECT, 2022
## B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
## File description:
## Makefile
##

SRC		=	sources/main.cpp	\
			sources/adress.cpp	\
			sources/loadFile.cpp	\
			sources/gps.cpp	\
			sources/coreLoop.cpp	\
			sources/algoCityName.cpp	\
			sources/algoAdressName.cpp	\
			sources/firstPropal.cpp	\
			sources/formatString.cpp	\
			sources/utils.cpp	\
			sources/errorHandling.cpp

OBJ		=	$(SRC:%.cpp=%.o)

NAME	= 	autoCompletion

CXXFLAGS	= -I./includes -std=c++2a -Wall -Wextra -Werror

CXX	=	g++

LDFLAGS=

all: 		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

debug:	CXXFLAGS += -g
debug:	re

tests_run:		
				$(MAKE) -C tests/
				mv tests/unit_tests .
				./unit_tests

test_fclean:
				$(MAKE) -C tests/ fclean
				rm sources/*.gcno
				rm sources/*.gcda

test_re:
				$(MAKE) -C tests/ re
				mv tests/unit_tests .
				./unit_tests
				gcovr --exclude tests/ --exclude includes/exceptions/ --exclude-throw-branches --exclude-unreachable-branches