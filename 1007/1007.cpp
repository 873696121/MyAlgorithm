#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 50, M = 20010, INF = 0x3f3f3f3f;

typedef long long ll;

int n, k;
ll f[N][N];
char q[N];

ll get(int l, int r){
    ll res = 0;
    for(int i = l; i <= r; i ++){
        res = res * 10 + q[i] - '0';
    }
    return res;
}

void solve()
{
    memset(f, 0, sizeof f);
    cin >> n >> k >> q + 1;
    ll temp = 0;
    for(int i = 1; i <= n; i ++){
        temp = temp * 10 + q[i] - '0';
        f[i][0] = temp;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= k; j ++){
            for(int p = 1; p < i; p ++){
                f[i][j] = max(f[i][j], f[p][j - 1] * get(p + 1, i));
            }
        }
    }
    cout << f[n][k] << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}