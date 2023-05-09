include ./build/vars.mk

CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -Wpointer-arith -Wuninitialized -Winit-self -Wunreachable-code -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR ?= ./src
OUTDIR ?= ./build
OBJDIR ?= $(OUTDIR)/objects

SRCFILES := $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
HEADERFILES := $(wildcard $(SRCDIR)/**/*.h) $(wildcard $(SRCDIR)/*.h)

# firulinha
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

$(OUTDIR)/main.exe: $(OBJFILES) $(HEADERFILES)
	@$(call run_and_test,$(CXX) $(OBJFILES) -o $@ -L$(SFMLDIR)/lib $(CXXFLAGS))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(call run_and_test,$(CXX) -c $< -I$(SFMLDIR)/include $(CXXFLAGS) -o $@)

clean:
	@printf "$(COM_COLOR)Removing $(OBJ_COLOR)$(OUTDIR)$(NO_COLOR)\n"
	@rm -rf $(OUTDIR)

