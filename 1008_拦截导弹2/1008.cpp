#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, M = 10010, INF = 0x3f3f3f3f;

int n;
int q[N], dp1[N], dp2[N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> q[i];
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        dp1[i] = 1;
        dp2[i] = 1;
        for (int j = 0; j < i; j ++){
            if(q[i] < q[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
            if(q[i] > q[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
        res1 = max(res1, dp1[i]);
        res2 = max(res2, dp2[i]);
     }
    cout << res1 << " " << res2 << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}