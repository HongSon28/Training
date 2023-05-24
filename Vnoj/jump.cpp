#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    deque<int>dq;
    for (int i=1;i<=n;i++) dq.push_back(i);
    for (int i=1;i<=n;i++) {
        if (i%2==1) {
            cout<<dq.front()<<' ';
            dq.pop_front();
        } else {
            cout<<dq.back()<<' ';
            dq.pop_back();
        }
    }
}
