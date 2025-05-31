#include<bits/stdc++.h>

using namespace std;
struct Knapsack{
	int weight;
	int value;
};

void title(){
	cout << "---------------------------------------\n";
	cout << setw(15) << "WEIGHT";
	cout << setw(15) << "VALUE" << endl;
	cout << "---------------------------------------\n";
}
void QHD(Knapsack d[], int n, int maxWeight, int selected[], int &count, int dp[][7], int prev[][7]){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= maxWeight; ++j){
			dp[i][j] = 0;
			prev[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= maxWeight; j++){
			// TH1: Khong chon chai thu i - 1
			dp[i][j] = dp[i - 1][j];
			prev[i][j] = prev[i - 1][j];
			// TH2: Chon chai thu i - 1
			if(j >= d[i - 1].weight){
				int maxValue = dp[i - 1][j - d[i - 1].weight] + d[i - 1].value;
				if(maxValue > dp[i][j]){
					dp[i][j] = maxValue;
					prev[i][j] = i - 1;
				}
			}
		}
	}
	count = 0;
	int k = maxWeight;
	int i = n;
	// Truy vet
	while(i >= 1 && k >= 0){
		if(prev[i][k] != prev[i - 1][k] && prev[i][k] != -1){
			selected[count++] = prev[i][k];
			k -= d[prev[i][k]].weight;
		}
		--i;
	}
	// Dao nguoc
	for(int i = 0; i < count / 2; i++){
		swap(selected[i], selected[count - i - 1]);
	}
}

int main(){
	int n = 4;
	Knapsack d[4] = {
		{2, 3},
		{1, 3},
		{4, 4},
		{3, 2},
	};
	title();
	for(int i = 0; i < n; i++){
		cout << setw(13) << d[i].weight;
		cout << setw(16) << d[i].value << endl;
	}
	cout << endl;
	int w = 6, selected[100], count = 0, dp[5][7], prev[5][7];
	QHD(d, n, w, selected, count, dp, prev);
	// Lap bang qhd
	for(int i = 0; i <= w; i++){
		cout << setw(10) << i;
	}
	cout << endl;
	for(int i = 0; i <= n; ++i){
		cout << setw(1) << i << ": ";
		for(int j = 0; j <= w; j++){
			cout << setw(10) << dp[i][j];
		}
		cout << endl;
	}
	cout << "So do vat co the lay voi weight " << w << " la: " << count << endl;
	if(count > 0){
		cout << "DANH SACH DO VAT LAY\n";
		title();
		for(int i = 0; i < count; i++){
			cout << setw(13) << d[selected[i]].weight;
			cout << setw(16) << d[selected[i]].value << endl;
		}
	}
	else{
		cout << "Khong the lay duoc do vat nao voi weight " << w << endl;
	}
	return 0;
}
