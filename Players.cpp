// Players.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>





class Player {
    char name [100];
    int score;
public:
       Player() {
        std::cout << "input player name: ";
        std::cin >> name;
        std::cout << "input player score: ";
        std::cin >> score;}
    int GetScore() { return score;}
    char* GetName() { return name;}
};

struct tnode { // дерево
    Player field;
    struct tnode* left;  // левый потомок
    struct tnode* right; // правый потомок
};

struct tnode* addNode(struct tnode* tree, Player* pl) { // добавляем ветку дерева
    if (tree == NULL) { // если нет ветки - инициализируем ее
        tree = (struct tnode*)malloc(sizeof(struct tnode));
        tree->field = *pl;
        tree->left = tree->right = NULL;
    }
    else if (tree->field.GetScore() < pl->GetScore()) { // если очки ветки меньше, идем на левую ветку
        tree->left = addNode(tree->left, pl);
    }
    else { // иначе идем на правую ветку
        tree->right = addNode(tree->right, pl);
    }
    return tree;
}

void PrintTree(struct tnode* tree) { 
    if (tree != NULL) {
        PrintTree(tree->left);
        std::cout << tree->field.GetName() << "  " << tree->field.GetScore() << std::endl;
        PrintTree(tree->right);
    }
}
int main()
{
    int playersCount;
    std::cout << "how many players do you want to add?\n";
    std::cin >> playersCount;
    Player* (*players) = new Player * [playersCount];
    for (int i = 0; i < playersCount; i++) {
        players[i] = new Player;
    }
    // сортировка деревом
    struct tnode* root;
    root = NULL;
    for (int i = 0; i < playersCount; i++) {
        root = addNode(root, players[i]);
    }
    PrintTree(root);
   
   // пузырьковая 
    bool b = true;
    int elements = playersCount;
    while (b) {
        b = false;
        for (int i = 0; i + 1 < elements; i++) {

            if (players[i]->GetScore() < players[i + 1]->GetScore()) {
                Player* temp = players[i];
                players[i] = players[i + 1];
                players[i + 1] = temp;
                b = true;
            }

        }
        elements--;
    }
    for (int i = 0; i < playersCount; i++) {
        std::cout << players[i]->GetName() << "  - " << players[i]->GetScore() << std::endl;
    }
    for (int i = 0; i < playersCount; i++) {
        delete players[i];
        players[i] = nullptr;
    }
    delete players;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
