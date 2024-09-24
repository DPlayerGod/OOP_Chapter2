#include<bits/stdc++.h>

using namespace std;

// Lớp Phân số
class PhanSo {
private:
    int tu;  // Tử số
    int mau; // Mẫu số

public:
    // Hàm khởi tạo không tham số
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    // Hàm nhập phân số
    void nhap() {
        cout << "Nhập tử số: ";
        cin >> tu;
        cout << "Nhập mẫu số: ";
        cin >> mau;
        while (mau == 0) {
            cout << "Mẫu số phải khác 0. Nhập lại mẫu số: ";
            cin >> mau;
        }
    }

    // Hàm xuất phân số
    void xuat() {
        if (mau == 1) {
            cout << tu;
            return;
        }
        cout << tu << "/" << mau;
    }

    // Hàm rút gọn phân số
    void rutGon() {
        int ucln = timUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

    // Hàm tìm ước chung lớn nhất
    int timUCLN(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    // Hàm cộng phân số
    PhanSo cong(const PhanSo& ps) {
        PhanSo kq;
        kq.tu = tu * ps.mau + ps.tu * mau;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    // Hàm so sánh phân số lớn hơn
    bool lonHon(const PhanSo& ps) const {
        return tu * ps.mau > ps.tu * mau;
    }
};

// Hàm tính tổng của một dãy phân số
PhanSo tinhTong(const vector<PhanSo>& dayPhanSo) {
    PhanSo tong = dayPhanSo[0];
    for (size_t i = 1; i < dayPhanSo.size(); ++i) {
        tong = tong.cong(dayPhanSo[i]);
    }
    return tong;
}

// Hàm tìm phân số lớn nhất trong một dãy phân số
PhanSo timPhanSoLonNhat(const vector<PhanSo>& dayPhanSo) {
    PhanSo maxPhanSo = dayPhanSo[0];
    for (size_t i = 1; i < dayPhanSo.size(); ++i) {
        if (dayPhanSo[i].lonHon(maxPhanSo)) {
            maxPhanSo = dayPhanSo[i];
        }
    }
    return maxPhanSo;
}

int main() {
    int n;
    cout << "Nhập số lượng phân số: ";
    cin >> n;

    vector<PhanSo> dayPhanSo(n);
    
    // Nhập dãy phân số
    for (int i = 0; i < n; ++i) {
        cout << "Nhập phân số thứ " << i + 1 << ":\n";
        dayPhanSo[i].nhap();
    }

    // Tính tổng các phân số
    PhanSo tong = tinhTong(dayPhanSo);

    // Tìm phân số lớn nhất
    PhanSo maxPhanSo = timPhanSoLonNhat(dayPhanSo);

    // Xuất kết quả
    cout << "\nTổng của dãy phân số là: ";
    tong.xuat();

    cout << "\nPhân số lớn nhất là: ";
    maxPhanSo.xuat();

    return 0;
}
