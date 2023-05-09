include ./build/vars.mk

CXX=g++
CXXFLAGS=-Wall -Wextra -Wshadow -Wpointer-arith -Wuninitialized -Winit-self -Wunreachable-code -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR ?= ./src
OUTDIR ?= ./build
OBJDIR ?= $(OUTDIR)/objects


$(OUTDIR)/main.exe: $(OBJDIR)/main.o
	$(CXX) $^ -o $@ -L$(SFMLDIR)/lib $(CXXFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	mkdir -p $(OUTDIR)
	mkdir -p $(OBJDIR)
	$(CXX) -c $^ -I$(SFMLDIR)/include $(CXXFLAGS) -o $@ 

clean:
	rm -rf $(OUTDIR)

