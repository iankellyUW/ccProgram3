# Makefile
# COSC 4785
# $Author: ikelly $

CXXFLAGS=-ggdb -Wall -Wno-sign-compare
CXX=g++ 
LEX=flex++
LEXFLAGS=--warn


program2: program3.cpp program3_lex.cpp
	$(CXX) $(CXXFLAGS) program3.cpp program3_lex.cpp -o program3

program2_lex.cpp: program3.lpp
	$(LEX) $(LEXFLAGS) program3.lpp

# 
# Probably do not need the core.* for students.
# This removes all the 'generated' files. You can always generate them again.
# Do need the -f so that all files get deleted even if some are missing.
#
clean: 
	/bin/rm -f program3 program3_lex.cpp core.* 
