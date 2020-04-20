#include "Node.h"

template <typename T>
class List {
    protected:
        typedef Node<T> Node;
        Node *head;
        Node *tail;

    public:
        List(const List &list){head = list.head; tail=list.tail;}
        
        List(T* array, int size){
          head= nullptr;
          tail = head;
          
          for(int i =0 ; i < size ; i++){
              push_back(array[i]);
          }
          tail->next = nullptr;
        }

        List(Node *node){ 
          head = node;
          tail = node;
        }

        List(int n){ 
          head = nullptr;
          tail = head;
          for (int i = 0 ; i < n ; i++)
            push_back(rand());
        }

        List(){ head= nullptr; tail = nullptr;}

        ~List(){
        }

        T front(){
          return head->value;
        } 
        
		    T back(){
          return tail->value;
        } 
        
		  // Inserta un elemento al final
        void push_back(const T& element){
          if (empty()){
            this-> head = new Node{element,nullptr};
            tail = this->head;
          }
          else{
            tail->next = new Node{element, nullptr};
            tail = tail->next;
          }
        } 

		  // Inserta un elemento al inicio
        void push_front(const T& element){
          if (empty()){
            this->head = new Node{element, nullptr};
            tail = this->head;
          }else{
            auto *node = new Node{element, nullptr};
            this->head = node;
          }
        } 
        
		  // Quita el ultimo elemento y retorna una referencia
        T pop_back(){
          Node *actual = head;
          if (actual != nullptr){
            while (actual->next !=tail)
              actual=actual->next;
          }
          delete tail;
          actual -> next = nullptr;
          tail = actual;
        }

  		  // Quita el primer elemento y retorna una referencia
        T pop_front(){
          Node *actual = head;
          if (actual != nullptr){
            actual = actual->next;
            delete head;
            head = actual;
          }
        }  

		  // Acceso aleatorio
        T& operator[] (const int &i){
          if (!empty()){
            auto pointer = this->head;
            for (auto j=0 ; j<i ; j++)
              pointer = pointer->next;
            return pointer->value;
          }
        } 
        
		  // la lista esta vacia?
        bool empty(){
          return (this->head == nullptr && this->tail == nullptr);
        }

		  // retorna el tamaño de la lista
        unsigned int size(){
          Node *actual = head;
          int contador = 0;
          
          while (actual != nullptr){
            contador++;
            actual = actual->next;
          }
          return contador;
        } 

		  // Elimina toda la lista
        void clear(void){
          Node *actual = head;
          while (actual != nullptr){
            actual = actual->next;
            delete head;
            head = actual;
          }
          delete actual;
          delete head;
          delete tail;
        } 

		  // Elimina un elemento en base a un puntero
        void erase(Node *node){
          if (!empty()){
            auto pointer = this->head;
            while (pointer != nullptr){
              if (pointer-> next == node){
                auto temp = pointer->next;
                pointer->next = temp->next;
                delete temp;
                break;
              }
              pointer = pointer->next;
            }
          }
        }

        
		  // Inserta un elemento  en base a un puntero
        void insert(Node *node, const T& t){
          if (!empty()){
            auto pointer = this->head;
            while(pointer != nullptr){
              if(pointer->next == node){
                pointer->next->value = t;
                break;
              }
              pointer = pointer->next;
            }
          }
        } 

		  // Elimina todos los elementos por similitud
        void remove(const T&t){
          Node *actual = head;
          if (head->value == t){
            head = head->next;
            delete actual;
          }
          while(actual!=nullptr){
            if(actual->next !=nullptr){
              if(actual->next->value == t){
                actual->next = actual->next->next;
                if(actual->next == nullptr)
                  tail =actual;
              }
            }
            actual = actual->next;
          }
        } 



		  // ordena la lista
        void sort(){
          Node *i = head;
          Node *j = head->next;
          for (i = head ; i != nullptr ; i = i->next){
            for (j=i->next; j!= nullptr ; j = j->next){
              if(i->value > j->value){
                T temp = i->value;
                i->value = j->value;
                j->value = temp;
              }
            }
          }       
        }
        

		  // invierte la lista
        List& reverse(){
          Node *actual, *temp, *aux;
          temp = nullptr;
          actual = head;
          while (actual!=nullptr){
            aux = actual->next;
            actual->next = temp;
            temp = actual;
            actual = aux;
          }
          head = temp;
        } 

		  // Imprime la lista con cout
        friend std::ostream& operator << (std::ostream &os , const List &list){
          Node *pointer = list.head;
          os << "List: ";
          while (pointer!=nullptr){
            os << pointer->value <<" ";
            pointer = pointer->next;
          }
          return os;
        } 
};