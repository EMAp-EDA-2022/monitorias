// Copyright (c) 2022 Giovani Valdrighi

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.

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
void BubbleSortVector(vector<T>* ptr_vec) {
    bool changed = true;
    // Caso passemos um loop inteiro sem fazer trocas,
    // o vector já está ordenada
    while (changed) {
        changed = false;
        for (int i = 0; i < (ptr_vec->size() - 1); i++) {
            // Se dois consecutivos estiverem em ordem erradas
            // Faz a inversão (swap)
            if ((*ptr_vec)[i] > (*ptr_vec)[i + 1]) {
                T aux = (*ptr_vec)[i];
                (*ptr_vec)[i] = (*ptr_vec)[i + 1];
                (*ptr_vec)[i + 1] = aux;
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
void SortVector(vector<T>* ptr_vec) {
    sort(ptr_vec->begin(), ptr_vec->end());
}


template<class T>
void Print(vector<T> vec) {
    cout << "vec.: {";
    for (int i = 0; i < (vec.size() - 1); i++) {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.size() - 1] << "}" << endl;
}

int main() {
    vector<int> myvec = {5, 4, 3, 2, 1};
    Print(myvec);
    BubbleSortVector(&myvec);
    Print(myvec);
    myvec.push_back(-1);
    Print(myvec);
    SortVector(&myvec);
    Print(myvec);
    return 0;
}
