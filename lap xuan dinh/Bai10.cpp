#include<bits/stdc++.h>
using namespace std;
int main () {
    unsigned int n;
    unsigned int j;
    unsigned int cv[100];
    cin>>n;
    for(int i=sqrt(n); i>=1;i--) {
        if(n%i==0) {
            j=n/i;
            cout<<(j+i)*2;
            break;
        }
    }
}
