//   program3.cpp
//   Ian Kelly
//   COSC 4785  Fall 2021
//   Program  03
//   October 9, 2021
#include <iostream>
#include <iomanip>
#include <string>
#include "nodes.hpp"
#include "program3.tab.hpp"
#include <FlexLexer.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string TOKEN;
string value;
int first_column = 1;
int next_column = 1;
int errorCount = 0;

yyFlexLexer scanner;
Node *tree;

int main()
{
    tree = 0;
    //   any   n e e d e d   i n i t i a l i z a t i o n   c o d e
    yyparse();
    tree->print(&cout);
    cout << endl;
    // more   c o d e   i f   n e e d e d
    return 0;
}