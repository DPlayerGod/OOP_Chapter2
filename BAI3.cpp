#include<bits/stdc++.h>

#define int long long 

using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> dat;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        dat.resize(rows + 3, vector<int>(cols + 3, 0));
    }

    // Hàm nhập ma trận từ bàn phím
    void inputMatrix() {
        cout << "Nhập ma trận " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
               cin >> dat[i][j];
            }
        }
    }

    // Hàm in ma trận
    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << dat[i][j] << " ";
            }
            cout << '\n';
        }
    }

    // Phép cộng hai ma trận
    Matrix operator + (const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Kích thước của hai ma trận không giống nhau, không thể cộng.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.dat[i][j] = dat[i][j] + other.dat[i][j];
            }
        }
        return result;
    }

    // Phép trừ hai ma trận
    Matrix operator - (const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Kích thước của hai ma trận không giống nhau, không thể trừ.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.dat[i][j] = dat[i][j] - other.dat[i][j];
            }
        }
        return result;
    }

    // Phép nhân hai ma trận
    Matrix operator * (const Matrix &other) {
        if (cols != other.rows) {
            throw invalid_argument("Số cột của ma trận thứ nhất phải bằng số hàng của ma trận thứ hai.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.dat[i][j] += dat[i][k] * other.dat[k][j];
                }
            }
        }
        return result;
    }
};

int32_t main() {
    int rows1, cols1;
    cout << "Nhập số hàng của ma trận thứ nhất: ";
    cin >> rows1;
    cout << "Nhập số cột của ma trận thứ nhất: ";
    cin >> cols1;

    Matrix matrix1(rows1, cols1);
    matrix1.inputMatrix();

   
    int rows2, cols2;
    cout << "Nhập số hàng của ma trận thứ hai: ";
    cin >> rows2;
    cout << "Nhập số cột của ma trận thứ hai: ";
    cin >> cols2;

    Matrix matrix2(rows2, cols2);
    matrix2.inputMatrix();

    // Tính tổng
    try {
        Matrix sumMatrix = matrix1 + matrix2;
        cout << "Tổng của hai ma trận là:\n";
        sumMatrix.printMatrix();
    } catch (invalid_argument &e) {
        cout << e.what() << '\n';
    }

    // Tính hiệu
    try {
        Matrix diffMatrix = matrix1 - matrix2;
        cout << "Hiệu của hai ma trận là:\n";
        diffMatrix.printMatrix();
    } catch (invalid_argument &e) {
        cout << e.what() << '\n';
    }

    // Tính tích
    try {
        Matrix prodMatrix = matrix1 * matrix2;
        cout << "Tích của hai ma trận là:\n";
        prodMatrix.printMatrix();
    } catch (invalid_argument &e) {
        cout << e.what() << '\n';
    }

    return 0;
}