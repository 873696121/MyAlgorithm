#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1010, M = 20010, INF = 0x3f3f3f3f;

int m, n, target;
int q[N][N];

void solve()
{
    cin >> n >> m >> target;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> q[i][j];
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        if(q[i][j] == target) break;
        else if(q[i][j] < target) i ++;
        else j --;
    }
    if(q[i][j] == target) puts("true");
    else puts("false");
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}