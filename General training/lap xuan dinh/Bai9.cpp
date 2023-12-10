#include<bits/stdc++.h>
using namespace std;
int main() {
    int gao;
    cin>>gao;
    int a,b;
    for (a=gao/5; a>=0; a--) {
        if((gao-a*5)%3==0) {
            b=(gao-a*5)/3;
            cout<<a+b;
            break;
        }
        if ((a==0)&&(gao%3!=0)) {
            cout<<"-1";
        }
    }
}
