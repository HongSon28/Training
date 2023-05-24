#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    string a;
    cin>>k;
    cin>>a;
    int n=a.length();
    int dem=1;
    char chucai[n];
    int solan[n]={};
    int ch=0;
    chucai[0]=a[0];
    solan[0]=1;
    for (int i=1;i<n;i++) {
        int ch=0;
        for (int j=0;j<dem;j++) {
            if (a[i]==chucai[j]) {
                solan[j]+=1;
                ch+=1;
            }
        }
        if (ch==0) {
            chucai[dem]=a[i];
            solan[dem]=1;
            dem+=1;
        }
    }
    for (int i=0;i<dem;i++) {
        if (solan[i]%k==0) {
            ch+=1;
        }
    }
    if (ch==dem) {
        for (int i=0;i<k;i++) {
            for (int j=0;j<dem;j++) {
                for (int l=0;l<solan[j]/k;l++) {
                    cout<<chucai[j];
                }
            }
        }
    } else {
        cout<<"-1";
    }
}

