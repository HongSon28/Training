#include<bits/stdc++.h>
using namespace std;
int demuoc(int a) {
    int dem=0;
    for (int i=1;i<=a;i++) {
        if (a%i==0)
            dem++;
    }
    return dem;
}
int main() {
    ifstream inp("uocso.inp");
    ofstream out("uocso.out");
    int a,b;
    inp>>a>>b;
    int sl=1;
    int mn;
    int ct=0;
    int c[b];
    for (int i=a;i<=b;i++) {
        c[i]=demuoc(i);
        if (c[i]>sl) {
            sl=c[i];
            mn=i;
        }
    }
    for (int i=a;i<=b;i++) {
        if (c[i]==sl)
            ct++;
    }
    out<<mn<<" "<<sl<<" "<<ct;
}
