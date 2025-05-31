#include<bits/stdc++.h>

using namespace std;

struct ChuyenXe{
	char tenNhaXe[100];
	int soHanhKhach;
	int tienVe;
}; 
// Lay duoc so chuyen xe it nhat ma thu duoc p lon hon m
int thamlam1(ChuyenXe d[], int n, int &p, int m, int selected[]){
	p = 0;
	int count = 0;
	int i = 0;
	while(i < n && p <= m){
		p += d[i].tienVe;
		selected[count++] = i;
		i++;
	}
	if(p <= m) return 0;
	return count;
}
// Lay duoc so chuyen xe nhieu nhat thu duoc p khong vuot qua m
int thamlam2(ChuyenXe d[], int n, int &p, int m, int selected[]){
	p = 0;
	int count = 0;
	int i = n - 1;
	while(i >= 0 && p + d[i].tienVe <= m){
		p += d[i].tienVe;
		selected[count++] = i;
		i--;
	}
	return count;
}
// Lay duoc so chuyen xe it nhat thu duoc p dung bang m
int thamlam3(ChuyenXe d[], int n, int &p, int m, int selected[]){
	p = 0;
	int count = 0;
	int i = 0;
	while(i < n){
		if(p + d[i].tienVe <= m){
			p += d[i].tienVe;
			selected[count++] = i;
		}
		if(p == m) break;
		i++;
	}
	if(p != m) return 0;
	return count;	
}
int BMH(char P[], char T[]){
	int m = strlen(P);
	int n = strlen(T);
	if(m > n)  return -1;
	int shift[256];
	for(int i = 0; i < 256; ++i) shift[i] = m;
	for(int i = 0; i < m - 1; ++i) shift[(char)P[i]] = m - i - 1;
	int i = m - 1;
	while(i < n){
		int k = 0;
		while(k < m && P[m - k - 1] == T[i - k]) ++k;
		if(k == m) return i - m + 1;
		i += shift[(char)T[i]];
	}
	return -1;
}
bool checkViet(char tenNX[]){
	return BMH((char*)"Viet", tenNX) != -1;
}
void QHD(ChuyenXe d[], int n, int v, int &t, int &count, int selected[], int dp[][999], int prev[][999]){
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= v; ++j){
			dp[i][j] = 0;
			prev[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= v; ++j){
			// TH1: Khong lay chuyen xe thu i - 1
			dp[i][j] = dp[i - 1][j];
			prev[i][j] = prev[i - 1][j];
			// TH2: Lay chuyen xe thu i - 1
			if(j >= d[i - 1].soHanhKhach){
				int maxValue = dp[i - 1][j - d[i - 1].soHanhKhach] + d[i - 1].tienVe;
				if(maxValue > dp[i][j]){
					dp[i][j] = maxValue;
					prev[i][j] = i - 1;
				}
			}
		}
	}
	count = 0;
	t = dp[n][v];
	int i = n, k = v;
	// Truy vet
	while(i > 0 && k >= 0){
		if(prev[i][k] != prev[i - 1][k] && prev[i][k] != -1){
			selected[count++] = prev[i][k];
			k -= d[prev[i][k]].soHanhKhach;
		}
		i--;
	}
	// Dao nguoc
	for(int i = 0; i < count / 2; i++) swap(selected[i], selected[count - i - 1]);
}



int main(){
	int n = 8;
	ChuyenXe d[8] = {
		{"Anh Khoi", 35, 80000},
		{"Hoang Khanh", 30, 70000},
		{"Quoc Viet", 40, 60000},
		{"Anh Tuan", 30, 55000},
		{"Tuan Tu", 35, 50000},
		{"Gia Khiem", 35, 45000},
		{"Viet Luxury", 25, 40000},
		{"Nam Hong", 30, 35000}
	};
	int m = 250000;
	int p = 0, selected1[100];
	int u = thamlam1(d, n, p, m, selected1);
	cout << "So chuyen xe can su dung it nhat la u = " << u << endl;
	if(u > 0){
		cout << "Tong tien ve thu duoc lon nhat p = " << p << " lon hon " << m << endl;  
		cout << "Danh sach chuyen xe chon: " << endl;
		for(int i = 0; i < u; ++i){
			cout << "Chuyen xe " << selected1[i] + 1 << ": " << "Nha xe: " << d[selected1[i]].tenNhaXe
			     << ", so hanh khach: " << d[selected1[i]].soHanhKhach
			     << ", gia ve: " << d[selected1[i]].tienVe << endl;
		}
		cout << endl;
	}
	else cout << "Khong co chuyen xe nao" << endl;
	cout << endl;
	
	int m1 = 150000;
	int p1 = 0, selected2[100];
	int u1 = thamlam2(d, n, p1, m1, selected2);
	cout << "So chuyen xe can su dung nhieu nhat la u1 = " << u1 << endl;
	if(u1 > 0){
	cout << "Tong tien ve thu duoc lon nhat p = " << p1 << " khong vuot qua " << m1 << endl;
		cout << "Danh sach chuyen xe chon: " << endl;
		for(int i = 0; i < u1; ++i){
			cout << "Chuyen xe " << selected2[i] + 1 << ": " << "Nha xe: " << d[selected2[i]].tenNhaXe
			     << ", so hanh khach: " << d[selected2[i]].soHanhKhach
			     << ", gia ve: " << d[selected2[i]].tienVe << endl;
		}
		cout << endl;
	}
	else cout << "Khong co chuyen xe nao" << endl;
	cout << endl;
	int m2 = 150000;
	int p2 = 0, selected3[100];
	int u2 = thamlam3(d, n, p2, m2, selected3);
	cout << "So chuyen xe can su dung nhieu nhat la u2 = " << u2 << endl;
	if(u2 > 0){
	cout << "Tong tien ve thu duoc lon nhat p = " << p2 << " dung bang " << m2 << endl;
		cout << "Danh sach chuyen xe chon: " << endl;
		for(int i = 0; i < u2; ++i){
			cout << "Chuyen xe " << selected3[i] + 1 << ": " << "Nha xe: " << d[selected3[i]].tenNhaXe
			     << ", so hanh khach: " << d[selected3[i]].soHanhKhach
			     << ", gia ve: " << d[selected3[i]].tienVe << endl;
		}
		cout << endl;
	}
	else cout << "Khong co chuyen xe nao" << endl;
	cout << endl;
	int countBMH = 0;
	cout << "Cac nha xe co chua tu Viet\n";
	for(int i = 0; i < n; i++){
		if(checkViet(d[i].tenNhaXe)){
			countBMH++;
			cout << "Chuyen xe " << i + 1 << ": " 
				 <<	"Ten nha xe: " << d[i].tenNhaXe		
				 <<	", so hanh khach: " << d[i].soHanhKhach
				 <<	", tien ve: " << d[i].tienVe << endl;
		}
	}
	if(countBMH > 0) cout << "So nha xe co chua tu Viet la " << countBMH << endl;
	else cout << "Khong co nha xe nao chua tu Viet" << endl;
	cout << endl;
	int selectedQHD[100], dp[101][999], prev[101][999];
	int v = 175, t = 0, countQHD = 0;
	QHD(d, n, v, t, countQHD, selectedQHD, dp, prev);
	if(countQHD > 0){
		cout << "So chuyen xe dua vao nha cho k la q = " << countQHD << endl;
		cout << "Tong tien ve thu duoc lon nhat t = " << t << endl;
		for(int i = 0; i < countQHD; ++i){
			cout << "Chuyen xe " << selectedQHD[i] + 1 << ": " 
				 <<	"Ten nha xe: " << d[selectedQHD[i]].tenNhaXe		
				 <<	", so hanh khach: " << d[selectedQHD[i]].soHanhKhach
				 <<	", tien ve: " << d[selectedQHD[i]].tienVe << endl;
		}
	}
	else cout << "Khong co phuong an";
	
	return 0;
}
