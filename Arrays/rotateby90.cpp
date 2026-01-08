//You are given an n x n 2D matrix representing an image,
// rotate the image by 90 degrees (clockwise).

#include <bits/stdc++.h>
using namespace std;    

void rotateBruteForce(vector<vector<int>>& matrix) {//o(N^2) space and o(N^2) time
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));// 2D vector to store rotated matrix
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    
    matrix = rotated;
}

void rotateInPlace(vector<vector<int>>& matrix) {// o(1) space and o(N^2) time
    int n = matrix.size();
    
    // Transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reverse each row
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    rotateInPlace(matrix);
    
    // Print rotated matrix
    for(const auto& row : matrix) {
        for(const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}