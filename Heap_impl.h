/// Konieczna byla zamiana .cpp na plik .h bo linker nie radzi sobie z template, gdy jest rozbity na .cpp i .h
/// https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
#include "Heap.h"
/*Przeniesienie elementu w góre kopca*/
template<typename T>
void Heap<T>::goUp(int v) {
    while (true) {
        int p = v / 2;//wyznaczenie rodzica v
        if (p == 0)//sprawdzenie czy indeks rodzica jest równy 0
            return;
        if (comp(t[v], t[p])) {
            swap(t[v], t[p]);//zamiana rodzica z węzłem
            v = p;
        } else
            return;
    }
}
/*Przenoszenie elementu w dół kopca*/
template<typename T>
void Heap<T>::goDown(int v) {
    int l = 2 * v, r = 2 * v + 1;//wyznaczenie lewego i praweg "syna"
    if (l >= t.size())//sprawdzenie czy indeks lewego syna jest większy od rozmiaru kopca 
        return;
    int mini = l;
    if (r < t.size() && comp(t[r], t[l]))
        mini = r;
    if (comp(t[mini], t[v])) {
        swap(t[v], t[mini]);//zamiana wezła v z węzłem "mini"
        return goDown(mini);
    }
}

template<typename T>
Heap<T>::Heap(bool (*comp)(const T &, const T &)) {
    this->comp = comp;
    t.push(T()); /// zerowy element nie jest uzywany
}
/*Budowanie kopca*/
template<typename T>
void Heap<T>::build(DynamicArray<T> arr) {
    t.clear();//usuwanie elementów
    t.push(T());

    for (int i = 0; i < arr.size(); i++) {
        t.push(arr[i]);//dodawanie elementów do kopca
    }
    for (int i = t.size() - 1; i >= 1; i--) {
        goDown(i);//przenoszenie elementów na dół kopca
    }
}
/*Dodanie elementu do kopca*/
template<typename T>
void Heap<T>::push(T val) {
    t.push(val);//dodanie elementu na końcu vectora
    goUp(t.size() - 1);//przeniesienie elementu w górę Kopca
}
/*zwrócenie korzenia kopca*/
template<typename T>
T Heap<T>::top() const {
    return t[1];
}
/*zwrócenie rozmiaru kopca*/
template<typename T>
int Heap<T>::size() const {
    return t.size() - 1;
}
/*opróżnianie węzła*/
template<typename T>
bool Heap<T>::empty() const {
    return size() <= 0;
}
/*usuwanie korzenia i zwrócenie go*/
//// zakladamy ze przed wywolaniem sprawdzono size
template<typename T>
T Heap<T>::pop() {
    T res = t[1];//tworzymy zmienną pomocniczą i przepisujemy do niej wartość korzenia
    t[1] = t.pop();//korzeniowi przypisujemy wartośc ostatniego elementu usunietego z kopca
    goDown(1);//pierwszy element przesuwamy na sam koniec kopca
    return res;
}
/*wypisanie kopca*/
template<typename T>
void Heap<T>::printTree() {
    for (int i = 1; i < t.size(); i++) {
        std::cout << t[i] << " ";
    }
}