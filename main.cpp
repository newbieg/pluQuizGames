#include <iostream>
#include "plu.h"
#include <time.h>
#include <stdlib.h>

using namespace std;


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
				if(hintsize < 4)
				{
					int dontCare = 0;
					cout << "Nope! That was "<< bob.getProduct(bob.getLinePLU(answer, dontCare)) << " try Again.\n Hint: ";
					hintsize++;
					for(int j = 0; j < hintsize; j ++)
					{
						cout << plulist[i][j];
					
					}
					cout << endl;
					i --;
				}
				else 
				{
					hintsize = 0;
					cout << "\nSorry, next product.\n";
				}
	
			}
		}
	}
	cout <<"\nYou got a score of: " << (score * 100) << "%\n";
	return 0;
}
