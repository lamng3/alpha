// problem url: https://cses.fi/problemset/task/1652
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector< vector<int> >;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define RFOR(i, n) for (int i = (n) - 1; i >= 0; i--)

#define fi first
#define se second
#define pb push_back

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    int q; cin >> q;

    vii g(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        string r; cin >> r;
        for (int j = 0; j < n; j++) g[i][j] = (r[j] == '*');
    }

    // pref[i][j] = sum (0,0) to (i,j)
    vii pref(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pref[i][j] = g[i][j];
            if (i > 0) pref[i][j] += pref[i-1][j];
            if (j > 0) pref[i][j] += pref[i][j-1];
            if (i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        int ans = pref[y2][x2];
        // cerr << x2 << ' ' << y2 << ' ' << pref[x2][y2] << '\n';
        if (x1 > 0) ans -= pref[y2][x1-1];
        if (y1 > 0) ans -= pref[y1-1][x2];
        if (x1 > 0 && y1 > 0) ans += pref[y1-1][x1-1];
        cout << ans << '\n';
    }
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}