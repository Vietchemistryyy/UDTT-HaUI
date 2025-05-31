#include<bits/stdc++.h>

using namespace std;
struct GoiHang{
	int khoiluong;
	int giatri;	
};
void sapXep(GoiHang a[], int n, int idx[]){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[idx[i]].giatri > a[idx[j]].giatri){
				swap(idx[i], idx[j]);
			}
		}
	}
}
int D(GoiHang a[], int n, int C, int &tongGiaTri, int selected[]){
	int idx[100];
	for(int i = 0; i < n; i++) idx[i] = i;
	sapXep(a, n, idx);
	int count = 0;
	tongGiaTri = 0;
	int i = 0;
	while(i < n){
		if(tongGiaTri + a[idx[i]].giatri <= C){
			tongGiaTri += a[idx[i]].giatri;
			selected[count++] = idx[i];
		}		
		if(tongGiaTri == C) break;
		i++;
	}
	if(tongGiaTri != C) return 0;
	return count;
}
void QHD(GoiHang a[], int n, int M, int &tongGiaTri, int &count, int selected[], int dp[][101], int prev[][101]){
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= M; j++){
			dp[i][j] = 0;
			prev[i][j] = -1;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= M; j++){
			dp[i][j] = dp[i - 1][j];
			prev[i][j] = prev[i - 1][j];
			if(j >= a[i - 1].khoiluong){
				int maxValue = dp[i - 1][j - a[i - 1].khoiluong] + a[i - 1].giatri;
				if(maxValue > dp[i][j]){
					dp[i][j] = maxValue;
					prev[i][j] = i - 1;
				}
			}
		}
	}
	count = 0;
	tongGiaTri = dp[n][M];
	int i = n, k = M;
	// Truy vet
	while(i > 0 && k >= 0){
		if(prev[i][k] != prev[i - 1][k] && prev[i][k] != -1){
			selected[count++] = prev[i][k];
			k -= a[prev[i][k]].khoiluong;
		}
		--i;
	}
	// Dao nguoc
	for(int i = 0; i < count / 2; ++i) swap(selected[i], selected[count - i - 1]);
}

int main(){
	
	int n = 8;
	GoiHang a[8] = {
        {2, 4}, {1, 2}, {3, 6}, {1, 4},
        {2, 5}, {1, 3}, {2, 6}, {1, 1}
    };
    cout << "\tDANH SACH GOI HANG\n";
    for(int i = 1; i <= n; i++){
    	cout << "Goi " << i << ": Khoi luong = " << a[i - 1].khoiluong 
    	     << ", Gia tri = " << a[i - 1].giatri << endl;
	}
	cout << endl;
	int C = 10, selected[100], tongGiaTri = 0;
	int count_D = D(a, n, C, tongGiaTri, selected);
	if(count_D > 0){
		cout << "So goi hang chon D = " << count_D << endl;
		cout << "Cac goi hang lay: " << endl;
		for(int i = 0; i < count_D; ++i){
			cout << "  Goi " << selected[i] + 1 << ": Khoi luong = " << a[selected[i]].khoiluong
                 << ", Gia tri = " << a[selected[i]].giatri << endl;
		}
//		cout << endl;
		cout << "==> Tong gia tri cua cac goi hang: " << tongGiaTri << endl;
	}
	else{
		cout << "Khong co phuong an" << endl;
	}
	cout << endl;
	int M = 5;
	int selectedQHD[100], countQHD = 0, tongGT = 0, dp[101][101], prev[101][101];
	QHD(a, n, M, tongGT, countQHD, selectedQHD, dp, prev);
	cout << "Gia tri lon nhat P = " << tongGT << " de tong khoi luong khong vuot qua " << M << endl;
	if(countQHD > 0){
		cout << "So goi hang da chon: " << countQHD << endl;
		cout << "Danh sach cac goi hang chon: " << endl;
		for(int i = 0; i < countQHD; ++i){
			 cout << "  Goi " << selectedQHD[i] + 1 << ": Khoi luong = " << a[selectedQHD[i]].khoiluong
                  << ", Gia tri = " << a[selectedQHD[i]].giatri << endl;
		}
	}
	else{
		cout << "Khong co phuong an";
	}
	return 0;
}
