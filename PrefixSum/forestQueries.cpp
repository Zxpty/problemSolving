#include <algorithm>
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;

void solve(){
	int n,q; read(n,q);
	vector<string> grid(n);
	for(int i = 0; i < n; i++) cin>>grid[i];
	vector<vector<int>> A(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;i++){
			A[i][j] = (grid[i][j] == '*' ? 1 : 0);
		}
	}
	vector<vector<int>> p(n,vector<int>(n));
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n ; y++){
			p[x][y] = A[x][y];
			if(y - 1>= 0) p[x][y]+=p[x][y-1];
			if(x - 1>= 0) p[x][y]+=p[x-1][y];
			if(x - 1>=0 && y - 1>=0) p[x][y]-= p[x-1][y-1];
		}
	}
	auto get = [&](int x1, int y1, int x2, int y2){
		int ans = p[x2][y2];
		if(y1>0) ans-=p[x2][y1-1];
		if(x1>0) ans-=p[x1-1][y2];
		if(y1>0 && x1>0) ans-= p[x1-1][y1-1];
		return ans;
	};
	while(q--){
		int y1,x1,y2,x2; cin>>x1>>y1>>x2>>y2;
		x1--,y1--,x2--,y2--;
		cout<<get(x1,y1,x2,y2)<<'\n';
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
