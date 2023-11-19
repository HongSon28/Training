#include<bits/stdc++.h>
using namespace std;
struct td {
    float x,y;
};
bool checkt(td a,td b) {
    if (a.x==b.x&&a.y==b.y)
        return true;
    return false;
}
bool check(td a,td b,td c) {
    float d1=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    float d2=sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y));
    float d3=sqrt((c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y));
    if (d1+d2==d3||d1+d3==d2||d2+d3==d1)
    {
        return true;
    }
    return false;
}
bool cat(td a, td b, td c, td d) {
    float a1=(a.y-b.y)/(a.x-b.x);
    float b1=a.y-a1*a.x;
    float c1=(c.y-d.y)/(c.x-d.x);
    float d1=c.y-c1*c.x;
    float nx=(d1-b1)/(a1-c1);
    float ny=a1*nx+b1;
    if (a.x>b.x)
        swap(a.x,b.x);
    if (a.y>b.y)
        swap(a.y,b.y);
    if (nx>a.x&&ny<b.x&&ny>a.y&&ny<b.y)
        return true;
    return false;
}
float length(td a, td b) {
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
float s(float a, float b, float c) {
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main() {
    ifstream inp("tugiac.inp");
    ofstream out("tugiac.out");
    td a,b,c,d;
    cout.precision(3);
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    if (checkt(a,b)==true||checkt(b,c)==true||checkt(c,d)==true||checkt(a,d)==true||checkt(a,c)==true||checkt(b,d)==true) {
        cout<<"0";
        return 0;
    }
    if (check(a,b,c)==true||check(b,c,d)==true||check(a,c,d)==true||check(a,b,d)==true) {
        cout<<"0";
        return 0;
    } else {
        if (cat(a,c,b,d)==true) {
            cout<<"1"<<endl;
            float ab=length(a,b),bc=length(b,c),cd=length(c,d),ad=length(a,d),ac=length(a,c);
            cout<<fixed<<s(ab,bc,ac)+s(ad,cd,ac);
        } else if (cat(a,b,c,d)==true) {
            cout<<"3";
        } else {
            cout<<"2"<<endl;
            float ab=length(a,b),bc=length(b,c),cd=length(c,d),ad=length(a,d),bd=length(b,d);
            cout<<fixed<<s(ab,ad,bd)+s(bc,cd,bd);
        }
    }
}
