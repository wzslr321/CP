#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int n;
string s;
void solve() {
  cin >> n >> s;
  int ans = 0;
  char prev = s[0];
  int best_len = 0;
  int curr_len = s[0] == '.';
  if (n == 1 && s[0] == '.') {
    cout << 1 << '\n';
    return;
  }
  for (int i = 1; i < n; i++) {
    if (prev == '#' && s[i] == '#') continue;
    if (prev == '.' && (s[i] == '#' || i == n - 1)) {
      if (i == n - 1 && s[i] == '.') ++curr_len;
      if (curr_len > 1)
        ans += 2;
      else
        ans += 1;

      // ans += min(2., ceil(curr_len / 2.) + (curr_len % 2));
      curr_len = 0;
      prev = '#';
      continue;
    }
    prev = '.';
    ++curr_len;
    if (i == n - 1) {
      if (curr_len > 1)
        ans += 2;
      else
        ans += 1;
    }
    best_len = max(best_len, curr_len);
  }
  if (best_len > 2) {
    cout << "2\n";
    return;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
