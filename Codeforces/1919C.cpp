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
	int last_s = MX, last_t = MX;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x <= last_s && x <= last_t){
			if(last_s < last_t){
				last_s = x;
			}else{
				last_t = x;
			}
		}else if(x <= last_s){
			last_s = x;
		}else if(x <= last_t){
			last_t = x;
		}else{
			ans++;
			if(last_s < last_t){
				last_s = x;
			}else{
				last_t = x;
			}
		}
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
