#include "edx-io.hpp"

using namespace std;


int main() {
	long N;
	io >> N;
	char action;
	long* queue = new long[N];
	long offset = -1;
	long head = 0;
	long *minQueue = new long[N];
	long minOffset = -1;
	long minHead = 0;

	for (long i = 0; i < N; i++) {
		io >> action;
		switch (action)
		{
		case '+':
			io >> queue[++offset];
			
			while (minOffset - minHead >= 0 && minQueue[minOffset] > queue[offset]) {
				minOffset--;
			}
			minQueue[++minOffset] = queue[offset];
			continue;
		case '-':
	
			if (queue[head] == minQueue[minHead]) {
				minHead++;
			}
			head++;
			continue;
		case '?':
			io << minQueue[minHead] << '\n';
			continue;
		}

	}
	return 0;
}