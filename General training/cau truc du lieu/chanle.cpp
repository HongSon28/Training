#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> le;
    queue<int> chan;
    int n;
    cin>>n;
    int temp;
    for (int i=0;i<n;i++) {
        cin>>temp;
        if (temp%2==1)
            le.push(temp);
        else
            chan.push(temp);
    }
    while (le.empty()==false) {
        cout<<le.top()<<' ';
        le.pop();
    }
    while (chan.empty()==false) {
        cout<<chan.front()<<' ';
        chan.pop();
    }
}
