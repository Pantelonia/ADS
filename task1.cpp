#include <fstream>
using namespace std;
int main(){
    ifstream input ("input.txt");
    long a, b;
    input >>a>>b;
    long long c = a+b;
    ofstream output ("output.txt");
    output << c;
    return 0;
    
}