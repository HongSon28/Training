#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    while (pow(2,i)<=n)
        i++;
    i--;
    cout<<i;
}
