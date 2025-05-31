#include<bits/stdc++.h>
using namespace std;

struct CongViec {
	string maCV;
	string batdau;
	double thoigian; // hour
};	

int n = 6;
CongViec c[10] = {
	{"CV001", "08:00", 0.5},
	{"CV002", "08:30", 1.0},
	{"CV003", "09:30", 0.25},
	{"CV004", "10:00", 2.0},
	{"CV005", "13:00", 0.4},
	{"CV006", "15:00", 0.75}
};

string L[10] = {"An", "Binh", "Chi", "Dung", "Hoa", "Khanh"};
int a[100], dd[100], countA3_5 = 0;

void tieude() {
	cout << "----------------------------------------------------------------------------\n";
	cout << "STT";
	cout << setw(15) << "MA CV";
	cout << setw(15) << "BAT DAU";
	cout << setw(15) << "THOI GIAN" << endl;
	cout << "----------------------------------------------------------------------------\n";
}

// A1: In danh sach nguoc bang de quy
void A1(CongViec c[], int n) {
	if (n == 0) return;
	cout << n;
	cout << setw(15) << c[n - 1].maCV;
	cout << setw(15) << c[n - 1].batdau;
	cout << setw(15) << c[n - 1].thoigian << endl;
	A1(c, n - 1);
}

// A2: Dem so cong viec <= 0.5 gio bang chia de tri
int A2(CongViec c[], int l, int r) {
	if (l > r) return 0;
	if (l == r) return c[l].thoigian <= 0.5 ? 1 : 0;
	int m = (l + r) / 2;
	return A2(c, l, m) + A2(c, m + 1, r);
}

// A3: Quay lui liet ke cac phuong an phan cong
void showA3_5(CongViec c[], string L[]) {
	for (int i = 0; i < n; i++) {
		cout << c[i].maCV << " -> " << L[i] << " | ";
	}
	cout << endl;
	countA3_5++;
}

void A3(CongViec c[], string L[], int k) {
	if (k == n) {
		showA3_5(c, L);
		return;
	}
	for (int i = k; i < n; i++) {
		swap(L[k], L[i]);
		A3(c, L, k + 1);
		swap(L[k], L[i]);
	}
}

int main() {
	cout << "Danh sach cong viec:\n";
	tieude();
	for (int i = 0; i < n; i++) {
		cout << i + 1;
		cout << setw(15) << c[i].maCV;
		cout << setw(15) << c[i].batdau;
		cout << setw(15) << c[i].thoigian << endl;
	}

	cout << "\nDanh sach cong viec theo thu tu nguoc:\n";
	tieude();
	A1(c, n);

	cout << "\nSo cong viec co thoi gian <= 0.5 gio: " << A2(c, 0, n - 1) << "\n";

	cout << "\nCac phuong an phan cong:\n";
	A3(c, L, 0);
	cout << "\nTong so cach phan cong: " << countA3_5 << "\n";
}

