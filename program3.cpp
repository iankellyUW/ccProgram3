//   program1.cpp
//   Ian Kelly
//   COSC 4785  Fall 2021
//   Program  01
//   August 26, 2021
#include <iostream>
#include <iomanip>
#include <string>
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

int main()
{

    FlexLexer *myScanner = new yyFlexLexer();
    int rtn;

    cout << "Line"
         << "\t"
         << "Column"
         << "\t"
         << "Token"
         << "\t"
         << "Value" << endl;

    //   any   n e e d e d   i n i t i a l i z a t i o n   c o d e
    while ((rtn = myScanner->yylex()) != 0)
    {
        //   l o o p   c o d e   g o e s   h e r e

        if (!TOKEN.compare("ER_CH") || !TOKEN.compare("ER_WD"))
        {
            errorCount++;
            if (errorCount > 20)
            {
                cout << "ERRORS";
                return 0;
            }
        }

        cout << myScanner->lineno() << "\t" << first_column << "\t" << TOKEN << "\t" << value << endl;
        TOKEN = "";
        value = "";
    }
    // more   c o d e   i f   n e e d e d
    return 0;
}