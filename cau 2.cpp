#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

public:
    // Tính năng: Nhập phân số
    
    void Nhap() {
        cout << "Nhap tu so: "; cin >> iTu;
        do {
            cout << "Nhap mau so (khac 0): "; cin >> iMau;
            if (iMau == 0) cout << "Mau phai khac 0. Nhap lai: ";
        } while (iMau == 0);
    }

    // Tính năng: Xuất phân số
    
    void Xuat() {
        cout << iTu << "/" << iMau;
    }

    // Tính năng: So sánh giá trị với một phân số khác
  
    double GiaTri() {
        return (double)iTu / iMau;
    }
};

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n"; ps1.Nhap();
    cout << "Nhap phan so thu hai:\n"; ps2.Nhap();

    cout << "Phan so lon nhat la: ";
    if (ps1.GiaTri() >= ps2.GiaTri()) {
        ps1.Xuat();
    } else {
        ps2.Xuat();
    }
    cout << endl;
    return 0;
}