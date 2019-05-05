#include "OrthogonalNumbers.h"

int main()
{
	OrthogonalNumbers ogn;
	ogn.generate(3);
	ogn.generate(4);
	cout << ogn;
}