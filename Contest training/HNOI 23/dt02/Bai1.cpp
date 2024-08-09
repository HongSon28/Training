#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("Digits.inp");
    ofstream out("Digits.out");
    int t;
    inp>>t;
    int kq[t];
    for (int i=0;i<t;i++) {
        int a;
        inp>>a;
        while (a>=10) {
            int tong=0;
            int temp=a;
            while (temp!=0) {
                tong+=temp%10;
                temp/=10;
            }
            a=tong;
        }
        kq[i]=a;
    }
    for (int i=0;i<t;i++) {
        out<<kq[i]<<endl;
    }
}
