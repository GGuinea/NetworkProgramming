
all: client

clean:
	 rm -rf *.o client


CC = $(CXX)
CXXFLAGS = -std=c++14
CXXFLAGS += -Wall -Wextra -pedantic