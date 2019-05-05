#include "OrthogonalNumbers.h"
#include <ctime>
#include <stdlib.h>


OrthogonalNumbers::OrthogonalNumbers()
{
	range = 39;
	distance = 4;
	nums = 5;
}

OrthogonalNumbers::OrthogonalNumbers(int n, int c, int d)
{
	range = n;
	nums = c;
	distance = d;
}

RandomNumberSet OrthogonalNumbers::gen(int range, int num)
{
	RandomNumberSet temp(range);

	for (int i = 0; i < num; i++)
	{
		int j = rand() % range + 1;

		if (temp.test(j))
			i--;
		else
			temp.set(j);
	}
	
	cout << "-----------------------------------------------\nThe new generated set is \n" << temp;

	return temp;
}

bool OrthogonalNumbers::generate(int gen_num)
{
	srand(time(NULL));

	if ((gen_num + onvec.size()) > 100)
	{
		cerr << "There's too much set!\n";
		return false;
	}

	for (int i = 0; i < gen_num; i++)
	{	
		int state = 1;
		RandomNumberSet temp = gen(range, nums);
		for (int j = 0; j < onvec.size(); j++)
		{
			cout << "The vec[" << j<<"] is\n" << onvec[j];
			cout << "The distance between temp and vec[" << j << "] is " << temp - onvec[j] << endl;;
			if ((temp - onvec[j]) < distance)
			{
				cout << "The distance is smaller than " << distance << " , discard!\n";
				state = 0;
				break;
			}
			cout << "The distance is bigger than " << distance << " , continue!\n";
		}
		if (state)
		{
			cout << "All set satisfied! Accepted!\n";
			onvec.push_back(temp);
		}
		else
		{
			i--;
		}
	}

	return true;
}

bool OrthogonalNumbers::reset()
{
	if (onvec.size() == 0)
	{
		cerr << "There's no set to clear!\n";
		return false;
	}
	else
	{
		onvec.resize(0);
		return true;
	}

}


OrthogonalNumbers::~OrthogonalNumbers()
{
}

ostream & operator<<(ostream & outs, OrthogonalNumbers &ogn)
{
	for (int i = 0; i < ogn.onvec.size(); i++)
	{
		outs << ogn.onvec[i];
	}
	
	return outs;
}
