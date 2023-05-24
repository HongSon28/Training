#include<bits/stdc++.h>
using namespace std;
vector <float> a;
vector <char> dau;
float calc() {
    vector <float> temp = a;
    vector <char> tempdau = dau;
    int n=tempdau.size();
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
    n=tempdau.size();
    if (tempdau[n-1]=='*') {
        int x=temp[n-1]*temp[n];
        temp.pop_back();
        temp.pop_back();
        temp.push_back(x);
        tempdau.pop_back();
    }
    for (int i=0;i<tempdau.size();i++) {
        cout<<temp[i]<<tempdau[i];
    }
    cout<<temp[i]<<endl;
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
int main() {
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    dau.push_back('+');
    dau.push_back('+');
    dau.push_back('*');
    dau.push_back('*');
    cout<<calc();
}
