#include <set>
#include <stdlib.h>
#include <ctime>
using namespace std;

//No number would be replicated
class RandomNumberBucket
{
public:
	//Default constructor must initialize the bucket with number form 1 to 39
	RandomNumberBucket();
	//The non-default constructor would take the range for generating numbers
	RandomNumberBucket(int range);
	//return a number chosen at random form the bucket and extracted from the bucket,
	//return -1 if empty,all numbers show have equal possibility to return
	int pop();
	//replenish the numbers numbers from 1-N when called
	void refill();
	//Return the number of elments left
	int size();
	//whether empty or not, while true needs refill
	bool empty();
	//refill before poping an empty bucket which never failed
	void popWithRefill();
private:
	set<int> bucket;
	set<int>::iterator bi;
	int max;
};