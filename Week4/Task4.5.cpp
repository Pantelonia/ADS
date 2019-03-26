#include <fstream>
#include <queue>
#include <string>
#include <map>
using namespace std;


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	queue<unsigned short> MainQueue = {};
	map<char, unsigned short> registers;
	for (char i = 'a'; i <= 'z'; i++)
	{
		registers.insert(pair<char, unsigned short>(i, 0));
	}
	map <string, long> labels;
	string *commands = new string[100001];
	long N = -1;
	while (!input.eof()) {
		input >> commands[++N];
		if (commands[N][0] == ':') {
			labels.insert(pair<string, long>(commands[N].substr(1), N));
		}
	}
	if (commands[N].empty()) {
		N--;
	}
	input.close();
	long Number_of_command = 0;
	unsigned short a, b;

	do {
		switch (commands[Number_of_command][0])
		{
		case '+':
			a = MainQueue.front();
			MainQueue.pop();
			b = MainQueue.front();
			MainQueue.pop();
			MainQueue.push((a + b) % 65536);
			Number_of_command++;
			break;
		case '-':
			a = MainQueue.front();
			MainQueue.pop();
			b = MainQueue.front();
			MainQueue.pop();
			MainQueue.push((a - b) % 65536);
			Number_of_command++;
			break;
		case '*':
			a = MainQueue.front();
			MainQueue.pop();
			b = MainQueue.front();
			MainQueue.pop();
			MainQueue.push((a * b) % 65536);
			Number_of_command++;
			break;
		case '/':
			a = MainQueue.front();
			MainQueue.pop();
			b = MainQueue.front();
			MainQueue.pop();
			if (b == 0) {
				MainQueue.push(0);
			}
			else {
				MainQueue.push(a / b);
			}
			Number_of_command++;
			break;
		case '%':
			a = MainQueue.front();
			MainQueue.pop();
			b = MainQueue.front();
			MainQueue.pop();
			if (b == 0) {
				MainQueue.push(0);
			}
			else {
				MainQueue.push(a % b);
			}
			Number_of_command++;
			break;
		case '>':
			a = MainQueue.front();
			MainQueue.pop();
			registers[commands[Number_of_command][1]] = a;
			Number_of_command++;
			break;
		case '<':
			MainQueue.push(registers[commands[Number_of_command][1]]);
			Number_of_command++;
			break;
		case 'P':
			if (commands[Number_of_command].size() == 1) {
				output << MainQueue.front() << '\n';
				MainQueue.pop();
			}
			else {
				output << registers[commands[Number_of_command][1]] << '\n';
			}
			Number_of_command++;
			break;
		case 'C':
			if (commands[Number_of_command].size() == 1) {
				output << (char)(MainQueue.front() % 256);
				MainQueue.pop();
			}
			else {
				output << (char)(registers[commands[Number_of_command][1]] % 256);
			}
			Number_of_command++;
			break;
		case ':':
			Number_of_command++;
			break;
		case 'J':
			Number_of_command = labels[commands[Number_of_command].substr(1)] + 1;
			break;
		case 'Z':
			if (registers[commands[Number_of_command][1]] == 0) {
				Number_of_command = labels[commands[Number_of_command].substr(2)] + 1;
			}
			else {
				Number_of_command++;
			}
			break;
		case 'E':
			if (registers[commands[Number_of_command][1]] == registers[commands[Number_of_command][2]]) {
				Number_of_command = labels[commands[Number_of_command].substr(3)] + 1;
			}
			else {
				Number_of_command++;
			}
			break;
		case 'G':
			if (registers[commands[Number_of_command][1]] > registers[commands[Number_of_command][2]]) {
				Number_of_command = labels[commands[Number_of_command].substr(3)] + 1;
			}
			else {
				Number_of_command++;
			}
			break;
		case 'Q':
			Number_of_command = N;
			Number_of_command++;
			break;
		default:
			MainQueue.push(stoi(commands[Number_of_command]));
			Number_of_command++;
		}
	} while (Number_of_command <= N);
	output.close();

	return 0;
}