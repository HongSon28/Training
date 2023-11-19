#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    string a;
    cin>>k;
    cin>>a;
    int n=a.length();
    int dem=1;
    int chucai[n];
    int solan[n]={};
    int kq=0;
    chucai[0]=(int)a[0];
    for (int i=1;i<n;i++) {
        int ch=0;
        for (int j=0;j<dem;j++) {
            if ((int)a[i]==chucai[j]) {
                solan[j]+=1;
                ch+=1;
            }
        }
        if (ch==0) {
            chucai[dem]=(int)a[i];
            dem+=1;
        }
    }
    for (int i=0;i<dem;i++) {
        int ch=0;
        if (solan[i]%k==0) {
            ch+=1;
        }
        if (ch=dem) {
            kq+=1;
        }
    }
    cout<<dem<<endl<<kq<<endl;
    if (dem%k==0&&kq==dem) {
        for (int i=0;i<dem;i++) {
            for (int j=0;j<solan[i];j++) {
                cout<<chucai[i];
            }
        }
    } else {
        cout<<"-1";
    }
}
