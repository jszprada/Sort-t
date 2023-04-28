#include <iostream>
#include <iomanip>
#include <time.h>
#include<windows.h>
using namespace std;


class TimeSpan {

    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
public:
    TimeSpan(unsigned int seconds) {
        hours = seconds / 3600;
        minutes = (seconds / 60) % 60;
        this->seconds = seconds % 60;
    }
    void print() {
        cout << setfill('0') << setw(2) << hours << ":";
        cout << setfill('0') << setw(2) << minutes << ":";
        cout << setfill('0') << setw(2) << seconds;
    }
    unsigned int getHours() const { return hours; }
    unsigned int getMinutes() const { return minutes; }
    unsigned int getSeconds() const { return seconds; }
};


class Element
{
public:
    int data;
    Element* left;
    Element* right;
    Element(int d) :data(d), right(nullptr), left(nullptr) {};
};

class BSTree {
private:
    void deleteSubTree(Element* node)
    {
        if (node == nullptr) return;
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
    void inOrder(Element* ptr) {
        if (ptr == nullptr)return;
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }

public:
    Element* root;
    BSTree() :root(nullptr) {};


    void insert(int val) {
        if (root == nullptr) { root = new Element(val); return; }
        Element* current = root, * child;
        while (current) {
            if (val < current->data) {
                child = current->left;
                if (child == nullptr) {
                    current->left = new Element(val);
                    return;
                }
            }
            else {
                child = current->right;
                if (child == nullptr) {
                    current->right = new Element(val);
                    return;
                }
            }
            current = child;
        }
    }
    bool isEmpty() {
        if (root == nullptr)
            return true;
        else
            return false;
    }
    void printInOrder() {
        inOrder(this->root);
    }
    void clear() {
        deleteSubTree(this->root);
        this->root = nullptr;
    }

    bool contains(int val) {
        Element* current = root;
        while (current != nullptr) {
            if (current->data == val)
                return true;

            if (val > current->data)
                current = current->right;
            else
                current = current->left;
        }
        return false;
    }
    ~BSTree() {}

};

class Ulamek {
public:
    Ulamek() {};
    ~Ulamek() {};

    int licznik, mianownik;
    int calk;
    int czescDziesietna[50] = { 0 };
};


void buble_sort(long long int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

        }
    }
}

void quick_sort(long long int* arr, int left, int right) {
    int v = arr[(left + right) / 2];
    int i, j, x;
    i = left;
    j = right;
    do
    {
        while (arr[i] < v) i++;
        while (arr[j] > v) j--;
        if (i <= j)
        {
            x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > left) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

void heapify(long long int* arr, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest);
    }
}

// main function to do heap sort 
void heapSort(long long int* arr, int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end 
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap 
        heapify(arr, i, 0);
    }
}

double theTime(clock_t start, clock_t stop) {
    double time = 0.0;
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    return time;
}
int main()
{
    setlocale(LC_ALL, "");
    unsigned int number;
    cin >> number;
    switch (number)
    {
    case 1:
    {
        TimeSpan a(3936);
        a.print();
        break;
    }
    case 3: {
        BSTree bst;
        cout << (bst.isEmpty() ? "Drzewo jest puste" : "Drzewo nie jest puste") << endl;
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(4);
        bst.insert(2);
        cout << (bst.isEmpty() ? "Drzewo jest puste" : "Drzewo nie jest puste") << endl;
        cout << "Drzewo zawiera element o wartosci 3: " << bst.contains(3) << endl;
        cout << "Drzewo zawiera element o wartosci 9: " << bst.contains(9) << endl;
        bst.printInOrder();
        cout << endl;
        bst.clear();
        cout << (bst.isEmpty() ? "Drzewo jest puste" : "Drzewo nie jest puste") << endl;
        break;
    }
    case 4:
    {
        Ulamek ulamek1;

        cin >> ulamek1.licznik;
        cin >> ulamek1.mianownik;

        int reszta[101] = { 0 };

        ulamek1.calk = ulamek1.licznik / ulamek1.mianownik;

        int licznik = 0, flag = -1;
        reszta[licznik] = ulamek1.licznik % ulamek1.mianownik;

        while (reszta[licznik]) {
            ulamek1.czescDziesietna[licznik] = reszta[licznik] * 10 / ulamek1.mianownik;
            for (int j = 0; j < licznik; j++) {
                if (reszta[j] == reszta[licznik]) { flag = j; break; }
            }
            if (flag != -1) break;
            licznik++;
            reszta[licznik] = reszta[licznik - 1] * 10 % ulamek1.mianownik;
        }
        if (ulamek1.calk != 0) cout << ulamek1.calk << ".";
        else {
            cout << "0.";
        }
        for (int j = 0; j < licznik; j++) {
            if (j == flag) cout << "(" << ulamek1.czescDziesietna[j];
            else cout << ulamek1.czescDziesietna[j];
        }
        if (flag == -1) cout << endl;
        else cout << ")" << endl;
        break;
    }
    case 5:
    {

        int rozmiar;
        cout << "Podaj ktora liczbe doskonala znalezc: ";
        cin >> rozmiar;
        long int* liczby = new long int[rozmiar];

        int znalezione = 0, x = 2, suma_dzielnikow = 0;

        while (znalezione < rozmiar) {
            for (int i = 1; i <= (x / 2); i++) {
                if ((x % i) == 0)
                    suma_dzielnikow += i;
            }

            if (suma_dzielnikow == x) {
                liczby[znalezione] = x;
                ++znalezione;
            }
            ++++x;
            suma_dzielnikow = 0;
        }

        cout << liczby[rozmiar - 1] << endl;

        break;
    }
    case 6:
    {
        int size, howMany;
        clock_t start, stop;
        cout << "ile liczb chcesz podać: ";
        cin >> size;
        cout << "ile razy chcesz losować: ";
        cin >> howMany;

        long long int* arr_buble = new long long int[size];
        long long  int* arr_quick = new long long int[size];
        long long int* arr_heap = new long long int[size];
        double time_buble = 0, time_quick = 0, time_heap = 0;

        srand(time(NULL));

        for (int i = 0; i < howMany; i++) {
            for (int j = 0; j < size; j++) {
                arr_buble[j] = rand() % 1000;
                arr_quick[j] = arr_buble[j];
                arr_heap[j] = arr_buble[j];
            }
            start = clock();
            buble_sort(arr_buble, size);
            stop = clock();
            time_buble += theTime(start, stop);
            start = clock();
            quick_sort(arr_quick, 0, size - 1);
            stop = clock();
            time_quick += theTime(start, stop);
            start = clock();
            heapSort(arr_heap, size);
            stop = clock();
            time_heap += theTime(start, stop);
        }

        cout << "Średni czas sortowania bąbelkowego: " << setprecision(20) << time_buble / howMany << endl;
        cout << "Średni czas sortowania szybkiego: " << setprecision(20) << time_quick / howMany << endl;
        cout << "Średni czas sortowania strogowego: " << setprecision(20) << time_heap / howMany << endl;
        delete[] arr_buble;
        delete[] arr_quick;
        delete[] arr_heap;
        break;
    }
    }


    return 0;
}
