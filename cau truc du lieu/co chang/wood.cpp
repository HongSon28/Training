#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>>q;
        for (int j=0;j<n;j++) {
            int t;
            cin>>t;
            q.push(t);
        }
        long long res=0;
        for (int j=1;j<n;j++) {
            int x=q.top();
            q.pop();
            int y=q.top();
            res+=x+y;
            q.pop();
            q.push(x+y);
        }
        cout<<res;
    }
}
