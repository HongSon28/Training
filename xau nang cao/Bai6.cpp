#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string kq[n];
    for (int i=0;i<n;i++) {
        string s,t;
        cin>>s>>t;
        string a=s,b=t;
        while (s.size()!=t.size()) {
            if (s.size()<t.size()) {
                s+=a;
            }  else {
                t+=b;
            }
        }
        if (s==t)
            kq[i]=s;
        else
            kq[i]="-1";
    }
    for (int i=0;i<n;i++)
        cout<<kq[i]<<endl;
}
