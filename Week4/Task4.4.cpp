#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	char command;
	long N, min, head, min_head, tail, min_tail;
	N = head = min_head = 0;
	min_tail = tail = -1;
	input >> N;
	long* queue = new long[N];
	long* queue_of_min = new long[N];
	for (long i = 0; i < N; i++)
	{
		input >> command;
		switch (command)
		{
		case '+':
			input >> queue[++tail];
			while (min_head - min_tail >= 0 && queue[tail] < queue_of_min[min_tail]) {
				min_tail--;
			}

			queue_of_min[++min_tail] = queue[tail];

			continue;
		case '-':
			if (queue[head] == queue_of_min[min_head]) {
				min_head++;
			}
			head++;
			continue;
		case'?':
			output << queue_of_min[min_head] << '\n';
			continue;

		}

	}
	return 0;
}