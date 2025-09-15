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
const int x = 1;
const int N = 10000000 + 5;
int len;
int S[N];
void solve()
{
  
  /* 
  unordered_set<int> S;
  unordered_map<int,int> frec;
  for(int i=0;i<=1000000;i++){
    S.emplace(x);
    frec[x]++;
  }
  int cn = 0;
  for(int i=0;i<=1000000;i++)cout<<frec[x]<<'\n';
  */
  const int L = 1000000;
  const int x = 1;
  for(int i=1;i<=L;i++){
    S[len++] = x;
  }
  for(int i=1;i<=L;i++){
    cout<<S[len-1]<<'\n';
    len--;
    
  }
    
}
/* stack STL = 857 ms
 * stack array = 841ms
 *
 *
 *
*/


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

