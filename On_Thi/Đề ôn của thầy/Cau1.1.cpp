#include<bits/stdc++.h>

using namespace std;

double tong_chiadetri(double a[], int left, int right){
	if(left == right) return a[left];
	int mid = (left + right) / 2;
	return tong_chiadetri(a, left, mid) + tong_chiadetri(a, mid + 1, right);
}
int main(){
	int n = 10;
	double a[10] = {1.5, 2.5, 4.65, 4.85, 5.5, 7.25, 8.75, 9.5, 10.0, 12.5};
	cout << "Tong cua cac so trong mang a la: " << tong_chiadetri(a, 0, n - 1);
	return 0;
}
