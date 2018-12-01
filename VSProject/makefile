
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o character.o board.o circularLinkedList.o backpack.o

SRCS = main.cpp menu.cpp inputValidation.cpp character.cpp board.cpp circularLinkedList.cpp backpack.cpp

HEADERS = menu.hpp inputValidation.hpp character.hpp board.hpp circularLinkedList.hpp backpack.hpp

#target: dependencies
#	rule to build
#

kitty: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o kitty

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
