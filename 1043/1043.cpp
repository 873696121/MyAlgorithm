#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

// const int N = 1e5 + 10, M = 20010, INF = 0x3f3f3f3f;

int N, K;

void solve()
{
    cin >> K >> N;
    vector<int> dp(K + 1);
	int res = 0;
	for (; dp[K] < N; ++res) {
		for (int i = K; i > 0; --i) {
			dp[i] = dp[i] + dp[i - 1] + 1;
		}
	}
	cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}