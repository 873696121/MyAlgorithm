#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, M = 10010, INF = 0x3f3f3f3f;

int n;
int q[N], dp[N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> q[i];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j ++){
            if(q[i] < q[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
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