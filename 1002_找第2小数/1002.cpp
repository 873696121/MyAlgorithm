#include <iostream>
#include <queue>

using namespace std;

int n;

int main(){
    cin >> n;
    while(n --){
        priority_queue<int, vector<int>, greater<int> > heap;
        int k;
        cin >> k;
        while(k --){
            int t;
            cin >> t;
            heap.push(t);
        }
        heap.pop();
        cout << heap.top() << endl;
    }
    return 0;
}