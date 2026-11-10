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
	int n, q; cin >> n >> q;
	vector<int> r(n);
	for(int& x : r) cin >> x;

	sort(r.begin(), r.end());
	vector<int> answer;
	while(true){
		int calc = r.back() - r.front();
		answer.push_back(calc);
		if(calc == 0) break;
		vector<int> other;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				other.push_back(r[i] ^ r[j]);
			}
		}
		sort(other.begin(), other.end());
		for(int i = 0; i < n; i++){
			r[i] = other[i];
		}
	}

	for(int i = 0; i < q; i++){
		int nth; cin >> nth;
		if(nth >= int(answer.size())){
			cout << 0 << "\n";
		}else{
			cout << answer[nth] << '\n';
		}
	}

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
