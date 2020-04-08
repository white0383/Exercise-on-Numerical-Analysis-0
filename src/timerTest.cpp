#include <iostream>
#include <time.h>

using namespace std;

int main() {
    clock_t start = clock();

    unsigned int count = 0;

    while( (clock() - start)/CLOCKS_PER_SEC < 3){
        count ++;
    }

    clock_t end = clock();

    cout << "count: " << count << endl;
    cout << "start: " << start << endl;
    cout << "end  : " << end << endl;
    cout << "time : " << (end - start) / CLOCKS_PER_SEC << endl;
    cout << "tanni: " << CLOCKS_PER_SEC << endl;
}