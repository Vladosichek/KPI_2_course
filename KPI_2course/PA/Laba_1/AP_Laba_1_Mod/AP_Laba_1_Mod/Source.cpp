#include "Header.h"
void merge(int* arr, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1];
    int* M = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void gen(int siz, int am, char* Name) {
    ofstream fill(Name);
    bool hf0 = 0;
    int num;
    srand(time(NULL));
    int* arr = new int[siz];
    for (int i = 0; i < siz * am; i++) {
        if (hf0) {
            fill << "\n";
        }
        else {
            hf0 = 1;
        }
        num = rand() % 65536 - 2768;
        fill << num;
    }
    fill.close();
}
void GenSort(int siz, int am, char* Name) {
    char Sorted[] = "sorted.txt";
    char Help[] = "help.txt";
    bool hf0;
    ofstream SortedP(Sorted);
    SortedP.close();
    ifstream Readf(Name);
    string line = "";
    for (int i = 0; i < am; i++) {
        hf0 = 0;
        int* arr = new int[siz];
        for (int j = 0; j < siz; j++) {
            getline(Readf, line);
            arr[j] = stoi(line);
        }
        mergeSort(arr, 0, siz - 1);
        line = "";
        ifstream SortedY(Sorted);
        ofstream HelpP(Help);
        for (int j = 0; j < i * siz; j++) {
            getline(SortedY, line);
            if (hf0) {
                HelpP << "\n";
            }
            else {
                hf0 = 1;
            }
            HelpP << line;
        }
        SortedY.close();
        HelpP.close();
        hf0 = 0;
        ofstream SortedN(Sorted);
        ifstream HelpN(Help);
        int c = 0;
        int q = 0;
        getline(HelpN, line);
        while (c < siz || q < siz * i) {
            if (c < siz && q < siz * i) {
                if (arr[c] <= stoi(line)) {
                    if (hf0) {
                        SortedN << "\n";
                    }
                    else {
                        hf0 = 1;
                    }
                    SortedN << arr[c];
                    c++;
                }
                else {
                    if (hf0) {
                        SortedN << "\n";
                    }
                    else {
                        hf0 = 1;
                    }
                    SortedN << stoi(line);
                    if (q < siz * i) {
                        getline(HelpN, line);
                        q++;
                    }
                }
            }
            else {
                if (c < siz) {
                    if (hf0) {
                        SortedN << "\n";
                    }
                    else {
                        hf0 = 1;
                    }
                    SortedN << arr[c];
                    c++;
                }
                else {
                    if (hf0) {
                        SortedN << "\n";
                    }
                    else {
                        hf0 = 1;
                    }
                    SortedN << stoi(line);
                    if (q < siz * i) {
                        getline(HelpN, line);
                        q++;
                    }
                }
            }
        }
        delete[] arr;
        SortedN.close();
        HelpN.close();
    }
    Readf.close();
}