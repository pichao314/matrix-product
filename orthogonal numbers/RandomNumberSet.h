#ifndef RANDOMNUMBERSET_H
#define RANDOMNUMBERSET_H

#include <iostream>
#include <bitset>

using namespace std;

//No number would be replicated
class RandomNumberSet
{
public:
	//Default constructor 
	RandomNumberSet();

	//The non-default constructor would take the range
	RandomNumberSet(int range);

	//Destructor
	virtual ~RandomNumberSet();

	//clears all the number stored
	void reset();

	//test the bit if existed
	bool test(int i);

	// If number i is not in the set, stored by setting the corresponding bit in the bit set and return true, else return false
	bool set(int i);

	// returns numbers of numbers stored
	int size();

	//Overload operator << so that the numbers can be printed out aligned to the right and in 3 spaces
	friend ostream& operator << (ostream& outs, RandomNumberSet& rns);

	//overload the operator - to show the difference between two RandomNumberSets can be determined in O(1)
	friend int operator - (RandomNumberSet& r1, RandomNumberSet& r2);

private:
	int max;
	bitset<999> bs;

};

#endif // !RANDOMNUMBERSET_H