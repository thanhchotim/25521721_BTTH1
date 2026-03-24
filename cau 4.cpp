#include <iostream>
using namespace std;

class Ngay {
private:
    int iNgay, iThang, iNam;

public:
    // Tính năng: Kiểm tra năm nhuận
    bool LaNamNhuan() {
        return (iNam % 400 == 0) || (iNam % 4 == 0 && iNam % 100 != 0);
    }

    // Tính năng: Trả về số ngày tối đa trong tháng
    int TimSoNgayTrongThang() {
        int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (iThang == 2 && LaNamNhuan()) return 29;
        return ngayTrongThang[iThang];
    }

    // Tính năng: Nhập ngày tháng năm từ bàn phím [cite: 12]
    void Nhap() {
        cout << "Nhap ngay, thang, nam: ";
        cin >> iNgay >> iThang >> iNam;
    }

    // Tính năng: Tìm và in ngày kế tiếp [cite: 12]
    void XuatNgayKeTiep() {
        int d = iNgay, m = iThang, y = iNam;
        d++;
        if (d > TimSoNgayTrongThang()) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        cout << "Ngay ke tiep la: " << d << "/" << m << "/" << y << endl;
    }
};

int main() {
    Ngay homNay;
    homNay.Nhap();
    homNay.XuatNgayKeTiep();
    return 0;
}