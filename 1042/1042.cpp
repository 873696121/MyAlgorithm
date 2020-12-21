#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1010, M = 20010, INF = 0x3f3f3f3f;

void solve()
{
    vector<int> costs(3);
    vector<int> days;
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int t;
        cin >> t;
        days.push_back(t);
    }
    cin >> costs[0] >> costs[1] >> costs[2];
    int last = days.back();
    // dp[i]表示到第i天的花费(若买了从n到m天的票，则第m天付钱)
    vector<int> dp(last + 1);
    // 标记当天出行
    for(auto c : days)
        dp[c] = -1;
    for(int i = 1; i <= last; i ++){
        // 如果不出行，则延续昨天的花费
        if(!dp[i])
            dp[i] = dp[i - 1];
        else{
            int a = dp[i - 1] + costs[0];
            int b, c;
            if(i >= 7)
                b = dp[i - 7] + costs[1];
            // 如果在第7天以前也可以买7天的票
            else
                b = costs[1];
            if(i >= 30)
                c = dp[i - 30] + costs[2];
            else
                c = costs[2];
            dp[i] = min(a, b);
            dp[i] = min(dp[i], c);
        }
    }
    cout << dp[last] << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}
