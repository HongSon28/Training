#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double w,h;
    cin>>n>>w>>h;
    double mx=sqrt(w*w+h*h);
    while (n--) {
        double temp;
        cin>>temp;
        if (temp<=mx) cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
}
