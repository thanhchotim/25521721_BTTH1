#include <iostream>
#include <algorithm> 

using namespace std;

// Định nghĩa lớp Phân Số
class PhanSo {
private:
    int iTu, iMau;

public:
    // Hàm tìm Ước chung lớn nhất 
    int timUCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // Tính năng: Nhập phân số từ bàn phím
    
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> iTu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> iMau;
            if (iMau == 0) cout << "Mau so phai khac 0. Vui long nhap lai!\n";
        } while (iMau == 0);
    }

    // Tính năng: Rút gọn phân số về dạng tối giản
    
    void RutGon() {
        int ucln = timUCLN(iTu, iMau);
        iTu /= ucln;
        iMau /= ucln;
        
        // Xử lý dấu trừ cho đẹp 
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    // Tính năng: Xuất phân số ra màn hình
    
    void Xuat() {
        if (iMau == 1) {
            cout << iTu << endl;
        } else {
            cout << iTu << "/" << iMau << endl;
        }
    }
};

int main() {
    PhanSo ps; // Tạo một đối tượng ps từ lớp PhanSo
    
    cout << "--- Chuong trinh rut gon phan so ---\n";
    ps.Nhap();
    ps.RutGon();
    
    cout << "Phan so sau khi rut gon la: ";
    ps.Xuat();

    return 0;
}