CXX		  := g++
CXX_TEST  := g++

CXX_LIB_FLAGS := -shared -fPIC -Iinclude -Wall -Wextra -std=c++17
CXX_TEST_FLAGS:= -Wall -Wextra -std=c++17

BINDIR		:= bin
SRCDIR		:= src
INCLUDEDIR	:= include
LIBDIR	    := lib
TESTDIR     :=testsrc

BINDIR_TEST:=$(TESTDIR)
SRCDIR_TEST:=$(TESTDIR)
INCLUDEDIR_TEST:=$(TESTDIR)

BINARIES  := clieditor
LIBRARIES := 
all:  $(BINDIR)/$(BINARIES)

run: clean all
	clear
	./$(BINDIR)/$(BINARIES)

$(BINDIR)/$(BINARIES): $(SRCDIR)/*.cpp
	$(CXX_TEST) $(CXX_TEST_FLAGS) -I./$(INCLUDEDIR) $^ -o $(BINDIR)/$(BINARIES) -L$(LIBDIR)

clean:
	-rm $(BINDIR)/*
