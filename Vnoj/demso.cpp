#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int demam=0;
    int demduong=0;
    for (int i=0;i<n;i++) {
        if (a[i]>0)
            demduong+=1;
        else if (a[i]<0)
            demam+=1;
    }
    cout<<demam<<" "<<demduong;
}
