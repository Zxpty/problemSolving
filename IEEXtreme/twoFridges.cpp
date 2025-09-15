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
vector<vector<int>>adj;
vector<int> star;
vector<bool> visited;

void dfs(int city,int lstar,int cn, int &mxcn){
  visited[city] = true;
  if(star[city]>=lstar){
    cn++;
    lstar = star[city];
  }
  mxcn = max(mxcn,cn);
  visited[city] = true;
  for(int x: adj[city]){
    if(!visited[x]){
      dfs(x,lstar, cn, mxcn);
    }
  }
  visited[city] = false;
}
void solve()
{
  int n; cin>>n;
  star.resize(n);
  adj.resize(n);
  visited.assign(n,false);
  for(int i=0;i<n;i++){
    cin>>star[i];
  }
  bool ok = true;
  for(int i=1;i<n;i++){
    if(star[i]!=star[i-1]){
      ok = false;
      break;
    }
  }
  if(ok){
    cout<<"1\n";
    return;
  }
  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mxCn = 0;
  for(int i=0;i<n;i++){
    dfs(i,-1,0,mxCn);
  }
  cout<<mxCn<<'\n';
  
    
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
