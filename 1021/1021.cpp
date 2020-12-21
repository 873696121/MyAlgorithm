#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e4 + 10, M = 1e4, INF = 0x3f3f3f3f;

void solve(){
    int f[N];
    int n, m;
    cin >> n >> m;
    vector<PII> value(m);
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        value[i] = {a, b};
    }
    sort(value.begin(), value.end());
    for(int i = 1; i <= n; i ++){
        int MAX = 0;
        for(auto c : value){
            int a = c.first, b = c.second;
            if(i >= a){
                MAX = max(MAX, f[i - a] + b);
            }else{
                break;
            }
        }
        f[i] = MAX;
    }
    cout << f[n] << endl;
}


int main(){
    int T;
    cin >> T;
    while(T --)
        solve();
    return 0;
}