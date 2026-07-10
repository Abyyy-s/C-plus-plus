#include<iostream>
using namespace std;

int main()
{
    int arr[]={5,2,7,2,9,2};
    int i;

    int n = sizeof(arr)/sizeof(arr[0]);
    int large=arr[0];
    for(i=1; i<n; i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }

    cout << "largest element is " <<large<< endl;

    return 0;
}
