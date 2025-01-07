# CS326
# Student: Tyler Vickers
# Purpose: To rotate a 2D array by 90 degrees using both
# C++ and Python, and then comparing each's use of variables.

# Rotation: I decided to use a matrix transformation trick,
# by first transposing the matrix, and then reversing the entries
# in each row. I simply chose this method because I like matrices
# and transforming them is fun.



def main():

    notRotated = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9],
              [10, 11, 12],
              [13, 14, 15]]
    
    printArrToFile(notRotated)
    rotated = rotateArray(notRotated)

    printArrToFile(rotated)
    

def printArrToFile(array2D):
    file = open('./rotatedArrayPython.txt', 'a')
    file.write("\n")
    for i in range(len(array2D)):
        for j in range(len(array2D[0])):
            file.write(str(array2D[i][j]) + " ")
        file.write("\n")
    file.close()
    
def rotateArray(array2D):
    rotatedArray = [[0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0]]
    # Transpose
    for i in range(len(array2D)):
        for j in range(len(array2D[i])):
            rotatedArray[j][i] = array2D[i][j]

    # Reverse the rows
    for row in rotatedArray:
        row.reverse()

    return rotatedArray


if __name__ == "__main__":
    main()