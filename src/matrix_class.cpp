#include "/home/kavo/matr/matrix_class/include/matrix.h"

    Matrix Matrix::getMinor(Matrix& matrix_, int rows, int cols){
        int n = matrix_.rows;

        Matrix out_minor = *new Matrix(n - 1, n - 1);


       if(n == 1) return matrix_;

        for(int i = 0, p = 0; i < n; i++){
            if(i == rows) continue;
            for(int j = 0, q = 0; j < n; j++){
                if(j == cols) continue;
                out_minor.arr[p][q] = matrix_.arr[i][j];
                q++;
            }
            p++;
        }
        return out_minor;
    }

    double Matrix::determinant(Matrix& matrix_){
        int n = matrix_.rows;
        int b = matrix_.cols;

        int det = 0;

        if(n != b){
            cout << "Not square! n = " << n << " b = " << b << "\n";
            return 0;
        } 

        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return matrix_.arr[0][0];
        }
        else if(n == 2){
            return (matrix_.arr[0][0] * matrix_.arr[1][1]) - (matrix_.arr[0][1] * matrix_.arr[1][0]); //косяк тут
        }
        else{
            for(int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    Matrix minor = *new Matrix;
                    minor = getMinor(matrix_, i, j);
                    int sign = j % 2 ? 1 : -1;
                    det += sign * matrix_.arr[i][j] * determinant(minor);
              }
            }
            
            return det;
        }
    }

    Matrix Matrix::getAlgAppend(Matrix& mat_){
        int n = mat_.rows;
        
        Matrix cofactors = *new Matrix(n, n);
        cofactors.arr = new double*[n];

        for (int i = 0; i < n; i++){
            cofactors.arr[i] = new double[n - 1];
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                Matrix minors = *new Matrix; 
                minors = getMinor(mat_, i, j);
                int sign = (i + j) % 2 == 0 ? 1: -1;
                cofactors.arr[j][i] = double(sign * determinant(minors));
            }
        }
        return cofactors;
    }

    Matrix::Matrix(){
        rows = 3;
        cols = 3;
        arr = nullptr;

        arr = new double*[rows];
            for(int i = 0; i < rows; i++){
                arr[i] = new double[cols];
            }
         for(int i = 0; i < rows; i++){
               for(int j = 0; j < cols; j++){
                      arr[i][j] = double(0);
                }
         }
    }
    Matrix::Matrix(int Rows, int Cols){
        rows = Rows;
        cols = Cols; 
        arr = new double*[Rows];

            for (int i = 0; i < Rows; i++) {
        arr[i] = new double[Cols];
    }
}
    Matrix::Matrix(Matrix& other)
    {
        rows = other.rows;
        cols = other.cols;
        arr = nullptr;

        if (rows > 0 && cols > 0) {
            arr = new double*[rows];
            for(int i = 0; i < rows; i++){
                arr[i] = new double[cols];
            }

if (rows == other.rows && cols == other.cols) {
    arr = new double*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new double[cols];
    }
    for (int a = 0; a < rows; a++) {
        for (int b = 0; b < cols; b++) {
            arr[a][b] = other.arr[a][b];
        }
    }
} else {
    throw std::runtime_error("matrix have different sizes");
}
        }
    }
    Matrix::~Matrix() noexcept {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

    Matrix Matrix::operator+(const Matrix &mat_){

        double** arr_ = arr;

        if(rows != mat_.rows or cols != mat_.cols){
            throw("Error: Cannot sum it because matrix have different sizes!");
        }

        Matrix out = *new Matrix;
        out.changeMatrix(arr_, mat_.rows, mat_.cols);

        out.SumMatrix(mat_);

        return out;
    }

    Matrix Matrix::operator-(const Matrix &mat_){
        double** arr_ = arr;

        if(rows != mat_.rows or cols != mat_.cols){
            throw("Error: Cannot sub it because matrix have different sizes!");
        }

        Matrix out = *new Matrix;
        out.changeMatrix(arr_, rows, cols);

        out.SubMatrix(mat_);

        return out;
    }

    bool Matrix::operator==(const Matrix &other){
        return this->EqMatrix(other);
    }

    void Matrix::operator=(const Matrix &other){
        rows = other.rows;
        cols = other.cols;
        arr = new double*[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new double[cols];
        }
        for(int a = 0; a < rows; a++){
            for(int b = 0; b < cols; b++){
                arr[a][b] = other.arr[a][b];
            }
        }
    }

    void Matrix::operator+=(const Matrix &other){
        if(rows != other.rows or cols != other.cols){
            throw("Error: Cannot sum it because matrix have different sizes!");
        }

        this->SumMatrix(other);
    }
    void Matrix::operator-=(const Matrix &other){
        if(rows != other.rows or cols != other.cols){
            throw("Error: Cannot sub it because matrix have different sizes!");
        }

        this->SubMatrix(other);
    }
    void Matrix::operator*=(int count){
        this->MulNumber(count);
    }
    void Matrix::operator*=(const Matrix &other){
        if(rows != other.rows or cols != other.cols){
            throw("Error: Cannot mul it because matrix have different sizes!");
        }

        this->MulMatrix(other);
    }

    Matrix Matrix::operator*(int count){
        double** arr_ = arr;
        Matrix out = *new Matrix;
        out.changeMatrix(arr_, rows, cols);

        out.MulNumber(count);
        
        return out;
    }
    Matrix Matrix::operator*(const Matrix &mat_){
        double** arr_ = arr;

        if(rows != mat_.rows or cols != mat_.cols){
            throw("Error: Cannot exp it because matrix have different sizes!");
        }

        Matrix out = *new Matrix;
        out.changeMatrix(arr_, rows, cols);

        out.MulMatrix(mat_);

        return out;
    }

    void Matrix::changeMatrix(double** arr_, int Rows, int Cols){
        cols = Cols;
        rows = Rows;
        arr = arr_;
    }

    void Matrix::setRows(int Rows){
        rows = Rows;
    }
    void Matrix::setCols(int Cols){
        cols = Cols;
    }
    void Matrix::setArr(double** arr_){
        arr = arr_;
    }
    int Matrix::getRows(){
        return rows;
    }
    int Matrix::getCols(){
        return cols;
    }
    double** Matrix::getArr(){
        return arr;
    }
    void Matrix::printMatrix(){
        cout << "rows: " << rows << "\n";
        cout << "cols: " << cols << "\n";

        for(int a = 0; a < rows; a++){
            for(int b = 0; b < cols; b++){
                cout << arr[a][b] << " ";
            }
            cout << "\n";
        }
    }

    bool Matrix::EqMatrix(const Matrix& other){
        if(rows == other.rows and cols == other.cols and arr == other.arr){
            return true;
        }
        return false;
    }

    Matrix Matrix::SumMatrix(const Matrix& other){
        if(rows != other.rows or cols != other.cols){
            throw("Error: Cannot sum it because matrix have different sizes!");
        }

        for(int a = 0; a < cols; a++){
            for(int b = 0; b < rows; b++){
                arr[a][b] += other.arr[a][b];
            }
        }

        Matrix out = *new Matrix;
        out.changeMatrix(arr, rows, cols);
        return out;
    }

    Matrix Matrix::SubMatrix(const Matrix& other){

        if(rows != other.rows or cols != other.cols){
            throw("Error: Cannot sub it"); 
        }

        for(int a = 0; a < cols; a++){
            for(int b = 0; b < rows; b++){
                arr[a][b] -= other.arr[a][b];
            }
        }
        Matrix out = *new Matrix;
        out.changeMatrix(arr, rows, cols);
        return out;
    }

    Matrix Matrix::MulNumber(const double num){
        for(int a = 0; a < cols; a++){
            for(int b = 0; b < rows; b++){
                arr[a][b] *= num;
            }
        }
        Matrix out = *new Matrix;
        out.changeMatrix(arr, rows, cols);
        return out;
    }

    Matrix Matrix::MulMatrix(const Matrix& other){
        if(rows != other.rows or cols != other.cols){
            throw("Error: Cannot exp it because matrix have different sizes!");
        }

        for(int a = 0; a < cols; a++){
            for(int b = 0; b < rows; b++){
                arr[a][b] *= other.arr[a][b];
            }
        }

        Matrix out = *new Matrix;
        out.changeMatrix(arr, rows, cols);
        return out;
    }

    Matrix Matrix::Transpose(){
        Matrix out = *new Matrix(cols, rows);

        double** arrT = new double*[rows];
        for (int i = 0; i < rows; i++){
            arrT[i] = new double[cols];
        }

        out.arr = arrT;

        for(int a = 0; a < rows; a++){
            for(int b = 0; b < cols; b++){
                out.arr[b][a] = arr[a][b];
            }
        }
        out.cols = rows;
        out.rows = cols;

        return out;
    }

    Matrix Matrix::CalcComplements(){

        if(cols != rows) throw("Error: Matrix is not square");
        Matrix in = *new Matrix;
        in.arr = this->arr;
        in.rows = this->rows;
        in.cols = this->cols;

        Matrix out = *new Matrix(rows, cols);
        out = getAlgAppend(in);

        return out;  
    }

/*int main(){
        
    Matrix matTest = *new Matrix();
    
    int a, b;
    a = 3; b = 3;

    double** matTestArr = new double*[a];
    for (int i = 0; i < a; i++){
        matTestArr[i] = new double[b];
    }

    int counter = 1;
    for(int y = 0; y < a; y++){
        for(int x = 0; x < b; x++){
            matTestArr[y][x] = counter;
            counter++;
        }
    }

    matTest.changeMatrix(matTestArr, a, b);
    matTest.printMatrix();
    matTest.CalcComplements().printMatrix();

}*/
