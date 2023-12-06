#include<bits/stdc++.h>
using namespace std;
struct hs {
    string ten, gioitinh, ngaysinh;
    double toan, van, tin;
};
int main() {
    int n;
    cin>>n;
    hs a[n];
    for (int i=0;i<n;i++) {
        cin.ignore();
        getline(cin,a[i].ten);
        getline(cin,a[i].ngaysinh);
        cin>>a[i].gioitinh;
        cin>>a[i].toan>>a[i].van>>a[i].tin;
    }
    for (int i=0;i<n;i++) {
        cout<<a[i].ten<<" "<<a[i].ngaysinh<<" "<<a[i].gioitinh<<" "<<a[i].toan<<" "<<a[i].van<<" "<<a[i].tin<<" "<<a[i].toan+a[i].van+a[i].tin<<" ";
        if (a[i].toan+a[i].van+a[i].tin>=15&&a[i].toan>=2&&a[i].van>=2&&a[i].tin>=2) {
            cout<<"do"<<endl;
        } else {
            cout<<"truot"<<endl;
        }
    }
    for (int i=0;i<n;i++) {
        if (a[i].toan+a[i].van+a[i].tin>=15&&a[i].toan>=2&&a[i].van>=2&&a[i].tin>=2) {
            cout<<a[i].ten<<" "<<a[i].ngaysinh<<" "<<a[i].gioitinh<<" "<<a[i].toan<<" "<<a[i].van<<" "<<a[i].tin<<" "<<a[i].toan+a[i].van+a[i].tin<<" "<<"do"<<endl;
        }
    }
    for (int i=0;i<n;i++) {
        if (a[i].toan+a[i].van+a[i].tin>=24&&a[i].toan>=8&&a[i].van>=8&&a[i].tin>=8) {
            cout<<a[i].ten<<" "<<a[i].ngaysinh<<" "<<a[i].gioitinh<<" "<<a[i].toan<<" "<<a[i].van<<" "<<a[i].tin<<" "<<a[i].toan+a[i].van+a[i].tin<<" "<<"do"<<endl;
        }
    }
}
