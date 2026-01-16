#include <bits/stdc++.h>
using namespace std;

void markRow(int i, vector<vector<int>>& matrix) {
    for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}

void markCol(int j, vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(i, matrix);
                markCol(j, matrix);
            }
        }
    }

    // Final pass
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}


void betterSolution(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // Step 1: mark rows & columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Step 2: set zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}


int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Using the first method
    setZeroes(matrix);

    cout << "Matrix after setting zeroes (Method 1):\n";
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Resetting the matrix for the better solution
    cout << "Enter the matrix elements again for better solution:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Using the better method
    betterSolution(matrix);

    cout << "Matrix after setting zeroes (Better Method):\n";
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}