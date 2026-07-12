#include<iostream>
#include<vector>
using namespace std;

int main()
{

vector<int>v;
int n,j,i,temp=0;
cout<<"enter the limit";
cin>>n;

for(i=0;i<n;i++)
{
	cout<<"enter element"<<i+1<<":"<<endl;
	int x;
	cin>>x;
	v.push_back(x);
	}
	
for(i=0;i<n-1;i++)
{ bool sw=false;
	for(j=0;j<n-i-1;j++)
	{
		if(v[j]>v[j+1])
		{
			//temp=v[j];
			//v[j]=v[j+1];
			//v[j+1]=temp;
			swap(v[j],v[j+1]);
			sw=true;
		}
		
		}
		if(!sw)
		{
			break;
			}}
		
cout<<"sorted array is\n";

for(i=0;i<n;i++)
{
	cout<<v[i]<<' ';
	cout<<'\n';}
	return 0;
}
			



