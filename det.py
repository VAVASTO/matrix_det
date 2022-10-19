def checkZero(matrix, rows, cols, size):
    if (rows >= size):
        return -1
    if (matrix[rows*size + cols] == 0):
       return checkZero(matrix, rows+1, cols, size); 
    return rows
 
def swapRows(matrix, firstRows, secondRows, size, cols = 0):
    if (firstRows >= size or secondRows >= size or cols >= size):
        return
    matrix[firstRows*size + cols], matrix[secondRows*size + cols] = matrix[secondRows*size + cols], matrix[firstRows*size + cols]
    return swapRows(matrix, firstRows, secondRows, size, cols+1)
 
def subRows(matrix, rows, cols, size, origRows, origCols):
    if (rows == size):
        return
    koef = matrix[rows*size+ cols] / matrix[origRows*size + origCols]
    subCols(matrix, rows, cols, size, koef, origRows)
    return subRows(matrix, rows+1, cols, size, origRows, origCols)
 
def subCols(matrix, rows, cols, size, koef, origRows):
    if (cols == size):
        return
    matrix[rows*size + cols] -= koef*matrix[size*origRows + cols]
    subCols(matrix, rows, cols+1, size, koef, origRows)
 
def Umatrix(matrix, rows, cols, size):
    if (rows >= size):
        return
    if (matrix[rows*size + cols] == 0):
        pointRows = checkZero(matrix, rows+1, cols, size)
        if (pointRows == -1):
            return -1
        else:
            swapRows(matrix, rows, pointRows, size)
    subRows(matrix, rows+1, cols, size, rows, cols)
    return Umatrix(matrix, rows+1, cols+1, size)
 
def det(matrix, rows, cols, size, det_ = 1):
    if (rows == size):
        return det_
    return det(matrix, rows+1, cols+1, size, det_*matrix[rows*size + cols])
 
def main():
    size = int(input())
    matrix = []
    for i in range(size*size):
        matrix.append(float(input()))
    if (Umatrix(matrix, 0, 0, size) == -1):
        print("det = 0")
        return -1
    for i in range(size):
        for j in range(size-1):
            print(matrix[size*i + j], end=" ")
        print(matrix[size*i + size-1])
    print(det(matrix, 0, 0, size))
 
# Если сценарий запущен из командной строки
if __name__ == "__main__":
    main()  