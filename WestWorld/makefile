#------------------------------------------------------------------------
#
#  Author:  Jérémy Bois
#
#  Desc:   Makefile to compile and link source
#
#------------------------------------------------------------------------


# ------------------------------------------------------------------------------
# MACROS
# ------------------------------------------------------------------------------
# Define macro which can be used later.
CC = g++
# Flags to use when compiling.
CFLAGS= -O -Wall -W -ansi -pedantic -std=c++11 -c
# Files to compile (*.cpp).
SOURCES= BaseGameEntity.cpp MinerStates.cpp Miner.cpp main.cpp
# Define objects as source with .o in place of .cpp
OBJECTS=$(SOURCES:.cpp=.o)
# Final executable name.
OUT_EXE = WestWorld


# ------------------------------------------------------------------------------
# ACTIONS
# ------------------------------------------------------------------------------
# Combining make syntax to write an expandable script.
all: $(SOURCES) $(OUT_EXE)

$(OUT_EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Change *.cpp to *.o to mark them as object.
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# `-` sign used to ignore status (usefull when no files to delete)
clean:
	-rm -f *.o core

# Clean all (object and executable)
purge:
	-rm -f *.o core $(OUT_EXE)

# Target can be a combinaison of other target
rebuild: purge all
