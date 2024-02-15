#include "linkedlist.hpp"
#include "iterator.hpp"
#include <iostream>

template<class T>
void print(const T str) {
    std::cout << str <<  std::endl;
}

int main(){
    using namespace std;
    LinkedList<std::string> liste;
    liste.append("Element 1");
    liste.append("Element 2");
    LinkedList<std::string> liste2 = liste;
    cout << "Liste:" << endl;
    liste.visit_all(print);
    liste.remove(2);
    cout << "Liste:" << endl;
    liste.visit_all(print);
    cout << "Liste2:" << endl;
    liste2.visit_all(print);
}