#include <fstream>
using namespace std;
int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n, newindex;
    long temp;
    input >> n;
    long* M = new long[n];
    
    for (int i = 0; i < n; i++) {
        input >> M[i];
    }
    
    for (int i = 0; i < n; i++) {
       
        newindex =i;
        temp = M[i];
         for (int j = i+1; j < n; j++) {
             //Если текущий элемент меньше последующих, то менем
            if(temp > M[j]){
              temp = M[j];
              newindex = j;
            }
         }
        // while(j<n){
        //     if(temp>M[j]){
        //         temp = M[j];
        //         newindex =j;
        //     }
        //     j++;
        // }
          if(i!=newindex){
                M[newindex] = M[i];
                M[i] = temp;
                output << "Swap elements at indices " << i +1 << " and " << newindex+1 << "." << endl;
            }
    }
    output << "No more swaps needed." << endl;

	for (int i = 0; i < n; i++) {
		output << M[i];
		if (i != n - 1) output << " ";
	}

	output.close();

    return 0;
    
}	