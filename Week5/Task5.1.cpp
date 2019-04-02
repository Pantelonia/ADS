#include <fstream>
#include <string>

using namespace std;

string check_is_heap(long* A, long n) {
	for (long i = n / 2; i > 0; i--)
	{		
		if (A[i-1] > A[2 * i-1] )
			return "NO";
				
		if (2*i + 1 <= n && A[i-1] > A[2 * i ])
			return "NO";		
	}
	return "YES";


}


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	long n;
	input >> n;
	long* A = new long[n];

	for (long i = 0; i < n; i++)
	{
		input >> A[i];
	}
	output << check_is_heap(A, n);

	

	return 0;
}