#include <iostream>

using std::cout;
using std::cin;

class matrix{
public:

//matrix
    matrix();
    matrix(int Rows, int Cols);
    matrix(matrix& other);
    ~matrix();
    
    double determinant(matrix& matrix_);
    matrix getAlgAppend(matrix& mat_);

//method
    matrix CalcComplements();
    matrix Transpose();
    matrix MulMatrix(const matrix& other);
    matrix MulNumber(const double num);
    matrix SubMatrix(const matrix& other);
    matrix SumMatrix(const matrix& other);
    bool EqMatrix(const matrix& other);
    void printMatrix();
    void changeMatrix(double** arr_, int Rows, int Cols);

//operators
    matrix operator+(const matrix &mat_);
    matrix operator-(const matrix &mat_);
    matrix operator*(int count);
    matrix operator*(const matrix &mat_);

    bool operator==(const matrix &other);

    void operator=(const matrix &other);
    void operator+=(const matrix &other);
    void operator-=(const matrix &other);
    void operator*=(int count);
    void operator*=(const matrix &other);

    
//get and set
    int getRows();
    int getCols();
    void setMatrix(double** atrix_);
    void setCols(int Cols);
    void setRows(int Rows);
    void setArr(double** arr_);
    double** getMatrix();
    double** getArr();

private:

    int rows, cols;
    double** arr;

    matrix getMinor(matrix& matrix_, int rows, int cols);

};
