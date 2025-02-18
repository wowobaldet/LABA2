#include "Func.h"

void Kasar(string& roman_value, int& convert, Hash& rome){
    while(convert / 1000 > 0){
        if (convert / 1000 > 3 || convert / 1000 <= 0) {
            cout << "Incorrect" << endl;
            return;
        }
        roman_value += rome.HGet("1000");
        convert -= 1000;
    }
}

void Sotki(string& roman_value, int& convert, Hash& rome){
    if (convert % 1000 / 100 == 4) {
        roman_value += rome.HGet("100") + rome.HGet("500");
    }
    if (convert % 1000 / 100 == 5) {
        roman_value += rome.HGet("500");
    }
    if (convert % 1000 / 100 <= 3){
        while (convert % 1000 / 100 > 0){
            roman_value += rome.HGet("100");
            convert -= 100;
        }
    }
    if (convert % 1000 / 100 == 9) {
        roman_value += rome.HGet("100") + rome.HGet("1000");
    }
    if (convert % 1000 / 100 < 9 && convert % 1000 / 100 > 5){
        roman_value += rome.HGet("500");
        convert -= 500;
        while (convert % 1000 / 100 > 0){
            roman_value += rome.HGet("100");
            convert -= 100;
        }
    }
}

void Chervonec(string& roman_value, int& convert, Hash& rome){
    if (convert % 100 / 10 == 5) roman_value += rome.HGet("50");
    if (convert % 100 / 10 <= 3) {
        while (convert % 100 / 10 > 0){
            roman_value += rome.HGet("10");
            convert -= 10;
        }
    }
    if (convert % 100 / 10 == 4) roman_value += rome.HGet("10") + rome.HGet("50");
    if (convert % 100 / 10 == 9) roman_value += rome.HGet("10") + rome.HGet("100");
    if (convert % 100 / 10 > 5 && convert % 100 / 10 != 9){
        roman_value += rome.HGet("50");
        convert -= 50;
        while (convert % 100 / 10 > 0){
            roman_value += rome.HGet("10");
            convert -= 10;
        }
    }
}

void Digit(string& roman_value, int& convert, Hash& rome){
    if (convert % 10 == 5) roman_value += rome.HGet("5");
    if (convert % 10 == 9) roman_value += rome.HGet("1") + rome.HGet("10");
    if (convert % 10 == 4) roman_value += rome.HGet("1") + rome.HGet("5");
    if (convert % 10 <= 3){
        while (convert % 10 > 0){
            roman_value += rome.HGet("1");
            convert -= 1;
        }
    }
    if (convert % 10 < 9 && convert % 10 > 5){
        roman_value += rome.HGet("5");
        convert -= 5;
        while (convert % 10 > 0){
            roman_value += rome.HGet("1");
            convert -= 1;
        }
    }
}

void Hash_zad(){
    Hash rome;
    rome.HPush("1", "I");
    rome.HPush("5", "V");
    rome.HPush("10", "X");
    rome.HPush("50", "L");
    rome.HPush("100", "C");
    rome.HPush("500", "D");
    rome.HPush("1000", "M");
    string value = "";
    string roman_value = "";
    cin >> value;
    int i = 0;
    int convert = stoi(value);
    Kasar(roman_value, convert, rome);
    Sotki(roman_value, convert, rome);
    Chervonec(roman_value, convert, rome);
    Digit(roman_value, convert, rome);
    cout << roman_value << endl;
}