#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100, M = 20010, INF = 0x3f3f3f3f;

long long dp[N][N];
int q[N];
int n, k;
long long sum[N];

void solve()
{
    memset(q, 0, sizeof q);
    memset(sum, 0, sizeof sum);
    memset(dp, 0, sizeof dp);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> q[i];
        sum[i] = q[i] + sum[i - 1];
        // 边界处理，若无乘号即前缀和
        dp[i][0] = sum[i];
    }
    // dp[i][j] 表示前i个数插入j个乘号的最大值
    for(int i = 2; i <= n; i ++){
        for(int j = 1; j <= min(i - 1, k); j ++){ // 遍历乘号个数
            for(int l = 2; l <= i; l ++){ // 遍历插入乘号的位置
                dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] * (sum[i] - sum[l - 1]));
            }
        }
    }
    cout << dp[n][k] << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}