#include <fstream>
using namespace std;
int main(){
    ifstream input ("input.txt");
    long long a, b;
    input >>a>>b;
    long long c = a+b*b;
    ofstream output ("output.txt");
    output << c;
    return 0;
    
}