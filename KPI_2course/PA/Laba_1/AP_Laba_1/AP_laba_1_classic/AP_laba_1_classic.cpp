#include "Header.h"
#include <iostream>
using namespace std;

int main()
{
    char Main_file[] = "main_file.txt";
    int ammount = 100000;
    gen(Main_file, ammount);
    cout << "---Initial file:\n";
    outcontent(Main_file);
    merge(Main_file, ammount);
    cout << "---Sorted file:\n";
    outcontent(Main_file);
    system("pause");
    return 0;
}