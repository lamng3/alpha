// problem url: 
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

    vi cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i];
 
    map<int,int> pos;
    pos[0] = -1;

    ll ans = 0, run = 0;

    for (int i = 0; i < n; i++) {
        run += cows[i];
        if (pos.count(run % 7)) ans = max(ans, (ll)i - pos[run % 7]);
        else pos[run % 7] = i;
    }

    cout << ans << '\n';
}

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}