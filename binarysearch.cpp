#include <iostream>
using namespace std;
int binary_search(int a[], int n, int x)
{
int rst = 0;
int last = n -1;
int mid;
while (rst <= last)
{
mid = (rst + last) / 2;
if (a[mid] == x)
{
return mid;
}
else if (a[mid] < x)
{
rst = mid + 1;
}
else
{
last = mid -1;
}
}
return -1;
}
int main()
{
int n, x;
int a[20];
cout << "Enter the size of the array: ";
cin >> n;
cout << "Enter " << n << " sorted integers:\n";
for (int i = 0; i < n; i++)
{
cin >> a[i];
}
cout << "Enter the target element to search for: ";
cin >> x;
int position = binary_search(a, n, x);
if (position != -1)
cout << "Element found at position: " << position << endl;
else
cout << "Element not found." << endl;
return 0;
}


//OUTPUT
//PS D:\Rahul> g++ binarysearch.cpp
//PS D:\Rahul> ./binarysearch
//Enter the size of the array: 5
//Enter 5 sorted integers:
//2 3 4 5 6 
//Enter the target element to search for: 4
//Element found at position: 2
//PS D:\Rahul>