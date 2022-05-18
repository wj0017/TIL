#include<iostream>

using namespace std;

template <class T> class Chain; // forward declaration

template <class T>
class ChainNode {
friend class Chain<T>;
private:
    T data;
    ChainNode<T> *link;
};

template <class T>
class Chain {
public:
    Chain() {     
        first = new ChainNode;
        first->link = NULL;
    };

    ~Chain() {}

    // Chain manipulation operations
    
    void InsertNode(T value, ChainNode<T> index);
    void DelteNode(ChainNode<T> index);

    void InsertNodeFront(T value);
    void InsertNodeBack(T value);

    void Get(int i);
    void Front();
    void Back();

    void DelteFront();
    void DelteBack();
   
private:
    ChainNode<T> *first;
};

template <class T>
void Chain<T>::InsertNode(T value, ChainNode<T> index){

    ChainNode<T> *ptr = first; 
    ChainNode<T> *tmp = ptr; 
    ChainNode<T> *node = new ChainNode<T>;
    
    node->data = value;
    node->link = NULL;

    for (int i = 0; i < index - 1; i++) {
        tmp = ptr; // 들어갈 노드의 전 위치 
        ptr = ptr->next; // 들어갈 노드의 위치
    }
    
    tmp->link = node;
    node->link = ptr; //새노드는 기존에 있는 노드위치를 가리킨다. 
}

template <class T>
void Chain<T>::DelteNode(ChainNode<T> i){
}

template <class T>
void Chain<T>::InsertNodeFront(T value){
    InsertNode(value, 0);
}

template <class T>
void Chain<T>::InsertNodeBack(T value){

    ChainNode<T> *node = new ChainNode<T>; //노드 동적 할당 size++; 

    node->data = value; 
    node->link = NULL;

    while (node != nullptr){ 

        node = node->next;
    }
    
    if (first == NULL) {

        first = node;
        end = node;
    } 
    else { 
        end->link = node; 
        end = end->link; 
    }

}

template <class T>
void Chain<T>::Get(int index){
}

template <class T>
void Chain<T>::Front(){
    Get(0);
}

template <class T>
void Chain<T>::Back(){

    // 맨 뒤의 값을 찾는 알고리즘 필요

    Get();
}

template <class T>
void Chain<T>::DelteFront(){
    DelteNode(0);
}

template <class T>
void Chain<T>::DelteBack(){

    // 맨 뒤의 값을 찾는 알고리즘 필요

    DelteNode();
}

// 반복자 생성

int main(){
    
}