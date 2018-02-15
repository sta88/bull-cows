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

int CheckAndChange (int n){
        // Переводим число в вектор
	vector<int> v = NumberToVector(n);	
	for (size_t i = 0; i < v.size(); i++ ){ // Для каждой цифры
		if ( count(v.begin(), v.end(), v[i]) > 1 ){ // Если в векторе есть такая же цифра
                        // Заменяем текущую цифру на новую от 1 до 9 (почему не 0-9 ?)
                        // Ну окей, допустим заменили. А вдруг новая цифра опять совпала с той, которую мы уже проверили до этого?
			v[i] = 1 + rand() % 9;
			i = -1; // не понял зачем это 
		}
	}
        
        // Переводим вектор опять в число
	n = 0;
	for (size_t i=v.size()-1; i>=1; i--){
		n += v[i]*pow(10,i);
	}
	n += v[0];
	return n;
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

	int X = RandFunc();
	vector<int> X_digits;
	// cout << X << endl;
	X = CheckAndChange(X);
	// cout << X << endl;

        // переводим число в вектор, при том что в функции CheckAndChange() мы уже делали это,
        // но потом конвертировали опять в число. Много лишних конвертаций туда-сюда
	X_digits = NumberToVector(X); 

	int Y = 0;
	vector<int> Y_digits;
	int cows=0, bulls=0;	

	while ( Y!= X ){
	
		cout << "Enter your number (4 different digits)" << endl;
		cout << "If you want to know rules, enter 0" << endl;
		cin >> Y;
		if( Y == 0 ){
			ReadRules(rules);
			continue;
		}
		if( (Y<1000 || Y>=10000) && Y!=0 ){
			cout << "Wrong number!" << endl;
			continue;
		}
		Y_digits = NumberToVector(Y);

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

        // system("pause") - не нужна. Во-первых, это будет работать только в windows. Во-вторых даже там она не нужна.
        // Если человек запускает консольную программу из своей консоли, он и так увидит результат на экране, даже после завершения программы.
        // Консольные программы почти всегда так делают (выходят сразу), это нормальное поведение.
	system("pause");

	return 0;
}
