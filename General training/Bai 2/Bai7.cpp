#include<bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cout<<"Nhap N ";
    cin>>N;
    int nghin=N/1000;
    int tram=(N-(1000*nghin))/100;
    int chuc=(N-(1000*nghin)-(100*tram))/10;
    int donvi=(N-(1000*nghin)-(100*tram)-(10*chuc));
    cout<<endl<<"Hang nghin la "<<nghin<<endl;
    cout<<"Hang tram la "<<tram<<endl;
    cout<<"Hang chuc la "<<chuc<<endl;
    cout<<"Hang don vi la "<<donvi;
}
