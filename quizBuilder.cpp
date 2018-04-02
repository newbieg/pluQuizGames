#include "plu.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void help(char** mainInput)
{
	cout << "Call this program by:\n";
	cout << mainInput[0] << " -f MainPLUFile -s searchString(including_plu#) -0 quizFile\n";
	cout << mainInput[0] << " MainPLUFile searchString searchString quizFile\n";

	cout << "These quizFiles can then be used to dope a quiz with more relevent PLU's, or to make the quiz solely of those PLU's that you want to focus on.\n";
}


int main(int argc, char ** argv)
{
	help(argv);
}
