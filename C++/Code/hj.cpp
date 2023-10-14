#include <stdio.h>
#include <stdlib.h>
#include <sqlext.h>
#include <sql.h>

#define NAME_LEN 50
#define PHONE_LEN 20

void show_error() {
   printf("errorn");
}

int main() {
   SQLHENV henv;
   SQLHDBC hdbc;
   SQLHSTMT hstmt = 0;
   SQLRETURN retcode;
   SQLCHAR szName[NAME_LEN], szPhone[PHONE_LEN], sCustID[NAME_LEN];
   SQLLEN cbName = 0, cbCustID = 0, cbPhone = 0;

   // Allocate environment handle
   retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

   // Set the ODBC version environment attribute
   if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
      retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER*)SQL_OV_ODBC3, 0);

      // Allocate connection handle
      if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
         retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

         // Set login timeout to 5 seconds
         if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);

            // Connect to data source
            retcode = SQLConnect(hdbc, (SQLCHAR*) "SQLCMD", SQL_NTS, (SQLCHAR*) "Test1", 5, (SQLCHAR*) "Password1", 9);

            // Allocate statement handle
            if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
               retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

               retcode = SQLExecDirect (hstmt, (SQLCHAR *) "SELECT CustomerID, ContactName, Phone FROM CUSTOMERS ORDER BY 2, 1, 3", SQL_NTS);
               if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {

                  // Bind columns 1, 2, and 3
                  retcode = SQLBindCol(hstmt, 1, SQL_C_CHAR, sCustID, 100, &cbCustID);
                  retcode = SQLBindCol(hstmt, 2, SQL_C_CHAR, szName, NAME_LEN, &cbName);
                  retcode = SQLBindCol(hstmt, 3, SQL_C_CHAR, szPhone, PHONE_LEN, &cbPhone);

                  // Fetch and print each row of data. On an error, display a message and exit.
                  for (int i=0 ; ; i++) {
                     retcode = SQLFetch(hstmt);
                     if (retcode == SQL_ERROR || retcode == SQL_SUCCESS_WITH_INFO)
                        show_error();
                     if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
                        printf( "%d: %s %s %sn", i + 1, sCustID, szName, szPhone);
                     else
                        break;
                  }
               }

               // Process data
               if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
                  SQLCancel(hstmt);
                  SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
               }

               SQLDisconnect(hdbc);
            }

            SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
         }
      }
      SQLFreeHandle(SQL_HANDLE_ENV, henv);
   }
}

/*
#include <iostream>

using namespace std;

void printArray(int* arr, int size) {

   cout << "Array:" << endl;
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void mergeArray(int* arr1, int* arr2, int arr3[][5], int row, int column) {
   for (int i = 0; i < column; i++) {
      arr3[row-2][i] = arr1[i];
   }
   for (int i = 0; i < column; i++) {
      arr3[row-1][i] = arr2[i];
   }
}

void printArray(int arr3[][5], int row, int column) {

   cout << "Array:" << endl;
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
         cout << arr3[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

int main()
{
   int arr1[5] = { 10,20,30,40,50 };
   int arr2[5] = { 60,70,80,90,100 };
   int arr3[2][5];

   //배열 출력(배열, 배열크기)
   printArray(arr1, 5);
   printArray(arr2, 5);

   mergeArray(arr1, arr2, arr3, 2, 5);

   printArray(arr3, 2, 5);
}
*/
/*

#include<iostream>

using namespace std;

void ranking(int* sco, int* rank);
void maxmin(int data[][4], int* max, int* min);

int main() {

   int data[][4] =
   {// 학번,국어,영어,수학
      {1, 90, 82, 100},
      {2, 40, 85, 60},
      {3, 50, 50, 40},
      {4, 100, 74, 50},
   };

   cout << "학번\t총점\t평균\t\t최대\t최소\t등수\t" << endl;

   int total[4];
   int rank[4];
   int max[4];
   int min[4];

   for (int i = 0; i < 4; i++) {
      total[i] = data[i][1] + data[i][2] + data[i][3];
   }

   ranking(total, rank);
   maxmin(data, max, min);

   for (int i = 0; i < 4; i++) {
      cout << data[i][0] << "\t" << total[i] << "\t" << total[i] / (float)3 << "\t\t";
      cout << max[i] << "\t" << min[i] << "\t" << rank[i] << endl;
   }

   return 0;
}

void ranking(int* sco, int* rank) {

   int cnt = 0;

   for (int i = 0; i < 4; i++) {
      cnt = 0;
      for (int j = 0; j < 4; j++) {
         if (sco[i] < sco[j]) {
            cnt++;
         }
      }
      rank[i] = cnt + 1;
   }
}

void maxmin(int data[][4], int* max, int* min) {

   for (int i = 0; i < 4; i++) {
      if (data[i][1] < data[i][2]) {

         if (data[i][2] < data[i][3]) {
            max[i] = data[i][3];
            min[i] = data[i][1];
         }

         else {
            max[i] = data[i][2];
            
            if (data[i][1] < data[i][3])
               min[i] = data[i][1];
            else
               min[i] = data[i][3];
         }
      }

      else {

         if (data[i][1] < data[i][3]) {

            max[i] = data[i][3];
            min[i] = data[i][2];
         }

         else {
            max[i] = data[i][1];

            if (data[i][2] > data[i][3])
               min[i] = data[i][3];
            else
               min[i] = data[i][2];
         }
      }
   }
}
*/

#include <iostream>
using namespace std;

class BinaryNode{
protected:
  int data;
  BinaryNode *left;
  BinaryNode *right;
public:
  BinaryNode( int val=0, BinaryNode *l=NULL, BinaryNode*r = NULL) : data(val), left(l), right(r) {}
  ~BinaryNode() {}

  void setData(int val) {data = val;}
  void setLeft(BinaryNode *l) {left = l;}
  void setRight(BinaryNode *r) {right = r;}
  int getData() {return data;}
  BinaryNode* getLeft() {return left;}
  BinaryNode* getRight() {return right;}
  bool isLeaf() {return left==NULL && right==NULL;}
};

class BinaryTree{
  BinaryNode* root;
public:
  BinaryTree(): root(NULL){}
  ~BinaryTree() {}

  void setRoot(BinaryNode* node) {root = node;}
  BinaryNode* getRoot() {return root;}
  bool isEmpty() { return root==NULL;}

  void display(){
    cout << "Binary Tree:" << endl;
    if(isEmpty()){
      cout << "Empty tree." << endl;
    } else{
      display(root, 0);
    }
  }
  void inorder(){ cout << "\n   inorder: "; inorder(root);}
  void inorder(BinaryNode *node){
   if(node!=NULL){
      inorder(node->getLeft());
      cout << "[" << static_cast<char>(node->getData()) << "] ";
      inorder(node->getRight());
   }
  }
  void preorder(){ cout << "\n  preorder: "; preorder(root);}
  void preorder(BinaryNode *node){
   if(node!=NULL){
      cout << "[" << static_cast<char>(node->getData()) << "] ";
      preorder(node->getLeft());
      preorder(node->getRight());
   }
  }
  void postorder(){ cout << "\n postorder: "; postorder(root);}
  void postorder(BinaryNode *node){
   if(node!=NULL){
      postorder(node->getLeft());
      postorder(node->getRight());
      cout << "[" << static_cast<char>(node->getData()) << "] ";
   }
  }
private:
  void display(BinaryNode* node, int depth){
    if(node==NULL){
      return;
    }
    for(int i = 0; i<depth; i++){
      cout << "  ";
    }
    cout << "- " << static_cast<char>(node->getData()) << endl;

    display(node->getLeft(), depth + 1);
    display(node->getRight(), depth + 1);
  }
};


int main() {
  BinaryTree tree;

  BinaryNode *d = new BinaryNode('D', NULL, NULL);
  BinaryNode *e = new BinaryNode('E', NULL, NULL);
  BinaryNode *b = new BinaryNode('B', d, e);
  BinaryNode *f = new BinaryNode('F', NULL, NULL);
  BinaryNode *c = new BinaryNode('C', f, NULL);
  BinaryNode *a = new BinaryNode('A', b, c);
  tree.setRoot(a);
  tree.display();
  tree.inorder();
  tree.preorder();
  tree.postorder();
  return 0;
}