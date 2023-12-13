#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class matrix{
public:

//matrix
    matrix() noexcept;
    matrix(int Rows, int Cols);
    matrix(matrix& other);
    ~matrix();
    vector<vector<int>> getMinor(vector<vector<int>> matrix_, int rows, int cols);

//method
    matrix CalcComplements();
    matrix Transpose();
    matrix MulMatrix(const matrix& other);
    matrix MulNumber(const double num);
    matrix SubMatrix(const matrix& other);
    matrix SumMatrix(const matrix& other);
    bool EqMatrix(const matrix& other);
    void printMatrix();
    void changeMatrix(vector<vector<int>> arr_, int Rows, int Cols);

//operators
    matrix operator + (const matrix &mat_);
    matrix operator - (const matrix &mat_);
    matrix operator * (int count);
    matrix operator * (const matrix &mat_);

    bool operator == (const matrix &other);

    void operator = (const matrix &other);
    void operator += (const matrix &other);
    void operator -= (const matrix &other);
    void operator *= (int count);
    void operator *= (const matrix &other);

    
//get and set
    int getRows();
    int getCols();
    void setArr(vector<vector<int>> arr_);
    void setCols(int Cols);
    void setRows(int Rows);
    vector<vector<int>> getArr();

private:

    int rows, cols;
    vector<vector<int>> arr;

};