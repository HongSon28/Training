#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
vector<string>v;
queue<int>q;
stack<int>st;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        q.push(i);
    }
    for (int i=1;i<=n;i++) {
        while ((q.front()!=a[i])&&(st.empty()||st.top()!=a[i])) {
            if (!q.empty()) {
                v.push_back("A->B");
                //cout<<"A->B"<<endl;
                st.push(q.front());
                q.pop();
            } else break;
        }
        if (!q.empty()&&q.front()==a[i]) {
            v.push_back("A->C");
            //cout<<"A->C"<<endl;
            q.pop();
        } else if (!st.empty()&&st.top()==a[i]) {
            v.push_back("B->C");
            //cout<<"B->C"<<endl;
            st.pop();
        } else {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
