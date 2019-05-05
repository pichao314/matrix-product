#include "RandomNumberSet.h"
#include <bitset>

RandomNumberSet::RandomNumberSet()
{
	max = 39;
	count = 0;
	bs = new string(max, '0');
}

RandomNumberSet::RandomNumberSet(int range)
{
	if (range > 999)
	{
		cerr << "The range is too big!\n";
		range = 999;
	}
	if (range < 5)
	{
		cerr << "The range is too small!\n";
		range = 5;
	}
	max = range;
	count = 0;
	bs = new string(max, '0');
}

RandomNumberSet::~RandomNumberSet()
{
	delete bs;
}

void RandomNumberSet::reset()
{
	bs->assign(max, '0');
	count = 0;
}

bool RandomNumberSet::set(int i)
{
	if (count >= 5)
	{
		cerr << "There's too much numbers!";
	}
	if (i > max || i <= 0)
	{
		cerr << "The number is out of range!";
		return false;
	}
	if ((*bs)[max - i] != '1')
	{
		(*bs)[max - i] = '1';
		count++;
		return true;
	}
	else
	{
		return false;
	}
}

int RandomNumberSet::size()
{
	return(count);
}

ostream & operator<<(ostream & outs, RandomNumberSet & rns)
{
	if (rns.count == 0)
	{
		cerr << "There's no number to output!";
		return outs;
	}
	for (int i = rns.max; i >= 0; i--)
	{
		if ((*rns.bs)[i] == '1')
		{
			outs.width(3);
			outs.setf(ios::right);
			outs << rns.max - i << " ";
		}
	}
	outs << endl;
	return outs;
}

int operator-(RandomNumberSet & r1, RandomNumberSet & r2)
{
	bitset<999> bs1(*(r1.bs));
	bitset<999> bs2(*(r2.bs));

	return ((r1.count > r2.count ? r1.count : r2.count) - (bs1 &= bs2).count());
}
