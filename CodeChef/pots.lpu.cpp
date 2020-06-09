#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, input;
        cin >> n >> m;

        vector<pair<int, int>> pots(n, make_pair(0, 0));

        for (auto &x : pots) cin >> x.first;
        for (int i = 0; i < m; i++) {
            cin >> input;
            pots[input - 1].second = -1;
        }

        for (auto x : pots)
            if (x.second != -1)
                cout << x.first << " ";
        for (auto x : pots)
            if (x.second == -1)
                cout << x.first << " ";

        cout << endl;
        }
    return 0;
}
