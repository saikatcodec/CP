#include <bits/stdc++.h>
using namespace std;

typedef struct phone
{
    char os[50];
    int ram;
    int rom;
    double screen;
} phone;

typedef struct student {
    char name[100];
    int ag;
    double a;
} st;

int main()
{
    phone ph;

    strcpy(ph.os, "Android 11");
    ph.ram = 8;
    ph.rom = 32;
    ph.screen = 5.6;

    cout << "Phone OS: " << ph.os << endl;
    cout << "RAM: " << ph.ram << "GB" << endl;
    cout << "ROM: " << ph.rom << "GB" << endl;
    cout << "Screen Size: " << ph.screen << " inch" << endl;

    cout << sizeof(ph) << endl;

    st st1;
    cout << sizeof(st1) << endl;

    return 0;
}