#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t; cin >> n >> m >> t;
    for(int i = 0; i < m; i++) {
        int p, v; cin >> p >> v;
        char ch; cin >> ch;
        int l; cin >> l;
        string str(n, '=');
        if(ch == 'L') {
            int id = p - (v * t);
            for(long long i = max(0, -id); i < l; i++) {
				if(id + i >= n) break;
				if(i == 0) {
					str[id + i] = '!';
				} else {
					str[id + i] = '#';
				}
            }
            cout << str << '\n';
        } else {
            int id = p + (v * t) + l - 1;
            for(int i = max(0, id - n + 1); i < l; i++) {
				if(id - i <= 0)
            }
            cout << str << '\n';
        }
    }
}

