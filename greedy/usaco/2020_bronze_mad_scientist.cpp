// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1012
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
    int N; cin >> N;
    string A; cin >> A;
    string B; cin >> B;

    int ans = 0, run = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) {
            ans += (run > 0);
            run = 0;
        }
        else run++;
    }
    ans += (run > 0);
    cout << ans << '\n';
}

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}