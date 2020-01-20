#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int N, Q;
  cin >> N >> Q;
  int a[N - 1], b[N - 1];
  // 隣接リスト
  vector<int> adj[N];
  for (int i = 0; i < N - 1; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    adj[a[i]].push_back(b[i]);
    adj[b[i]].push_back(a[i]);
  }
  int p[Q];
  ll x[Q];
  ll c[N]{};
  for (int i = 0; i < Q; i++) {
    cin >> p[i] >> x[i];
    p[i]--;
    c[p[i]] += x[i];
  }
  ll t = 0;
  deque<int> q;
  q.push_back(0);
  int vis[N]{};
  vis[0] = 1;
  while(!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (int i : adj[u]) {
      if (vis[i] == 1) continue;
      vis[i] = 1; 
      c[i] += c[u];
      q.push_back(i);
    }
  }
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << c[i] << "\n";
    } else {
      cout << c[i] << " ";
    }
  }
  return 0;
}