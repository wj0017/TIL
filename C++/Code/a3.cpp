#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class K, class E>
class Dictionary{
public:
	virtual bool IsEmpty() const=0;
	   //공백이면 true 반환
	virtual pair<K,E>*Get(const K&) const = 0;
	   //지시한 키 값을 가진 쌍에 대한 포인터 반환, 쌍이 없으면 0 반환
	virtual void Insert(const pair<K,E>&)=0;
	   //쌍을 삽입, 키가 중복되면 관련 원소 갱신
	virtual void Delete(const K&)=0;
	   //지시된 키를 가진 쌍 삭제
};

template <typename T>
class TreeNode{

public: 
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
    TreeNode(T temp) :data(temp), leftChild(NULL), rightChild(NULL){}
};


template <typename K, typename E>
class BST : public Dictionary<K, E>{

public :
    BST() : root(NULL) { }

    bool IsEmpty() const { 
        return (root == NULL);
    }

    pair<K, E> *Get(const K &k) const { 
        return Get(root, k);
    }

    pair<K,E>* BST<K,E>::Get(const K& k)
    {
        TreeNode<pair<K,E> > *currentNode = root;
        while (currentNode){

            if (k < currentNode->data.first)
                currentNode = currentNode->leftChild;

            else if (k > currentNode->data.first)
                currentNode = currentNode->rightChild;

            else 
                return &currentNode->data;
        }

        return 0;
    }
  
  // no matching pair
  return 0;
}