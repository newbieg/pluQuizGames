#ifndef PLUNUMBEROBJECTDEFINED
#define  PLUNUMBEROBJECTDEFINED

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


class plu 
{
	public:
		plu();
		plu(std::string fileName);

		// Get the full line by searching its contents
		std::string getLinePLU(std::string descriptor, int &start);

		// Get the full line by index
		std::string getLinePLU(int index);

		// Return the product name associated with a PLU
		std::string getProduct(int number);
		
		
		// pull the product name from the input string
		std::string getProduct(std::string fromInput);


		// return the PLU associated with a Product name
		std::string getPLU(std::string product);


		// print whole listing of available PLU's
		void printList();

		int listSize();

	private:
		void readFile(std::string fileName);
		std::vector <std::string> book;

};



#endif
