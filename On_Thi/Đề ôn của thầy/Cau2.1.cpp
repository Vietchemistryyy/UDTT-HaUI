#include <bits/stdc++.h>
using namespace std;

// Ham D: thuat toan tham lam tinh so luong phan tu nhieu nhat de duoc gia tri M khong vuot qua C
int D(double a[], int n, double C, double da_lay[], double &M) {
    M = 0;
    int dem = 0;
    int i = 0;
    while (i < n && M + a[i] <= C) {
        M += a[i];
        da_lay[dem++] = a[i];
        i++;
    }
    return dem;
}

// Ham BMH: kiem tra Q co la chuoi con cua P khong
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
    double a[10] = {0.5, 1.2, 2.3, 3.1, 3.9, 4.5, 5.0, 6.1, 7.3, 8.5};
    double C = 8.5;
    char P[256] = "Xin chao moi nguoi toi la Viet";
    char Q[256] = "Viet";

    // Goi ham D
    double da_lay[100], M = 0;
    int so_phan_tu = D(a, n, C, da_lay, M);

    // In ket qua cua D
    cout << "So luong phan tu nhieu nhat co the lay la D = " << so_phan_tu << endl;
    cout << "Gia tri M = " << fixed << setprecision(2) << M << " khong vuot qua " << C << endl;
    if (so_phan_tu > 0) {
        cout << "Cac gia tri da lay trong mang a: ";
        for (int i = 0; i < so_phan_tu; i++) {
            cout << da_lay[i] << " ";
        }
        cout << endl;
    }

    // Goi ham BMH
    if (BMH(Q, P) != -1) cout << "Chuoi Q la chuoi con cua chuoi P" << endl;
    else cout << "Chuoi Q khong phai la chuoi con cua chuoi P" << endl;
    
    return 0;
}

