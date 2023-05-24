#include<bits/stdc++.h>
using namespace std;
int main() {
    int dem[123]={};
    int m;
    cin>>m;
    cin.ignore();
    string s;
    getline(cin,s);
    int n=s.length();
    int j=0;
    while (j<n) {
        while (s[j]==' ')
            s.erase(j,1);
        j++;
    }
    j=0;
    int cnt=0, res=0;
    while (cnt<=m) {
        if (dem[s[j]]==0) {
            cnt++;
            res++;
        } else {
            res++;
        }
        dem[s[j]]++;
        j++;
    }
    dem[s[j]]--;
    cnt--;
    res--;
    j--;
    int luu=res;
    int tam=res;
    n=s.length();
    int temp=0;
    for (int i=j;i<=n-m;i++) {
        int index=i;
        while (dem[s[index]]!=0) {
            luu++;
            index++;
        }
        res=max(res,luu);
        luu=tam;
        dem[s[temp]]--;
        temp=index-1;
    }
    cout<<res;
}
