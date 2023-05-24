#include<bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    cout<<"Nhap a, b, c ";
    cin>>a>>b>>c;
    double delta = b*b-4*a*c;
    double x1 = (-b+sqrt(delta))/2/a;
    double x2 = (-b-sqrt(delta))/2/a;
    cout<<endl<<"Delta = "<<delta<<endl;
    cout<<"Cac nghiem cua phuong trinh la "<<x1<<" "<<x2;
}
