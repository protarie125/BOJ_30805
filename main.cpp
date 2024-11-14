#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

ll N, M;
vl A, B;
vb visA, visB;
vl ans;

void solve(ll a, ll b) {
  if (a == N || b == M) return;

  ll mx = 0;
  ll mxi = -1;
  for (auto i = a; i < N; ++i) {
    if (visA[i]) continue;

    if (mx < A[i]) {
      mx = A[i];
      mxi = i;
    }
  }

  if (mxi == -1) return;

  ll my = 0;
  ll myi = -1;
  for (auto i = b; i < M; ++i) {
    if (visB[i]) continue;

    if (my < B[i]) {
      my = B[i];
      myi = i;
    }
  }

  if (myi == -1) return;

  if (mx == my) {
    ans.push_back(mx);
    solve(mxi + 1, myi + 1);
  } else if (mx > my) {
    visA[mxi] = true;
    solve(a, b);
  } else {
    visB[myi] = true;
    solve(a, b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  A = vl(N);
  for (auto&& a : A) cin >> a;
  visA = vb(N, false);

  cin >> M;
  B = vl(M);
  for (auto&& b : B) cin >> b;
  visB = vb(M, false);

  solve(0, 0);

  cout << ans.size() << '\n';
  for (const auto& x : ans) {
    cout << x << ' ';
  }

  return 0;
}