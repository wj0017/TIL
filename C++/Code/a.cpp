#include<iostream>
#include<cstring>
#include<ctime>

using namespace std;


class Bizcard{
public:

    Bizcard() {}
    Bizcard(const char * myname, const char * myaddress, long long mobile, long long office)
    {
        int Name_len = strlen(myname)+1;
        int Address_len = strlen(myaddress)+1;
        name = new char[Name_len];
        address = new char[Address_len];

        strcpy(name, myname);
        strcpy(address, myaddress);
        office_phone = office;
        mobile_phone = mobile;
    }
    
    Bizcard(const Bizcard &copy)
    {
        name = new char[strlen(copy.name)+1];
        address = new char[strlen(copy.address)+1];

        strcpy(name, copy.name);
        strcpy(address, copy.address);
        office_phone = copy.office_phone;
        mobile_phone = copy.mobile_phone;
    }

    Bizcard &operator=(const Bizcard &ref)
    {
        delete[] name; 
        int lenName = strlen(ref.name) + 1; 
        name=new char[lenName];
        strcpy(name, ref.name);

        delete[] address;
        int lenPhone = strlen(ref.address) + 1;
        address = new char[lenPhone];
        strcpy(address, ref.address);

        office_phone = ref.office_phone;
        mobile_phone = ref.mobile_phone;

        return *this;
    }


    ~Bizcard(){
        delete[] name;
        delete[] address;
    }

    void ShowInfo(){
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Mobile_phone : " << mobile_phone << endl;
        cout << "Office_phone : " << office_phone << endl;
    }
    
private:

    char * name;
    char * address;
    long long office_phone;
    long long mobile_phone;
};

template<class T> 
class Bag{
public:
    Bag(int bagCapacity = 3);
    ~Bag(); //소멸자

    int Size() const;
    bool IsEmpty() const; 
    T& Element() const; 

    void Push(const T&);  
    void Pop(); 

 private:
    T*  array;  
    int capacity; 
    int top;
};

template<class T> 
void ChangeSizeID(T*& a, const int oldSize, const int newSize)
{
  if(newSize<0)throw "New length must be >= 0";

  T* temp = new T[newSize]; 
  int number = min(oldSize,newSize); 
  copy(a, a+number,temp);
  delete[]a;
  a=temp;
}

template<class T> 
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity){
  if(capacity<1) throw "Capacity must be > 0";
  array=new T[capacity];
  top=-1;
}

template<class T>
Bag<T>::~Bag(){delete[]array;}

template<class T>
inline int Bag<T>::Size() const {return top+1;}

template<class T>
inline bool Bag<T>::IsEmpty() const {return Size()==0;}

template<class T>
inline T& Bag<T>::Element() const {
  if(IsEmpty()) throw "Bag is empty";
  return array[rand()%(top+1)];
}

template<class T>
void Bag<T>::Push(const T& x){
  if(capacity == top+1)
  {
    ChangeSizeID(array,capacity,2*capacity);
    capacity *= 2;
  }
  array[++top] = x;
}

template<class T>
void Bag<T>::Pop(){
  if(IsEmpty()) throw "Bag is empty, cannot delete";
  int deletePos = rand()%(top+1);
  copy(array + deletePos + 1, array + top + 1,array + deletePos);
  top--;
}


int main(){

    srand(time(NULL));

    Bag<Bizcard> a;

    try{
        cout<< "Size : " << a.Size() << ", IsEmpty : " << a.IsEmpty() << "\n\n";
        a.Element().ShowInfo();
    }
    catch(const char *b){
        cout<< b <<endl;
    }

    Bizcard Lys("Lee Yu Seong", " Seoul " , 11049171936 ,11017491547);
    Bizcard Lwj("Lee Woo Jin" , " Seoul " , 11012341234 ,11023452345);
    Bizcard Ljj("Lee Jin Ju", " Seoul " , 11038104719 ,11018391648);
    

    cout << endl << "------- 3개 생성 -------" << "\n\n";

    a.Push(Lys);
    a.Push(Lwj);
    a.Push(Ljj);

    try{
        cout<< "Size : " << a.Size() << ", IsEmpty : " << a.IsEmpty() << "\n\n";
        a.Element().ShowInfo();
    }
    catch(const char *b){
        cout<< b <<endl;
    }

    Bizcard Lth("Lee Tae Hoon" , " Seoul " , 11031252134 ,11083657194);
    Bizcard Yjh("Yi Ju Hoon", " Seoul " , 11047119719 ,11046198376);
    Bizcard Lms("Kim Min Su", " Seoul " , 11018391649 ,11039176491);
    Bizcard Cun("Cha U Na", " Seoul " , 11019261972 ,11017401647);

    cout << endl << "------- 4개 생성 -------" << "\n\n";

    a.Push(Lth);
    a.Push(Yjh);
    a.Push(Lms);
    a.Push(Cun);

    try{
        cout<< "Size : " << a.Size() << ", IsEmpty : " << a.IsEmpty() << "\n\n";
        a.Element().ShowInfo();
    }
    catch(const char *b){
        cout<< b <<endl;
    }

    cout << endl << "-------2개 삭제 -------" << "\n\n";

    a.Pop();
    a.Pop();

    try{
        cout<< "Size : " << a.Size() << ", IsEmpty : " << a.IsEmpty() << "\n\n";
        a.Element().ShowInfo();
    }
    catch(const char *b){
        cout<< b <<endl;
    }

    return 0;
}