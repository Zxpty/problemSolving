#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(0);cin.tie(0);
using namespace std;


void Ga(){
    long long d, c, r; cin >> d >> c >> r;
     long long s = 0 ;
     vector<long long> v(c); for(auto& x:v) cin >> x;
     for(int i = 0 ; i < r ; i++) {
            long long x ; cin >> x; 
            s+= x;
     }
     long long operaciones = r;
     d+=s;
     for(int i = 0 ; i < c ; i++) {
        if( d - v[i]  >= 0) {
            d-=v[i]; operaciones++;
        }
        else{break;}
     }
     cout << operaciones << endl;
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