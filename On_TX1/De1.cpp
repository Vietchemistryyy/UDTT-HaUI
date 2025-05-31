#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100], n = 5, dd[100], count_config = 0;
struct MayIn{
	string tenhangsanxuat;
	string loaimayin;
	ll giaban;
	int phantramgiamgia;
};
MayIn d[5] = {
	{"Canon", "In mau", 3500000, 14},	
	{"Samsung", "Den trang", 3000000, 40},
	{"Panasonic", "Den trang", 45000000, 23},
	{"LG", "In mau", 10000000, 24},
	{"Sony", "In mau", 7000000, 0},
};
void tieude(){
	cout << "---------------------------------------------------------------------------\n";
	cout << setw(15) << "TEN HANG SAN XUAT";
	cout << setw(15) << "LOAI MAY IN";
	cout << setw(15) << "GIA BAN";
	cout << setw(25) << "PHAN TRAM GIAM GIA" << endl;
	cout << "---------------------------------------------------------------------------\n";
	
}
//ll A(MayIn d[], int n){
//	if(n == 0){
//		return 0;
//	}
//	return d[n - 1].giaban += A(d, n - 1);
//}
void A1(MayIn d[], int n){
	if(n == 0){
		return;
	}
	A1(d, n - 1);
	cout << setw(10) << d[n - 1].tenhangsanxuat;
	cout << setw(20) << d[n - 1].loaimayin;
	cout << setw(17) << d[n - 1].giaban;
	cout << setw(20) << d[n - 1].phantramgiamgia << endl;
}
int A2(MayIn d[], int left, int right){
	if(left == right){
		if(d[left].loaimayin == "In mau" && d[left].phantramgiamgia > 0){
			return 1;
		}
	}
	else{
		int mid = (left + right) / 2;
		int left_count = A2(d, left, mid);
		int right_count = A2(d, mid + 1, right);
		return left_count + right_count;
	}
}
ll cnt = 0;
void show(MayIn d[]){
	for(int i = 1; i <= n; i++){
		cout << " (" << d[a[i] - 1].tenhangsanxuat << ") ";
	}
	cnt++;
	cout << endl;
	
}

//void A3(MayIn d[], int k, int start){
//	for(int i = start; i <= n; i++){
//		a[k] = i;
//		if(k == n){
//			show(d);
//		}
//		else A3(d, k + 1, i + 1);
//	}
//}
void A3(int i){
	for (int j = 1; j <= n; j++){
		if (!dd[j]){
			a[i] = j;
			dd[j] = 1;
			if (i == n) show(d);
			else A3(i + 1);
			dd[j] = 0;
		}
	}
}
int main(){
	cout << "\t\t\tDANH SACH MAY IN\n";
	tieude();
	A1(d,n);
	cout << "\n\nSo may in mau duoc giam gia: " << A2(d, 0, n - 1);
	cout << "\n\n\tCAC CACH KHAC NHAU DAT MAY IN\n";
//	A3(d, 1);
	A3(1);
	cout<<"\n\n"<<cnt;
	return 0;
}
