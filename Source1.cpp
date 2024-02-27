#include <iostream>
#include "header.h"
using namespace std;

void main() {
    arrayListType<char>   char_array(10);
    char_array.insertAt(0, 'A');
    char_array.insertAt(1, 'B');
    char_array.insertAt(2, 'C');
    char_array.insertAt(3, 'D');

    char_array.print();
    char_array.remove('C');
    char_array.print();
    char_array.replaceAt(1, 'X');
    char_array.print();

    arrayListType<char> char_array2(char_array);

    char_array2.print();

    char_array.clearList();
    char_array.print();
    std::cout << char_array.isEmpty() << "\n";
}