#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int res(int x, int base) {
    int acc = 0;
    int b = 1;
    while(x != 0) {
        acc += (x % 10) * b;
        b *= base;
        x /= 10;
    }
    return acc;
}


bool check(int x, int base) {
    int acc = 0;
    int b = 1;
    while(x != 0) {
		if(x % 10 >= base) return false;
        acc += (x % 10) * b;
        b *= base;
        x /= 10;
    }
	return true;
}

void solve()
{
    int x, y, z; cin >> x >> y >> z;
    for(int a = 2; a <= 10; a++) {
        for(int b = 2; b <= 10; b++) {
            if(check(x, a) && check(y, b) && ((res(x, a) + res(y, b)) == z)) {
				cout << a << " " << b << '\n';
				return;
            }
        }
    }
}
int main()
{
    cpu();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
