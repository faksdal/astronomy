#
#
#	Makefile
#	
#	target: prerequisites prerequisites ...
#		<tab>command
#		<tab>command
#
#	$@	=	target name
#	$?	=	all prerequisites newer than target
#	$<	=	first prerequisites
#	$^	=	all prerequisites
#
#	The @ in front of the echo command, prevents the actual command from being printed to screen
#
#	$(patsubst PATTERN,REPLACEMENT,TEXT)
####################################################################################################
TARGET = jdn
CXX = g++
CPPFLAGS = -I. -I./inc -g -Wall
INCDIR = inc
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard *.cpp $(SRCDIR)/*.cpp) # $(INCDIR)/*.h)
OBJFILES = $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

all: $(OBJFILES)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJFILES)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp	
	$(CXX) $(CPPFLAGS) -c -o $@ $^

obj/main.o: main.cpp
	#@echo $(SOURCES)
	#@echo $(OBJFILES)
	$(CXX) $(CPPFLAGS) -c -o obj/main.o main.cpp

clean:
	rm $(TARGET) $(OBJDIR)/*