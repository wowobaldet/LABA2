#include "Func.h"

int count(Massive& mas, string symb){
    int count = 0;
    for (int i = 0; i < mas.Size(); i++){
        if (mas[i] == symb) {
            if (count >= 1) mas.MPopind(i);  
            count++;  
        }
    }
    return count;
}

void sort(Massive& mas, Massive& numbers){
    int ind = 0;
    while (ind < numbers.Size()){
        for (int i = 0, j = numbers.Size()-1; i != numbers.Size()/2 || j > numbers.Size()/2+1; i++, j--){
            if (stoi(numbers[i]) > stoi(numbers[i+1])){
                string temp = numbers[i+1];
                numbers.MChange(i+1, numbers[i]);
                numbers.MChange(i, temp);
                temp = mas[i+1];
                mas.MChange(i+1, mas[i]);
                mas.MChange(i, temp);
                temp = "";
            }
            if (stoi(numbers[j]) > stoi(numbers[j-1])){
                string temp = numbers[j-1];
                numbers.MChange(j-1, numbers[j]);
                numbers.MChange(j, temp);
                temp = mas[j-1];
                mas.MChange(j-1, mas[j]);
                mas.MChange(j, temp);
                temp = "";
            }
        }
        ind++;
    }
    return;
}

bool is_all_zero(Massive& numbers){
    for (int i = 0; i < numbers.Size(); i++){
        if (numbers[i] != "0") return 0;
    }
    return 1;
}

bool is_inlist(char symb, Massive& levels, int level){
    for (int i = 0; i < levels[level].size(); i++){
        if (symb == levels[level][i]) return 1;
    }
    return 0;
}

void Pyramid(Massive& numbers, Massive& mas){
    Massive levels;
    while (!is_all_zero(numbers)){
        string count = "";
        for (int i = 0; i < numbers.Size(); i++){
            int new_num = 0;
            if (numbers[i] == "0") {
                continue;
            }
            new_num = stoi(numbers[i]) - 1;
            numbers.MChange(i, to_string(new_num));
            count += mas[i];
        }
        if (count != "") levels.MPushback(count);
    }
    for (int i = levels.Size()-1; i >= 0; i--){
        for (int j = 0; j < mas.Size(); j++){
            if (!is_inlist(mas[j][0], levels, i)) cout << ' ';
            else cout << '#';
        }
        cout << endl;
    }
}

void Second(){
    Massive mas;
    Massive numbers;
    string slovo = "";
    getline(cin, slovo);
    for (int i = 0; i < slovo.size(); i++){
        if (slovo[i] == ' ' || slovo[i] == '\n') {
            i+1;
            continue;
        }
        string enter = "";
        enter += slovo[i];
        mas.MPushback(enter);
    }
    for (int i = 0; i < mas.Size(); i++){
        numbers.MPushback(to_string(count(mas, mas[i])));
    }
    sort(mas, numbers);
    Pyramid(numbers, mas);
    mas.MPrint();
}