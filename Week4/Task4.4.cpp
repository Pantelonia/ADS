#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	char command;
	long N, min, top, head, tail;
	N = top = head = tail = 0;
	top = -1;
	input >> N;
	long* queue = new long[N];
	long* stack_of_min = new long[N];
	for (long i = 0; i < N; i++)
	{
		input >> command;
		switch (command)
		{
		case '+':
			input >> queue[tail];
			stack_of_min[++top] = queue[tail];
			min = top;
			while (min > 0 && stack_of_min[min - 1] < stack_of_min[min])
			{
				swap(stack_of_min[min - 1], stack_of_min[min]);
				min--;
			}
			tail++;
			continue;
		case '-':
			if (queue[head] == stack_of_min[top])
				top--;
			head++;
			continue;
		case'?':
			output << stack_of_min[top] << '\n';
			continue;

		}

	}
	return 0;
}