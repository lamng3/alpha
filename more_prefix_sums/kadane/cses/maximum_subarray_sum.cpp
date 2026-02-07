// problem url: https://cses.fi/problemset/task/1643
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

const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    
    vi x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    ll ans = -INF, curr = 0;
    for (int i = 0; i < n; i++) {
        curr += x[i];
        ans = max(ans, curr);
        curr = max(curr, 0LL);
    }
    cout << ans << '\n';
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