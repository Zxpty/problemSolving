#include <algorithm>
#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
    int k, n; cin >> k >> n;
	int goal = k;
	int m = n;
    string ans = "";
    if(3 * k == n) {
        for(int i = 0; i < n ; i++) {
            if(i % 3 == 1) {
                ans += 'X';
            } else {
                ans += '-';
            }
        }
    } else if(3 * k > n) {
		ans = "X-";
		k--;
		n-=2;
		if(3 * k == n){
			for(int i = 0; i < n; i++){
				if(i % 3 == 1) ans += 'X';
				else ans+= '-';
			}
		}else{
			int rest = abs((3 * k) - n);
			int go =(3 * (k - rest));
			for(int i = 0; i < go; i++){
				if(i % 3 == 0) ans += 'X';
				else ans += '-';
			}
			for(int i = 0; i < n - go; i++){
				if(i % 2 == 0) ans += 'X';
				else ans += '-';
			}

		}
	}else{
		ans = '*';
		cout << ans << '\n';
		return;
	}
	string ga = "";
	for(int i = 0; i < m; i++){
		ga += ans[i];
	}
	int cn = count(ga.begin(), ga.end(), 'X');
	if(cn != goal){
		cout << '*' << '\n';
		return;
	}
    cout << ga << '\n';
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
