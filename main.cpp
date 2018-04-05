#include <iostream>
#include "plu.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

void handleWrongAnswer(string answer, string list[], int &index, int & hintsize, plu data);
string getRank(double value);


int main()
{
	srand(time(NULL));

	plu bob("pluNums1.txt");
	int index = rand()%bob.listSize();


	string plulist[11];
	string products[11];
	string answer;

	for(int i = 0; i < 10; i ++)
	{
		plulist[i] = bob.getPLU(bob.getLinePLU(index));
		products[i] = bob.getProduct(bob.getLinePLU(index));
		index = rand()%bob.listSize();
	}

	double score = 0.0;
	for(int m = 0; m < 4; m ++)
	{
		int hintsize = 0;
		for(int i = 1; i < 10; i ++)
		{
			cout << products[i] << ": ";
			cin >> answer; 
			if(answer == plulist[i])
			{
				cout << "correct!\n";
				score += (.1 - .03 * hintsize)/4;
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
		return "Squirell Trainer";
	}
	else if(value < 0.35)
	{
		return "Goblin Zen Guru";
	}
	else if(value < 0.4)
	{
		return "Rookie Nose-Picker";
	}
	else if(value < 0.6)
	{
		return "Squire";
	}
	else if(value < .65)
	{
		return "Band Manager";
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
	else if(value < 1)
	{
		return "Legend";
	}
	
}
