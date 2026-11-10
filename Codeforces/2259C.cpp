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
	int n; cin >> n;
	vector<int> r(n);
	vector<int> ones, minus;
	for(int i = 0; i < n; i++){
		cin >> r[i];
		if(r[i] == 1) ones.push_back(i);
		if(r[i] == -1) minus.push_back(i);
	}
	int mx = 0;
	int left = -1, right = -1;
	for(int i = 0;i + 1 < ones.size(); i++){
		int l = ones[i];
		int r = ones[i + 1];
		int ln = r - l + 1;
		if(ln > mx){
			mx = ln;
			left = l;
			right = r;
		}
	}
	if(!minus.empty() && !ones.empty()){
		int f_minus = minus[0];
		int f_one = ones[0];
		if(f_minus < f_one){
			int ln = f_one - f_minus + 1;
			if(ln > mx){
				mx = ln;
				left = f_minus;
				right = f_one;
			}
		}
	}

	if(!minus.empty() && !ones.empty()){
		int l_minus = minus[int(minus.size()) - 1];
		int l_one = ones[int(ones.size()) - 1];
		if(l_minus > l_one){
			int ln = l_minus - l_one + 1;
			if(ln > mx){
				mx = ln;
				left = l_one;
				right = l_minus;
			}
		}
	}

	if(ones.empty() && !minus.empty()){
		int f_minus = minus[0];
		int l_minus = minus[int(minus.size()) - 1];
		int ln = l_minus - f_minus + 1;
		if(ln > mx){
			mx = ln;
			left = f_minus;
			right = l_minus;
		}
	}

	for(int i = 0; i < n; i++){
		if(r[i] == -1){
			if(i == left || i == right){
				cout << 1 << " ";
			}else{
				cout << 0 << " ";
			}
		}else{
			cout << r[i] << " ";
		}
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
