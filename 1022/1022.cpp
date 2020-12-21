#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 510, M = 20010, INF = 0x3f3f3f3f;

string a, b;
int n, m;
int f[N][N];
// f[i][j] 表示a[1~i]与b[1~j]的最长公共子序列长度

void solve()
{
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = "0" + a;
    b = "0" + b;
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i] == b[j])
                f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
        }
    }
    cout << f[n][m] << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}
