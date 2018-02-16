#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int RandFunc(){
	srand( time(0) );
	return rand() % 10;
}

int VectorToNumber (const vector<int>& v){
	int x = 0;
	double EPS = 1e-9;
	for(size_t i=0; i<v.size(); i++ ){
		x += v[i] * (int)(pow(10.0, i)+EPS); 
	}
	return x;
}

vector<int> RandNumberVector(const int& n){
	vector<int> v;
	int r;
	for(size_t i=0; i<n; i++){
		r = RandFunc();
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


int main(){

	const string rules = "rules.txt";	
	int N = 0;

	while( N<3 || N>6 ){
		cout << "Enter quantity of digits (from 3 to 6): ";
		cin >> N;
	}

	vector<int> X_digits = RandNumberVector(N);
	// PrintV (X_digits); // for testing
	int X = VectorToNumber(X_digits);
	// cout << X << endl; // for testing

	int Y = 0;
	vector<int> Y_digits;
	int cows=0, bulls=0;	

	while ( Y!= X ){
	
		cout << "Enter your number (" << N << " different digits)" << endl;
		cout << "If you want to know rules, enter 0" << endl;
		cin >> Y;

		if( Y == 0 ){
			ReadRules(rules);
			continue;
		} else if( Y<pow(10, N-1) || Y>=pow(10, N) ){
			cout << "Wrong number!" << endl;
			continue;
		}
		Y_digits = NumberToVector(Y, N);

		cows=0, bulls=0;
		for( size_t i=0; i<Y_digits.size(); i++ ){
			if( Y_digits[i] == X_digits[i] ){
				bulls++;
			} else {
				if( find(X_digits.begin(), X_digits.end(), Y_digits[i]) != X_digits.end() ){
					cows++;
				}
			}
		}
		cout << "--- Bulls: " << bulls << " Cows: " << cows <<endl;
	}
	cout << "You win!" << endl;

	// system("pause");

	return 0;
}
