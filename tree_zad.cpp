#include "Func.h"

void zigzagLevelOrder(TNode* root) {
    if (!root) return; // Если дерево пустое, выходим

    Stk current_level; // Стек для текущего уровня
    Stk next_level;    // Стек для следующего уровня
    bool left_to_right = true; // Флаг для определения направления

    current_level.SPUSH(root); // Добавляем корень в текущий уровень

    while (!current_level.is_empty()) {
        TNode* node = current_level.head->Ndata;
        current_level.SPOP();
        if (node) {
            cout << node->data << " ";

            // Добавляем дочерние узлы в следующий уровень
            if (left_to_right) {
                if (node->left) next_level.SPUSH(node->left);
                if (node->right) next_level.SPUSH(node->right);
            } else {
                if (node->right) next_level.SPUSH(node->right);
                if (node->left) next_level.SPUSH(node->left);
            }
        }

        if (current_level.is_empty()) {
            swap(current_level, next_level);
            left_to_right = !left_to_right;
        }
    }
    cout << endl;
}

void tree_zad(){
    Tree derevo{nullptr};
    derevo.TPush(derevo.root, "22");
    derevo.TPush(derevo.root, "52");
    derevo.TPush(derevo.root, "16");
    derevo.TPush(derevo.root, "57");
    derevo.TPush(derevo.root, "43");
    derevo.TPush(derevo.root, "19");
    derevo.TPush(derevo.root, "7");
    derevo.TPush(derevo.root, "8");
    derevo.TPush(derevo.root, "7");
    derevo.TPush(derevo.root, "8");
    zigzagLevelOrder(derevo.root);
}