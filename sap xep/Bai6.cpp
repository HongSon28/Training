#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    string x;
    cin>>x;
    int n=x.length();
    int soluong=1;
    string hv[n];
    hv[0]=x;
    for (int i=1;i<n;i++) {
        char temp=x[0];
        x.erase(0,1);
        x.push_back(temp);
        int demtemp=0;
        for (int j=0;j<soluong;j++) {
            if (x==hv[j]) {
                demtemp++;
            }
        }
        if (demtemp==0) {
            hv[i]=x;
            soluong++;
        }
    }
    sort(hv,hv+soluong);
    if (k>soluong) {
        cout<<"-1";
    } else {
        cout<<hv[k-1];
    }
}
