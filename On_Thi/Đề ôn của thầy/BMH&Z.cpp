#include <bits/stdc++.h>
using namespace std;

/*
Thuat toan BMH (Boyer-Moore-Horspool):
- Muc tieu: Kiem tra chuoi Q co la chuoi con cua chuoi P hay khong, tra ve vi tri xuat hien dau tien.

Vi du:
P = "Toi ten la Viet"
Q = "Viet"
m = 4 (do dai Q), n = 16 (do dai P)

Buoc 1: Tao bang shift, voi tat ca cac ki tu ban dau deu co gia tri m (4)
Buoc 2: Cap nhat shift theo cac ki tu cua Q ngoai tru ki tu cuoi:
    shift['V'] = 3
    shift['i'] = 2
    shift['e'] = 1
==> Do khong tinh shift ki tu cuoi nen cong thuc tinh shift se = m - vi tri - 1 (understand?)
Buoc 3: Bat dau so sanh tu vi tri i = m - 1 = 3 tro di
    Neu khong khop, dich sang theo shift[T[i]]

Loi ich: Chi so sanh 1 lan tu phai sang trai, neu khong khop thi dich xa hon chu khong can di tung buoc nhu brute-force.
*/

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

/*
Thuat toan Z (Z-Algorithm):
- Muc tieu: Tim xem Q co xuat hien trong P khong (Q la chuoi con cua P)

Buoc 1: Noi chuoi pattern = Q va text = P thanh:
        concat = Q + '$' + P

Vi du:
Q = "Viet"
P = "Toi ten la Viet"
=> concat = "Viet$Toi ten la Viet"

Buoc 2: Xay dung mang Z[] voi Z[i] la do dai xau con lon nhat bat dau tai i cung trung voi prefix

Buoc 3: Neu co vi tri i nao trong concat co Z[i] = do dai Q, thi tim duoc Q trong P tai vi tri i - do dai Q - 1

Loi ich: Thuat toan nhanh va don gian, chi can tinh mang Z 1 lan
*/

int Z_algo(char P[], char Q[]) {
    string pattern = Q;
    string text = P;
    string concat = pattern + '$' + text;

    int l = 0, r = 0;
    int len = concat.length();
    vector<int> Z(len, 0);

    for (int i = 1; i < len; i++) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);

        while (i + Z[i] < len && concat[Z[i]] == concat[i + Z[i]])
            Z[i]++;

        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }

        if (Z[i] == pattern.length()) {
            return i - pattern.length() - 1;
        }
    }
    return -1;
}

int main() {
    char P[256] = "Xin chao moi nguoi toi la Viet";
    char Q[256] = "Viet";

    // Goi ham Z_algo
    if (Z_algo(P, Q) != -1)
        cout << "Chuoi Q la con cua chuoi P";
    else
        cout << "Chuoi Q khong phai la chuoi con cua chuoi P";
    cout << endl;

    // Goi ham BMH
    if (BMH(Q, P) != -1)
        cout << "Chuoi Q la chuoi con cua chuoi P" << endl;
    else
        cout << "Chuoi Q khong phai la chuoi con cua chuoi P" << endl;

    return 0;
}

