#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 310, M = N * N, INF = 0x3f3f3f3f;

int n, m;
int cnt[N];
int h[N], e[M], ne[M], idx;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topsort(){
    queue<int> q;
    for(int i = 1; i <= n; i ++)
        if(!cnt[i])
            q.push(i);
    vector<int> res;
    while(q.size()){
        auto t = q.front();
        q.pop();
        res.push_back(t);
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            cnt[j] --;
            if(!cnt[j]) q.push(j);
        }
    }
    if(res.size() != n) cout << 0 << endl;
    else {
        for(auto c : res)
            cout << c << " ";
        cout << endl;
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    memset(cnt, 0, sizeof cnt);
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        cnt[b] ++;
    }
    topsort();
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}