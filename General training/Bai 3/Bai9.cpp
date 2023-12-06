#include<bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    cout.precision(3);
    cout<<"Nhap a, b, c ";
    cin>>a>>b>>c;
    cout<<fixed<<endl<<"a. "<<a*a-2*b+a*b/c<<endl;
    cout<<fixed<<"b. "<<(b*b-4*a*c)/2/a<<endl;
    cout<<fixed<<"c. "<<3*a-b*b*b-2*sqrt(c)<<endl;
    cout<<fixed<<"d. "<<sqrt(a*a/b-4*a/b/c+1);
}
