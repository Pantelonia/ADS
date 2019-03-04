#include <fstream>
using namespace std;
int main(){
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    int n, j,  min, max, middle;
    float* tmp;
    input >>n;
    //объявление динамического массива на N строк и два столбца
    float** ptrarray = new float*[n];
    for (int i = 0; i < n; i++) {
        ptrarray[i] = new float[2]; 
        input >> ptrarray[i][0];//записываем состояние
        ptrarray[i][1] = i+1;// записываем индекс начиная с единицы
    }
    input.close();
    //сортировка вставками
    for(int i = 0 ; i<n; i++){
        for(j=i; j>0 && ptrarray[j-1][0] > ptrarray[j][0];j--){
            tmp = ptrarray[j-1];
            ptrarray[j-1]=ptrarray[j];
            ptrarray[j] = tmp;
        }
        
    }
    max = ptrarray[n-1][1];
    min = ptrarray[0][1];
    middle = ptrarray[n/2][1];
    output << min << " " << middle << " " << max;
    output.close();
    
    return 0;
    
}