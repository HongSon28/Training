#include<bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    bool kq[10000];
    int tt=0;
    while (a!="END"&&b!="END") {
        int dem1[123]={};
        int dem2[123]={};
        int n1=a.length();
        int n2=b.length();
        for (int i=0;i<n1;i++) {
            dem1[a[i]]++;
        }
        for (int i=0;i<n2;i++) {
            dem2[b[i]]++;
        }
        int dem=0;
        for (int i=97;i<=122;i++) {
            if (dem1[i]==dem2[i])
                dem++;
        }
        if (dem==26)
            kq[tt]=true;
        else
            kq[tt]=false;
        tt++;
        cin>>a>>b;
    }
    for (int i=0;i<tt;i++) {
        if (kq[i]==true)
            cout<<"same"<<endl;
        else
            cout<<"different"<<endl;
    }
}
