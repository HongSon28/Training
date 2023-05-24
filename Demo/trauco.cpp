#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int a[t];
    int b[t];
    int dung, nam , gia;
    int td[1000], tn[1000], tg[1000];
    for (int i=0;i<t;i++) {
        cin>>a[i]>>b[i];
    }
    for (int i=0;i<t;i++) {
        unsigned dem=0;
        for (dung=0;dung<a[i];dung++) {
            for (nam=a[i]-dung;nam>=0;nam--) {
                gia=(b[i]-dung*5-nam*3)*3;
                if (gia+dung+nam==a[i]) {
                    td[dem]=dung;
                    tn[dem]=nam;
                    tg[dem]=gia;
                    dem+=1;
                }
            }
        }
        cout<<dem<<endl;
        for (int i=0;i<dem;i++) {
            cout<<td[i]<<" "<<tn[i]<<" "<<tg[i]<<endl;
        }
    }
}
