#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int tong;
    int tc=0;
    int tl=0;
    for (int i=1;i<=100-n;i++) {
        tong=(i+n+i-1)*n/2;
        if (tong%2==0)
            tc+=1;
        else
            tl+=1;
    }
    if ((tc>=1)&&(tl==0))
        cout<<"0";
    else if ((tl>=1)&&(tc==0))
        cout<<"1";
    else
        cout<<"2";
}
