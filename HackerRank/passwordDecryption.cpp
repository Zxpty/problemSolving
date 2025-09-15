#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

void solve()
{
    string s; cin >> s;
    string numbers = "";
    string letters = "";
    int i = 0;
    while (i<s.size() && isdigit(s[i])) {
        numbers += s[i];
        i++;
    }
    
    reverse(numbers.begin(), numbers.end());
    
    letters = s.substr(i);

    string ans = "";
    int num_idx = 0; 

    i = 0;
    int n = (int)letters.size();

    while (i < n) {
        if (letters[i] == '0') {
            if (num_idx < numbers.size()) {
                ans += numbers[num_idx];
                num_idx++;
            }else{
              ans+='0';
            }
            i += 1;
        }
        else if (i + 2 < n && islower(letters[i+1]) && isupper(letters[i]) && letters[i+2] == '*') {
            ans += letters[i+1];
            ans += letters[i];
            i += 3; 
        } else {
            ans += letters[i];
            i++;
        }
    }

    cout << ans;
}

int main()
{
    cpu();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


