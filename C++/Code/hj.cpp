
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