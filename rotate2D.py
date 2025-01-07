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
    

def printArrToFile(notRotated):
    file = open('./rotate2DArray/rotatedArrayPython.txt', 'a')
    for i in range(len(notRotated)):
        for j in range(len(notRotated[i])):
            file.write(str(notRotated[i][j]) + " ")
        file.write("\n")
    file.close()
    


if __name__ == "__main__":
    main()