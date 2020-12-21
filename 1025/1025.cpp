#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 10010, INF = 0x3f3f3f3f, NINF = -INF - 1;
    
int n;
int q[N], res[N];
    
void solve()
{
    // memset(q, 0, sizeof q);
    // memset(res, 0, sizeof res);
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> q[i];
    res[0] = -INF;
    int len = 0;
    for(int i = 0; i < n; i ++){
        int l = 0, r = len;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(res[mid] <= q[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        res[r + 1] = q[i];
    }
    cout << len << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}