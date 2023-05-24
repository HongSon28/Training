#include<bits/stdc++.h>
using namespace std;
int main () {
    double x1, x2, x3, y1, y2, y3;
    cout<<"Nhap x1, y1 ";
    cin>>x1>>y1;
    cout<<endl<<"Nhap x2, y2 ";
    cin>>x2>>y2;
    cout<<endl<<"Nhap x3, y3 ";
    cin>>x3>>y3;
    double AB=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double AC=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double BC=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double p=(AB+BC+AC)/2;
    cout<<endl<<"Dien tich tam giac la "<<sqrt(p*(p-AB)*(p-BC)*(p-AC))<<endl;
    cout<<"Chu vi tam giac la "<<p*2;
}
