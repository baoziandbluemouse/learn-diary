#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> score(n);
    for (int i = 0; i < n; i++) {
        int A, B;
        cin >> A >> B;
        score[i] += A - B;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    multiset<int> s;
    for (int i = n - 1; i >= 0; i--) {
        auto pos = s.upper_bound(score[p[i]]);
        if (pos != s.end()) {
            s.erase(pos);
        }

        s.insert(score[p[i]]);
    }

    int ans = n - s.size();

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

