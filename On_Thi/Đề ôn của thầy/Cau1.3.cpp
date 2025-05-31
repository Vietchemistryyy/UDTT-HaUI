#include<bits/stdc++.h>

using namespace std;

double tongduong_chiadetri(double a[], int left, int right){
	if(left == right){
		if(a[left] > 0){
			return a[left];
		}
		else return 0;	
	}
	int mid = (left + right) / 2;
	return tongduong_chiadetri(a, left, mid) + tongduong_chiadetri(a, mid + 1, right);
	
}
int main(){
	int n = 10;
	double a[10] = {-1.5, 2.5, 4.65, -4.85, 5.5, 7.25, 8.75, 9.5, 10.0, -12.5};
	cout << "Tong cua cac so duong trong mang a la: " << tongduong_chiadetri(a, 0, n - 1);
	return 0;
}
