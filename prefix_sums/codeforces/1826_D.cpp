// problem url: https://codeforces.com/contest/1826/problem/D
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

    vi b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    // optimally set boundaries to be beautiful sight to minimize distance
    // f(i) = bi + bL + bR - (R - L) = bi + (bR - R) + (bL + L)
    // for each i, we find L that maximizes bL + L
    // for each i, we find R that maximizes bR - R

    vi pref(n);
    pref[0] = b[0] + 1;
    for (int i = 1; i < n; i++) pref[i] = max(pref[i-1], b[i] + (i+1));

    vi suff(n);
    suff[n-1] = b[n-1] - n;
    for (int i = n-2; i >= 0; i--) suff[i] = max(suff[i+1], b[i] - (i+1));

    int ans = 0;
    for (int i = 1; i < n-1; i++) {
        int L = pref[i-1];
        int R = suff[i+1];
        ans = max(ans, b[i] + L + R);
    }
    cout << ans << '\n';
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}