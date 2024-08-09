#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    cin>>n;
    short a[n];
    for (short i=0;i<n;i++) {
        cin>>a[i];
    }
    short am=0;
    short duong=0;
    short khong=0;
    for (short i=0;i<n;i++) {
        if (a[i]>0) {
            duong+=1;
        } else if (a[i]<0) {
            am+=1;
        } else {
            khong+=1;
            break;
        }
    }
    if (khong>=1) {
        cout<<"-1";
    } else if (duong>am) {
        cout<<am;
    } else {
        cout<<duong;
    }
}
