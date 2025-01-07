/*
CS326
Student: Tyler Vickers
Purpose: To rotate a 2D array by 90 degrees using both
C++ and Python, and then comparing each's use of variables.

Rotation: I decided to use a matrix transformation trick,
by first transposing the matrix, and then reversing the entries
in each row. I simply chose this method because I like matrices
and transforming them is fun. Inspiration can be credited to:
https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
*/

#include <iostream>
#include <fstream>

// I hope it's okay that i hard input the array's dimensions
// as parameters here, so i wouldn't have to create struct or
// pointers or something.  
void rotateArray(int arr[5][3], int arr2[3][5]);
void printArrToFile(int arr[5][3]);
void printArrToFile(int arr[3][5]);

int main() {
    // 5x3 matrix
    int notRotated[5][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    }; 
    int rotated[3][5];

    printArrToFile(notRotated);
    rotateArray(notRotated, rotated);

    printArrToFile(rotated);

    return 0;
}



void rotateArray(int notRotated[5][3], int rotated[3][5]) {
    // Transpose 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            rotated[j][i] = notRotated[i][j];
        }
    }

    // Reverse the rows
    for (int i = 0; i < 3; i++) {
        int start = 0;
        int end = 4;

        while (start < end) {
            int temp = rotated[i][start];
            rotated[i][start] = rotated[i][end];
            rotated[i][end] = temp;
            start++;
            end--;
        }
    }

}

void printArrToFile(int arr[5][3]) {
    std::ofstream file;
    file.open("rotatedArrayCpp.txt", std::ios::app); // For printing to end of file
    file << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            file << arr[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}

void printArrToFile(int arr[3][5]) {
    std::ofstream file;
    file.open("rotatedArrayCpp.txt", std::ios::app); // For printing to end of file
    file << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            file << arr[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}

/*
Notes (for me):
Declaring the parameters is different, c++ doesn't like arr[][]
I think this is because the compiler doesn't know how much memory
to allocate for the second dimension of the array, but I will need
to dig further. 
Resource for further reading: https://www.geeksforgeeks.org/pass-2d-array-parameter-to-functions-in-cpp/
*/