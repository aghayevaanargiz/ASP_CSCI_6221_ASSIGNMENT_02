#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> expected = {
        {19, 22},
        {43, 50}
    };

    vector<vector<int>> result = multiplyMatrices(A, B);

    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }

    return 0;
}

