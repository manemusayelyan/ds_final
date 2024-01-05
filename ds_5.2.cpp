#include <iostream>
#include <stack>
using namespace std;

/*
* 5.2
* Գրել ծրագիր, որը պահունակի միջոցով տրված բնական թիվը
* տասական համակարգից բերում է p-ական համակարգի (p > 1)։
* Սկզբում պետք է p-ական համակարգում ստացված թվանշանները
* գցել պահունակի մեջ, հետո հանել և տպել։
*/

int main()
{
	int num;
	int base;
	cin >> num >> base;
	int n = num;
	stack <char> rm_stack;
	if (!num)
		rm_stack.push('0');
	while (num && base > 1)
	{
		int rm = num % base;
		char digit;

		if (rm < 10)
			digit = '0' + rm;
		else
			digit = 'A' + (rm - 10);
		num = num / base;
		rm_stack.push(digit);
	}
	cout << base << " base representation of " << n << endl;
	while (!rm_stack.empty())
	{
		cout << rm_stack.top();
		rm_stack.pop();
	}
	cout << endl;
	return 0;
}

