#include <iostream>
#include <unordered_map>
#include <random>
#include <chrono>


using namespace std;

int main(){
	
	unordered_map<int, char> asciiMAP;

	for(int i = 33; i<127; i++){
		asciiMAP[i] = static_cast<char>(i);
	}

//	for (const auto& pair : asciiMAP) {
		
//		cout << "Characters: " << pair.first << ", ASCII Values: " << pair.second << endl;

//	}


	
	unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 gen(seed);
	
	uniform_int_distribution<> dis(33, 127);

	int passkey_length = 20;
	string password;
	for(int i = 0; i< passkey_length; i++){

		int ascii_value = dis(gen);
			password += asciiMAP[ascii_value];

	}

	cout << password << endl;
	
	
	cin.get();
	
	return 0;


		

}
