#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,res=0;
    cin>>n;
    vector<int>a,b;
    for (int i=0;i<n;i++) {
        int t1,t2;
        cin>>t1>>t2;
        a.push_back(t1);
        b.push_back(t2);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    while (i<b.size()) {
        int mn=0,pos;
        bool ch=false;
        for (int j=0;j<a.size();j++) {
            if (a[j]<b[i]) {
                mn=max(mn,a[j]);
                pos=j;
            }
        }
        if (mn!=0) {
            res+=2;
            a.erase(a.begin()+pos);
            b.erase(b.begin()+i);
        } else i++;
    }
    //cout<<res<<endl;
    i=0;
    while (i<b.size()) {
        int pos=-1;
        for (int j=0;j<a.size();j++) {
            if (b[i]==a[j]) {
                pos=j;
            }
        }
        if (pos!=-1) {
            res++;
            a.erase(a.begin()+pos);
            b.erase(b.begin()+i);
        } else i++;
    }
    cout<<res;
}
