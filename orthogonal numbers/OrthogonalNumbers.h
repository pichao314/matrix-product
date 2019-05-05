#ifndef ORTHOGONALNUMBERS_H
#define ORTHOGONALNUMBERS_h

#include <vector>
#include "RandomNumberSet.h"
class OrthogonalNumbers :
	public RandomNumberSet
{
public:
	//default constructor
	OrthogonalNumbers();

	//Parameterized constructor including range of randomnumbers, numbers in each set and minimum distance between any two sets
	OrthogonalNumbers(int n, int c, int d);

	//Generate and return a sets with random numbers setted
	RandomNumberSet gen(int range, int count);

	//Generate function to generate the amount of differenced sets int the bucket
	bool generate(int gen_num);

	//The reset function would return the state of reset
	bool reset();

	//Print the sets each line
	friend ostream& operator << (ostream&, OrthogonalNumbers&);

	virtual ~OrthogonalNumbers();

private:

	//Vector to store the sets
	vector<RandomNumberSet> onvec;
	
	//range of the random numbers
	int range;

	//The minimum distance between any two sets
	int distance;

	//numbers of each set
	int nums;
};


#endif // !ORTHOGONALNUMBERS_H