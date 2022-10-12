#include <iostream>
using namespace std;
#include "Header.h"
int main() {
    char Initial[] = "initial.txt";
    int size = 100000;// 20000000;
    int amm = 10;
    bool hf0 = 0;
    gen(size, amm, Initial);
    GenSort(size, amm, Initial);
    system("pause");
    return 0;
}