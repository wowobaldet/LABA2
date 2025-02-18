#include "Func.h"

bool has_space(string& primer){
    int count = 0;
    int count_elements = 1;
    for (int i = 0; i < primer.size(); i++){
        if (primer[i] == ' ') count++ && count_elements++;
    }
    if (count + count + 1 < count_elements) return 0;
    return 1;
}

bool count_act(string& primer){
    int count_num = 0;
    int count_act = 0;
    for (int i = 0; i < primer.size(); i++){
        if (isdigit(primer[i]) && i+2 >= primer.size()) return 0;
        if (primer[i+1] == ' ' && isdigit(primer[i])) count_num++;
        if (!isdigit(primer[i]) && primer[i] != ' ') count_act++; 
    }
    if (count_act / count_num >= 1) return 0;
    else return 1;
}

int First(){
    Stk math_pol;
    string primer = "";
    getline(cin, primer);
    if (!has_space(primer) || !count_act(primer)) {
        cout << "Incorrect" << endl;
        return 0;
    }
    string vstavka = "";
    istringstream is(primer);
        Stk reverse_stack;
        while (is >> vstavka){
            reverse_stack.SPUSH(vstavka);
            vstavka = "";
        }
        while (!reverse_stack.is_empty()){
            math_pol.SPUSH(reverse_stack.head->data);
            reverse_stack.SPOP();
        }
    int equals = 0;
    SNode* current = math_pol.head;
    while (!math_pol.is_empty()){
        current = math_pol.head;
        while (isdigit(current->next->next->data[0])){
            current = current->next;
        }
        if (current->next->next->data == "+"){
            equals = stoi(current->data) + stoi(current->next->data);
        }
        else if (current->next->next->data == "-"){
            equals = stoi(current->data) - stoi(current->next->data); 
        }
        else if (current->next->next->data == "*"){
            equals = stoi(current->data) * stoi(current->next->data);
        }
        else if (current->next->next->data == "/"){
            equals = stoi(current->data) / stoi(current->next->data);
        }
        else {
            cout << "Incorrect" << endl;
            return 0;
        }
        SNode* recreate = math_pol.head;
        primer = "";
        while(recreate != nullptr){
            if (recreate == current) {
                recreate->data = to_string(equals);
                primer += recreate->data + ' ';
                recreate = recreate->next->next->next;
            }
            if (recreate == nullptr){
                return equals;
            }
            primer += recreate->data + ' ';
            recreate = recreate->next;
        }
        while (!math_pol.is_empty()){
            math_pol.SPOP();
        }
        istringstream is(primer);
        Stk reverse_stack;
        while (is >> vstavka){
            reverse_stack.SPUSH(vstavka);
            vstavka = "";
        }
        while (!reverse_stack.is_empty()){
            math_pol.SPUSH(reverse_stack.head->data);
            reverse_stack.SPOP();
        }
        if (math_pol.is_empty()) return equals;  
    }   
    return equals;
}