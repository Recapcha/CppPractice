#include <iostream>
#include <vector>
using namespace std;

int Vector()
{
    setlocale(LC_ALL, "ru");

    vector<int> myVector(20, 11);

    //можем сами создать размер capacity
    myVector.reserve(100);

    myVector.push_back(51);
    myVector.push_back(211);
    myVector.push_back(111);
    myVector.push_back(621);

    //вывод общего количества
    cout << "Количество элементов в векторе " << myVector.size() << endl;

    //возвращает челочисленную переменную
    //емкость вектора
    cout << "capacity вектора " << myVector.capacity() << endl;

    //подогнать размер capacity под размер чисел
    cout << "shrink_to_fit() " << endl;
    myVector.shrink_to_fit();

    //емкость вектора
    cout << "capacity вектора " << myVector.capacity() << endl;

    //вывод всех чисел в векторе
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << endl;
    }

    //метод проверки есть или в векторе элементы, буллевая, поэтому вернется 1 или 0
    cout << myVector.empty() << endl;

    //то же самое что в конструкторе, только без него
    //изменяет размер ячеек с числами в векторе, не capacity
    myVector.resize(20);

    //метод вставки элементов куда угодно
    myVector.insert();

    //метод стереть
    myVector.erase();

    return 0;
}