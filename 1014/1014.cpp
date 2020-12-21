#include <iostream>
#include <cstring>

using namespace std;

const int N = 51000, M = 20010, INF = 0x3f3f3f3f;

int n;
int dp[N];

void solve()
{
    cin >> n;
    int res = -INF;
    for(int i = 1; i <= n; i ++){
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i] + dp[i - 1]);
        res = max(res, dp[i]);
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