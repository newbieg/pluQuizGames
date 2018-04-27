/* This is the text user Interface version for the PLU quiz game.
 * In the GUI version there will generally be some type of game interface,
 * here, it's going to be more of a flash-card type quiz.
 * It will sellect some random PLUs, expect you to type the number in,
 * give hints if they are typed wrong, and give you a rank based on
 * how well you did. All games should generally follow this type of form
 * if you really wish the user to memorize PLU's, though I hope to add
 * a level-based system so that the user is first exposed to some of the
 * most basic PLUs, then gradually introduced to tougher ones while still 
 * getting review ones...
 * */
#include <iostream>
#include "plu.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int PLUCOUNT = 5;
const int QUIZLOOPS = 4;

void handleWrongAnswer(string answer, string list[], int &index, int & hintsize, plu data);
string getRank(double value);


void help(char* programName);

void processTerminalInput(int argCount, char** args);



int main(int argc, char **argv)
{
	
	processTerminalInput(argc, argv);

	srand(time(NULL));

	plu bob("pluNums1.txt");
	int index = rand()%bob.listSize();

	string plulist[PLUCOUNT + 1];
	string products[PLUCOUNT + 1];
	string answer;

	for(int i = 0; i <= PLUCOUNT; i ++)
	{
		plulist[i] = bob.getPLU(bob.getLinePLU(index));
		products[i] = bob.getProduct(bob.getLinePLU(index));
		index = rand()%bob.listSize();
	}

	double score = 0.0;
	for(int m = 0; m < QUIZLOOPS; m ++)
	{
		int hintsize = 0;
		for(int i = 1; i <= PLUCOUNT; i ++)
		{
			cout << products[i] << ": ";
			cin >> answer; 
			if(answer == plulist[i])
			//if(hintsize == 0) // pretend all answers are correct (Debug)
			{
				cout << "correct!\n";
				score += ((1.0/((double) PLUCOUNT)) - ((double)hintsize)/(4.0 *(double) PLUCOUNT))/4.0;
				hintsize = 0;
			}
			else
			{
				handleWrongAnswer(answer, plulist, i, hintsize, bob);	
			}
		}
	}
	cout <<"\nYou got a score of: " << (score * 100) << "%\n";
	string rank = getRank(score);
	cout << "RANK: " << rank << endl;

	return 0;
}


void help(char* programName)
{
	cout << "This program is made as a proof of concept.\nI used it myself to help memorize PLU codes to get better as a grocery checker.\nTo use this program, simply enter " << programName << " into your terminal and start playing the quiz.\n";
	cout << "I have added difficulty settings, use -d 1-3 to set the dificulty as shown below:\n\t" << programName << " -d 3\nWhich would set it to maximum dificulty.\n\n";

}



void processTerminalInput(int argCount, char** args)
{
	// a loop is currently overkill here, 
	// but I think there's likely to be more options 
	// as tui is developed...
	for(int i = 1; i < argCount; i ++)
	{
		if(!(strcmp(args[i], "-d")))
		{
			if(i+1 < argCount)
			{
				i ++;
				if(!(strcmp(args[i], "2")))
				{
					PLUCOUNT = 10;		
				}
				if(!(strcmp(args[i], "3")))
				{
					PLUCOUNT = 20;		
				}
			}
			else
			{
				help(args[0]);
				exit(0);
			}
		}
		else
		{
			help(args[0]);
			exit(0);
		}
	}
}








void handleWrongAnswer(string answer, string list[], int &index, int & hintsize, plu data)
{
	if(hintsize < 4)
	{
		int dontCare = 0;
		if(answer.length() > 3)
		{
			cout << "Nope! That was "<< data.getProduct(data.getLinePLU(answer, dontCare)) << " try Again.\n Hint: ";
		}
		else
		{
			cout << "Nope!\n Hint: ";
		}
		hintsize++;
		for(int j = 0; j < hintsize; j ++)
		{
			cout << list[index][j];
		}
		cout << endl;
		index --;
	}
	else 
	{
		hintsize = 0;
		cout << "\nSorry, next product.\n";
	}

}







string getRank(double value)
{
	if(value <= 0.0)
	{
		return "Comedian";
	}
	else if(value < 0.10)
	{
		return "NPC";
	}
	else if(value < 0.2)
	{
		return "Slow Zombie";
	}
	else if(value < 0.3)
	{
		return "Squirell Tamer";
	}
	else if(value < 0.35)
	{
		return "Goblin Zen Guru";
	}
	else if(value < 0.4)
	{
		return "Rookie";
	}
	else if(value < 0.6)
	{
		return "Squire";
	}
	else if(value < .63)
	{
		return "Band Manager";
	}
	else if(value < 0.67)
	{
		return "Barbarian Accountant";
	}
	else if(value < 0.7)
	{
		return "Knight in Training";
	}
	else if(value < 0.8)
	{
		return "Knight After";
	}
	else if(value < 0.9)
	{
		return "Expert Swordsman";
	}
	else if(value < 0.95)
	{
		return "Wizard";
	}
	else if(value <= 1.01)
	{
		return "Legend";
	}
	else
		return "OOPS";
	
}
