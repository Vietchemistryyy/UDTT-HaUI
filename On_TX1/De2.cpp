#include<bits/stdc++.h>

using namespace std;
int a[100], n = 6, dd[100], count_config;
struct DauSach{
	string tendausach;
	int sotap;
	int socuon;
	double giabia;
};
DauSach d[6] = {
	{"Dac nhan tam", 5, 150, 250000},
	{"Giai tich", 3, 210, 120000},
	{"Tieng Anh Co Ban", 6, 100, 80000},
	{"Ba chu AI", 6, 80, 140000},
	{"Triet hoc Mac-Lenin", 2, 125, 160000},
	{"Phap luat dai cuong", 2, 270, 9000},
};
void tieude(){
	cout << "----------------------------------------------------------------------------------\n";
	cout << setw(20) << "TEN DAU SACH";
	cout << setw(20) << "SO TAP";
	cout << setw(20) << "SO CUON";
	cout << setw(20) << "GIA BIA" << endl;
	cout << "----------------------------------------------------------------------------------\n";
}
void hienthi(DauSach d[], int n){
	if(n == 0) return;
	hienthi(d, n - 1);
	cout << setw(20) << d[n -1].tendausach; 
	cout << setw(20) << d[n -1].sotap;
	cout << setw(20) << d[n -1].socuon;
	cout << setw(20) << d[n -1].giabia << endl;
}
int A4(DauSach d[], int n){
	if (n == 0) return d[0].giabia;
	return d[n].giabia + A4(d, n - 1);
}
int A5(DauSach d[], int left, int right){
	if(left == right){
		if(d[left].giabia > 10000){
			cout << setw(20) << d[left].tendausach;
			cout << setw(20) << d[left].sotap;
			cout << setw(20) << d[left].socuon;
			cout << setw(20) << d[left].giabia << endl;
			return 1;			
		}
		return 0;
	}
	else{
		int mid = (left + right) / 2;
		int left_count = A5(d, left, mid);
		int right_count = A5(d, mid + 1, right);
		return left_count + right_count;		

	}	
}
void showA6(DauSach d[]) {
	for (int i = 1; i <= 5; i++) {
		int idx = a[i];
		cout << "(" << d[idx].tendausach << " - " << d[idx].giabia << ") ";
	}
	cout << "\n";
	count_config++;
	
}
void A6(DauSach d[], int k, int start){
	for(int i = start; i < n; i++){
		a[k] = i;
		if(k == 5){
			showA6(d);
		}
		else A6(d, k + 1, i + 1);
	}
}

int main(){
	cout << "\t\t\t\tDANH SACH CAC DAU SACH\n";
	tieude();
	hienthi(d,n);
	cout << "\n==> Tong gia bia cac cuon sach: " << A4(d, n);
	cout << endl;
	cout << "\n\t\tDANH SACH CUON SACH GIA BIA TREN 10000\n";
	tieude();
	cout << "\nSo dau sach co gia bia tren 10000: " << A5(d, 0, n - 1);
	cout << endl << endl;
	cout << "\n\t\t\tSO CACH CHON RA 5 CUON TRONG D:\n\n";
	A6(d, 1, 0);
	cout << "\nSo cach chon: " << count_config;

	return 0;
}
