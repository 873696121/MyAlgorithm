#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 60, M = 1e4, INF = 0x3f3f3f3f;

int match[N];
int h[N], e[M], ne[M], idx;
bool st[N];
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int u){
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(!match[j] || find(match[j])){
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    memset(h, -1, sizeof h);
    memset(match, 0, sizeof match);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        int k;
        cin >> k;
        while(k --){
            int t;
            cin >> t;
            add(i, t);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++){
        memset(st, false, sizeof st);
        if(find(i)) res ++;
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