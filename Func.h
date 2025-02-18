#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool has_space(string& primer);

bool count_act(string& primer);

int First();

int count(Massive& mas, string symb);

void sort(Massive& mas, Massive& numbers);

bool is_all_zero(Massive& numbers);

bool is_inlist(char symb, Massive& levels, int level);

void Pyramid(Massive& numbers, Massive& mas);

void Second();

void Kasar(string& roman_value, int& convert, Hash& rome);

void Sotki(string& roman_value, int& convert, Hash& rome);

void Chervonec(string& roman_value, int& convert, Hash& rome);

void Digit(string& roman_value, int& convert, Hash& rome);

void Hash_zad();

void zigzagLevelOrder(TNode* root);

void tree_zad();

void TrueOrFalse(int kol);