#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>vec = {1,2,4,5};

    for(int value : vec){
        cout << value << endl;
    }

    return 0;

}