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
	int n; read(n);
	vi r(n); read(r);
	vi p,im;
	bool all = 1;
	for(int i=0;i+1<n;i++){
		if(r[i]!=r[i+1]) {all = 0; break;}
	}
	if(all){cout<<-1<<'\n';return;}

	for(int i=0;i<n;i++){
		if(r[i]%2==0)p.push_back(r[i]);
		else im.push_back(r[i]);
	}
	int p_size = (int)p.size();
	int im_size = (int)im.size();
	if(p_size>0 && im_size>0){
		cout<<im_size<<' '<<p_size<<'\n';
		for(int i : im) cout<<i<<' ';
		cout<<'\n';
		for(int i : p) cout<<i<<' ';
		cout<<'\n';
	}else if(p_size ==0 && im_size>0){
		cout<<1<<' '<<im_size-1<<'\n';
		cout<<im[0]<<'\n';
		for(int i=1;i<im_size;i++){
			cout<<im[i]<<' ';
		}cout<<'\n';
	}else if(im_size == 0 && p_size>0){
		sort(p.begin(),p.end());
		int mx = *max_element(p.begin(),p.end());
		int index = 0;
		vi ans;
		for(int i=0;i<p_size;i++){
			if(p[i]==mx){
				index = i;
				break;
			}else{
				ans.push_back(p[i]);
			}
		}
		cout<<index<<' '<<p_size-index<<'\n';
		for(int x : ans) cout<<x<<' ';
		cout<<'\n';
		for(int i=index;i<n;i++){cout<<p[i]<<' ';}
		cout<<'\n';
	}

}


int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


