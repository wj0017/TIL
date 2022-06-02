#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class K, class E>
class Dictionary{
public:
	virtual bool IsEmpty() const=0;
	virtual pair<K,E>*Get(const K&) const = 0;
	virtual void Insert(const pair<K,E>&)=0;
	virtual void Delete(const K&)=0;
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

private:
    TreeNode<pair<K, E>> *root;

public :
    BST() : root(NULL) { }

    bool IsEmpty() const { 
        return (root == NULL);
    }

    pair<K,E> *Get(const K& k) const{

        return Get(root, k);
    }

    pair<K, E> *Get(TreeNode<pair<K, E>> *p, const K &k) const{
        if (!p) {
            cout<< "There is no node" << endl;
            return 0;
        }

        if (k < p->data.first)
            return Get(p->leftChild, k);
        if (k > p->data.first)
            return Get(p->rightChild, k);
        
        return &p->data;
    }

    void Insert(const pair<K, E> &thePair) {
        // Insert thePair into the binary search tree.
        // search for thePair.first, pp is parent of p
        TreeNode<pair<K,E> > *p = root, *pp = 0;
        while (p) {
            pp = p;
            if (thePair.first < p->data.first) p = p->leftChild;
            else if (thePair.first > p->data.first) p = p->rightChild;
            else //  duplicate, update associated element
                {p->data.second = thePair.second; return;}
        }

        // perform insertion
        p = new TreeNode<pair<K,E> > (thePair);
        if (root)  // tree not empty
            if (thePair.first < pp->data.first) pp->leftChild = p;
            else pp->rightChild = p;
        else root = p;
    }

    void Delete(const K &k){

        TreeNode<pair<K, E>>*currentNode = root;
        TreeNode<pair<K, E>> *deleteNode= NULL;
        TreeNode<pair<K, E>> *parentNode= NULL;
        
        int lastLocation = NULL;

        while(currentNode){
            if(currentNode->data.first > k) { 
                parentNode= currentNode;
                currentNode= currentNode->leftChild;
                lastLocation= 1;
            }

            else if(currentNode->data.first < k){
                
                parentNode= currentNode;
                currentNode= currentNode->rightChild;
                lastLocation= 2;
            }

            else{ 
                deleteNode= currentNode; 
                break;
            }
        }

        if (deleteNode == NULL){

            cout<< "There is no node to delete" << endl;
            exit(1);
        }

        while(currentNode){

            if (deleteNode->leftChild){

                currentNode= deleteNode->leftChild;

                while(currentNode->rightChild){
                    parentNode = currentNode;
                    lastLocation = 2;
                    currentNode = currentNode->rightChild;
                }

                deleteNode->data = currentNode->data;
                deleteNode = currentNode;
                continue;
            }

            else if(deleteNode->rightChild){

                currentNode= deleteNode->rightChild;

                while(currentNode->rightChild){
                    parentNode = currentNode;
                    lastLocation = 2;
                    currentNode = currentNode->leftChild;
                }

                deleteNode->data = currentNode->data;
                deleteNode = currentNode;
                continue;
            }

            else{

                switch (lastLocation)
                {
                case 1:
                    parentNode->leftChild = NULL;
                    deleteNode->~TreeNode();
                    delete deleteNode;
                    break;
                
                case 2:
                    parentNode->rightChild = NULL;
                    deleteNode->~TreeNode();
                    delete deleteNode;
                    break;

                }
            }

            cout << "Complete" << endl;
            return;
        }

    }

    void Inorder(TreeNode<pair<K, E>> *tree)
    {
        if (tree != NULL) {
            Inorder(tree->leftChild);
            cout << tree->data << " ";
            Inorder(tree->rightChild);
        }
    }

    void callInorder(){
        Inorder(root);
        cout << endl;
    }

    int getLeftSize(){
        int count = 1;
        TreeNode<pair<K, E>>*currentNode = root;
        if (currentNode != NULL){
            currentNode= currentNode->leftChild; 
            count++;
        }
        return count;
    }

    friend ostream&operator<<(ostream &os, const pair<K, E> &p);

};

template <typename K, typename E>
ostream&operator<<(ostream &os, const pair<K, E> &p){
    os << "(" << p.first << ", " << p.second << ") ";
    return os;
}


int main(){

    BST<int, int> Tree;

    cout << "1. Adding nodes" << endl;

    Tree.Insert(pair<int,int> (20220033,90));
    Tree.Insert(pair<int,int> (20220050,73));
    Tree.Insert(pair<int,int> (20220043,99));
    Tree.Insert(pair<int,int> (20220011,82));
    Tree.Insert(pair<int,int> (20220024,78));
    Tree.Insert(pair<int,int> (20220046,96));
    Tree.Insert(pair<int,int> (20220001,71));
    Tree.Insert(pair<int,int> (20220008,88));
    Tree.Insert(pair<int,int> (20220036,77));
    Tree.Insert(pair<int,int> (20220056,93));
    Tree.Insert(pair<int,int> (20220053,82));
    Tree.Insert(pair<int,int> (20220059,100));

    cout << "2. Print " <<endl;
    Tree.callInorder();

    cout << "3. Delete 20220050 " <<endl;
    Tree.Delete(20220050);

    cout << "4. Print " <<endl;
    Tree.callInorder();

    cout << "5. Delete 20220008 " <<endl;
    Tree.Delete(20220008);

    cout << "6. Print " <<endl;
    Tree.callInorder();

    cout << "7. Delete 20220056 " <<endl;
    Tree.Delete(20220056);

    cout << "8. Print " <<endl;
    Tree.callInorder();

    cout << "9. Check, Print 20220056 " <<endl;
    if(!Tree.Get(20220056) == 0){
        cout << Tree.Get(20220056)->first << ", " << Tree.Get(20220056)->second << endl;
    }

    cout << "10. Check, Print 20220043 " <<endl;
    if(!Tree.Get(20220043) == 0){
        cout << Tree.Get(20220043)->first << ", " << Tree.Get(20220043)->second << endl;
    }

}