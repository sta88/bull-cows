#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

int RandFunc(){
	srand( time(0) );
	return 1000 + rand() % 8999;
}
void PrintV(const vector<int>& v){
	for (int i : v){
		cout << i << " ";
	}
	cout << endl;
}
vector<int> NumberToVector (int n){
	vector<int> v;
	while( n>0 ){
		v.push_back(n%10);
		n /= 10;
	}
	return v;
}

int main(){

	int X = RandFunc();
	vector<int> X_digits = NumberToVector(X);
	cout << X << endl;
	// PrintV(X_digits);
	int Y = 0;
	vector<int> Y_digits;
	int cows=0, bulls=0;	

	while ( Y!= X ){
	
		cout << "Enter your number (4 different digits): ";
		cin >> Y;
		if( Y<1000 || Y>=10000 ){
			cout << "Wrong number!" << endl;
			continue;
		}
		Y_digits = NumberToVector(Y);
		// PrintV(Y_digits);

		cows=0, bulls=0;
		for( int i=0; i<Y_digits.size(); i++ ){
		    // cout << i <<endl;
			if( Y_digits[i] == X_digits[i] ){
				bulls++;
			} else {
				if( find(X_digits.begin(), X_digits.end(), Y_digits[i]) != X_digits.end() ){
					cows++;
				}
			}
		}
		cout << "Bulls: " << bulls << " Cows: " << cows <<endl;
	}
	cout << "You win!" << endl;


	return 0;
}