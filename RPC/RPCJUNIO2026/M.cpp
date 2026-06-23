#include <bits/stdc++.h>
#include <cctype>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ios>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


typedef int64_t i64;
const long long MX = 1e9+7;

void GA(){
	string pass; read(pass);
	int q; read(q);
	map<char, char> LS_MY = {
		{'Q', 'W'},
		{'W', 'R'},
		{'E', 'R'},
		{'R', 'T'},
		{'A', 'S'},
		{'S', 'D'},
		{'D', 'F'},
		{'F', 'G'},
		{'Z', 'X'},
		{'X', 'C'},
		{'C', 'V'},
		{'V', 'B'}
	};

	map<char, char> RS_MY = {
		{'U', 'Y'},
		{'I', 'U'},
		{'O', 'I'},
		{'P', 'O'},
		{'J', 'H'},
		{'K', 'J'},
		{'L', 'K'},
		{'M', 'N'},
	};

	auto checkLS = [&](string s){
		string temp = pass;
		for(char& c : temp){
			bool wasLower = (c >= 'a' && c <= 'z');
			char key = toupper(c);
			if(LS_MY.count(key)){
				c = LS_MY[key];
				if(wasLower) c = tolower(c);
			}
		}
		return temp == s;
	};

	auto checkRS = [&](string s){
		string temp = pass;
		for(char& c : temp){
			bool wasLower = (c >= 'a' && c <= 'z');
			char key = toupper(c);
			if(RS_MY.count(key)){
				c = RS_MY[key];
				if(wasLower) c = tolower(c);
			}
		}
		return temp == s;
	};

	auto checkMC = [&](string s){
		if(int(pass.size()) != int(s.size()) + 1) return false;
		int i = 0, j = 0;
		bool skip = 0;
		while(i < pass.size() && j < s.size()){
			if(pass[i] == s[j]){
				i++, j++;
			}else{
				if(skip) return false;
				skip = 1;
				i++;
			}
		}
		return true;
	};

	auto checkEC = [&](string s){
		if(int(pass.size()) + 1 != int(s.size())) return false;
		int i = 0, j = 0;
		bool skip = 0;
		while(i < pass.size() && j < s.size()){
			if(pass[i] == s[j]){
				i++, j++;
			}else{
				if(skip) return false;
				skip = 1;
				j++;
			}
		}
		return true;
	};

	auto checkCL = [&](string s){
		string temp = pass;
		for(char& c : temp){
			if(c >= 'a' && c <= 'z'){
				c = toupper(c);
			}else if(c >= 'A' && c <= 'Z'){
				c = tolower(c);
			}
		}
		return temp == s;
	};


	auto check = [&](string s){
		if(checkLS(s)) return true;
		if(checkRS(s)) return true;
		if(checkMC(s)) return true;
		if(checkEC(s)) return true;
		if(checkCL(s)) return true;
		return false;
	};
	for(int i = 0; i < q; i++){
		string s; read(s);
		if(check(s)){
			ps("YES");
		}else{
			ps("NO");
		}
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
