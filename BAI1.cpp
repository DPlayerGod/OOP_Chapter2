#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu; 
    int mau;

public:
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

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
    void xuat() const {
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

    // Hàm cộng 2 phân số
    PhanSo cong(const PhanSo& ps) {
        PhanSo kq;
        kq.tu = tu * ps.mau + ps.tu * mau;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    // Hàm trừ 2 phân số
    PhanSo tru(const PhanSo& ps) {
        PhanSo kq;
        kq.tu = tu * ps.mau - ps.tu * mau;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    // Hàm nhân 2 phân số
    PhanSo nhan(const PhanSo& ps) {
        PhanSo kq;
        kq.tu = tu * ps.tu;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    // Hàm chia 2 phân số
    PhanSo chia(const PhanSo& ps) {
        PhanSo kq;
        kq.tu = tu * ps.mau;
        kq.mau = mau * ps.tu;
        kq.rutGon();
        return kq;
    }
};


int main() {
    PhanSo ps1, ps2;
    
    cout << "Nhập phân số thứ nhất: \n";
    ps1.nhap();
    
    cout << "Nhập phân số thứ hai: \n";
    ps2.nhap();
    
    PhanSo tong = ps1.cong(ps2);
    PhanSo hieu = ps1.tru(ps2);
    PhanSo tich = ps1.nhan(ps2);
    PhanSo thuong = ps1.chia(ps2);
    
    cout << "\nKết quả: \n";
    cout << "Tổng: ";
    tong.xuat();
    
    cout << "\nHiệu: ";
    hieu.xuat();
    
    cout << "\nTích: ";
    tich.xuat();
    
    cout << "\nThương: ";
    thuong.xuat();
    
    return 0;
}
