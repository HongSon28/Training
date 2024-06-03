#include<bits/stdc++.h>
using namespace std;
int GetRandom(){
    return 0 + (int)(rand()*(25-0+1.0)/(1.0+RAND_MAX));
}
int main() {
    cout<<"PHAN MEM RANDOM 100% UY TIN"<<endl;
    cout<<"An phim bat ki de bat dau, nhap Stop de huy"<<endl;
    srand(time(NULL));
    string s[26];
    s[0]="Pham Khanh An";
    s[1]="Nguyen Xuan Bach";
    s[2]="Le Nguyen Quoc Binh";
    s[3]="Hoang Cao Tri Dung";
    s[4]="Lam Hoang Duong";
    s[5]="Le Nguyen Duc";
    s[6]="Nguyen Anh Duc";
    s[7]="Dao Thien Hai";
    s[8]="Nguyen Minh Hieu A";
    s[9]="Nguyen Minh Hieu B";
    s[10]="Truong Minh Hieu";
    s[11]="Cao Xuan Huy";
    s[12]="Tran Quoc Hung";
    s[13]="Bui Nam Khanh";
    s[14]="Dao Dinh Kien";
    s[15]="Nguyen Thanh Long";
    s[16]="Ngo Xuan Minh";
    s[17]="Vu Dao Minh";
    s[18]="Tran Tuan Nghia";
    s[19]="Nguyen Khoi Nguyen";
    s[20]="Nguyen Huu Nhat";
    s[21]="Vu Quang";
    s[22]="Nguyen Hong Son";
    s[23]="Nguyen Le Thanh Vinh";
    s[24]="Bui Ngoc Truong Vu";
    s[25]="Nguyen Minh Vu";
    int lan[25]={};
    for (int i=0;i<9;i++) {
        string a;
        getline(cin,a);
        if (a=="Stop")
            return 0;
        int k=GetRandom();
        while (lan[k]!=0) {
            k=GetRandom();
        }
        lan[k]++;
        cout<<s[k]<<endl;
    }
}
