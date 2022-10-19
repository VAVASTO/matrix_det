#include <iostream>
#include <stdlib.h>
#include <time.h>
 
double* createMatrix(size_t &sizeMatrix) {
    srand(time(NULL));
    std::cin >> sizeMatrix;
    double* matrix = new double[sizeMatrix*sizeMatrix];
    for (size_t i = 0; i < sizeMatrix*sizeMatrix; ++i) {
        matrix[i] = (rand()%2);
    }
    return matrix;
}
 
 
int main() {
    size_t sizeMatrix = 0;
    double* matrix = createMatrix(sizeMatrix);
 
 
    // print
    for (size_t i = 0; i < sizeMatrix; ++i) {
        for (size_t j = 0; j < (sizeMatrix-1); ++j) {
            std::cout << matrix[i*sizeMatrix+j] << " ";
        }
        std::cout << matrix[i*sizeMatrix +(sizeMatrix-1)] << std::endl;
    }
    std::cout << std::endl;
    // end print
 
 
 
    // Gaus's method
    double koef = 0;
    bool flagFind;
    for (size_t i = 0; i < sizeMatrix; ++i) {
        // if a = 0
        if (matrix[i*sizeMatrix + i] == 0) {
            flagFind = false;
            for (size_t j = i+1; j < sizeMatrix; ++j) {
                if (matrix[j*sizeMatrix + i] != 0) {
                    for (size_t k = 0; k < sizeMatrix; ++k) {
                        std::swap(matrix[j*sizeMatrix + k], matrix[i*sizeMatrix + k]);
                    }
                    flagFind = true;
                    break;
                }
            }
            if (!flagFind) {
                delete[] matrix;
                puts("Baaaaaaad!");
                return -1;
            }
        }
        // nice
        for (size_t j = i+1; j < sizeMatrix; ++j) {
 
            koef = matrix[j*sizeMatrix + i] / matrix[i*sizeMatrix + i];
            for (size_t k = 0; k < sizeMatrix; ++k) {
                matrix[j*sizeMatrix + k] -= koef*matrix[i*sizeMatrix + k];
            }
        }
 
    }
 
 
    double det = 1;
    for (size_t i = 0; i < sizeMatrix; ++i) {
        det *= matrix[i*sizeMatrix + i];
    }
 
 
 
    // print
    for (size_t i = 0; i < sizeMatrix; ++i) {
        for (size_t j = 0; j < (sizeMatrix-1); ++j) {
            std::cout << matrix[i*sizeMatrix+j] << " ";
        }
        std::cout << matrix[i*sizeMatrix +(sizeMatrix-1)] << std::endl;
    }
    std::cout << std::endl;
    // end print
    std::cout << "det = " << det << std::endl;
 
    delete[] matrix;
    return 0;
}