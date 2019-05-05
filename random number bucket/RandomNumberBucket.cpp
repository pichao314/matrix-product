#include "RandomNumberBucket.h"
#include <ctime>

RandomNumberBucket::RandomNumberBucket()
{
	//use current time to seed the rand()
	srand(time(NULL));

	//set default size
	max = 39;

	//insert all elements
	for (int i = 0; i < max; i++)
	{
		bucket.insert(i);
	}
}

RandomNumberBucket::RandomNumberBucket(int range)
{
	srand(time(NULL));

	//set the size as argument
	max = range;

	for (int i = 0; i < max; i++)
	{
		bucket.insert(i);
	}
}

int RandomNumberBucket::pop()
{
	//return -1 if it's empty
	if (bucket.empty())
		return -1;

	//choose a random location of element to pop
	srand(time(NULL));
	int loc = rand() % bucket.size();

	//move the iterator to the location
	bi = bucket.begin();
	for (int i = 0; i < loc; i++)
		bi++;

	//remove the element
	bucket.erase(bi);

	return 0;
}

void RandomNumberBucket::refill()
{
	//iterate all members
	for (int i = 0; i < max; i++)
	{
		//add the missed member
		if ((bi = bucket.find(i)) == bucket.end())
			bucket.insert(i);
	}
}

int RandomNumberBucket::size()
{
	return(bucket.size());
}

bool RandomNumberBucket::empty()
{
	return(bucket.empty());
}

void RandomNumberBucket::popWithRefill()
{
	//check the empty status for refill
	if (bucket.empty())
		this->refill();

	this->pop();
}