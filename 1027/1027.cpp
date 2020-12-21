#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100, M = 20010, INF = 0x3f3f3f3f;

int n;
struct Node{
    int a, b, w;
};

void solve()
{
  cin >> n;
  vector<Node> v(n);
  for(int i = 0; i < n; i ++){
      int a, b, c;
      cin >> a >> b >> c;
      v[i] = {a, b, c};
  }
  sort(v.begin(), v.end(), [&](Node u, Node v){
      if(u.b != v.b) return u.b < v.b;
      else return u.w > v.w;
  });
  vector<int> dp(n);
  for(int i = 0; i < n; i ++){
      dp[i] = v[i].w;
      int MAX = 0;
      for(int j = 0; j < i; j ++){
          if(v[j].b <= v[i].a) MAX = max(MAX, dp[j]);
      }
      dp[i] += MAX;
  }
  int res = -1;
  for(int i = 0; i < n; i ++)
    res = max(res, dp[i]);
  
  cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}