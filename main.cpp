#include <iostream>
#include <vector>
using namespace std;

// Function to print a matrix
void print_matrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
vector<vector<int>> add_matrices(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> C(A.size(), vector<int>(A[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to multiply two matrices
vector<vector<int>> multiply_matrices(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> C(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            int sum = 0;
            for (int k = 0; k < A[0].size(); k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

// Function to raise a matrix to a power
vector<vector<int>> matrix_power(vector<vector<int>> A, int n) {
    vector<vector<int>> C(A.size(), vector<int>(A.size()));
    if (n == 1) {
        return A;
    }
    vector<vector<int>> B = matrix_power(A, n / 2);
    if (n % 2 == 0) {
        C = multiply_matrices(B, B);
    } else {
        C = multiply_matrices(multiply_matrices(B, B), A);
    }
    return C;
}

// Function to transpose a matrix
vector<vector<int>> transpose_matrix(vector<vector<int>> A) {
    vector<vector<int>> C(A[0].size(), vector<int>(A.size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            C[j][i] = A[i][j];
        }
    }
    return C;
}

int main() {
    int choice;
    do {
        // Display the menu
        cout << "Pick a choice from the list:" << endl;
        cout << "1- Addition Operation" << endl;
        cout << "2- Multiplication Operation" << endl;
        cout << "3- Power Operation" << endl;
        cout << "4- Transpose Operation" << endl;
        cout << "5- Exit" << endl;

        // Get the user's choice
        cin >> choice;

        // Execute the corresponding operation
        if (choice == 1) {
            // Addition operation
            int m, n;
            cout << "Enter the dimensions of the first matrix: ";
            cin >> m >> n;
            vector<vector<int>> A(m, vector<int>(n));
            cout << "Enter the elements of the first matrix: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cin >>
//tbc
