#include<bits/stdc++.h>

using namespace std;
struct CauThu{
	string tencauthu;
	int tuoi;
	int soao;
	double luong;
};
void tieude(){
	cout << "-------------------------------------------------------------------------\n";
	cout << setw(18) << "TEN CAU THU";
	cout << setw(18) << "TUOI";
	cout << setw(18) << "SO AO";
	cout << setw(18) << "LUONG" << endl;
	cout << "-------------------------------------------------------------------------\n";
}
// In danh sach cau thu bang de quy ( in xuoi )
void A1(CauThu d[], int n){
	if(n == 0){
		return;
	}
	A1(d, n - 1);
	cout << setw(18) << d[n - 1].tencauthu;
	cout << setw(18) << d[n - 1].tuoi;
	cout << setw(18) << d[n - 1].soao;
	cout << setw(18) << d[n - 1].luong << endl;
}
// In nguoc
void A11(CauThu d[], int n){
	if(n == 0){
		return;
	}
	
	cout << setw(18) << d[n - 1].tencauthu;
	cout << setw(18) << d[n - 1].tuoi;
	cout << setw(18) << d[n - 1].soao;
	cout << setw(18) << d[n - 1].luong << endl;
	A11(d, n - 1);
}
// Dem so cau thu lon hon 35 tuoi bang chia de tri
int A2(CauThu d[], int left, int right){
	if(left == right){
		if(d[left].tuoi > 35){
			return 1;
		}
		return 0;
	}
	int mid = (left + right) / 2;
	int count_left = A2(d, left, mid);
	int count_right = A2(d, mid + 1, right);
	return count_left + count_right;
}

// Tra ve cau thu co luong cao nhat bang chia de tri
CauThu A3(CauThu d[], int left, int right){
	if(left == right){
		return d[left];
	}
	int mid = (left + right) / 2;
	CauThu maxLeft = A3(d, left, mid);
	CauThu maxRight = A3(d, mid + 1, right);
	return (maxLeft.luong > maxRight.luong) ? maxLeft : maxRight;
}
// Chon 6 cau thu tu 7 dung backtracking
void show_A4(CauThu d[], int a[], int n){
	for(int i = 0; i < 6; i++){
		int idx = a[i];
		cout << " (" << d[idx].tencauthu << " - " << d[idx].soao << ") ";
	}
	cout << endl;
}
void A4(CauThu d[], int a[], int n, int k, int start, int &count_config1){
	for(int i = start; i < n; i++){
		a[k] = i;
		if(k == 5){
			show_A4(d, a, n);
			count_config1++;
		}
		else{
			A4(d, a, n, k + 1, i + 1, count_config1);
		}
	}
	
}
// Xep 7 cau thu vao 7 cho
void show_A5(CauThu d[], int a[], int n){
	for(int i = 0; i < n; i++){
		int idx = a[i];
		cout << " (" << d[idx].tencauthu << " - " << d[idx].soao 	<< ") ";
	}
	cout << endl;
	
}
void A5(CauThu d[], int a[], int dd[], int n, int k, int &count_config2){
	for(int i = 0; i < n; i++){
		if(dd[i] == 0){
			a[k] = i;
			dd[i] = 1;
			if(k == n - 1){
				show_A5(d, a, n);
				count_config2++;
			}
			else{
				A5(d, a, dd, n, k + 1, count_config2);
			}
			dd[i] = 0;
		}
	}
}
int main(){
	int n = 7, a[100] = {0}, dd[100] = {0}, count_config1 = 0, count_config2 = 0;
	CauThu d[7] = {
		{"Cristiano Ronaldo", 40, 7, 450000},
		{"Lionel Messi", 38, 10, 500000},
		{"Neymar JR", 34, 11, 380000},
		{"David Degea", 39, 1, 400000},
		{"Thiery Henry", 36, 20, 410000},
		{"David Beckham", 35, 41, 360000},
		{"Kylian Mbappe", 26, 10, 430000},
	};
	cout << "\n\t\t\t\tDANH SACH CAU THU\n";
	tieude();	
	A1(d, n);
	
//	cout << endl;
//	cout << "\n\t\t\t\tDANH SACH CAU THU\n";
//	tieude();	
//	A11(d, n);
//	
	cout << endl;
//	cout << "\n\t\t\tDANH SACH CAU TREN 35 TUOI\n";
//	tieude();
//	A2(d, 0, n - 1);

	cout << "So cau thu tren 35 tuoi: " << A2(d, 0, n - 1);
	
	cout << endl;
	CauThu maxLuong = A3(d, 0, n - 1);
	cout << "\n\t\t\t\tCAU THU LUONG CAO NHAT\n";
	tieude();
	cout << setw(18) << maxLuong.tencauthu;
	cout << setw(18) << maxLuong.tuoi;
	cout << setw(18) << maxLuong.soao;
	cout << setw(18) << maxLuong.luong << endl;
	
	cout << endl;
	cout << "\n\t\t\tCAC CACH CHON 6 CAU THU TU 7 CAU THU\n";
	A4(d, a, n, 0, 0, count_config1);
	cout << "So cach chon 6 cau thu tu 7 cau thu: " << count_config1;
	
	cout << endl;
	cout << "\n\t\t\tCAC CACH XEP 7 CAU THU VAO 7 CHO\n";
	A5(d, a, dd, n, 0, count_config2);
	cout << "So cach xep 7 cau thu vao 7 cho: " << count_config2;
	return 0;
}
