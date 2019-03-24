#include <fstream>
#include <string>
using namespace std;

string volid_seq(string sequence, char* stack, long top) {
	for (int i = 0; i < sequence.size(); i++)
	{
		switch (sequence[i])
		{
		case '(':
			stack[++top] = sequence[i];
			continue;
		case '[':
			stack[++top] = sequence[i];
			continue;
		case ')':
			if (stack[top] != '(' || top < 0)
				return "NO\n";
			top--;
			continue;
		case ']':
			if (stack[top] != '[' || top < 0)
				return "NO\n";
			top--;
			continue;
		}
	}

		if (top == -1) {
			return "YES\n";
		}
		return "NO\n";


	


}

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	long N, top;
	input >> N;
	char* stack = new char[10000];
	string sequence;
	for (long i = 0; i < N; i++)
	{
		input >> sequence;
		top = -1;
		output << volid_seq(sequence, stack, top);
	}
	return 0;
}