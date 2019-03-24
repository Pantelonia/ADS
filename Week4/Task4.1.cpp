#include <fstream>
using namespace std;


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	char command;
	long n;
	long top = -1;
	input >> n;
	long* stack = new long[n];

	for (long i = 0; i < n; i++)
	{
		input >> command;
		if (command == '+') {
			top++;
			input >> stack[top];
			
		}
		else
		{
			output << stack[top] << '\n';
			top--;
		}
	}

	


	return 0;
}