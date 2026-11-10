#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 100005;
// preparamos las cajas (100000 es el valor maximo posbile)
long long dp[MX];

void UWU(){
	// llenamos todas las cajas con infinito
	for(int i = 1; i <= 100000; i++){
		dp[i] = 1e18;
	}
	// la caja 0 lleva 0 kilos
	dp[0] = 0;
	int N, W; cin >> N >> W;
	vector<int> w(N), v(N);
	for(int i = 0; i < N; i++){
		cin >> w[i] >> v[i];
	}

	// empieza el juevo revisamos cada objeto
	for(int i = 0; i < N; i++){
		long long kilos = w[i];
		int valor = v[i];
		// caminamos de reversa por las cajas
		//
		for(int caja = 100000; caja >= valor; caja--){
			// que habia en la caja de donde vengo
			long long kilos_anteriores = dp[caja - valor];
			// si no era infinito hacemos la suma
			if(kilos_anteriores != 1e18){
				long long nuevo_peso = kilos_anteriores + kilos;
				// si el nuevo peso es mas ligerito que el que ya estaba en la caja lo cambiamos.
				if(nuevo_peso < dp[caja]){
					dp[caja] = nuevo_peso;
				}
			}
		}
	}

	for(int caja = 100000; caja >= 0; caja--){
		if(dp[caja] <= W){
			cout << caja << "\n";
			break;
		}
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
