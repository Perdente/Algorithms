// https://vjudge.net/contest/474613#problem/P
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

const int N = 1e6;
int divisor[N + 5];

void malena() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            ++divisor[j];
        }
    }
    // for (int i = 1; i < N; ++i) {
    //     cout << divisor[i] << "\n";
    // }
    vector<bool> vis(N, true);
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            if (divisor[j] < 3 or divisor[j] % divisor[i] != 0) {
                vis[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i < N; ++i) {
        if (vis[i]) ans.push_back(i);
    }
    for (int i = 107; i < (int)ans.size(); i += 108) {
        cout << ans[i] << "\n";
    }cout << '\n';

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}
