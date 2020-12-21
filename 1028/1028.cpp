#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;

int g[N][N];
int d[N];
bool st[N];
int n, m, s, t;

int dijkstra(){
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    for (int i = 0; i < n; i ++){
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j ++){
            if(!st[j] && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        st[u] = true;
        for (int j = 1; j <= n; j ++)
            d[j] = min(d[j], d[u] + g[u][j]);
    }
    if(d[t] == INF)
        return -1;
    return d[t];
}

void solve(){
    memset(g, 0x3f, sizeof g);
    memset(st, false, sizeof st);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}