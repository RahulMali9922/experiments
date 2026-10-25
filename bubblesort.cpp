#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]= a[j+1];
                a[j+1] = temp;
            
            }
        }
    }
}
int main(){
    int n;
    int a[10];
    cout<<"Enter the size of the array :";
    cin>>n;

    cout<<"Enter"<< n << "integer in any order:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>> a[i];
    }
    bubble_sort(a,n);

    cout<<"sorted array:";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//OUTPUT
//PS D:\Rahul> g++ bubblesort.cpp
//PS D:\Rahul> ./bubblesort
//Enter the size of the array :8
//Enter8integer in any order:
//1 4 6 8 7 9 5 3
//sorted array:1 3 4 5 6 7 8 9
//PS D:\Rahul>