#include<bits/stdc++.h>
using namespace std;
int main() {
    double BC,AC;
    cout<<"Nhap BC, AC ";
    cin>>BC>>AC;
    double AB=sqrt(BC*BC-AC*AC);
    double BH=AB*AB/BC;
    double CH=BC-BH;
    double AH=sqrt(AB*AB-BH*BH);
    cout<<endl<<"AB = "<<AB<<endl;
    cout<<"AH = "<<AH<<endl;
    cout<<"BH = "<<BH<<endl;
    cout<<"CH = "<<CH;
}
