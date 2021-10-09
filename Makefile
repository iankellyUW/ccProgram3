# Makefile
# COSC 4785
# $Author: ikelly $
CXX=g++
CXXFLAGS=-ggdb -Wall -Wno-sign-compare
YACC=bison
YFLAGS=--report=state -W -d
LEX=flex
LEX=flex++
LFLAGS=--warn
SRC=program3.cpp program3.tab.cpp program3_lex.cpp nodes.cpp
HDRS=program3.tab.hpp nodes.hpp

.PHONY: clean tarball

program3: $(SRC) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRC) -o program3

program3.tab.cpp : program3.ypp nodes.hpp
	$(YACC) $(YFLAGS) program3.ypp

program3_lex.cpp: program3.lpp nodes.hpp
	$(LEX) $(LFLAGS) program3.lpp

tidy:
	/bin/rm -f a.out core.* program3.tab.* program3.output \
	  program3_lex.cpp program3

# the tidy rule cleans up but leaves the executable. The clean, uses tidy
# then it removes the executable. 
clean: tidy
	/bin/rm -f bison_test 

tarball:
	tar cf program3.tar Makefile nodes.hpp nodes.cpp program3.lpp program3.ypp\
	  program3.cpp input
