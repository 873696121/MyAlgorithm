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

const int N = 1e5 + 10, M = 20010, INF = 0x3f3f3f3f;

int n;
vector<PII> res;
vector<PII> points;
multiset<int> heights;

void solve()
{
    cin >> n;
    for(int i = 0; i < n;i ++){
        int a, b, c;
        cin >> a >> b >> c;
        points.push_back({a, -c});
        points.push_back({b, c});
    }
    sort(points.begin(), points.end());
    heights.insert(0);
    for(auto& c : points){
        int t = c.first, h = abs(c.second);
        if(c.second < 0) {
            // 左端点
            if(h > *heights.rbegin()){
                res.push_back({t, h});
            }
            heights.insert(h);
        }else{
            heights.erase(heights.find(h));
            if(h > *heights.rbegin()){
                res.push_back({t, *heights.rbegin()});
            }
        }
    }
    for(auto c : res){
        cout << c.first << " " << c.second << endl;
    }
}

int main(){
    solve();
    return 0;
}