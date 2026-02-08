// problem url: https://codeforces.com/contest/295/problem/A
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

struct Query {
    int l, r, d;
    Query(int L, int R, int D) : l(L), r(R), d(D) {}
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Query> queries;
    queries.reserve(m);
    for (int i = 0; i < m; i++) {
        int l, r, d; 
        cin >> l >> r >> d;
        l--; r--;
        queries[i] = Query(l, r, d);
    }

    vector<ll> f(m, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        f[x]++;
        if (y+1 < m) f[y+1]--;
    }
    for (int i = 1; i < m; i++) f[i] += f[i-1];

    vector<ll> diff(n, 0);
    for (int i = 0; i < m; i++) {
        Query q = queries[i];
        int l = q.l, r = q.r, d = q.d;
        diff[l] += (ll)d * f[i];
        if (r + 1 < n) diff[r+1] -= (ll)d * f[i];
    }
    for (int i = 1; i < n; i++) diff[i] += diff[i-1];

    for (int i = 0; i < n; i++) {
        a[i] += diff[i];
        cout << a[i] << (i == n-1 ? '\n' : ' ');
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