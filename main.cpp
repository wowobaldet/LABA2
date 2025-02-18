#include "Header.h"
#include "Func.h"
#include "func.cpp"
#include "second.cpp"
#include "hash_zad.cpp"
#include "tree_zad.cpp"
#include "turtles.cpp"

int main(){
    cout << "Choose your task: " << "\n1.\n2.\n3.\n4.\n5." << endl;
    int num_task = 0;
    cin >> num_task;
    cin.get();
    switch (num_task)
    {
    case 1:
        cout << First() << endl;
        break;
    case 2: {
        int num = 0;
        cin >> num;
        TrueOrFalse(num);
        break;
    }
    case 3:
        Second();
        break;
    case 4:
        tree_zad();
        break;
    case 5:
        Hash_zad();
    default:
        break;
    } 
    
}

