#include<iostream>
using namespace std;

// Main function
int main(){
    // Variables to store matrix dimensions.
    int x,y;
    cout << "Enter matrix dimensions ";
    cin >> x >> y;

    // Dynamic allocation of matrix based on user input dimensions.
    int mat[x][y];
    cout << "Enter matrix elements" << endl;
    // Variable to count non-zero elements.
    int element = 0;

    // Reading matrix elements from user input and counting non-zero elements.
    int i = 0, j;
    while(i < x) {
        j = 0;
        while(j < y) {
            cin >> mat[i][j];
            if(mat[i][j] != 0)
            	element++;
            j++;
        }
        i++;
    }

    // Sparse matrix representation using arrays.
    // We use a 2D array with 3 rows representing the row index, column index, and value of non-zero elements.
    int sparse_matrix[3][element];

    // Conversion from full matrix to sparse matrix representation.
    element = 0; // Reset element counter for use in indexing non-zero elements.
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if(mat[i][j] != 0){
                sparse_matrix[0][element] = i; // Row index of non-zero element.
                sparse_matrix[1][element] = j; // Column index of non-zero element.
                sparse_matrix[2][element] = mat[i][j]; // Value of non-zero element.
                element++;
            }
        }
    }

    // Labels for printing the sparse matrix.
    string names[3] = {"row", "column", "value"};
    // Printing the sparse matrix in the format (row, column, value).
    for(i = 0; i < 3; i++){
        cout << names[i] << " ";
        for(j = 0; j < element; j++){
            cout << sparse_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0; // End of program.
}
