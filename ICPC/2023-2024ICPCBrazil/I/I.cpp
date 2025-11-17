#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(0);cin.tie(0);
using namespace std;


void Ga(){
    int n; cin >> n;
    vector<int> r(n);
    for(int &x : r) cin >> x;

    int right = 0, left = 0;
    int sum = 0;
    int ans = 0;
    while(right < n){
        sum += r[right];
        cout << sum << '\n';
        while(left < n and sum % 2 == 0){
            left++;
            sum -= r[left];
        }
        ans += right - left + 1;
        cout << right << " " << left << '\n';
        right++;
    }
    cout << ans << '\n';

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