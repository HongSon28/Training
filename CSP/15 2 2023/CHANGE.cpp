#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("CHANGE.INP","r",stdin);
    freopen("CHANGE.OUT","w",stdout);
    string s;
    cin>>s;
    int c=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='L') c--;
        else c++;
    }
    if (c<0) {
        c=abs(c);
        c%=8;
        queue<int>q;
        for (int i=1;i<=8;i++) q.push(i);
        for (int i=1;i<=c;i++) {
            int t=q.front();
            q.pop();
            q.push(t);
        }
        while (q.empty()==false) {
            cout<<q.front();
            q.pop();
        }
    } else {
        c%=8;
        deque<int>q;
        for (int i=1;i<=8;i++) q.push_back(i);
        for (int i=1;i<=c;i++) {
            int t=q.back();
            q.pop_back();
            q.push_front(t);
        }
        while (q.empty()==false) {
            cout<<q.front();
            q.pop_front();
        }
    }
}
