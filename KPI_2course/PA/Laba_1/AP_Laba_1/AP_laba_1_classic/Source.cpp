#include "Header.h"
void outcontent(char* Name) {
    ifstream outp(Name);
    string line = "";
    int number;
    while (!outp.eof()) {
        getline(outp, line);
        number = stoi(line);
        cout << number << " ";
    }
    outp.close();
    cout << endl;
}
int coun(int quan) {
    double ah = log2(quan);
    int quamer = int(ah);
    if (fmod(ah, 1) > 0.0) {
        quamer += 1;
    }
    return quamer;
}
void gen(char* Name, int quan) {
    srand(time(NULL));
    ofstream fill(Name);
    int number;
    bool hf0 = 0;
    for (int i = 0; i < quan; i++) {
        if (hf0) {
            fill << "\n";
        }
        else {
            hf0 = 1;
        }
        number = rand() % 65536 - 12768;
        fill << number;
    }
    fill.close();
}
void merge(char* Name, int quan) {
    char Help1[] = "help1.txt";
    char Help2[] = "help2.txt";
    int ammer = coun(quan);
    int h, a, b;
    bool hf0, hf1;
    string lh, lh1, lh2;
    for (int i = 0; i < ammer; i++) {
        ifstream outp(Name);
        ofstream fill1(Help1);
        ofstream fill2(Help2);
        hf0 = 0;
        hf1 = 0;
        h = pow(2, i);
        for (int j = 0; j < quan; j++) {
            getline(outp, lh);
            if ((j / h) % 2 == 0) {
                if (hf0) {
                    fill1 << "\n";
                }
                else {
                    hf0 = 1;
                }
                fill1 << lh;
            }
            else {
                if (hf1) {
                    fill2 << "\n";
                }
                else {
                    hf1 = 1;
                }
                fill2 << lh;
            }
        }
        outp.close();
        fill1.close();
        fill2.close();
        ofstream refill(Name);
        ifstream outp1(Help1);
        ifstream outp2(Help2);
        bool flag1 = 1;
        bool flag2 = 1;
        if (!outp1.eof()) {
            getline(outp1, lh1);
        }
        else {
            flag1 = 0;
        }
        if (!outp2.eof()) {
            getline(outp2, lh2);
        }
        else {
            flag2 = 0;
        }
        hf0 = 0;
        while (flag1 || flag2) {
            a = 0;
            b = 0;
            while (a < h || b < h) {
                if (flag1 && flag2) {
                    if (a >= h) {
                        if (hf0) {
                            refill << "\n";
                        }
                        else {
                            hf0 = 1;
                        }
                        refill << lh2;
                        b++;
                        if (!outp2.eof()) {
                            getline(outp2, lh2);
                        }
                        else {
                            flag2 = 0;
                        }
                    }
                    else if (b >= h) {
                        if (hf0) {
                            refill << "\n";
                        }
                        else {
                            hf0 = 1;
                        }
                        refill << lh1;
                        a++;
                        if (!outp1.eof()) {
                            getline(outp1, lh1);
                        }
                        else {
                            flag1 = 0;
                        }
                    }
                    else {
                        if (stoi(lh1) <= stoi(lh2)) {
                            if (hf0) {
                                refill << "\n";
                            }
                            else {
                                hf0 = 1;
                            }
                            refill << lh1;
                            a++;
                            if (!outp1.eof()) {
                                getline(outp1, lh1);
                            }
                            else {
                                flag1 = 0;
                            }
                        }
                        else {
                            if (hf0) {
                                refill << "\n";
                            }
                            else {
                                hf0 = 1;
                            }
                            refill << lh2;
                            b++;
                            if (!outp2.eof()) {
                                getline(outp2, lh2);
                            }
                            else {
                                flag2 = 0;
                            }
                        }
                    }
                }
                else {
                    if (flag1) {
                        if (hf0) {
                            refill << "\n";
                        }
                        else {
                            hf0 = 1;
                        }
                        refill << lh1;
                        if (!outp1.eof()) {
                            getline(outp1, lh1);
                        }
                        else {
                            flag1 = 0;
                        }
                    }
                    else {
                        if (hf0) {
                            refill << "\n";
                        }
                        else {
                            hf0 = 1;
                        }
                        refill << lh2;
                        if (!outp2.eof()) {
                            getline(outp2, lh2);
                        }
                        else {
                            flag2 = 0;
                        }
                    }
                }
                if (!flag1 && !flag2) {
                    a = h;
                    b = h;
                }
            }
        }
        outp1.close();
        outp2.close();
        refill.close();
    }
}