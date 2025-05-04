#include <iostream>
#include <string>
using namespace std;

class MyString
{
public:
    //����������� ��� ����������, ������������� ������, ��� �� ����� ������ ��� �� ����
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    //����������� � �����������, ��� �������� ������� ������ ���������� ��������� ������, ������� �� ����� �������
    //����������� � �����������, ��� ������� ���������� ������� ����� �� ������
    MyString(const char *str)
    {
        //�������� ���������� �������� � ������, ������� �� �������� � ������
        length = strlen(str);

        //�������� ������ ��� ������������� �������, ��� ����� ��������� ���� ������
        //+1 ������ ��� ��� ����� ����� � ������� ��� ������������� 0
        //��� �� �� ����� str, ������� member. +1 ��� ���� �� �� ������ '\0'
        this->str = new char[length + 1];

        //�������� ������� ������ � ������ ������ ������
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        //��������� ������ ������������� 0
        this->str[length] = '\0';
    }

    //����������, �������� �� ������������ �������� ������� ��������, ���������� ��� ����������� ������� ������
    //����������, ���������� ��� �������, ����� ��������� ����������� ������
    ~MyString()
    {
        //������ ������� ��� ������, �� ������� ��������� ��� ������
        delete[] this->str;
    }

    //����������� �����������, ��������� ��� �������� ������ ����� ������� ������, �� � ������ ������� ������
    //����������� �����������, ��� ���������� ������ �������� ������� �������, ��� �� �� �������� ����� � ������������ ������
    MyString(const MyString &other)
    {
        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }

    //������������� ����������� ������������, ���������� ����� ���������� ��������� �������� ������ ������� �������
    MyString &operator=(const MyString &other)
    {
        //����� ������ ������ �� �� ������� � �����������, �� ����������� ����, ��� ��� ����� ������������
        //�� ������������ �������� �������, ���� �� ����������� � ���� ����� ������ �� ��� �������� ���
        //+ ����������� ��������� ���������� ��������� =

        if (this->str != nullptr)
        {
            delete[] str;
        }
        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';

        return *this;
    }

    //������������� �������� ��������, � ������� ���������� ������ String ��������� ��� ������������ �����. ����������� ����� � ����
    //�������� ������������
    MyString operator+(const MyString &other)
    {
        //������� ����� ������ ������, ��� ����� ������� ��������� ������������ ����� � ������� ����� ����������� ������
        //�������������� ��������� +
        MyString newStr;

        //�������� ���������� �������� � ����� ������� ��� ������������
        int thisLenght = strlen(this->str);
        int otherLenght = strlen(other.str);

        newStr.length = thisLenght + otherLenght;

        //�������� ����� � ������������ ������ ��� ����� ������
        newStr.str = new char[thisLenght + otherLenght + 1];

        //�������� ������ �� 2� ��������������� ����� � ����� ������
        int i = 0;
        for (; i < thisLenght; i++)
        {
            newStr.str[i] = this->str[i];
        }

        for (int j = 0; j < otherLenght; j++, i++)
        {
            newStr.str[i] = other.str[j];
        }

        newStr.str[thisLenght + otherLenght] = '\0';

        //���������� ��������� ������������
        return newStr;
    }

    //������� ������ � �������, � ������ ��� ����� ���������� ���������� ��������� <<
    void Print()
    {
        cout << str;
    }

    int Lenght()
    {
        return length;
    }


    //����������� ������ �� ������, �� ����������� � ����, �������� � ����� �� ������ �� �����, ��� ��� ��� ������
    //������������� �������� ���������, ���������� ��� ������ ������� ����� �� �� ����� ���� �����, ����� ����������� ���������� �� ���� ���� ������� ���� �� �����
    //������ 
    //bool equal = str.operator == str2;
	//bool equal = str == str2;
	//cout << (str != str2) << endl;
    bool operator==(const MyString &other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }

        return true;
    }

    //������������� �������� �� �����, ���������� �������� �������� ��������� ���������
    bool operator!=(const MyString &other)
    {
        return !(this->operator==(other));
    }

    //������� ���������, ������ �������
    //������������� �������� ���������� ������, ��������� ������ �� ��� char, ��� �� ����� ����������� �������� ���
    //����� ������������ ������ � ����������� ��� � ������� str ������ ���� ������
    //������    
	//str[0] = 'Q';
    char &operator[](int index)
    {
        return this->str[index];
    }

    //������ �� ������ �� ������. ����� �� ����������, ������� ������ � ���� ��� ���� �����
    //����������� �����������
    MyString(MyString &&other)
    {
        this->length = other.length;
        this->str = other.str;

        //��� �� �������� delete �� ������ ������ ��� ����������� ����� ������ � ������
        //����� ���������� ��� ��� ������, ��� ������������� nullptr �������� delete ������ ������ �� �����
        //expression must be a modifiable lvalue, �������� �������� �� ������ ���� ���������� MyString(MyString &&other)
        other.str = nullptr;
    }

private:
    //��������� �� ������ char, ������ ������� ������� �� �������� � ��� ������
    //��� m_data. �������� ��� m_ member
    char *str;

    //���������� ����� ������
    int length;
};

int main()
{
    MyString str("Hello");
    MyString str2("Hello");

    MyString result;
    result = str + str2;

    return 0;
}