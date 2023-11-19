#include<bits/stdc++.h>
using namespace std;
int main() {
    string np;
    cin>>np;
    string kq;
    int n=np.length();
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
            kq.push_back('0');
        } else if (a=="0001"){
            kq.push_back('1');
        } else if (a=="0010"){
            kq.push_back('2');
        } else if (a=="0011"){
            kq.push_back('3');
        } else if (a=="0100"){
            kq.push_back('4');
        } else if (a=="0101"){
            kq.push_back('5');
        } else if (a=="0110"){
            kq.push_back('6');
        } else if (a=="0111"){
            kq.push_back('7');;
        } else if (a=="1000"){
            kq.push_back('8');
        } else if (a=="1001"){
            kq.push_back('9');
        } else if (a=="1010"){
            kq.push_back('A');
        } else if (a=="1011"){
            kq.push_back('B');
        } else if (a=="1100"){
            kq.push_back('C');
        } else if (a=="1101"){
            kq.push_back('D');
        } else if (a=="1110"){
            kq.push_back('E');
        } else {
            kq.push_back('F');
        }
        n-=4;
        np.erase(0,4);
    }
    while (kq[0]=='0') {
        kq.erase(0,1);
    }
    cout<<kq;
}

