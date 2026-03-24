#include <iostream>
#include <string>
using namespace std;

class HocSinh {
private:
    string sHoTen;
    float fToan, fVan;

public:
    // Tính năng: Nhập họ tên, điểm toán, điểm văn [cite: 13]
    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore(); // Xóa bộ nhớ đệm để getline không bị trôi
        getline(cin, sHoTen);
        cout << "Nhap diem Toan: "; cin >> fToan;
        cout << "Nhap diem Van: "; cin >> fVan;
    }

    // Tính năng: Tính điểm trung bình và xuất kết quả 
    void XuatKetQua() {
        float fDTB = (fToan + fVan) / 2;
        cout << "Hoc sinh: " << sHoTen << endl;
        cout << "Diem trung binh: " << fDTB << endl;
    }
};

int main() {
    HocSinh hs;
    hs.Nhap();
    hs.XuatKetQua();
    return 0;
}