#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int>q;
    char temp;
    while (cin>>temp) {
        if (temp=='-'&&q.empty()==false) {
            int t=q.top();
            while (q.top()==t) q.pop();
        }
        if (temp=='+') {
            int t;
            cin>>t;
            q.push(t);
        }
    }
    cout<<q.size()<<'\n';
    while (q.empty()==false) {
        cout<<q.top()<<' ';
        q.pop();
    }
}
