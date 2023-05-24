#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a=0,b=0;
    string s;
    cin>>s;
    int h=0;
    for (int i=0;i<n;i++) {
        if (s[i]=='G') {
            if (h==0) {
                a++;
            } else if (h==1) {
                b++;
            } else if (h==2) {
                a--;
            } else {
                b--;
            }
        } else if (s[i]=='L') {
            h--;
            if (h<0) {
                h+=4;
            }
            if (h==0) {
                a++;
            } else if (h==1) {
                b++;
            } else if (h==2) {
                a--;
            } else {
                b--;
            }
        } else if (s[i]=='R') {
            h++;
            if (h>=4) {
                h-=4;
            }
            if (h==0) {
                a++;
            } else if (h==1) {
                b++;
            } else if (h==2) {
                a--;
            } else {
                b--;
            }
        } else {
            h+=2;
            if (h>=4)
                h-=4;
            if (h==0) {
                a++;
            } else if (h==1) {
                b++;
            } else if (h==2) {
                a--;
            } else {
                b--;
            }
        }
    }
    cout<<b<<" "<<a;
}
