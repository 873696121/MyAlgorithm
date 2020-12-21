#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1e5 + 10, M = 20010, INF = 0x3f3f3f3f;

int q[N], temp[N];
int n;

int merge_sort(int q[], int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    int res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k ++] = q[i ++];
        else {
            temp[k ++] = q[j ++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) temp[k ++] = q[i ++];
    while(j <= r) temp[k ++] = q[j ++];
    for(int i = l, j = 0; i <= r; i ++, j ++) q[i] = temp[j];
    return res;
}

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> q[i];
    cout << merge_sort(q, 0, n - 1) << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}