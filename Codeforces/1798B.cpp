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
  int m; cin>>m;
  vector<vector<int>> r(m);
  for(int i=0;i<m;i++){
    int n; cin>>n;
    r[i].resize(n);
    for(int j=0;j<n;j++){
      cin>>r[i][j];
    }
  }
  vector<int> ans(m,-1);
  set<int> st;
  /*
   * podemos usar ~i para condicionar que mi for sea >= 0
   * entendimos correcto la idea, fue dificil la implementacion.
   * la clave de esto fue usar un vector para guardar los ganadores de la
   * loteria por dia y usar un set para insertar estos numeros de loteria
   * ganadores permitiendo asi que luego hagamos un count para ver si ya lo
   * hemos usado y de esta manera poder cumplir con lo que pide el problema
   * y condicinar si es que aun nuestro ans[i]==-1 es pq no hay posibilida de
   * colocar un ganador ese dia.
   
   * Set-> verificar elementos que pudimos usar anteriormente
   * Vector -> sirve mucho para asignar valores que deseemos.
  */
  for(int i= m-1;i>=0;i--){
    for(int j = 0; j< r[i].size();j++){
      if(st.count(r[i][j]))continue;
      ans[i] = r[i][j];
      st.insert(r[i][j]);
    }
    if(ans[i]==-1){
      cout<<-1<<'\n';
      return;
    }
  }
  for(int& x : ans){
    cout<<x<<' ';
  }
  cout<<'\n';
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

