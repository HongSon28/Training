#include<bits/stdc++.h>
using namespace std;
bool checkhoa(char ch) {
    if (((int)ch>=65)&&((int)ch<=90))
        return true;
    else
        return false;
}
bool checkthuong(char ch) {
    if (((int)ch>=97)&&((int)ch<=122))
        return true;
    else
        return false;
}
bool checkdacbiet(char ch) {
    if (((int)ch==33)||((int)ch==35)||((int)ch==64)||((int)ch==36)||((int)ch==37)||((int)ch==38)||((int)ch==42)||((int)ch==94)||((int)ch==40)||((int)ch==41)||((int)ch==45)||((int)ch==43)) {
        return true;
    } else {
        return false;
    }
}
int main() {
    string s;
    cin>>s;
    unsigned dai=s.length();
    unsigned hoa=0;
    unsigned thuong=0;
    unsigned dacbiet=0;
    unsigned lientiep=0;
    if (dai<=8) {
        cout<<"NO";
    } else {
        for (unsigned i=0;i<dai;i++) {
            if (checkhoa(s[i])==true) {
                hoa=hoa+1;
            } else if (checkthuong(s[i])==true) {
                thuong=thuong+1;
            } else if (checkdacbiet(s[i])==true) {
                dacbiet=dacbiet+1;
            }
        }
    }
    if ((hoa>=1)&&(thuong>=1)&&(dacbiet>=1)) {
        for (unsigned i=0;i<dai-1;i++) {
            if (s[i]==s[i+1]) {
                lientiep=lientiep+1;
            }
        }
        if (lientiep==0) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }
    } else {
        cout<<"NO";
    }
}
