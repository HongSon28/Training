#include<bits/stdc++.h>
using namespace std;
int main() {
    string np;
    cin>>np;
    int kq[50];
    int n=np.length();
    int dem=0;
    if (n%4!=0) {
        int k=4-(n%4);
        for (int i=0;i<k;i++) {
            np.insert(0,"0");
        }
        n=n+4-(n%4);
    }
    while (n!=0) {
        string a=np.substr(0,4);
        if (a=="0000") {
            kq[dem]=0;
        } else if (a=="0001"){
            kq[dem]=1;
        } else if (a=="0010"){
            kq[dem]=2;
        } else if (a=="0011"){
            kq[dem]=3;
        } else if (a=="0100"){
            kq[dem]=4;
        } else if (a=="0101"){
            kq[dem]=5;
        } else if (a=="0110"){
            kq[dem]=6;
        } else if (a=="0111"){
            kq[dem]=7;
        } else if (a=="1000"){
            kq[dem]=8;
        } else if (a=="1001"){
            kq[dem]=9;
        } else if (a=="1010"){
            kq[dem]=10;
        } else if (a=="1011"){
            kq[dem]=11;
        } else if (a=="1100"){
            kq[dem]=12;
        } else if (a=="1101"){
            kq[dem]=13;
        } else if (a=="1110"){
            kq[dem]=14;
        } else {
            kq[dem]=15;
        }
        n-=4;
        np.erase(0,4);
        dem+=1;
    }
    for (int i=0;i<dem;i++) {
        if (kq[i]==10) {
            cout<<"A";
        } else if (kq[i]==11) {
            cout<<"B";
        } else if (kq[i]==12) {
            cout<<"C";
        } else if (kq[i]==13) {
            cout<<"D";
        } else if (kq[i]==14) {
            cout<<"E";
        } else if (kq[i]==15) {
            cout<<"F";
        } else {
            cout<<kq[i];
        }
    }
}
