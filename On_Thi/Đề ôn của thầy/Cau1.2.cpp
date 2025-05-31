#include<bits/stdc++.h>

using namespace std;

double tongle_dequy(int a[], int n){
	if(n == 0) return 0;
	if(a[n - 1] % 2 == 1){
		return a[n - 1] + tongle_dequy(a, n - 1);
	}
	else return tongle_dequy(a, n - 1);
}
int main(){
	int n = 10;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Tong cua cac so le trong mang a la: " << tongle_dequy(a, n);
	return 0;
}
