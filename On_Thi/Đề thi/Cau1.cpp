#include <bits/stdc++.h>

using namespace std;

int binarySearch(double a[], int left, int right, double k){
	if(left > right) return -1;
	int mid = (left + right) / 2;
	if(a[mid] == k) return mid;
	else if(a[mid] > k) return binarySearch(a, left, mid - 1, k);
	else return binarySearch(a, mid + 1, right, k);
	
}


int main(){
	int n = 13;
	double a[13] = {1.0, 1.5, 2.5, 3.5, 4.0, 5.5, 7.5, 8.5, 10.0, 11.5, 12.0, 12.5, 15};
	cout << "Mang ban dau: ";
	for(double &x : a) cout << x << "  ";
	cout << "\n\n";
	double k = 15;
	int pos = binarySearch(a, 0, n - 1, k);
	cout << "Vi tri xuat hien cua " << k << " la: " << pos;
	
	return 0;
}

