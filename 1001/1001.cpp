#include <iostream>

using namespace std;

int n;
string s;

int main(){
    scanf("%d\n", &n);
    while(n --){
        getline(cin, s);
        int cnt = 0;
        for(auto c : s) 
            if(c >= '0' && c <= '9') cnt ++;
        cout << cnt << endl;
    }
    return 0;
}