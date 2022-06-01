#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


//random class
class Random
{
private:
    int ranNum[10];
    int from;
    int to;
public:
    Random();
    Random(int fromNum, int toNum);
    void ShowNumbers();
    void ShowMinNumber();
    void ShowMaxNumber();
    void FindMostFreqNumber();
};

Random::Random()
{
    from = 1;
    to = 10;
}

Random::Random(int _from, int _to)
{
    from = _from;
    to = _to;
}
void Random::ShowNumbers()
{
    cout << "Random numbers ard as follows : ";
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        ranNum[i] = rand()% (to - from + 1)  + from;
        cout <<ranNum[i] << " ";
    }
    cout << endl;
}

void Random::ShowMinNumber()
{
    int min = 999999999;

    for (int i = 0; i < 10; i++) {
        if (ranNum[i] < min)
        {
            min = ranNum[i];
        }
    }
    cout << "Minimum number : " << min << endl;
}

void Random::ShowMaxNumber()
{
    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (ranNum[i] > max)
        {
            max = ranNum[i];
        }
    }
    cout << "Maximum number : " << max << endl;
}

void Random::FindMostFreqNumber()
{
    int freq[11] = { 0 }; //빈도수 세기 위한 배열
    int f_max = 0; //f_max 빈도수의 최대값

    cout << "Most occurred number : ";
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (ranNum[i] == ranNum[j])
                freq[i]++;
        }
        if (freq[i] >= f_max) {
            f_max = freq[i];
        }
    }

    for (int i = 0; i < 10; i++) {
        if(freq[i]== f_max)
            cout << ranNum[i] << " ";
    }
    cout << endl;
}

int main()
{
    Random a;
    a.ShowNumbers();
    a.ShowMinNumber();
    a.ShowMaxNumber();
    a.FindMostFreqNumber();

    cout << endl<<endl;

    Random b(40 , 45);
    b.ShowNumbers();
    b.ShowMinNumber();
    b.ShowMaxNumber();
    b.FindMostFreqNumber();

    return 0;
}