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

    //����� ����������� ���������� ���������
    int GetSize() { return Size; }

    //���������� ��������� ��������������, ��� �� ������ ������ ��� ��������
    T& operator[](const int index);

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
}

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


    //���� ����� 
    for (int i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand()%10);
    }

    //����� �����
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}