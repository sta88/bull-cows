#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int VectorToNumber (const vector<int>& v){
	int x = 0;
	for(size_t i=0; i<v.size(); i++ ){
		x += v[i] * round(pow(10.0, i)); 
	}
	return x;
}

vector<int> RandNumberVector(const int& n){
	vector<int> v;
	int r;
	for(size_t i=0; i<n; i++){
		r = rand() % 10;
		if( count(v.begin(), v.end(), r) == 0 ){
			v.push_back( r );
		} else {
			i--;
		}
	}
	if( v[n-1] == 0 ){  // т.к. для получения числа я переворачиваю вектор, то проверим, чтобы последний элемент не был равен 0
		v[n-1] = v[0];
		while( count(v.begin(), v.end(), v[n-1]) > 1){
			v[n-1] = rand() % 9 + 1;
		}
	}
	return v;
}

void PrintV(const vector<int>& v){
	for (int i : v){
		cout << i << " ";
	}
	cout << endl;
}

vector<int> NumberToVector (int x, const size_t& n){
	vector<int> v;
	for(size_t i=0; i<n; i++){
		v.push_back(x%10);
		x /= 10;
	}
	return v;
}

void ReadRules(const string& path){
	ifstream input(path);
	cout  << endl << "------------" << endl;
	if (input){
		string line;
		while ( getline(input, line) ){
			cout << line << endl;
		}
	}
	cout << "------------" << endl  << endl;
}

vector<int> CountBullAndCows(const vector<int> &x, const vector<int> &y){
	vector<int> bc = {0, 0};
	for( size_t i=0; i<y.size(); i++ ){
		if( y[i] == x[i] ){
			bc[0]++;
		} else {
			if( find(x.begin(), x.end(), y[i]) != x.end() ){
				bc[1]++;
			}
		}
	}
	return bc;
}


int main(){
	srand( time(0) );

	const string rules = "rules.txt";	
	int N = 0;

	while( N<3 || N>6 ){
		cout << "Enter quantity of digits (from 3 to 6): ";
		cin >> N;
	}

	vector<int> X_digits = RandNumberVector(N);
	PrintV (X_digits); // for testing
	int X = VectorToNumber(X_digits);
	cout << X << endl; // for testing

	int Y = 0;
	vector<int> Y_digits;
	vector<int> bulls_cows;
	int cows=0, bulls=0;	

	while ( Y!= X ){
	
		cout << "Enter your number (" << N << " different digits)" << endl;
		cout << "If you want to know rules, enter 0" << endl;
		cin >> Y;

		if( Y == 0 ){
			ReadRules(rules);
			continue;
		} else if( Y<round(pow(10.0, N-1)) || Y>=round(pow(10.0, N)) ){
			cout << "Wrong number!" << endl;
			continue;
		}
		Y_digits = NumberToVector(Y, N);

		bulls_cows = CountBullAndCows(X_digits, Y_digits);
		bulls = bulls_cows[0];
		cows = bulls_cows[1];
		
		cout << "--- Bulls: " << bulls << " Cows: " << cows <<endl;
	}
	cout << "You win!" << endl;

	// system("pause");

	return 0;
}
