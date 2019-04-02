#include <fstream>
#include <string>

using namespace std;


struct element {
	long value;
	long position_string;
};

void swop(element* a, element* b) {
	element temp = *a;
	*a = *b;
	*b = temp;
}

void find_place(element* array, long i, long* array_of_positions) {
	//Находим место для элемента, как было сказано в презентации
	long parent = i / 2 - (1 - i % 2);
	while (i != 0 && array[i].value < array[parent].value) {
		array_of_positions[array[i].position_string] = parent;
		array_of_positions[array[parent].position_string] = i;
		swop(&array[i], &array[parent]);
		i = parent;
		parent = i / 2 - (1 - i % 2);
	}
}

void recovery_heap(element* array, long tail, long* array_of_positions) {
	long position = 0;
	long left = 2 * (position + 1) - 1;
	long right = 2 * (position + 1);
	while (position != tail && ((array[position].value > array[left].value && left <= tail) || (array[position].value > array[right].value && right <= tail))) {
		if (array[right].value < array[left].value && right <= tail) {
			array_of_positions[array[position].position_string] = right;
			array_of_positions[array[right].position_string] = position;
			swop(&array[right], &array[position]);
			position = right;
		}
		else {
			array_of_positions[array[position].position_string] = left;
			array_of_positions[array[left].position_string] = position;
			swop(&array[left], &array[position]);
			position = left;
		}
		left = 2 * (position + 1) - 1;
		right = 2 * (position + 1);
	}
}


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	long N;
	input >> N;
	element* Queue = new element[N];
	long top = 0;
	long tail = -1;

	long* tree = new long[N];

	char command;
	long a, temp;


	for (long i = 0; i < N; i++) {
		input >> command;
		switch (command)
		{
		case 'A':
			input >> a;
			Queue[++tail] = element{ a, i };
			tree[i] = tail;
			find_place(Queue, tail, tree);
			break;
		case 'X':
			if (top > tail) {
				output << '*' << '\n';
			}
			else {
				tree[Queue[top].position_string] = tail;
				tree[Queue[tail].position_string] = top;
				swop(&Queue[top], &Queue[tail]);

				output << Queue[tail--].value << '\n';

				recovery_heap(Queue, tail, tree);
			}
			break;
		case 'D':
			input >> a;
			input >> temp;
			Queue[tree[a - 1]].value = temp;
			find_place(Queue, tree[a - 1], tree);
			break;
		default:
			break;
		}

	}

	return 0;
}