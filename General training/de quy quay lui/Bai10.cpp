#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<float> a;
vector<char> dau;
float ans=0;
float kq;
float res=INT_MAX;
char c[4]={'+','-','*','/'};
float calc() {
    vector <float> temp = a;
    vector <char> tempdau = dau;
    int l=tempdau.size();
    int i=0;
    while (i<tempdau.size()) {
        if (tempdau[i]=='*') {
            float x=temp[i]*temp[i+1];
            temp.erase(temp.begin()+i);
            temp.erase(temp.begin()+i);
            temp.insert(temp.begin()+i,x);
            tempdau.erase(tempdau.begin()+i);
        } else if (tempdau[i]=='/'){
            float x=temp[i]/temp[i+1];
            temp.erase(temp.begin()+i);
            temp.erase(temp.begin()+i);
            temp.insert(temp.begin()+i,x);
            tempdau.erase(tempdau.begin()+i);
        } else {
            i++;
        }
    }
    l=tempdau.size();
    if (tempdau[l-1]=='*') {
        int x=temp[l-1]*temp[l];
        temp.pop_back();
        temp.pop_back();
        temp.push_back(x);
        tempdau.pop_back();
    }
    if (tempdau[l-1]=='/') {
        int x=temp[l-1]/temp[l];
        temp.pop_back();
        temp.pop_back();
        temp.push_back(x);
        tempdau.pop_back();
    }
    float ca=temp[0];
    for (int i=0;i<tempdau.size();i++) {
        if (tempdau[i]=='+') {
            ca+=temp[i+1];
        } else {
            ca-=temp[i+1];
        }
    }
    return ca;
}
void dequy(int k) {
    for (int i=0;i<4;i++) {
        dau.push_back(c[i]);
        if (k==n) {
            float ans=calc();
            if (m-ans<res&&m-ans>=0) {
                res=m-ans;
                kq=ans;
            }
        } else {
            dequy(k+1);
        }
        dau.pop_back();
    }
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=n;i++) {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    dequy(2);
    cout.precision(3);
    cout<<fixed<<kq;
}
