#include <bits/stdc++.h>
using namespace std;

void GA(){
	long long n, a, b;
	cin >> n >> a >> b;
	long long mcm = __gcd(a, b);
	long long calc = (n - 1) / mcm;
	long long op = (calc * (calc + 1)) / 2;
	cout << mcm * op << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

