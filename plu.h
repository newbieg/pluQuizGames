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

		// Add a file to your PLU list,
		// Does not check for repeated PLU numbers.
		bool readFile(std::string fileName);


		// Add a PLU as you might see it in
		// the accompanying file 'pluNums1.txt'
		// PLUString == 'Product description',PLU#
		void addPLU(std::string PLUString);

		// Get the full line by searching its contents
		// Returns the string "Not found" if the descriptor is not
		// pressent in any plu.
		std::string getLinePLU(std::string descriptor, int &start);

		// Get the full line by unsorted index (just however it
		// was added into the plu obj
		std::string getLinePLU(int index);

		// Return the product name associated with a PLU
		std::string getProduct(int number);
		
		
		// pull the product name from the input string
		std::string getProduct(std::string fromInput);


		// return the PLU associated with a Product name
		std::string getPLU(std::string product);


		// print whole listing of available PLU's
		void printList();

		// return the number of lines are in the PLU list.
		int listSize();

	private:
		std::vector <std::string> book;

};



#endif
