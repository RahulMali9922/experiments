#include <iostream>
#include <vector>

using namespace std;

int linear_search(const vector<int>& a, int x) {
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    vector<int> a(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cout << "Enter the target element to search for: ";
    cin >> x;

    int location = linear_search(a, x);

    if (location != -1) {
        cout << "Element " << x << " found at index: " << location << endl;
    } else {
        cout << "Element " << x << " not found in the array." << endl;
    }

    return 0;
}

//OUTPUT
//PS D:\Rahul>  g++ linearsearch.cpp
//PS D:\Rahul> ./linearsearch
//Enter the size of the array: 6
//Enter 6 integers:
//5 4 2 1 7 9 
//Enter the target element to search for: 1
//Element 1 found at index: 3
//PS D:\Rahul>