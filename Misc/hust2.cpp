#include<bits/stdc++.h>
using namespace std;
string id[31],name[31],dob[31],phone[31],sales[31];
int top3[4];
void read_data() {
	freopen("sales_staff.txt","r",stdin);
	for (int i=1;i<=30;i++) {
		string s;
		getline(cin,s,',');
		id[i]=s;
		getline(cin,s,',');
		name[i]=s;
		getline(cin,s,',');
		dob[i]=s;
		getline(cin,s,',');
		phone[i]=s;
		getline(cin,s);
		sales[i]=s;
	}
}
void find_top3_sales_staff_members() {
	int mx=0;
	for (int i=1;i<=30;i++) {
		int temp=stoi(sales[i]);
		if (temp>mx) {
			top3[1]=i;
			mx=temp;
		}
	}
	mx=0;
	for (int i=1;i<=30;i++) {
		if (i==top3[1]) continue;
		int temp=stoi(sales[i]);
		if (temp>mx) {
			top3[2]=i;
			mx=temp;
		}
	}
	mx=0;
	for (int i=1;i<=30;i++) {
		if (i==top3[1]||i==top3[2]) continue;
		int temp=stoi(sales[i]);
		if (temp>mx) {
			top3[3]=i;
			mx=temp;
		}
	}
}
void print() {
	freopen("top3_sales_staff.txt","w",stdout);
	cout<<"ID  Name                          DOB         Phone      Sales     "<<endl;
	for (int i=1;i<=3;i++) {
		while (id[top3[i]].size()<4) id[top3[i]]+=' ';
		while (name[top3[i]].size()<30) name[top3[i]]+=' ';
		while (dob[top3[i]].size()<12) dob[top3[i]]+=' ';
		while (phone[top3[i]].size()<11) phone[top3[i]]+=' ';
		while (sales[top3[i]].size()<10) sales[top3[i]]+=' ';
		cout<<id[top3[i]]<<name[top3[i]]<<dob[top3[i]]<<phone[top3[i]]<<sales[top3[i]]<<endl;
	}
}
int main() {
	read_data();
	find_top3_sales_staff_members();
	print();
}