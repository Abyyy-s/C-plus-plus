#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector<int>v={1,2,3,4,5,6,7,8,9};
int low=0;
int high=v.size()-1;
int mid,n;

cout<<"enter the value to be found:";
cin>>n;

while(low<=high)
{
	mid=(low+high)/2;
	
	if(n==v[mid])
	{
		cout<<"element found at index:"<<mid<<endl;
		return 0;
	}
	else if(n>v[mid])
	{
		low=mid+1;
	}
	else
	{
		high=mid-1;
	}
}
cout<<"element not found";
return 0;
}
