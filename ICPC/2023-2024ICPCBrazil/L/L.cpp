#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(0);cin.tie(0);
using namespace std;


void Ga(){
    string s; cin >> s;
    int k; cin >> k;
    int n = int(s.size());
    
    if(k == 1){
        sort(s.begin(), s.end());
        cout << s;
        return;
    }
     for(int i = 0; i < k; i++){
        multiset<char> st;

        for(int j = i; j < n; j += k){
            st.insert(s[j]);
        }
        for(int j = i; j < n; j += k){
            s[j] = *st.begin();
            st.erase(st.begin());
        }

        
    }
    cout << s << '\n';
    
}
int main() {
    cpu();
    int t = 1;
    //cin >> t;
    while (t--) {
        Ga();
    }
    return 0;
}