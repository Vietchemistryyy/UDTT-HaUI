#include <bits/stdc++.h>
using namespace std;

// Ham D: thuat toan tham lam tinh so luong phan tu it nhat 
// co the lay tu day a de tong M > C
int D(double a[], int n, double C, double da_lay[], double &M) {
    M = 0;
    int dem = 0;
    int i = n - 1;
    while (i >= 0 && M <= C) {
        M += a[i];
        da_lay[dem++] = a[i];
        i--;
    }
    if (M <= C) return 0; // Khong co phuong an
    return dem;
}

// Ham BMH: tim vi tri xuat hien cua chuoi P trong chuoi Q
int BMH(char P[], char T[]) {
    int m = strlen(P);
    int n = strlen(T);

    if (m > n) return -1;

    int shift[256];
    for (int i = 0; i < 256; i++) shift[i] = m;
    for (int i = 0; i < m - 1; i++) shift[(char)P[i]] = m - i - 1;

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && P[m - 1 - k] == T[i - k]) k++;
        if (k == m) return i - m + 1;
        i += shift[(char)T[i]];
    }
    return -1;
}

int main() {
    int n = 10;
    double a[100] = {0.5, 1.2, 2.3, 3.1, 3.9, 4.5, 5.0, 6.1, 7.3, 8.5};
    double C = 15.0;
    char P[256] = "la";
    char Q[256] = "Xin chao moi nguoi toi la Viet";

    // Goi ham D
    double da_lay[100], M;
    int so_phan_tu = D(a, n, C, da_lay, M);

    // In ket qua cua D
    if (so_phan_tu > 0) {
        cout << "So luong phan tu it nhat co the lay la D = " << so_phan_tu << endl;
        cout << "Gia tri M = " << fixed << setprecision(2) << M << " lon hon " << C << endl;
        cout << "Cac gia tri da lay trong mang a: ";
        for (int i = 0; i < so_phan_tu; i++) {
            cout << da_lay[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Khong co phuong an de M > C" << endl;
    }

    // Goi ham BMH
    int vi_tri = BMH(P, Q);
    if (vi_tri != -1) 
        cout << "Chuoi P xuat hien trong chuoi Q tai vi tri: " << vi_tri << endl;
    else 
        cout << "Chuoi P khong xuat hien trong chuoi Q" << endl;

    return 0;
}

