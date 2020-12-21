#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1010, M = 20010, INF = 0x3f3f3f3f;

int n, m;

// 在v1从i开始，v2从j开始的数组中，找到第k小的元素
int find(vector<int>& v1, int i, vector<int>& v2, int j, int k){
        int n = v1.size(), m = v2.size();
        if(n - i > m - j) 
            return find(v2, j, v1, i, k);
        if(k == 1){
            if(i == n) 
                return v2[j];
            else
                return min(v1[i], v2[j]);
        }
        if(i == n)
            return v2[j + k - 1];
        int si = min(n, i + k / 2), sj = j + k / 2;
        if(v1[si - 1] < v2[sj - 1])
            return find(v1, si, v2, j, k - (si - i));
        else 
            return find(v1, i, v2, sj, k - (sj - j));
    }

void solve()
{
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for(int i = 0; i < n; i ++)
        cin >> v1[i];
    for(int i = 0; i < m; i ++)
        cin >> v2[i];
    int total = n + m;
    if(total % 2 == 0){
        int left = find(v1, 0, v2, 0, total / 2);
        int right = find(v1, 0, v2, 0, total / 2 + 1);
        cout << (double)(left + right) / 2.0 << endl;
    }else{
        cout << find(v1, 0, v2, 0, total / 2 + 1) << endl;
    }
}

int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}
