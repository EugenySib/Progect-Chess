// chest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cstdio>
#include<queue>
int knight(std::string pos1, std::string pos2) {
    char a = pos1[0], b=pos2[0];
    std::string nyt1(1,pos1[1]);
    std::string nyt2(1,pos2[1]);
    int nx, ny =std::atoi(nyt1.c_str()), tx, ty = std::atoi(nyt2.c_str());
    int mx[] = { -1, -1, 1, 1, -2, -2, 2, 2 };
    int my[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
    int A[8][8];  //Доска 8х8.
    nx = a - 'a';
    ny--;
    tx = b - 'a';
    ty--;
    A[nx][ny] = 0;
    std::queue< std::pair<int, int> > q; //???? std::queue std::pair  std::make_pair
    q.push(std::make_pair(nx, ny));
    while (!q.empty()) {
        std::pair<int, int> c = q.front();
        int x = c.first, y = c.second;
        if (x == tx && y == ty) break;
        q.pop();
        for (int i = 0; i < 8; i++) {
            if (x + mx[i] >= 0 && x + mx[i] < 8 && y + my[i] >= 0 && y + my[i] < 8) {
                q.push(std::make_pair(x + mx[i], y + my[i]));
                A[x + mx[i]][y + my[i]] = A[x][y] + 1;
            }
        }
    } 
    return (A[tx][ty]);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    std::string pos1,pos2;
    while (true) {
        std::cout << "Введите первую позицию\n";
        std::cin >> pos1;
        std::cout << "Введите вторую позицию\n";
        std::cin >> pos2;
        std::cout << "Минимальное число ходов из позиции " << pos1 << " в позицию " << pos2 << " равно " << knight(pos1, pos2) << " шагов\n";
        //printf("Минимальное число ходов для коня из позиции %s в позицию %s равно %d шагам.\n", pos1, pos2, A[tx][ty]);
    }
}