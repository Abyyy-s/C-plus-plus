#include<iostream>
using namespace std;

int main()
{
    int i, n, arr[15];
    
    cout << "enter the limit (maximum 15): ";
    cin >> n;
    

    if (n > 15) {
        cout << "Error: Limit cannot be greater than 15!" << endl;
        return 1;
    }
    
    for(i = 0; i < n; i++) {
        cout << "enter element " << i << ": " << endl;
        cin >> arr[i];
    }
    
    cout << "\nYour elements are:" << endl;
    for(i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}

