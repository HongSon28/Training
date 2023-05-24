#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    int i=1;
    int dem=1;
    if ((k%2!=0)&&(k%5!=0)) {
        while (i%k!=0) {
            i=i*10+1;
            dem+=1;
        }
        cout<<dem;
    } else {
        cout<<"-1";
    }
}
