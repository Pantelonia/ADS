#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
long long calculate_sum_distance(vector<long> positions) {
	long long sum = 0;
	long long temp;
	long k = positions.size() - 1;
	for (long i = positions.size() - 1; i >= 0; i--) {
		temp = (long long)k * positions[i];
		sum += temp;
		k -= 2;
	}
	for (long i = 1; i < positions.size(); i++)
	{
		sum -= i;
	}
	return sum;
}


int main() {

	ifstream input("input.txt");
	ofstream output("output.txt");

	string P = "";
	string tmp;
	while (!input.eof()) {
		input >> tmp;
		if (tmp != "") {
			P += tmp;
		}
		tmp = "";
	}
	map<char, vector<long>> letters;
	for (long i = 0; i < P.length(); i++) {
		letters[P[i]].push_back(i);
	}
	long long counter = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		if (letters.count(i) && letters[i].size() > 1) {
			counter += calculate_sum_distance(letters[i]);
		}
	}

	output << counter;
	return 0;
}