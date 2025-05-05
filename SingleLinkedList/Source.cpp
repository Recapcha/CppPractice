#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
public:
    List();
    ~List();

    //Метод вставить в конец списка
    void push_back(T data);

    //Метод возвращения количества элементов
    int GetSize() { return Size; }

    //Перегрузка оператора индексирования, что бы узнать данные под индексом
    T& operator[](const int index);

private:
    //Класс элемента, узел содержит данные адресе и данных
    template <typename T>
    class Node
    {
        //так как класс больше никто не увидит, мы можем оставить его public
    public:
        //указатель на след даннае
        Node* pNext;
        //некоторые данные которое лежат в ячейке
        T data;

        //конструктор в которые передаем новые данные
        //по умолчанию указатель будет указывать на 0, что бы последний элемент был 0
        //T data = T() если будет класс, то вызовется его конструктор по умолчанию
        //если будет какой то тип данных, значит в поле данных будут
        //присвоено значение по умолчанию это типа данных
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    //Количество элементов списка
    int Size;

    //будет получать тип данных при которых был создан List
    //Указатель на первый элемент
    Node<T>* head;
};

//Так как наш класс шаблонный, мы так же должны указывать для конструкторов шаблон
template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        //если первый элемент пустой, то мы должно создать первый элемент и передать туда данные
        head = new Node<T>(data);
    }
    else
    {
        //если у нас в head уже что то было, если первый элемент не равен 0
        //необходимо создать новый элемент и его адрес присвоить самому последнему полю pNext
        //самому последнему адресу в списке

        //создаем временную переменную, указатель на ноду
        //изначально присваеваем туда заголовок
        Node<T>* current = this->head;

        //затем мы будем идти по всему списку и искать последнюю
        //Пока мы ней найдем когда указатель 0.
        //на что указывает поле pNext нашего текующего элемента
        while (current->pNext != nullptr)
        {
            //если она не равно 0, то в поле current мы будет присваивать указатель на следующий элемент
            current = current->pNext;
        }

        //когда мы нашли что последний элемент указывает на 0, тогда мы этот адрес присваем новые данные
        current->pNext = new Node<T>(data);
    }

    //счетчик количества элементов
    Size++;
}

//Перегрузка оператора индексирования
template <typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    //в начале всегда текущий элемент присваеваем первому элементу 
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            //когда находим возвращаем поле data у текущего элемента
            return current->data;
        }
        //в текущий элемент мы присваеваем адрес следующего элемента и счетчик увел на 1
        current = current->pNext;
        counter++;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;
    //lst.push_back(5);
    //lst.push_back(10);
    //lst.push_back(22);

    //cout << lst[0] << endl;

    int numbersCount;
    cin >> numbersCount;


    //ввод чисел 
    for (int i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand()%10);
    }

    //вывод чисел
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}