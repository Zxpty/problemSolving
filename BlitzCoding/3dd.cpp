#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
void GA(){
	int n; cin>>n;
	vector<string> r(n);
	for(int i = 0; i < n; i++){
		cin>>r[i];
	}
	string s; cin>>s;
	map<int,int> mp;
	for(auto x : s) mp[x]++;
	vector<string> ans;
	for(int i = 0; i < n; i++){
		string a = r[i];
		bool ok = 1;
		for(int j = 0; j < (int) a.size(); j++){
			if(mp[a[j]] == 0){
				ok = 0;
				break;
			}
		}
		if(ok) ans.push_back(a);
	}
	if(ans.empty()){
		cout<< "Ninguno." << endl;
		return;
	}
	for(int i = 0; i < ans.size() - 1; i++){
		cout << ans[i] << " ";
	}
	cout<< ans[ans.size() - 1];
	cout<<endl;
}
int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
