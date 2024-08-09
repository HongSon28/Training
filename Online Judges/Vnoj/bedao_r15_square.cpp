#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,sum=0;
    cin>>n;
    n--;
    for (int i=1;i<=n;i++) {
        cout<<i<<' ';
        sum+=i;
    }
    int sq=sqrt(sum);
    sq++;
    while ((sq*sq-sum)<=n) sq++;
    cout<<sq*sq-sum;
}
