#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int T, n;
int q[N];

void bubble_sort(){
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> q[i];
    for(int i = 1; i < n; i ++)
        if(q[i] < q[i - 1]) swap(q[i], q[i - 1]);
    for(int i = 0; i < n; i ++)
        cout << q[i] << " ";
    cout << endl;
}

int main(){
    cin >> T;
    while(T --){
        bubble_sort();
    }
    return 0;
}