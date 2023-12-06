#include<bits/stdc++.h>
using namespace std;
#define mm 100000
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int t[k],d[k],a[k];
    int thia[mm],dua[mm];
    fill(thia,thia+mm,n);
    fill(dua,dua+mm,m);
    for (int i=0;i<k;i++) {
        cin>>t[i]>>d[i]>>a[i];
        if (a[i]==0) {
            if (thia[t[i]]>0) {
                cout<<"Yes"<<endl;
                for (int j=t[i];j<t[i]+d[i];j++) {
                    thia[j]--;
                }
            } else {
                cout<<"No"<<endl;
            }
        } else {
            if (thia[t[i]]>0&&dua[t[i]]>0) {
                cout<<"Yes"<<endl;
                for (int j=t[i];j<t[i]+d[i];j++) {
                    thia[j]--;
                    dua[j]--;
                }
            } else {
                cout<<"No"<<endl;
            }
        }
    }
}
