#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> reverse_and_sort(vector<int>& arr1, vector<int>& arr2) {
    stack<int> s;
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] >= arr2[j]) {
            s.push(arr1[i]);
            i++;
        } else {
            s.push(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        s.push(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        s.push(arr2[j]);
        j++;
    }
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

int main() {
    vector<int> arr1 = {10, 8, 5, 3};
    vector<int> arr2 = {9, 7, 6, 4, 2, 1};
    vector<int> result = reverse_and_sort(arr1, arr2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
