#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 20010, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int d[N];
bool st[N];

int prim(){
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j ++){
            if(!st[j] && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1)
            return -1;
        st[u] = true;
        res += d[u];
        for (int j = 1; j <= n; j ++)
            d[j] = min(d[j], g[u][j]);
    }
    return res;
}

void solve()
{
    memset(g, 0x3f, sizeof g);
    memset(st, false, sizeof st);
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    cout << prim() << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}