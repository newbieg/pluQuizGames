#include <iostream>
#include "plu.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

void handleWrongAnswer(string answer, string list[], int &index, int & hintsize, plu data);


int main()
{
	srand(time(NULL));

	plu bob;
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
