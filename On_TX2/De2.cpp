#include <bits/stdc++.h>
using namespace std;

struct GiaoTrinh {
	char tengiaotrinh[100];
	char tacgia[100];
	int giabia;
};

// Tieu de danh sach
void title() {
	cout << "------------------------------------------------------------------\n";
	cout << setw(30) << "TEN GIAO TRINH"
		 << setw(20) << "TAC GIA"
		 << setw(15) << "GIA BIA" << endl;
	cout << "------------------------------------------------------------------\n";
}

// Sap xep chi so tang dan theo gia bia
void sortIndexByGia(GiaoTrinh d[], int idx[], int n) {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (d[idx[i]].giabia > d[idx[j]].giabia)
				swap(idx[i], idx[j]);
}

// Thuat toan C - tham lam chon giao trinh mua nhieu nhat voi tong gia <= p
void C(GiaoTrinh d[], int n, int p, int selected[], int &count) {
	int idx[100];
	for (int i = 0; i < n; i++) idx[i] = i;

	sortIndexByGia(d, idx, n);

	count = 0;
	for (int i = 0; i < n && p >= d[idx[i]].giabia; ++i) {
		selected[count++] = idx[i];
		p -= d[idx[i]].giabia;
	}
}

// Thuat toan BMH - Boyer Moore Horspool tim vi tri dau cua P trong T
int BMH(char T[], char P[]) {
	int m = strlen(P);
	int n = strlen(T);
	if (m > n) return -1;

	int shift[256];
	for (int i = 0; i < 256; ++i)
		shift[i] = m;
		
	for (int i = 0; i < m - 1; ++i)
		shift[(char)P[i]] = m - i - 1;
	
	int i = m - 1;
	while (i < n) {
		int k = 0;
		while (k < m && P[m - 1 - k] == T[i - k]) ++k;
		if (k == m) return i - m + 1;
		i += shift[(char)T[i]];
	}
	return -1;
}

// Kiem tra xem ten giao trinh co chua "lap trinh" hay khong
bool chuaTuLapTrinh(char ten[]) {
	return BMH(ten, (char*)"Lap trinh") != -1 || BMH(ten, (char*)"lap trinh") != -1;
}
//bool chuaTuLapTrinh(char ten[]) {
//	char temp[100];
//	strcpy(temp, ten);
//	for (int i = 0; temp[i]; ++i) {
//		temp[i] = tolower(temp[i]); // viet thuong tat ca
//	}
//	return BMH(temp, (char*)"lap trinh") != -1;
//}

int main() {
	int n = 6;
	GiaoTrinh d[6] = {
		{" co so lap trinh Python co ban", "Nguyen Van A", 45000},
		{"Cau truc du lieu", "Tran Thi B", 50000},
		{"Lap trinh huong doi tuong", "Le Van C", 55000},
		{"Co so du lieu", "Pham Thi D", 60000},
		{"Thiet ke phan mem", "Ngo Van E", 40000},
		{"He dieu hanh", "Dinh Thi F", 70000}
	};

	int p = 150000; // So tien toi da

	cout << "------------------- DANH SACH GIAO TRINH -------------------\n";
	title();
	for (int i = 0; i < n; i++) {
		cout << setw(30) << d[i].tengiaotrinh
			 << setw(20) << d[i].tacgia
			 << setw(15) << d[i].giabia << endl;
	}
	cout << endl;

	// Thuat toan C
	int selectedC[100];
	int countC;
	C(d, n, p, selectedC, countC);

	cout << "So giao trinh co the mua voi " << p << " VND la: " << countC << endl;
	if (countC > 0) {
		cout << "\n       DANH SACH GIAO TRINH MUA DUOC\n";
		title();
		for (int i = 0; i < countC; i++) {
			cout << setw(30) << d[selectedC[i]].tengiaotrinh
				 << setw(15) << d[selectedC[i]].giabia << endl;
		}
	} else {
		cout << "==> Khong mua duoc giao trinh nao voi so tien " << p << endl;
	}

	// Thuat toan BMH
	cout << "\n======= DANH SACH GIAO TRINH LIEN QUAN DEN 'lap trinh' =======\n";
	int countBMH = 0;
	for (int i = 0; i < n; i++) {
		if (chuaTuLapTrinh(d[i].tengiaotrinh)) {
			if (countBMH == 0) title();
			cout << setw(30) << d[i].tengiaotrinh
				 << setw(20) << d[i].tacgia
				 << setw(15) << d[i].giabia << endl;
			countBMH++;
		}
	}
	if (countBMH == 0) {
		cout << "Khong co giao trinh nao chua tu 'lap trinh'\n";
	}

	return 0;
}

