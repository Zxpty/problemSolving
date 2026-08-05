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
	string a, b; cin >> a >> b;
	vector<int> apar, aimp;
	vector<int> bpar, bimp;
	for(int i = 0; i < n; i++){
		if(a[i] == '1'){
			if(i % 2 == 0) aimp.push_back(i);
			else apar.push_back(i);
		}
		if(b[i] == '1'){
			if(i % 2 == 0) bimp.push_back(i);
			else bpar.push_back(i);
		}
	}
	if((int(apar.size()) != int(bpar.size())) || (int(aimp.size()) != int(bimp.size()))){
		cout << -1 << '\n';
		return;
	}
	long long ans = 0;
	for(int i = 0; i < int(apar.size()); i++){
		ans += (abs(apar[i] - bpar[i]) / 2);
	}
	for(int i = 0; i < int(aimp.size()); i++){
		ans += (abs(aimp[i] - bimp[i]) / 2);
	}
	cout << ans << '\n';
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
