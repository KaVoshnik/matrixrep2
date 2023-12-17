#include <iostream>

using std::cout;
using std::cin;

class Matrix{
public:

//matrix
    Matrix();
    Matrix(int Rows, int Cols);
    Matrix(Matrix& other);
    ~Matrix();
    
    double determinant(Matrix& matrix_);
    
    Matrix getAlgAppend(Matrix& mat_);

//method
    Matrix CalcComplements();
    Matrix Transpose();
    Matrix MulMatrix(const Matrix& other);
    Matrix MulNumber(const double num);
    Matrix SubMatrix(const Matrix& other);
    Matrix SumMatrix(const Matrix& other);

    bool EqMatrix(const Matrix& other);

    void printMatrix();
    void changeMatrix(double** arr_, int Rows, int Cols);

//operators
    Matrix operator+(const Matrix &mat_);
    Matrix operator-(const Matrix &mat_);
    Matrix operator*(int count);
    Matrix operator*(const Matrix &mat_);

    bool operator==(const Matrix &other);

    void operator=(const Matrix &other);
    void operator+=(const Matrix &other);
    void operator-=(const Matrix &other);
    void operator*=(int count);
    void operator*=(const Matrix &other);

    
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

    Matrix getMinor(Matrix& matrix_, int rows, int cols);

};
