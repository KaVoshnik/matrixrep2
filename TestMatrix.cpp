#include <gtest/gtest.h>
#include "/home/kavo/matr/matrix_class/include/matrix.h"
#include "/home/kavo/matr/matrix_class/src/matrix_class.cpp"

class MatrixTest : public ::testing::Test {
protected:

    Matrix matrix;
    Matrix matrix1;
    Matrix matrix2;
};

TEST(MatrixTest, DefaultConstructor) {
    Matrix matrix;

    ASSERT_EQ(matrix.getRows(), 0);
    ASSERT_EQ(matrix.getCols(), 0);
}

// Test the parameterized constructor
TEST(MatrixTest, ParameterizedConstructor) {
    Matrix matrix(3, 3);

    ASSERT_EQ(matrix.getRows(), 3);
    ASSERT_EQ(matrix.getCols(), 3);
}

// Test the copy constructor
TEST(MatrixTest, CopyConstructor) {
    Matrix matrix(3, 3);

    Matrix copy(matrix);
}

TEST_F(MatrixTest, ChangeMatrix) {

    double** arr = new double*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new double[3];
    }

    matrix.changeMatrix(arr, 3, 3);

    ASSERT_EQ(matrix.getRows(), 3);
    ASSERT_EQ(matrix.getCols(), 3);
}

TEST_F(MatrixTest, SetRows) {
    matrix.setRows(3);
    ASSERT_EQ(matrix.getRows(), 3);
}

// Test case for setCols function
TEST_F(MatrixTest, SetCols) {
    matrix.setCols(4);
    ASSERT_EQ(matrix.getCols(), 4);
}

// Test case for setArr function
TEST_F(MatrixTest, SetArr) {
    double** arr = new double*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new double[4];
    }
    matrix.setArr(arr);
    ASSERT_EQ(matrix.getArr(), arr);
}

// Test case for getRows function
TEST_F(MatrixTest, GetRows) {
    matrix.setRows(3);
    ASSERT_EQ(matrix.getRows(), 3);
}

// Test case for getCols function
TEST_F(MatrixTest, GetCols) {
    matrix.setCols(4);
    ASSERT_EQ(matrix.getCols(), 4);
}

// Test case for getArr function
TEST_F(MatrixTest, GetArr) {
    double** arr = new double*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new double[4];
    }
    matrix.setArr(arr);
    ASSERT_EQ(matrix.getArr(), arr);
}

TEST_F(MatrixTest, PrintMatrix) {

    std::ostream nullStream(nullptr);
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(nullStream.rdbuf());
    
    matrix.printMatrix();
    
    std::cout.rdbuf(oldCoutBuffer);
    
}

// Test case for EqMatrix function
TEST_F(MatrixTest, EqMatrix) {
    Matrix matrix1;
    Matrix matrix2;

    ASSERT_TRUE(matrix1.EqMatrix(matrix2));

}

// Test case for SumMatrix function
TEST_F(MatrixTest, SumMatrix) {
    Matrix matrix1;
    Matrix matrix2;

    ASSERT_THROW(matrix1.SumMatrix(matrix2), const char*);
}

// Test case for SubMatrix function
TEST_F(MatrixTest, SubMatrix) {
    Matrix matrix1;
    Matrix matrix2;

    ASSERT_THROW(matrix1.SubMatrix(matrix2), const char*);
}

// Test case for MulNumber function
TEST_F(MatrixTest, MulNumber) {
    Matrix matrix;

    double num = 2.0;
    Matrix Result(3, 3);

    (matrix * num) = Result;

    ASSERT_TRUE(matrix == Result);
}

// Test case for MulMatrix function
TEST_F(MatrixTest, MulMatrix) {
    Matrix matrix1;
    Matrix matrix2;

    ASSERT_THROW(matrix1.MulMatrix(matrix2), const char*);
}

TEST(MatrixOperatorTest, OperatorPlus) {
    Matrix matrix1;
    Matrix matrix2;

    Matrix result = matrix1 + matrix2;

    ASSERT_TRUE(result == (matrix1 + matrix2));
}

// Test case for operator-
TEST(MatrixOperatorTest, OperatorMinus) {
    Matrix matrix1;
    Matrix matrix2;

    Matrix result = matrix1 - matrix2;

        ASSERT_TRUE(result == (matrix1 - matrix2));
}

// Test case for operator==
TEST(MatrixOperatorTest, OperatorEqualEqual) {
    Matrix matrix1;
    Matrix matrix2;

    ASSERT_TRUE(matrix1 == matrix2);
}

// Test case for operator=
TEST(MatrixOperatorTest, OperatorAssignment) {
    Matrix matrix1;
    Matrix matrix2;

    matrix1 = matrix2;

    ASSERT_TRUE(matrix1 == matrix2);
}

// Test case for operator+=
TEST(MatrixOperatorTest, OperatorPlusEqual) {
    Matrix matrix1;
    Matrix matrix2;

    matrix1 += matrix2;

    ASSERT_TRUE(matrix1 == matrix2);
}

// Test case for operator-=
TEST(MatrixOperatorTest, OperatorMinusEqual) {
    Matrix matrix1;
    Matrix matrix2;

    matrix1 -= matrix2;

    ASSERT_TRUE(matrix1 == matrix2);
}

// Test case for operator*=
TEST(MatrixOperatorTest, OperatorMultiplyEqual) {
    Matrix matrix;
    int count = 2;

    matrix *= count;

    ASSERT_TRUE(matrix == (matrix * count));
}

// Test case for operator*
TEST(MatrixOperatorTest, OperatorMultiply) {
    Matrix matrix1;
    Matrix matrix2;

    Matrix result = matrix1 * matrix2;

    ASSERT_TRUE(result == (matrix1 * matrix2));
}

int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}