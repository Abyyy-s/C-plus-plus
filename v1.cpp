#include<iostream>
#include<vector>
using namespace std;
int main()
{
cout<<"enter the limit:";
int n;
cin>>n;
vector<int>v;
for(int i=0;i<n;i++)
{
	cout<<"enter element "<<i+1<<":"<<endl;
	int x;
	cin>>x;
	v.push_back(x);
	}
int big=v[0];
for(int i=1;i<v.size();i++)
{
	if(v[i]>big)
	{
		big=v[i];
		}}
cout<<"the largset number is: "<<big<<endl;
return 0;

}	
