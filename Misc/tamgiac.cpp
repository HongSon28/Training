#include<bits/stdc++.h>
using namespace std;
int main() {
    float a;
    cin>>a;
    float p=3*a/2;
    float s=sqrt(p*(p-a)*(p-a)*(p-a));
    float r=s/p;
    float s2=r*r*3.14;
    cout.precision(2);
    cout<<fixed<<s-s2;
}
