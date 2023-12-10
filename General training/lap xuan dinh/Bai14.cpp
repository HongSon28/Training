#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int t;
    unsigned int nam,gia,dung;
    unsigned int x, y, co, socach;
    unsigned int b[1000];
    cin>>t;
    unsigned int n=2*t;
    unsigned int a[n];
    unsigned int sobo=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0; i<n; i=i+2) {
        x=a[i];
        y=a[i+1];
        co=3*y-x;
        socach=0;
        nam=0;
        for(dung=0;dung<=co;dung++) {
            if ((co-(14*dung))%8==0) {
                nam=(co-(14*dung))/8;
                gia=x-dung-nam;
                if ((5*dung+3*nam+gia/3==y)&&(gia%3==0)) {
                    socach=socach+1;
                    sobo=socach*3;
                    b[sobo-1]=gia;
                    b[sobo-2]=nam;
                    b[sobo-3]=dung;
                }
            }
        }
        cout<<socach<<endl;
        for (int j=0;j<socach*3;j=j+1) {
            cout<<b[j]<<" ";
        if((j+1)%3==0) {
            cout<<endl;
        }
        }
    }
}
