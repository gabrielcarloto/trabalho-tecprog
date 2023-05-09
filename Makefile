include ./build/vars.mk

CXX=g++
CXXFLAGS=-Wall -Wextra -Wshadow -Wpointer-arith -Wuninitialized -Winit-self -Wunreachable-code -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR ?= ./src
OUTDIR ?= ./build
OBJDIR ?= $(OUTDIR)/objects

SRCFILES := $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
HEADERFILES := $(wildcard $(SRCDIR)/**/*.h) $(wildcard $(SRCDIR)/*.h)

$(OUTDIR)/main.exe: $(OBJFILES) $(HEADERFILES)
	$(CXX) $(OBJFILES) -o $@ -L$(SFMLDIR)/lib $(CXXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $< -I$(SFMLDIR)/include $(CXXFLAGS) -o $@

clean:
	rm -rf $(OUTDIR)

