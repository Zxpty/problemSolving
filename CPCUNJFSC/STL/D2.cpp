#include <bits/stdc++.h>
using namespace std;

void GA(){
	int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    sort(r.begin(), r.end());
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] - r[i - 1] != 1)
        {
            ans = r[i-1] + 1;
            break;
        }
    }
 
    cout<< ans <<endl;

}

int main(){
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

