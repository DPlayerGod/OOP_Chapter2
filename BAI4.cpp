#include<bits/stdc++.h>

using namespace std;

class HocSinh {
private:
    string maHocSinh;
    string hoTen;
    string gioiTinh;
    long double diemToan, diemLy, diemHoa;

public:
    // Hàm nhập thông tin học sinh
    void nhapThongTin() {
        cout << "Nhập mã học sinh: ";
        getline(cin, maHocSinh);
        cout << "Nhập họ và tên: ";
        getline(cin, hoTen);
        cout << "Nhập giới tính: ";
        getline(cin, gioiTinh);
        cout << "Nhập điểm Toán: ";
        cin >> diemToan;
        cout << "Nhập điểm Lý: ";
        cin >> diemLy;
        cout << "Nhập điểm Hóa: ";
        cin >> diemHoa;
    }

    // Hàm tính điểm trung bình
    long double tinhDiemTrungBinh() const {
        return (diemLy + diemToan + diemHoa) / 3;
    }

    // Hàm xuất thông tin học sinh
    void xuatThongTin() const {
        cout << "Thông tin học sinh\n";
        cout << "Mã học sinh: " << maHocSinh << '\n';
        cout << "Họ và tên: " << hoTen << '\n';
        cout << "Giới tính: " << gioiTinh << '\n';
        cout << "Điểm Toán: " << diemToan << '\n';
        cout << "Điểm Lý: " << diemLy << '\n';
        cout << "Điểm Hóa: " << diemHoa << '\n';
        cout << "Điểm trung bình: " << tinhDiemTrungBinh() << '\n';
    }
};

int main() {
    HocSinh hs;

    // Nhập thông tin học sinh
    hs.nhapThongTin();

    // Xuất thông tin học sinh
    hs.xuatThongTin();

    return 0;
}

