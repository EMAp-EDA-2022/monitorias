#include <vector>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

/*
Função que ordena um vector in-place (sem gerar uma cópia)
utilizando o algoritmo bubble sort.
Funciona com um vector que possua qualquer tipo de dado,
desde que esse tipo suporte a operação de comparação.
*/
template<class T>
void BubbleSortVector(vector<T>& vec) {
    bool changed = true;
    // Caso passemos um loop inteiro sem fazer trocas, 
    // o vector já está ordenada
    while (changed) {
        changed = false;
        for (int i = 0; i < (vec.size() - 1); i++) {
            // Se dois consecutivos estiverem em ordem erradas
            // Faz a inversão (swap)
            if (vec[i] > vec[i + 1]) {
                T aux = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = aux;
                changed = true;
            }
        }
    }
}

/*
Função que utiliza a função "sort" para ordenar 
os elementos de um vector. É necessário incluir "algorithm".
*/
template<class T>
void SortVector(vector<T>& vec) {
    sort(vec.begin(), vec.end());
}


template<class T>
void Print(vector<T> vec) {
    cout << "vec.: {";
    for(int i = 0; i < (vec.size() - 1); i++) {
        cout << vec[i] << ", "; 
    }
    cout << vec[vec.size() - 1] << "}" << endl;
}

int main() {
    vector<int> myvec = {5, 4, 3, 2, 1};
    Print(myvec);
    BubbleSortVector(myvec);
    Print(myvec);
    myvec.push_back(-1);
    Print(myvec);
    SortVector(myvec);
    Print(myvec);
    return 0;
}