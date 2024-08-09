#include<bits/stdc++.h>
#define ll long long
using namespace std;
stack<int>s;
ll y;
ll ex[10];
int main() {
    cin>>y;
    ex[0]=1;
    for (ll i=1;i<=9;i++) ex[i]=ex[i-1]*i;
    while (y>0) {
        int i=9;
        while (ex[i]>y) i--;
        s.push(i);
        y-=ex[i];
    }
    while (!s.empty()) {
        cout<<s.top();
        s.pop();
    }
}
