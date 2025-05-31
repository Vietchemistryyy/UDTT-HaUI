#include<bits/stdc++.h>

using namespace std;

struct CanRuou{
	string nhanhieu;
	int dungtich;
	int giatri;
};

void title(){
	cout << "---------------------------------------------------------\n";	
	cout << setw(15)<< "NHAN HIEU";
	cout << setw(15)<< "DUNG TICH";
	cout << setw(15)<< "GIA TRI" << endl;
	cout << "---------------------------------------------------------\n";
}
void printHeader(int type){
	if(type == 1){
		cout << "-------------------------------\n";
		cout << setw(15) << "NHAN HIEU";
		cout << setw(15) << "GIA TRI" << endl;
		cout << "-------------------------------\n";
	}
	if(type == 2){
		cout << "---------------------------------------------------------\n";	
		cout << setw(15) << "NHAN HIEU";
		cout << setw(15) << "DUNG TICH";
		cout << setw(15) << "GIA TRI" << endl;
		cout << "---------------------------------------------------------\n";	
	}
	
}
// Sap xep tang dan theo gia tri
void sapXep(CanRuou d[], int n, int idx[]){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(d[idx[i]].giatri > d[idx[j]].giatri){
				swap(idx[i], idx[j]);
			}
		}
 	}
}
void A(CanRuou d[], int n, int m, int selected[], int &count){
	int idx[100];
	for(int i = 0; i < n; i++) idx[i] = i;
	
	sapXep(d, n, idx);
	count = 0;
	int i = 0;
	while (i < n && m >= d[idx[i]].giatri){
		selected[count++] = idx[i];
		m -= d[idx[i]].giatri;
		++i;
	}
}

void B(CanRuou d[], int n, int maxDungTich, int selected[], int &count, int dp[][11], int prev[][11]){
	// Tao bang phuong an
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= maxDungTich; j++){
			dp[i][j] = 0;
			prev[i][j] = -1;
		}
	}
	
	// Lap bang phuong an theo quy hoach dong
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= maxDungTich; j++){
			// TH1: Khong chon chai thu i - 1
			dp[i][j] = dp[i - 1][j];
			prev[i][j] = prev[i - 1][j];
			// TH2: Chon chai thu i - 1
			if(j >= d[i - 1].dungtich){
				int maxValue = dp[i - 1][j - d[i - 1].dungtich] + d[i - 1].giatri;
				if(maxValue > dp[i][j]){
					dp[i][j] = maxValue;
					prev[i][j] = i - 1;
				}
			}
		}
	}
	count = 0;
	int k = maxDungTich;
	// Truy vet
	int i = n;
	while(i >= 1 && k >= 0){
		if(prev[i][k] != prev[i - 1][k] && prev[i][k] != -1){
			selected[count++] = prev[i][k];
			k -= d[prev[i][k]].dungtich;
		}
		--i;
	}
	// Dao nguoc
	for(int i = 0; i < count / 2; ++i){
		swap(selected[i], selected[count - i - 1]);
	}
}


int main(){
	
	int n = 6;
	CanRuou d[6] = {
		{"Vang Phap", 2, 1200000},
		{"Vang Chile", 3, 800000},
		{"Vang Y", 1, 500000},
		{"Whisky Scot", 2, 1500000},
		{"Vodka Nga", 1, 600000},
		{"Rum Cuba", 2, 900000}
	};
	
	cout << "\n\t\t    DANH SACH RUOU\n";
	title();
	for(int i = 0; i < n; i++){
		cout << setw(15) << d[i].nhanhieu
			 << setw(13) << d[i].dungtich
			 << setw(17) << d[i].giatri << endl;
	}
	cout << endl;
	
	int m = 3000000; // So tien ban dau
	int selectedA[100];
	int countA = 0;
	A(d, n, m, selectedA, countA);
	cout << "So can ruou mua duoc voi so tien " << m << " la: " << countA << endl;
	if(countA > 0){
		cout << "\n     DANH SACH CAN RUOU MUA\n";
		printHeader(1);
		for(int i = 0; i < countA; i++){
			cout << setw(15) <<   d[selectedA[i]].nhanhieu;
			cout << setw(15) << d[selectedA[i]].giatri << endl;
		}	
	}
	else{
		cout << "Khong mua duoc can ruou nao voi so tien " << m;
	}
	int s = 10, selectedB[100], countB = 0, prev[7][11], dp[7][11];
	B(d, n, s, selectedB, countB, dp, prev);
	
	cout << "BANG PHUONG AN\n";
	for(int i = 0; i <= s; ++i){
		cout << setw(10) << i;
	}
	cout << endl;
	for(int i = 0; i <= n; i++){
		cout << setw(2) << i << ": ";
		for(int j = 0; j <= s; ++j){
			cout << setw(10) << dp[i][j];
		}
		cout << endl;
	}	
	cout << "\nSo can ruou toi da co the mua duoc voi dung tich " << s << " lit la: " << countB << endl;
	if(countB > 0){
		printHeader(2);
		for(int i = 0; i < countB; i++){
			cout << setw(15) << d[selectedB[i]].nhanhieu;
			cout << setw(15) << d[selectedB[i]].dungtich;
			cout << setw(15) << d[selectedB[i]].giatri << endl;
		}
	}
	else{
		cout << "==> Khong mua duoc chai nao\n";
	}
	
	return 0;
}
