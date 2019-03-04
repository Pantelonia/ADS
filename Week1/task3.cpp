#include <fstream>
using namespace std;
int main(){
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    int n, j;
    long tmp;
    input >>n;
    long* arr = new long[n];
    
    for (int i = 0; i < n; i++) {
		input >> arr[i];
	}
	input.close();
	for(int i = 0 ; i<n; i++){
	    for(j=i; j>0 && arr[j-1]>arr[j];j--){
	        tmp = arr[j-1];
	        arr[j-1]=arr[j];
	        arr[j] = tmp;
	    }
	    output << j+1;
	    if(i!=n-1) 
	        output << " ";
	 }
	 output << endl;
	 
	 for (int i = 0; i < n; i++) {
		output << arr[i];
		if (i != n - 1) output << " ";
	}

	output.close();
	
    
    return 0;
    
}