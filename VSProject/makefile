
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o character.o CircularLinkedList.o board.o

SRCS = main.cpp menu.cpp inputValidation.cpp character.cpp CircularLinkedList.cpp board.cpp

HEADERS = menu.hpp inputValidation.hpp character.hpp CircularLinkedList.hpp board.hpp

#target: dependencies
#	rule to build
#

pokemon: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o pokemon

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
