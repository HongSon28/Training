#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    cin>>n;
    short a[n][n];
    for (short i=0;i<n;i++) {
        for (short j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int mx=-100000000;
    short dong,cot,cao,rong;
    for (short i=0;i<=n-2;i++) {
        for (short j=0;j<=n-2;j++) {
            for (short p=i+1;p<n;p++) {
                for (short q=j+1;q<n;q++) {
                    int tong=0;
                    for (short r=i;r<=p;r++) {
                        for (short s=j;s<=q;s++) {
                                tong+=a[r][s];
                            }
                        }
                    if (mx<tong) {
                        mx=tong;
                        dong=i+1;
                        cot=j+1;
                        cao=p-i+1;
                        rong=q-j+1;
                    }
                }
            }
        }
    }
    cout<<dong<<" "<<cot<<" "<<cao<<" "<<rong<<endl;
    cout<<mx;
}
