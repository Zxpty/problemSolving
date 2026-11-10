#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

void UWU() {
    set<string> dic;

    string s;

    while (getline(cin, s) && s != "*") {
        if (!s.empty())
            dic.insert(s);
    }

    while (getline(cin, s) && !s.empty()) {
        string start, end;
        stringstream ss(s);
        ss >> start >> end;

        queue<string> q;
        map<string, int> dist;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr == end)
                break;

            for (int i = 0; i < (int)curr.size(); i++) {
                string next = curr;

                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;

                    if (next == curr)
                        continue;

                    if (dic.count(next) && !dist.count(next)) {
                        dist[next] = dist[curr] + 1;
                        q.push(next);
                    }
                }
            }
        }

        cout << start << " " << end << " " << dist[end] << '\n';
    }
}

int main() {
    cpu();

    int t;
    cin >> t;
    string s;
    getline(cin, s);
    getline(cin, s);

    while (t--) {
        UWU();
        if (t) cout << '\n';
    }
    return 0;
}
