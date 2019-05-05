#include "RandomNumberSet.h"


RandomNumberSet::RandomNumberSet()
{
	max = 39;
}


RandomNumberSet::RandomNumberSet(int range)
{
	if (range > 999)
	{
		cerr << "The range is too big!\n";
		range = 999;
	}
/*	if (range < 5)
	{
		cerr << "The range is too small!\n";
		range = 5;
	}
	*/
	max = range;
}


RandomNumberSet::~RandomNumberSet()
{

}


void RandomNumberSet::reset()
{
	bs.reset();
}

bool RandomNumberSet::test(int i)
{
	return(bs.test(i - 1));
}


bool RandomNumberSet::set(int i)
{
/*	if (count >= 5)
	{
		cerr << "There's too much numbers!";
	}
	*/
	if (i > max || i <= 0)
	{
		cerr << "The number is out of range!";
		return false;
	}
	if (!test(i))
	{
		bs.set(i - 1);
		return true;
	}
	else
	{
		return false;
	}
}


int RandomNumberSet::size()
{
	return(bs.count());
}


ostream & operator<<(ostream & outs, RandomNumberSet & rns)
{
	if (rns.bs.none())
	{
		cerr << "There's no number to output!";
		return outs;
	}
	for (int i = 0; i < rns.max; i++)
	{
		if (rns.bs.test(i))
		{
			outs.width(3);
			outs.setf(ios::right);
			outs << i+1 << " ";
		}
	}
	outs << endl;
	return outs;
}


int operator-(RandomNumberSet & r1, RandomNumberSet & r2)
{
	bitset<999> temp = r1.bs;
	return ((temp.count() > r2.bs.count() ? temp.count() : r2.bs.count()) - (temp &= r2.bs).count());
}
