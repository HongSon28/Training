#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long g,l;
    cin>>g>>l;
    if (__gcd(g,l)==1){
        cout<<"-1";
        return 0;
    } else {
        unsigned long long tich=g*l;
        for (unsigned long long i=sqrt(tich);i>=1;i--) {
            if (tich%i==0) {
                if (__gcd(i,tich/i)==g) {
                    cout<<i<<" "<<tich/i<<endl;
                    cout<<i+(tich/i);
                    return 0;
                }
            }
        }
    }
    cout<<"-1";
}

