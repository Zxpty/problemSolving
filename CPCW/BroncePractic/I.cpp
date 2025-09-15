#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


typedef long long ll;
const int mxn = 5e6;
const ll MX = 1e9+7;

void GA(int n, int m){
	vector<ll> d(n);
	for(int i = 0; i < n; i++){
		cin>>d[i];
	}
	multiset<ll> ms;
	for(int i = 0; i < m; i++){
		int num; cin>>num;
		ms.insert(num);
	}
	sort(d.begin(), d.end());
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll x = d[i];
		multiset<ll>::iterator it = ms.lower_bound(x);
		if(it != ms.end()){
			ans+=*it;
			ms.erase(it);
		}else{
			cout<< "Loowater is doomed!" << '\n';
			return;
		}
	}
	cout << ans << '\n';

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		GA(n, m);
	}
	return 0;
}

