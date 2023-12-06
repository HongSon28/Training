#include<bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin>>m;
    stack<int>s;
    if (m==0) {
        cout<<10;
        return 0;
    }
    for (int i=9;i>=2;i--) {
        while (m%i==0) {
            m/=i;
            s.push(i);
        }
        if (m==1) break;
    }
    if (m!=1) {
        cout<<-1;
    } else {
        while (!s.empty()) {
            cout<<s.top();
            s.pop();
        }
    }
}
