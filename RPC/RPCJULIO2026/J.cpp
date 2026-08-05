#include <bits/stdc++.h>
#include <utility>

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
	vector<pair<string, string>> pset(n);
	for(int i = 0; i < n; i++){
		string first, second; cin >> first >> second;
		pset[i] = {first, second};
	}
	auto check = [&](int mask){
		int cn = 0;
		while(mask){
			mask &= (mask - 1);
			cn++;
		}
		return cn == 3;
	};

	auto valid = [&](int mask){
		int cn = 0;
		while(mask){
			mask &= (mask - 1);
			cn++;
		}
		return cn == 1;
	};
	long long ans = 0;
	map<char, int> mp_nums = {{'1', 1}, {'2', 2}, {'3', 3}};
	map<char, int> mp_shape = {{'A', 1}, {'D', 2}, {'O', 3}};
	map<char, int> mp_color = {{'R', 1}, {'G', 2}, {'B', 3}};
	map<char, int> mp_fill = {{'E', 1}, {'S', 2}, {'F', 3}};


	auto fx = [&](vector<string> a, vector<string> b){
		int cn_a = 0;
		int color_a = 0;
		int shape_a = 0;
		int fill_a = 0;
		int cn_b = 0;
		int color_b = 0;
		int shape_b = 0;
		int fill_b = 0;
		for(int i = 0; i < 3; i++){
			cn_a += mp_nums[a[i][0]];
			color_a += mp_color[a[i][1]];
			fill_a += mp_fill[a[i][2]];
			shape_a += mp_shape[a[i][3]];
			cn_b += mp_nums[b[i][0]];
			color_b += mp_color[b[i][1]];
			fill_b += mp_fill[b[i][2]];
			shape_b += mp_shape[b[i][3]];
		}
		cn_a %= 3;
		color_a %= 3;
		shape_a %= 3;
		fill_a %= 3;
		cn_b %= 3;
		color_b %= 3;
		shape_b %= 3;
		fill_b %= 3;
		set<int> g = {cn_a, color_a, shape_a, fill_a, cn_b, color_b, shape_b, fill_b};
		return (int(g.size()) == 1 && *g.begin() == 0);
	};

	for(int mask = 0; mask < (1 << n); mask++){
		if(check(mask)){
			vector<string> a;
			vector<string> b;
			for(int i = 0; i < n; i++){
				if(mask & (1 << i)){
					a.push_back(pset[i].first);
					b.push_back(pset[i].second);
				}
			}
			if(fx(a, b)) ans++;
			for(int mask2 = 0; mask2 < (1 << 3); mask2++){
				vector<string> tempa = a;
				vector<string> tempb = b;
				if(valid(mask2)){
					for(int i = 0; i < 3; i++){
						if(mask2 & (1 << i)){
							swap(a[i], b[i]);
							if(fx(a, b)) ans++;
						}
					}
				}
			}
		}
	}
	cout << ans;
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
