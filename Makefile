MAKEFLAGS += --no-builtin-rules --no-builtin-variables


CC := g++
LD := $(CC)


CURDIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))


PROG := main
MAIN := $(PROG).cpp
OBJ := $(patsubst %.cpp, %.o, $(MAIN))


EXTENSIONSSRCS := VEGAS_map.cpp VEGAS_Stratify.cpp Bin.cpp\
				  VEGAS_Integrator.cpp VEGAS.cpp
EXTENSIONSOBJS := $(patsubst %.cpp, %.o, $(EXTENSIONSSRCS))


#c++20 standard is optional
#CCFLAGS := -std=c++20
#LDFLAGS := -std=c++20


RM := rm -rf $(PROG) $(OBJ) $(EXTENSIONSOBJS)


.PHONY: all clean


all: $(PROG)


$(PROG): $(OBJ) $(EXTENSIONSOBJS)
	$(LD) -o $@ $^ $(LDFLAGS)


$(OBJ): %.o: %.cpp
	$(CC) -c $< $(CCFLAGS)


$(EXTENSIONSOBJS): %.o:%.cpp
	$(CC) -c $< $(CCFLAGS)


$(OBJ): $(EXTENSIONSOBJS)


$(EXTENSIONSOBJS): %.o:%.h


VEGAS_Integrator.o: VEGAS_map.o VEGAS_Stratify.o Bin.o


VEGAS.o: VEGAS_Integrator.o Bin.o


$(EXTENSIONSOBJS): $(MAKEFILE_LIST)


clean:
	$(RM)
