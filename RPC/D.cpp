#include <bits/stdc++.h>

using namespace std;

void GA(){
    map<char, char> abc = {
        {'a', '2'}, {'b','2'}, {'c', '2'}, 
		{'d', '3'}, {'e','3'}, {'f','3'},
        {'g','4'}, {'h', '4'}, {'i', '4'}, 
		{'j', '5'}, {'k','5'}, {'l', '5'},
        {'m', '6'}, {'n', '6'}, {'o', '6'},
		{'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
        {'t', '8'}, {'u', '8'}, {'v', '8'}, 
		{'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}
    };
    int n, m; cin >> n >> m;
    vector<string> x(n); 
    vector<string> num(m); 
    for (string& s : x) cin >> s;
    for (string& s : num) cin >> s;
	vector<vector<string>> ans(m);
	for (int j = 0; j < n; j++) {
		string copy = "";
		for (int i = 0; i < (int) x[j].size(); i++) {
			copy += abc[x[j][i]];
		}
		for (int i = 0; i < m; i++) {
			if (copy == num[i]) {
				ans[i].push_back(x[j]);
			}
		}
	}
	
	for (auto v : ans) {
		if(v.size() == 0 || v.empty()){
			cout << "0" << '\n';
		}else{
			cout << (int)v.size() << " ";
			for (int i = 0; i < (int) v.size() - 1; i++) {
				cout << v[i] << " ";
			}
			cout << v[(int)v.size() - 1];
			cout << '\n';
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
