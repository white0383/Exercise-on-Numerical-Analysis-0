#include <iostream>
#include <time.h>

using namespace std;

#define EXPTIMES 180
#define MAXCHAIN 30

int main() {
    clock_t start = clock();

    int randNum = 0;
    int prevNum = -1;
    int chainCount = 1;
    unsigned int countArr[10] = {0,}; // 0から9までの数字が何回出たかを保存しておく
    unsigned int countChainArr[10][MAXCHAIN] = {0}; // countChainArr[i][j]: iが連続でj回出た回数

    srand((unsigned int)time(0));

    while( (clock() - start)/CLOCKS_PER_SEC < EXPTIMES ) {
        randNum = rand() % 10;
        countArr[randNum]++;

        if(randNum == prevNum){
            chainCount++;
        } else {
            if(chainCount >= MAXCHAIN){
                countChainArr[randNum][MAXCHAIN-1]++;
            } else {
                countChainArr[randNum][chainCount]++;
            }
            chainCount = 1;
        }

        prevNum = randNum;
    };

    for(int i=0;i<10;i++){
        cout<< i << ": " << countArr[i] << " times" << endl;
    }

    for(int i=0;i<10;i++){
        cout << i << "\t";
        for(int j=1;j<MAXCHAIN;j++){
            cout<< countChainArr[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
};