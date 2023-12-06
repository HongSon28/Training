#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,k;
    deque<int>dq;
    cin>>m>>k;
    for (int i=0;i<m;i++) dq.push_back(i);
    string s;
    cin>>s;
    for (int i=0;i<s.size()-1;i++) {
        if (s[i]=='A') {
            int t=dq.front();
            //cout<<t<<endl;
            dq.pop_front();
            dq.push_back(t);
        } else {
            int t1=dq.front();
            dq.pop_front();
            int t2=dq.front();
            //cout<<t1<<' '<<t2<<endl;
            dq.pop_front();
            dq.push_back(t2);
            dq.push_front(t1);
        }
    }
    for (int i=1;i<=k-1;i++) {
        //cout<<dq.back() <<' ';
        dq.pop_front();
    }
    cout<<dq.front()<<' ';
    dq.pop_front();
    cout<<dq.front()<<' ';
    dq.pop_front();
    cout<<dq.front();
}
