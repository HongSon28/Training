#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int res;
int main() {
    cin>>a>>b>>c>>d;
    for (int i=0;i<=100;i++) {
        if ((a<=i&&i<b)||(c<=i&&i<d)) res++;
    }
    cout<<res;
}
