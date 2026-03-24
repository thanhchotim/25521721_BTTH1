#include <iostream>
#include <algorithm> // Thư viện để dùng hàm __gcd có sẵn hoặc tự viết

using namespace std;

// Định nghĩa lớp Phân Số
class PhanSo {
private:
    int iTu, iMau;

public:
    // Hàm tìm Ước chung lớn nhất (sử dụng thuật toán Euclid)
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
    // Input: Không có
    // Output: Cập nhật giá trị cho iTu và iMau
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
    // Input: Phân số hiện tại
    // Output: Phân số đã được chia cả tử và mẫu cho UCLN
    void RutGon() {
        int ucln = timUCLN(iTu, iMau);
        iTu /= ucln;
        iMau /= ucln;
        
        // Xử lý dấu trừ cho đẹp (ví dụ 1/-2 thành -1/2)
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    // Tính năng: Xuất phân số ra màn hình
    // Input: Phân số đã xử lý
    // Output: In ra định dạng tu/mau hoặc số nguyên nếu mẫu = 1
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