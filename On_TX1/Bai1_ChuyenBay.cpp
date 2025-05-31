#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct ChuyenBay{
	string sohieu;
    double giave;
    int soghe;
};
void tieude(){
	cout << "----------------------------------------------------------------------------\n";
	cout << setw(5) << "STT";
	cout << setw(25) << "SO HIEU CHUYEN BAY";
	cout << setw(20) << "GIA VE";
	cout << setw(25) << "SO GHE NGOI" << endl;	
	cout << "----------------------------------------------------------------------------\n";
}

// Hien thi danh sach chuyen bay bang de quy
void A1(ChuyenBay d[], int n, int &stt){
	if(n == 0){
		return;
	}
	A1(d, n - 1, stt);
	cout << setw(4) << n;
	cout << setw(25) << d[n - 1].sohieu;
	cout << setw(21) << d[n - 1].giave;
	cout << setw(21) << d[n - 1].soghe << endl;	
}

// Hien thi danh sach dao nguoc chuyen bay bang de quy
void A2(ChuyenBay d[], int n, int &stt){
	if(n == 0){
		return;
	}
	cout << setw(4) << n;
	cout << setw(25) << d[n - 1].sohieu;
	cout << setw(21) << d[n - 1].giave;
	cout << setw(21) << d[n - 1].soghe << endl;	
	A2(d, n - 1, stt);
}

// Hien thi danh sach cac chuyen bay co gia ve > 700000 bang de quy
void A3(ChuyenBay d[], int n, int &stt){
	if(n == 0){
		return;
	}
	A3(d, n - 1, stt);
	if(d[n - 1].giave > 700000){
		stt++;
		cout << setw(4) << n;
		cout << setw(25) << d[n - 1].sohieu;
		cout << setw(21) << d[n - 1].giave;
		cout << setw(21) << d[n - 1].soghe << endl;	
	}
}

// Hien thi danh sach cac chuyen bay co gia ve < 800000 bang de quy
void A4(ChuyenBay d[], int n, int &stt){
	if(n == 0){
		return;
	}
	A4(d, n - 1, stt);
	if(d[n - 1].giave < 800000){
		stt++;
		cout << setw(4) << n;
		cout << setw(25) << d[n - 1].sohieu;
		cout << setw(21) << d[n - 1].giave;
		cout << setw(21) << d[n - 1].soghe << endl;
	}
}


// Tinh tong gia ve cua tat ca cac chuyen bay bang de quy
double A5(ChuyenBay d[], int n){
	if(n == 0){
		return 0;
	}	
	return d[n - 1].giave + A5(d, n - 1);
}

// Tra ve chuyen bay co gia ve thap nhat bang chia de tri 
ChuyenBay A6(ChuyenBay d[], int left, int right){
	if(left == right){
		return d[left];
	}
	int mid = (left + right) / 2;
	ChuyenBay minLeft = A6(d, left, mid);
	ChuyenBay minRight = A6(d, mid + 1, right);	
	return (minLeft.giave < minRight.giave) ? minLeft : minRight;
}

// Tra ve chuyen bay co gia ve cao nhat bang chia de tri 
ChuyenBay A7(ChuyenBay d[], int left, int right){
	if(left == right){
		return d[left];
	}
	int mid = (left + right) / 2;
	ChuyenBay maxLeft = A7(d, left, mid);
	ChuyenBay maxRight = A7(d, mid + 1, right);	
	return (maxLeft.giave < maxRight.giave) ? maxRight : maxLeft;
}
void show_A8(ChuyenBay d[], int a[]){
	for(int i = 0; i < 4; i++){
		int idx = a[i];
		cout << "(" << d[idx].sohieu << " - " << d[idx].soghe << ") ";
	}
	cout << endl;
}

// Hien thi ra cach chon 4 chuyen bay tu n (n = 7) chuyen bay
void A8(ChuyenBay d[], int a[], int k, int start, int n, int &count_config_1){
	for(int i = start; i < n; i++){
		a[k] = i;
		if(k == 3){ // Tu 0 -> 3
			show_A8(d, a);
			count_config_1++;
		}
		else{
			A8(d, a, k + 1, i + 1, n, count_config_1);
		}
	}
}


void show_A9(ChuyenBay d[], int a[], int n){
	for(int i = 0; i < n; i++){
		int idx = a[i];
		cout << "(" << d[idx].sohieu << " - " << d[idx].soghe << ") ";
	}
	cout << endl;
}

// Hien thi ra cach sap xep n chuyen bay vao n vi tri khac nhau (n = 7)
void A9(ChuyenBay d[], int a[], int dd[], int k, int n, int &count_config_2){
    for(int i = 0; i < n; i++){
        if(dd[i] == 0){ 
            a[k] = i;   
            dd[i] = 1;   
            if(k == n - 1){  
                show_A9(d, a, n);
                count_config_2++;
            } else {
                A9(d, a, dd, k + 1, n, count_config_2);  
            }
            dd[i] = 0;   
        }
    }
}

int main(){
	int a[100] = {0}, dd[100] = {0}, n = 7, stt = 0, count_config_1 = 0, count_config_2 = 0;
	ChuyenBay d[7] = {
		{"VietnamAirlines209", 800000, 120},
		{"VietnamAirlines103", 650000, 140},
		{"VietnamAirlines243", 700000, 135},
		{"VietnamAirlines124", 620000, 165},
		{"VietnamAirlines221", 750000, 155},
		{"VietnamAirlines167", 900000, 170},
		{"VietnamAirlines189", 850000, 165},
	};
	cout << "\t\t\tDANH SACH CHUYEN BAY\n";
	tieude();
	A1(d, n, stt);
	
	cout << "\n\t\t\tDANH SACH CHUYEN BAY DAO NGUOC\n";
	tieude();
	A2(d, n, stt);
	
	cout << "\n\tDANH SACH CHUYEN BAY CO GIA VE TREN 700000\n";
	tieude();
	A3(d, n, stt);
	
	cout << "\n\tDANH SACH CHUYEN BAY CO GIA VE DUOI 800000\n";
	tieude();
	A4(d, n, stt);
	
	cout << endl;
	cout << "\nTONG GIA VE CUA CAC CHUYEN BAY LA: " << A5(d, n);
	
	ChuyenBay minCB = A6(d, 0, n - 1);
	cout << "\n\n\t\tCHUYEN BAY CO GIA VE NHO NHAT LA\n";
	tieude();
	cout << setw(4) << 1;
	cout << setw(25) << minCB.sohieu;
	cout << setw(21) << minCB.giave;
	cout << setw(21) << minCB.soghe << endl;		
	
	cout << endl;
	ChuyenBay maxCB = A7(d, 0, n - 1);
	cout << "\n\n\t\tCHUYEN BAY CO GIA VE NHO NHAT LA\n";
	tieude();
	cout << setw(4) << 1;
	cout << setw(25) << maxCB.sohieu;
	cout << setw(21) << maxCB.giave;
	cout << setw(21) << maxCB.soghe << endl;		
	
	cout << endl;
	cout << "\n\t\t\t\tCac to hop chon 4 chuyen bay:\n\n";
	A8(d, a, 0, 0, n, count_config_1);
	cout << "\nTong so to hop: " << count_config_1 << "\n";
	
//	cout << "\nCac hoan vi cua " << n << " chuyen bay:\n";
//	A9(d, a, dd, 0, n, count_config_2);
//	cout << "\nTong so hoan vi: " << count_config_2 << "\n";

	return 0;
}
