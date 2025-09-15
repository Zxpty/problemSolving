#include <bits/stdc++.h>
using namespace std;

void GA(){
	int n, start;
	cin >> n >> start;
	deque<pair<string, int>> ga;
	for(int i = 0; i < n; i++){
		string x;
		int amount;
		cin >> x >> amount;
		ga.push_back({x, amount});
	}
	
	while(!ga.empty()){
		auto [name, amo] = ga.front();
		if(amo < start){
			cout << name << " " << amo + start << '\n';
			ga.pop_front();
		}else{
			ga.pop_front();
			ga.push_back({name, amo - start});
		}
	}
	

}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

