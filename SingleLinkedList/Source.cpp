#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
public:
    List();
    ~List();

    //����� �������� � ����� ������
    void push_back(T data);

    //�������� ������� �������� ������
    void pop_front();

    //�������� ������
    void clear();

    //����� ����������� ���������� ���������
    int GetSize() { return Size; }

    //���������� ��������� ��������������, ��� �� ������ ������ ��� ��������
    T& operator[](const int index);

    //���������� � ������ ������
    void push_front(T data);

    //���������� ������ �� �������
    void insert(T value, int index);

    //�������� �������� �� �������
    void removeAt(int index);
    
    //�������� ���������� ��������
    void pop_back();

private:
    //����� ��������, ���� �������� ������ ������ � ������
    template <typename T>
    class Node
    {
        //��� ��� ����� ������ ����� �� ������, �� ����� �������� ��� public
    public:
        //��������� �� ���� ������
        Node* pNext;
        //��������� ������ ������� ����� � ������
        T data;

        //����������� � ������� �������� ����� ������
        //�� ��������� ��������� ����� ��������� �� 0, ��� �� ��������� ������� ��� 0
        //T data = T() ���� ����� �����, �� ��������� ��� ����������� �� ���������
        //���� ����� ����� �� ��� ������, ������ � ���� ������ �����
        //��������� �������� �� ��������� ��� ���� ������
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    //���������� ��������� ������
    int Size;

    //����� �������� ��� ������ ��� ������� ��� ������ List
    //��������� �� ������ �������
    Node<T>* head;
};

//��� ��� ��� ����� ���������, �� ��� �� ������ ��������� ��� ������������� ������
template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
    clear();
}

//�������� ������� � ����� ������
template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        //���� ������ ������� ������, �� �� ������ ������� ������ ������� � �������� ���� ������
        head = new Node<T>(data);
    }
    else
    {
        //���� � ��� � head ��� ��� �� ����, ���� ������ ������� �� ����� 0
        //���������� ������� ����� ������� � ��� ����� ��������� ������ ���������� ���� pNext
        //������ ���������� ������ � ������

        //������� ��������� ����������, ��������� �� ����
        //���������� ����������� ���� ���������
        Node<T>* current = this->head;

        //����� �� ����� ���� �� ����� ������ � ������ ���������
        //���� �� ��� ������ ����� ��������� 0.
        //�� ��� ��������� ���� pNext ������ ��������� ��������
        while (current->pNext != nullptr)
        {
            //���� ��� �� ����� 0, �� � ���� current �� ����� ����������� ��������� �� ��������� �������
            current = current->pNext;
        }

        //����� �� ����� ��� ��������� ������� ��������� �� 0, ����� �� ���� ����� �������� ����� ������
        current->pNext = new Node<T>(data);
    }

    //������� ���������� ���������
    Size++;
}

//�������� ������� ��������
template <typename T>
void List<T>::pop_front()
{
    //��������� ����������, �������� ������ �������
    Node<T>* temp = head;

    //� ���� �������� ��������� �������, ��� �� ��� ���� ��������� ���������
    head = head->pNext;

    //������� ������������ ������ �������
    delete temp;

    Size--;
}

//�������� ������
//���� ���������� Size > 0
template <typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

//���������� ��������� ��������������
template <typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    //� ������ ������ ������� ������� ����������� ������� ��������
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            //����� ������� ���������� ���� data � �������� ��������
            return current->data;
        }
        //� ������� ������� �� ����������� ����� ���������� �������� � ������� ���� �� 1
        current = current->pNext;
        counter++;
    }
}

//���������� � ������ ������
template <typename T>
void List<T>::push_front(T data)
{
    //�������� ������ ��������
    //�������� ��� ������ � ��������� �� ������� ������ �������
    head = new Node<T>(data, head);
    Size++;
}

//���������� �������� � ������ �� �������
template <typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        //������� ��������� �� ���������� ������� � �������� �������� ������� ��������
        Node<T>* previous = this->head;

        //����� ������ �������������� �������� �������
        for (int i = 0; i < index - 1; i++)
        {
            //�� �������� �������� ������, ��� �� �������� ������� � ����
            previous = previous->pNext;
        }

        //���������� �� ������� �������
        //previous->pNext = new Node<T>(data, previous->pNext);
        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }
}

//�������� �������� ��� ��������
template <typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        //��� �����������, ��� ����� ������� � ��������� �����
        Node<T>* previous = this->head;
        for (int i = 0; i < index-1; i++)
        {
            previous = previous->pNext;
        }

        //������ ����� ��������, ������� �������
        Node<T>* toDelete = previous->pNext;

        //����� � ����������� �������� ����������� ����� ���������� �������� 
        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }
}

//�������� ���������� �������� 
template <typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;

    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(101);

    //lst.push_back(55);
    //lst.push_back(11);
    //lst.push_back(22);

    //cout << lst[0] << endl;

    //int numbersCount;
    //cin >> numbersCount;

    ////���� �����
    //for (int i = 0; i < numbersCount; i++)
    //{
    //    lst.push_back(rand()%10);
    //}

    //����� �����
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl
         << "����������� ����� pop_back" << endl
         << endl;

    lst.pop_back();

    //lst.insert(99, 2);

    //cout << endl
    //     << "��������� � ������ " << lst.GetSize() << endl
    //     << "�������� ����� clear" << endl
    //     << endl;

    //lst.clear();

    //����� �����
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    //cout << endl
    //     << "��������� � ������ " << lst.GetSize() << endl;

    return 0;
}