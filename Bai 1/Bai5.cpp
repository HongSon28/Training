#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    cout<<"Nhap do dai 3 canh ";
    cin>>a>>b>>c;
    cout<<endl<<"Chu vi tam giac la "<<a+b+c<<endl;
    double p=(a+b+c)/2;
    cout<<"Dien tich tam giac la "<<sqrt(p*(p-a)*(p-b)*(p-c));
}

