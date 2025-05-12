#include <iostream>
#include <vector>
using namespace std;

int Vector()
{
    setlocale(LC_ALL, "ru");

    vector<int> myVector(20, 11);

    //����� ���� ������� ������ capacity
    myVector.reserve(100);

    myVector.push_back(51);
    myVector.push_back(211);
    myVector.push_back(111);
    myVector.push_back(621);

    //����� ������ ����������
    cout << "���������� ��������� � ������� " << myVector.size() << endl;

    //���������� ������������� ����������
    //������� �������
    cout << "capacity ������� " << myVector.capacity() << endl;

    //��������� ������ capacity ��� ������ �����
    cout << "shrink_to_fit() " << endl;
    myVector.shrink_to_fit();

    //������� �������
    cout << "capacity ������� " << myVector.capacity() << endl;

    //����� ���� ����� � �������
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << endl;
    }

    //����� �������� ���� ��� � ������� ��������, ��������, ������� �������� 1 ��� 0
    cout << myVector.empty() << endl;

    //�� �� ����� ��� � ������������, ������ ��� ����
    //�������� ������ ����� � ������� � �������, �� capacity
    myVector.resize(20);

    //����� ������� ��������� ���� ������
    myVector.insert();

    //����� �������
    myVector.erase();

    return 0;
}