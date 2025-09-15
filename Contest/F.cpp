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
  string s; cin>>s;
  vector<int> freq(26);
  for(int i=0;i<(int)s.size();i++){
    freq[s[i]-'a']++;
  }
  int mx = 0;
  for(int i=0;i<26;i++){
    if(freq[i]%2!=0){
      mx = max(mx, freq[i]);
    }
  }
  dbg(freq);
  vector<int> pares;
  vector<int> impares;
  for(int i=0;i<26;i++){
    if(freq[i]%2==0 && freq[i]!=0){
      pares.push_back(freq[i]);
    }else{
      if(freq[i]!=0){
      impares.push_back(freq[i]);
      }
    }
  }
  dbg(pares);
  dbg(impares);
  if(impares.size()==1){
    cout<<(int)s.size();
    return;
  }else{
    int sum = mx;
    for(int i=0;i<(int)pares.size();i++){
      sum+=pares[i];
    }
    dbg(sum);
    for(int i=0;i<(int)pares.size();i++){
      sum+=impares[i];
    }
    sum-=mx-1;
    cout<<sum;
    dbg(sum);
  }

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


