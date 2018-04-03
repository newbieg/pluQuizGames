#include "plu.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void help(char** mainInput)
{
	cout << "Call this program by:\n";
	
	cout << mainInput[0] << " -f MainPLUFile -s searchString(including_plu#) -o quizFile\n";
	cout << mainInput[0] << " -h; to display help\n";

	cout << "These quizFiles can then be used to dope a quiz with more relevent PLU's, or to make the quiz solely of those PLU's that you want to focus on.\n";
}



int main(int argc, char ** argv)
{
	string fileName = "output.q";
	plu bob;
	plu telly;
	bool searchesMade = false;
	if(argc < 3)
	{
		help(argv);
	}
	// Process the inputs
	for(int i = 1; i < argc; i ++)
	{
		if(! (strcmp(argv[i], "-f")))
		{
			if(!(bob.readFile(argv[i+1])))
			{
				exit(1);
			}
			i ++;
		}
		else if(! (strcmp(argv[i], "-h")))
		{
			help(argv);
			exit(0);
		}
		else if(! (strcmp(argv[i], "-s")))
		{
			searchesMade = true;
			int start = 0;
			string temp = bob.getLinePLU((string) argv[i+1], start);

			while(start >= 0)
			{
				if(temp != "Not found")
				{
					telly.addPLU(temp);
				}
				temp = bob.getLinePLU((string)argv[i+1], start);
				cout << temp;
				cout << "adding PLUs " << argv[i+1];
			}
			i ++;
		}
		else if(! (strcmp(argv[i], "-o")))
		{
			fileName = argv[i + 1];
			i ++;
		}
		else
		{
			cout << argv[i];
			cout << "Bad Inputs, use -h\n";
		}
	}

	if(! searchesMade)
	{
		telly = bob;
	}
	if(telly.listSize() < 2)
	{
		cout << "\nNot enough PLU's Loaded... \n";
		return 0;
	}
	else
	{
		ofstream outFile(fileName.c_str());
		int index = 0;
		string temp =  telly.getLinePLU(index);
		while(outFile.good() && index < telly.listSize())
		{
			temp = telly.getLinePLU(index);
			outFile << temp;
			outFile << '\n';
			index ++;
		}
		outFile.close();

	}


}
