#include <algorithm>
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

void UWU(){
	int n, m, x; cin >> n >> m >> x;
	queue<int> q;
	q.push(x);
	for(int i = 0; i < m; i++){
		int k; cin >> k;
		char c; cin >> c;
		if(c == '?'){
			set<int> st;
			while(!q.empty()){
				int val = q.front(); q.pop();
				st.insert(val);
			}
			for(int x : st){
				q.push((x + (n - k)) % n);
				q.push((x + k) % n);
			}
		}else if(c == '1'){
			set<int> st;
			while(!q.empty()){
				int val = q.front(); q.pop();
				st.insert(val);
			}
			for(int x : st){
				q.push((x + (n - k)) % n);
			}
		}else if(c == '0'){
			set<int> st;
			while(!q.empty()){
				int val = q.front();
				q.pop();
				st.insert(val);
			}
			for(int x : st){
				q.push((x + k) % n);
			}
		}
	}
	set<int> ans;
	while(!q.empty()){
		ans.insert(q.front());
		q.pop();
	}
	cout << int(ans.size()) << '\n';
	vector<int> res;
	for(int x : ans){
		if(x == 0) res.push_back(n);
		else res.push_back(x);
	}
	sort(res.begin(), res.end());
	for(int x : res){
		cout << x << " ";
	}
	cout << '\n';
	
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
