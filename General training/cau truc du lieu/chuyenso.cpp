#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    while (k>=n) {
        k-=n;
    }
    queue<int>q;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        q.push(temp);
    }
    for (int i=0;i<k;i++) {
        int temp=q.front();
        q.pop();
        q.push(temp);
    }
    for (int i=0;i<n;i++) {
        cout<<q.front()<<' ';
        q.pop();
    }
}
