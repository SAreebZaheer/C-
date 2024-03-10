#include <iostream>
using namespace std;

//defining value of PI to be 314 instead of 3.14 so that operations can be performed
//preprocessing does not handle floating point comparisons
#define pi 314

int main()
{
	#ifdef pi
	#if pi > 314
		cout << "Value is greater than 3,14 \n" ;
	#elif pi < 314
		cout << "Value is less than 3.14 \n";
	#elif pi == 314
		cout << "Value is equal to 3.14 \n";
	#else
		#undef pi;
	#endif
#else
	cout << "Not Defined PI \n";
#endif
	return 0;
}
