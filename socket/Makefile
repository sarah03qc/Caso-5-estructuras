
CXX = g++
CFLAGS = -Wall -Werror

INCLUDE = -I/usr/local/include 
LDFLAGS = -L/usr/local/lib 
LDLIBS = -lcurl 

SOURCES = socket/contenful.cpp
OUT = test

all: comm_progs, build

comm_progs:
	g++ -o contenful.o contenful.cpp -lcurl

build:
	$(CXX) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SOURCES)



# docker run -it --rm -v C:\dev\cursostec\estructuras:/home gcc bash
# apt update -y
# app install curl