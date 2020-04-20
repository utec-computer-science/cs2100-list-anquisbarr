#include "Node.h"
template <typename T>
class Iterator{
private:
    typedef Node<T> Node;
    Node* iterator;
public:
    Iterator(){iterator=nullptr;}

    Iterator(Node<T>* it){this->iterator = it;}

    T operator ++ (){
        this->iterator =  this->iterator->next;
    }

    T operator --(){
        this->iterator = this->iterator->previous;
    }

    T operator * (){
        return iterator->value;
    }
    
    bool operator == (const iterator &it){
        return this-> iterator == it.iterator;
    }

    bool operator != (const iterator &it){
        return this-> iterator != it.iterator;
    }
};