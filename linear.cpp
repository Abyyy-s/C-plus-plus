#include<iostream>
using namespace std;
int main()
{
int n,i,arr[100],max,get=-1,j;
cout<<"enter the limit: ";
cin>>n;
for(i=0;i<n;i++)
{
	cout<<"enter element "<<i<<": "<<endl;;
	cin>>arr[i];
	}
	

cout<<"enter the element u want to find?:";
cin>>max;

for(i=0;i<n;i++)
{
	if(arr[i]==max)
	{
		j=i+1;
		get=0;
		break;
		}}
		
if(get==-1)
{
	cout<<"invalid"<<endl;
}
else
{
	cout<<"element found at index "<<":"<<j<<endl;
	}
	}
	
