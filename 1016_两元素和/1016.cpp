#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 50010, M = 20010, INF = 0x3f3f3f3f;

int n, k;
int v[N];

void solve()
{
    int t;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> v[i];
    unordered_map<int, bool> st;
    bool flag = false;
    for(int i = 0; i < n; i ++){
        t = v[i];
        if(st[k - t]) {
            puts("yes");
            return;
        }
        st[t] = true;
    }
    puts("no");
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}
