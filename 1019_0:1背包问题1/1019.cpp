#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

void solve()
{
    memset(f, 0, sizeof f);
    cin >> n >> V;
    for(int i = 1; i <= n; i ++)
        cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i ++)
        for(int j = V; j >= 0; j --)
            if(j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[V] << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}

