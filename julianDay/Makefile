# -------------------------------------------------------
# Makefile to build whatever you want.
# It tries to find all the sources you have and builds
# dependencies, to detect header file changes.
# This is especially helpful for C/C++ beginners,
# who don't want to edit a Makefile.
# https://gist.github.com/2552967
# Written by David Halter <davidhalter88@gmail.com>
# -------------------------------------------------------
CC=g++
CFLAGS=-c -O2 -Wall -I. -I src
SRC_DIR = src
BUILD_DIR = obj
LDFLAGS=
SOURCES=$(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/*.c $(SRC_DIR)/*.cpp)
# oh, how I hate make files!
HEADER_FILES_old1=$(patsubst %.cc, %.h, $(SOURCES))
HEADER_FILES_old2=$(patsubst %.cpp, %.h, $(HEADER_FILES_old1))
HEADER_FILES=$(patsubst %.c, %.h, $(HEADER_FILES_old2))
OBJECTS=$(patsubst $(SRC_DIR)/%.h,$(BUILD_DIR)/%.o,$(HEADER_FILES))
EXECUTABLE=sp

DEPENDENCIES=$(patsubst %.o, %.d, $(OBJECTS))

all: $(SOURCES) $(EXECUTABLE)

#	Linking
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) obj/main.o $(LDFLAGS) -o $@

obj/main.o: main.cpp
	$(CC) -MMD -MP $(CFLAGS) $< -o $@


# The -MP adds a 'phony' target for all prerequisite headers
# to stop 'make' complaining if you remove a header
# MMD generate dependency files
# The odd-looking 'sed' line makes the .d file itself 
# depend on relevant source and headers
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.*
	$(CC) -MMD -MP $(CFLAGS) $< -o $@
	@sed -i -e '1s,\($*\)\.o[ :]*,\1.o $(BUILD_DIR)/$*.d: ,' $(BUILD_DIR)/$*.d

# The include stops 'make' complaining if any .d files 
# are not found (eg. on initial build).
-include $(DEPENDENCIES)

clean:
	rm $(BUILD_DIR)/*
