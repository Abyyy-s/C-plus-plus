#include<iostream>
using namespace std;
int main()
 {
 int arr[]={5,2,7,2,9,2};
 int flag=0,i,t=2;
 int n=sizeof(arr)/sizeof(arr[0]);
 for(i=0;i<n;i++)
 {
 	if(arr[i]==t)
 	{
 		flag++;}}
 		
 cout<<"found "<<flag<<" times"<<endl;
 return 0;
 }
