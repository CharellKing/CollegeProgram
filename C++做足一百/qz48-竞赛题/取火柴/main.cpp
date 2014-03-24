#include <iostream>

using namespace std;

bool Pick(int n , int x1, int x2)
{
	int i;
	for(i = 1; n > 0; i ++)
	{
		if(i % 2) n -= x1;
		else n -= x2;
	}
	if(i % 2) return false;
	else return true;
}

int main()
{
	int n, x1, x2;
	while(cin >> n, n)
	{
		cin >> x1 >> x2;
		if(Pick(n, x1, x2)) cout << 'X';
		else cout << 'Y';
		cout << endl;
	}
	return 0;
}
