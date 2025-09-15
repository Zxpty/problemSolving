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
auto check =[&](int x){
    string s = to_string(x);
    int sum = 0;
    for(int i=0;i<s.size();i++){
      sum+=s[i]-'0';
    }
    return sum;
  };

 auto sum_digits = [&](int x,int y){
    if(check(x)==check(y)|| abs(check(x)-check(y))==1){
      return true;
    }
    return false;
  };
  int n; cin>>n;
  if(n==1){
    cout<<"1 0"<<'\n';
    return;
  }
  int techo = (n+1)/2;
  int piso = n/2;
  if(sum_digits(techo, piso)){
    cout<<techo<<" "<<piso<<'\n';
  }else{
    string cn = to_string(piso);
    int k = 0;
    for(int i=(int)cn.size()-1;i>=0;i--){
      if(cn[i]=='9')k++;
      else break;
    }
    int x = 0;
    if(k%2==0){
      x = ((9*k)/2);
    }else{
      x = (((9*k)-1)/2);
    }
    int nines = (x/9);
    string ans = "";
    for(int i=0;i<nines;i++){
      ans+='9';
    }
    if(x%9!=0){
      ans+=to_string(x%9);
    }
    int n_num = stoi(ans);
    techo+=n_num;
    piso-=n_num;
    cout<<techo<<" "<<piso<<'\n';

  }
}
int main()
{
    cpu();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

