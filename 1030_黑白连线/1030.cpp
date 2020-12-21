#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1e5 + 10, M = 20010, INF = 0x3f3f3f3f;

int n;
int q[N];
bool st[N];

void solve()
{
    memset(st, false, sizeof st);
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i ++)
        cin >> q[i];
    int res = 0;
    // 贪心
    // 对于每个未配对的棋子i，从后找出第一个未配对的且能和i配对的j
    for(int i = 0; i < n; i ++){
        if(!st[i]){
            for(int j = i + 1; j < n; j ++){
                if(!st[j] && q[i] != q[j]){
                    res += j - i;
                    st[i] = true;
                    st[j] = true;
                    break;
                }
            }
        }
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