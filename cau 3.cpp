#include <iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;
public:
    // Hàm hỗ trợ tìm UCLN để rút gọn
    int UCLN(int a, int b) {
        a = abs(a); b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void Nhap() {
        cout << "Nhap tu: "; cin >> iTu;
        do {
            cout << "Nhap mau (khac 0): "; cin >> iMau;
        } while (iMau == 0);
    }

    void RutGon() {
        int u = UCLN(iTu, iMau);
        iTu /= u;
        iMau /= u;
    }

    void Xuat() {
        RutGon();
        if (iMau == 1) cout << iTu;
        else cout << iTu << "/" << iMau;
    }

    // Tính năng: Cộng hai phân số
    // Input: PhanSo ps2
    // Output: Trả về đối tượng PhanSo mới là tổng
    PhanSo Cong(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = iTu * ps2.iMau + ps2.iTu * iMau;
        kq.iMau = iMau * ps2.iMau;
        return kq;
    }

    // Tính năng: Trừ hai phân số
    // Input: PhanSo ps2
    // Output: Trả về đối tượng PhanSo mới là hiệu
    PhanSo Tru(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = iTu * ps2.iMau - ps2.iTu * iMau;
        kq.iMau = iMau * ps2.iMau;
        return kq;
    }

    // Tính năng: Nhân hai phân số
    // Input: PhanSo ps2
    // Output: Trả về đối tượng PhanSo mới là tích
    PhanSo Nhan(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = iTu * ps2.iTu;
        kq.iMau = iMau * ps2.iMau;
        return kq;
    }

    // Tính năng: Chia hai phân số
    // Input: PhanSo ps2
    // Output: Trả về đối tượng PhanSo mới là thương
    PhanSo Chia(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = iTu * ps2.iMau;
        kq.iMau = iMau * ps2.iTu;
        return kq;
    }
};

int main() {
    PhanSo ps1, ps2, kq;
    cout << "Nhap phan so 1:\n"; ps1.Nhap();
    cout << "Nhap phan so 2:\n"; ps2.Nhap();

    cout << "\n--- Ket qua cac phep tinh ---";
    cout << "\nTong: "; kq = ps1.Cong(ps2); kq.Xuat();
    cout << "\nHieu: "; kq = ps1.Tru(ps2); kq.Xuat();
    cout << "\nTich: "; kq = ps1.Nhan(ps2); kq.Xuat();
    cout << "\nThuong: "; kq = ps1.Chia(ps2); kq.Xuat();
    cout << endl;

    return 0;
}