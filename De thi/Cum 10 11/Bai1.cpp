#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long n2=n;
    vector<int>v;
    int div=2;
    while (n>1) {
        while (n%div==0) {
            v.push_back(div);
            n/=div;
        }
        div++;
    }
    int sum=0;
    cout<<n2<<"=";
    for (int i=0;i<v.size()-1;i++) {
        cout<<v[i]<<'*';
        sum+=v[i];
    }
    cout<<v[v.size()-1]<<endl;
    sum+=v[v.size()-1];
    cout<<sum;
}

