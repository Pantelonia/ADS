#include <fstream>
using namespace std;


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	char command;
	long M;
	long head = 0;
	long tail = 0;
	input >> M;
	long* queue = new long[M];

	for (long i = 0; i < M; i++)
	{
		input >> command;
		if (command == '+')
		{
			
			input >> queue[tail];
			tail++;
		}
		else
		{
			output << queue[head] << '\n';
			head++;
		}
	}
	return 0;
}