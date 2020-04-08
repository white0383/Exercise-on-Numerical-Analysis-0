#include <iostream>

using namespace std;

int main() {
    srand((unsigned int)time(0));

    for(int i=0;i<10;i++){
        cout<<rand() % 10<<endl;
    }

    return 0;
}