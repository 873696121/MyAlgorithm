#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1e5 + 10, M = 20010, INF = 0x3f3f3f3f;

int q[N];
int n, tail;

void down(int k){
    int u = k;
    if(2 * k <= tail && q[2 * k] < q[u]) u = 2 * k;
    if(2 * k + 1 <= tail && q[2 * k + 1] < q[u]) u = 2 * k + 1;
    if(u != k) {
        swap(q[u], q[k]);
        down(u);
    }
}

void solve()
{
    cin >> n;
    tail = n;
    for(int i = 1; i <= n; i ++)
        cin >> q[i];
    for(int i = n / 2; i ; i --) down(i);
    for(int i = 1; i <= n; i ++)
        cout << q[i] << " ";
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}
