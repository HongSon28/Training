#include<bits/stdc++.h>
using namespace std;
int n;
double t;
string id[101],name[101],supplier[101];
double price[101];
int n1[101],n2[101];
int sup[11];
pair<double,string>rev[101];
int main() {
	freopen("products.txt","r",stdin);
    freopen("analysis.txt","w",stdout);
    cin>>n>>t;
    cin.ignore();
    for (int i=1;i<=n;i++) {
    	string s;
    	getline(cin,id[i],',');
    	getline(cin,name[i],',');
    	getline(cin,s,',');
    	price[i]=stod(s);
    	getline(cin,supplier[i],',');
    	getline(cin,s,',');
    	n1[i]=stoi(s);
    	getline(cin,s);
    	n2[i]=stoi(s);
    	sup[supplier[i][1]-'0']+=n1[i];
    }	
    cout<<"ID of products with 0 sold items: ";
    for (int i=1;i<=n;i++) {
    	if (n1[i]==0) cout<<id[i]<<' ';
    }
    cout<<endl;
    vector<pair<double,string>>v;
    for (int i=1;i<=n;i++) rev[i]={price[i]*n1[i],id[i]};
    sort(rev+1,rev+1+n);
    cout<<"Top 3 revenue products: "<<rev[n].second<<' '<<rev[n-1].second<<' '<<rev[n-2].second<<endl;
	int mx=0;
	for (int i=1;i<=9;i++) mx=max(mx,sup[i]);
	cout<<"Supplier with most products sold: ";
	for (int i=1;i<=9;i++) if (sup[i]==mx) cout<<"s"<<i<<' ';
	cout<<endl;
	cout<<"ID of products that need to be restocked: ";
	for (int i=1;i<=n;i++) {
		double temp=(double)n2[i]/(double)n1[i];
		if (temp<t) cout<<id[i]<<' ';
	}
}