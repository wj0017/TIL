#include<iostream>

using namespace std;

//Numberclass

class Number{

private :
    int num;

public :

    Number(int n = 0) : num(n){}

    Number& operator=(const Number& ref){
        num = ref.num;
        return *this;
    }

    operator int (){
        return num;
    }
};

template <class T> class Chain; // forward declaration

template <class T>
class ChainNode {
friend class Chain<T>;
public:
    ChainNode(T element = 0, ChainNode* next=0){
        data = element;
        link = next;
    }

private:
    T data;
    ChainNode<T> *link;

};

template <class T>
class Chain {
public:
    Chain() {     
        first = 0;
        last = 0;
    };

    ~Chain() {
        ChainNode<T> *ptr = first; 
        
        while (ptr != nullptr) { 
            first = ptr->link; 
            delete ptr; 
            ptr = first;
        } 
        delete first; // null 포인터 삭제
        last = 0;
        
    }

    // Chain manipulation operations
    
    void InsertNode(const T&  value, int index);
    void DeleteNode(int index);

    void InsertNodeFront(const T&  value);
    void InsertNodeBack(const T&  value);

    T& Get(int i);
    T& Front();
    T& Back();

    void DeleteFront();
    void DeleteBack();

    class ChainIterator;

    ChainIterator begin() {return ChainIterator(first);}
    ChainIterator end() {return ChainIterator(0);}

    void ShowInfo(){
            ChainIterator yi = begin();

            for(; yi != NULL ; yi++)
                cout<<*yi<<" ";

            cout<<"\n";
    }

    void accumulate();
   
private:
    ChainNode<T> *first;
    ChainNode<T> *last;

};


template <class T>
void Chain<T>::InsertNodeFront(const T& value){
    if (first){
        ChainNode<T> *temp = new ChainNode<T>(value,first); ;
        first = temp; 
    }else
        first = last = new ChainNode<T>(value); 
};


template <class T>
void Chain<T>::InsertNodeBack(const T& value){

    if (first) {
        last->link = new ChainNode<T>(value);
        last = last->link;
    }else 
        first = last = new ChainNode<T>(value);
};

template <class T>
T& Chain<T>::Get(int index){

    ChainNode<T> *node = first;

    for(int i = 0; i < index; i++){
        node = node->link;
    }

    cout << node->data << endl;
};

template <class T>
T& Chain<T>::Front(){
    return first -> data;
};

template <class T>
T& Chain<T>::Back(){

    return last -> data;
};

template <class T>
void Chain<T>::DeleteFront(){
    ChainNode<T> *temp;
    if(first){
        temp = first;
        first = first->link;
        delete temp;
    }
};

template <class T>
void Chain<T>::DeleteBack(){

    ChainNode<T> *ptr = first; 
    ChainNode<T> *tmp = ptr; 

    while (ptr->link != NULL) {
        tmp = ptr;
        ptr = ptr->link; 
    }

    tmp->link = NULL;
    delete ptr; // 동적 할당 해제 
};


template <class T>
void Chain<T>::InsertNode(const T&  value, int index){

    ChainNode<T> *ptr = first; 
    ChainNode<T> *tmp = ptr; 
    ChainNode<T> *node = new ChainNode<T>;
    
    node->data = value;
    node->link = NULL;

    for (int i = 0; i < index - 1; i++) {
        tmp = ptr; // 들어갈 노드의 전 위치 
        ptr = ptr->link; // 들어갈 노드의 위치
    }
    
    tmp->link = node;
    node->link = ptr; 
};

template <class T>
void Chain<T>::DeleteNode(int index){

    ChainNode<T> *ptr = first; 
    ChainNode<T> *tmp = ptr; 
    
    for (int i = 0; i < index; i++) {
        tmp = ptr; // 들어갈 노드의 전 위치 
        ptr = ptr->link; // 들어갈 노드의 위치
    }

    tmp->link = ptr->link; //삭제할 노드를 제외하고 연결 
    delete ptr; // 동적 할당 해제 

};

template <class T>
class Chain<T>::ChainIterator {
public:
    // typedefs required by C++ for a forward iterator omitted
    
    // constructor
    ChainIterator(ChainNode<T>* startNode = 0)
        {current = startNode;}
    
    // dereferencing operators
    T& operator*() const {return current->data;}
    T* operator->() const {return &current->data;}
    
    // increment
    ChainIterator& operator++()   // preincrement
    {current = current->link; return *this;}
    ChainIterator operator++(int) // postincrement
    {
        ChainIterator old = *this;
        current = current->link;
        return old;
    }
    
    // equality testing
    bool operator!=(const ChainIterator right) const
        {return current != right.current;}
    bool operator==(const ChainIterator right) const
        {return current == right.current;}

private:
    ChainNode<T>* current;
};

template<class T>
void Chain<T>::accumulate(){

    int sum = 0;
    ChainIterator yi = begin();
    for(; yi != NULL ; yi++){
        cout<<*yi<<" ";
        sum += *yi;
    }
    cout << sum << endl;
};



int main(){

    Chain <Number> list;

    cout << "1. add 1~9 node" << endl;
    for(int i = 1; i < 10; i++){
        
        list.InsertNodeBack(Number(i));
    }

    cout << "2. Print all of nodes with literator" << endl;
    list.ShowInfo();

    cout << "3. Insert 0 front" << endl;
    list.InsertNodeFront(Number(0));

    cout<<"4. Print all of nodes with literator" << endl;
    list.ShowInfo();

    cout<<"5. Insert 10 back" << endl;
    list.InsertNodeBack(Number(10));

    cout<<"6. Print all of nodes with literator" << endl;
    list.ShowInfo();

    cout<<"7. Check the Front '0' " << endl;
    cout<< list.Front() << endl;

    cout<<"8. Check the Back '10' " << endl;
    cout<< list.Back() << endl;

    cout<<"9. Check the Get(2) '2' " << endl;
    cout<< list.Get(2)<< endl;

    cout<<"10. Delete Front 0" << endl;
    list.DeleteFront();

    cout<<"11. Print all of nodes with literator" << endl;
    list.ShowInfo();

    cout<<"12. Delte Back 10" << endl;
    list.DeleteBack();

    cout<<"13. Print all of nodes with literator" << endl;
    list.ShowInfo();

    cout<<"14. Insert 100 between 3,4" << endl;
    list.InsertNode(Number(100), 4);

    cout<<"15. Print all of nodes with literator" << endl;
    list.ShowInfo();

    cout<<"16. Delete 6" << endl;
    list.DeleteNode(Number(6));

    cout<<"17. Print sum of all nodes with accumulate algorithm" << endl;
    list.accumulate();

    return 0;

    
}