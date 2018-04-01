#include "plu.h"

using namespace std;

plu::plu()
{
	readFile("pluNums1.txt");
}

plu::plu(string filename)
{
	readFile(filename);
}

string plu::getLinePLU(string number, int & start)
{
	for(int i = start; i < book.size(); i ++)
	{
		if(book[i].find(number) != string::npos)
		{
			start = i;
			return book[i];
		}

	}
	return "Not found";
}

string plu::getLinePLU(int index)
{
	if(index < book.size())
	{
		return book[index];
	}
	return "Not found";
}

string plu::getProduct(int num)
{
	string number;
	stringstream ss;
	ss << num;
	string ch;
	while(ss >> ch);
	{
		number += ch;
	}

	string temp;
	int skipper = 0;
	temp = getLinePLU(number, skipper);
	int start = temp.find("'");
	start ++;
	int size = start;
	size = temp.find("'", size);
	size = size - start;

	return temp.substr(start, size);

}


string plu::getProduct(string fromLine)
{
	string temp = fromLine;
	int start = temp.find("'");
	start ++;
	int size = start;
	size = temp.find("'", size);
	size = size - start;

	return temp.substr(start, size);
	
}

string plu::getPLU(string product)
{
	string pluLine = product;
	string temp;
	string skipper = "'";
	int start = 0;
	start = pluLine.find(skipper);
	start = pluLine.find(skipper, start+1);
	start += 2;

	bool foundNum = false;
	bool goOn = true;
	for(int i = start; i < pluLine.size() && goOn; i ++)
	{
		if(pluLine[i] >= '0' && pluLine[i] <= '9')
		{
			foundNum = true;
			temp += pluLine[i];
		}
		else if(foundNum) // the number has ended
		{
			goOn = false;
		}
		
	}
	return temp;

}

void plu::readFile(string fileName)
{
	ifstream inFile(fileName.c_str());
	stringstream ss;
	if(inFile.good())
	{
		ss << inFile.rdbuf();
		string temp;
		while(getline(ss, temp))
		{
			if(temp[0] != '#' && temp.size() > 5)
			{
				book.push_back(temp);
			}
		}
	}
	else
	{
		cout << "could not read file." << fileName << endl;
	}
	
}

void plu::printList()
{
	for(int i = 0; i < book.size(); i ++)
	{
		cout << book[i] << endl;
	}

}


int plu::listSize()
{
	return book.size();
}
