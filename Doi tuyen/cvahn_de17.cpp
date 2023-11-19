#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int res=101;
int main() {
    cin>>n>>s;
    s=' '+s;
    for (int len=1;len<=n;len++) {
        set<string>st;
        bool flag=true;
        for (int i=1;i<=n-len+1;i++) {
            string t=s.substr(i,len);
            if (st.count(t)!=0) {
                flag=false;
                break;
            }
            st.insert(t);
        }
        if (flag) res=min(res,len);
    }
    cout<<res;
}
