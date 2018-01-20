#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int RandFunc(){
	srand(time(0));
	return rand() % 10000;
}

int main(){

	int X = RandFunc();
	vector<int> X_digits;

	if ( X<10 ){
		X_digits.push(0);
		X_digits.push(0);
		X_digits.push(0);
		X_digits.push(X);
	} else if ( X<100 ){
		X_digits.push(0);
		X_digits.push(0);
		X_digits.push(X/10);
		X_digits.push(X%10);
	} else if ( X<100 ){
		X_digits.push(0);
		X_digits.push(X/100);
		X_digits.push((X%100)/10);
		X_digits.push(X%10);
	} else if ( X<100 ){
		X_digits.push(X/1000);
		X_digits.push((X%1000)/100);
		X_digits.push((X%100)/10);
		X_digits.push(X%10);
	}

	cout << X << endl;
	
	return 0;
}