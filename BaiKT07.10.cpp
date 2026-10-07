#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct KhachHang {
    int maKH;
    string tenKH;
    string soDT;
    double tongTien;
};

void nhapDanhSach(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Khach hang thu " << i + 1 << " ---\n";
        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();
        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);
        cout << "So dien thoai: ";
        getline(cin, a[i].soDT);
        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

void xuatDanhSach(KhachHang a[], int n) {
    cout << left << setw(10) << "Ma KH"
         << setw(25) << "Ten khach hang"
         << setw(15) << "So dien thoai"
         << setw(15) << "Tong tien" << endl;
    cout << string(65, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << a[i].maKH
             << setw(25) << a[i].tenKH
             << setw(15) << a[i].soDT
             << setw(15) << fixed << setprecision(2) << a[i].tongTien << endl;
    }
}

void insertionSort(KhachHang a[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].tongTien > key.tongTien) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int timKiemNhiPhan(KhachHang a[], int left, int right, double x) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (a[mid].tongTien == x) return mid;
    if (a[mid].tongTien > x) return timKiemNhiPhan(a, left, mid - 1, x);
    return timKiemNhiPhan(a, mid + 1, right, x);
}

void timKhachHangTheoTien(KhachHang a[], int n, double x) {
    int pos = timKiemNhiPhan(a, 0, n - 1, x);
    if (pos == -1) {
        cout << "Khong tim thay khach hang nao co tong tien = " << x << endl;
        return;
    }
    int l = pos, r = pos;
    while (l - 1 >= 0 && a[l - 1].tongTien == x) l--;
    while (r + 1 < n && a[r + 1].tongTien == x) r++;

    cout << "Cac khach hang co tong tien = " << x << ":\n";
    cout << left << setw(10) << "Ma KH"
         << setw(25) << "Ten khach hang"
         << setw(15) << "So dien thoai"
         << setw(15) << "Tong tien" << endl;
    cout << string(65, '-') << endl;
    for (int i = l; i <= r; i++) {
        cout << left << setw(10) << a[i].maKH
             << setw(25) << a[i].tenKH
             << setw(15) << a[i].soDT
             << setw(15) << fixed << setprecision(2) << a[i].tongTien << endl;
    }
}

int main() {
    int n;
    do {
        cout << "Nhap so luong khach hang n: ";
        cin >> n;
    } while (n <= 0 || n > 1000);

    KhachHang a[1000];

    nhapDanhSach(a, n);
    cout << "\n===== DANH SACH KHACH HANG VUA NHAP =====\n";
    xuatDanhSach(a, n);

    insertionSort(a, n);
    cout << "\n===== DANH SACH SAU KHI SAP XEP TANG DAN THEO TONG TIEN =====\n";
    xuatDanhSach(a, n);

    double x;
    cout << "\nNhap tong tien X can tim: ";
    cin >> x;
    cout << endl;
    timKhachHangTheoTien(a, n, x);

    return 0;
}
