#include <bits/stdc++.h>

using namespace std;

#define PB push_back

#define LPI(i, a, b, d) for (int i{a}; i < b; i += d)
#define LL_MAX 9223372036854775807

using VI = vector<int>;

void scan(VI nums, int k, int an) {
    LPI(i, 0, k, 1) {
        unordered_map<int, int> v{};
        LPI(j, 0, nums.size(), 1) {
            if (v[nums[j]] == 0) {
                v[nums[j]] = 1;
            } else {
                v[nums[j]] += 1;
            }
        }
        LPI(j, 0, nums.size(), 1) {
            v[nums[j]];
            nums[j] = v[nums[j]];
        }
    }
    cout << nums[an - 1] << '\n';
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t > 0) {
        int n, q;
        VI nums;
        cin >> n;
        LPI(i, 0, n, 1) {
            int an;
            cin >> an;
            nums.PB(an);
        }
        cin >> q;
        while (q > 0) {
            int x, k;
            cin >> x >> k;
            int log = log10(n);
            if (k > n) {
                if (log >= 1) {
                    k = ++log;
                } else {
                    k = n;
                }
            }
            scan(nums, k, x);
            --q;
        }

        --t;
    }

    return 0;
}
