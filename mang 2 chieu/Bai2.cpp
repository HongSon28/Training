#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int doimax=0;
    int diemmax=0;
    for (int i=0;i<n;i++) {
        int tong=0;
        for (int j=0;j<n;j++) {
            tong+=a[i][j];
        }
        if (tong>diemmax) {
            diemmax=tong;
            doimax=i;
        }
    }
    int demthang=0;
    int demhoa=0;
    int demthua=0;
    cout<<doimax+1<<" "<<diemmax<<" ";
    for (int i=0;i<n;i++) {
        if (a[doimax][i]==0)
            demthua+=1;
        else if (a[doimax][i]==1)
            demhoa+=1;
        else
            demthang+=1;
    }
    int demb=0;
    int demc=0;
    cout<<demthang<<" "<<demhoa<<" "<<demthua-1<<endl;
    for (int i=0;i<n;i++) {
        if (i!=doimax) {
            int tong=0;
            for (int j=0;j<n;j++) {
                tong+=a[i][j];
            }
            if (tong==diemmax) {
                cout<<i+1<<" "<<diemmax<<" ";
                demthang=0;
                demhoa=0;
                demthua=0;
                for (int k=0;k<n;k++) {
                    if (a[i][k]==0) {
                        demthua+=1;
                    } else if (a[i][k]==1) {
                        demhoa+=1;
                    } else {
                        demthang+=1;
                    }
                }
                cout<<demthang<<" "<<demhoa<<" "<<demthua-1<<endl;
            }
        }
    }
    for (int i=0;i<n;i++) {
        demthang=0;
        demhoa=0;
        demthua=0;
        for (int j=0;j<n;j++) {
            if (a[i][j]==0)
                demthua+=1;
            else if (a[i][j]==1)
                demhoa+=1;
            else
                demthang+=1;
        }
        if (demthang>demthua-1) {
            cout<<i+1<<" ";
            demb+=1;
        }
    }
    if (demb==0)
        cout<<"0";
    cout<<endl;
    for (int i=0;i<n;i++) {
        demthua=0;
        for (int j=0;j<n;j++) {
            if (a[i][j]==0)
                demthua+=1;
        }
        if (demthua==1) {
            cout<<i+1<<" ";
            demc+=1;
        }
    }
    if (demc==0)
        cout<<"0";
}
