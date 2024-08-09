#include<bits/stdc++.h>
using namespace std;
int main() {
    int v,n;
    cin>>v>>n;
    if (v==1) {
        int res=0;
        while (n>0) {
            switch(n%10) {
                case 0:
                    res+=6;
                    break;
                case 1:
                    res+=2;
                    break;
                case 2:
                    res+=5;
                    break;
                case 3:
                    res+=5;
                    break;
                case 4:
                    res+=4;
                    break;
                case 5:
                    res+=5;
                    break;
                case 6:
                    res+=6;
                    break;
                case 7:
                    res+=3;
                    break;
                case 8:
                    res+=7;
                    break;
                case 9:
                    res+=6;
                    break;
                default:
                    break;
            }
            n/=10;
        }
        cout<<res;
    } else {

    }
}
