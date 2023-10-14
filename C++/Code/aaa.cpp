#include<iostream>

using namespace std;

// 예제 1 - 구조체의 구현
/* struct student
{
    string name;
    int age;
    float gpa;
};

int main(){
    student s1;

    s1.name = "John Doe";
    s1.age = 10;
    s1.gpa = 3.5;

    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "GPA: " << s1.gpa << endl;

    return 0;
} */

//예제 2 - 클래스의 구현
/* class Person {
public:
    string name;
    int age;

    void introduce(){
        cout << " Hi, my name is " << name << " and I am " << age << " years old." << endl;
    }
};

int main(){

    Person person1;
    person1.name = "John";
    person1.age = 30;
    person1.introduce();

    Person person2;
    person2.name = "Jane";
    person2.age = 25;
    person2.introduce();

    return 0;
} */


// 예제 3 - 클래스와 구조체 구현
/* 
class Person {
public:
    string name;
    int age;
    void print(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

struct Car
{
    string make;
    string model;
    int year;
};

int main(){
    Person p1;
    p1.name = "Alice";
    p1.age = 25;
    p1.print();

    Car car1 = {"Toyota", "Camry", 2021};
    cout << "Make: " << car1.make << endl;
    cout << "Model: " << car1.model << endl;
    cout << "Year: " << car1.year << endl;

    return 0;
}
 */



class FruiteSeller{

private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMemvers(int price, int num, int money){
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int SaleApples(int money){
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesRusult(){
        cout << "남은 사과 : " << numOfApples << endl;
        cout << "판매 수익 : " << myMoney << endl << endl;
    }
};

class FruiteBuyer{
    int myMoney;
    int numOfApples;

public:
    void IntMembers(int money){
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruiteSeller &seller, int money){
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult(){
        cout << "현재 잔액 : " << myMoney << endl;
        cout << "사과 개수 : " << numOfApples << endl << endl;
    }
};

int main(){
    FruiteSeller seller;
    seller.InitMemvers(1000, 20, 0);
    FruiteBuyer buyer;
    buyer.IntMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesRusult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}