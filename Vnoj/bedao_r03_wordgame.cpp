#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<string>s;
    string last;
    cin>>last;
    s.insert(last);
    for (int i=2;i<=n;i++) {
        string t;
        cin>>t;
        if (t[0]!=last[last.size()-1]||s.count(t)>0) {
            cout<<"NO"<<endl<<i;
            return 0;
        }
        last=t;
        s.insert(t);
    }
    cout<<"YES";
}
