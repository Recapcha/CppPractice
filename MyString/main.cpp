#include <iostream>
#include <string>
using namespace std;

class MyString
{
public:
    //конструктор без параметров, присваивается ничего, что бы точно ничего там не было
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    //конструктор с параметрами, при создании объекта класса необходимо переслать строку, которую он будет хранить
    //констурктор с параметрами, это обычное присвоение объекта каких то данных
    MyString(const char *str)
    {
        //получаем количество символов в строке, которую мы передаем в объект
        length = strlen(str);

        //выделяем память для динамического массива, где будет храниться наша строка
        //+1 символ так как нужно место в массиве под терминирующий 0
        //что бы он понял str, который member. +1 для того то бы считал '\0'
        this->str = new char[length + 1];

        //копируем символы строки в массив нашего класса
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        //закрываем строку терминирующим 0
        this->str[length] = '\0';
    }

    //деструктор, отвечает за освобождение ресурсов занятых объектом, вызывается при уничтожении объекта класса
    //деструктор, уничтожает все объекты, когда программа заканчивает работу
    ~MyString()
    {
        //должны очищать дин память, на которую указывает наш массив
        delete[] this->str;
    }

    //конструктор копирования, необходим для создания точной копии объекта класса, но в другой области памяти
    //констурктор копирования, это присвоение одного значения объекта другому, что бы не занимало место в динамической памяти
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

    //перегруженный конструктор присваивания, вызывается когда необходимо присвоить значение одного объекта другому
    MyString &operator=(const MyString &other)
    {
        //здесь логика похожа на ту которая в констукторе, за исключением того, что нам нужно позаботиться
        //об освобождении ресурсов объекта, если до копирования в него новой строки он уже содержал код
        //+ стандартный синтаксис перегрузка оператора =

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

    //перегруженный оператор сложения, в текущей реализации класса String необходим для конкатенации строк. Объединение строк в одну
    //оператор конкотенации
    MyString operator+(const MyString &other)
    {
        //создаем новый пустой объект, где будем хранить результат конкатенации строк и который будет результатом работы
        //перегруженного оператора +
        MyString newStr;

        //получаем количество символов в обеих строках для конкатенации
        int thisLenght = strlen(this->str);
        int otherLenght = strlen(other.str);

        newStr.length = thisLenght + otherLenght;

        //выделяем место в динамической памяти под новую строку
        newStr.str = new char[thisLenght + otherLenght + 1];

        //копируем данные из 2х конкатенируемых строк в новую строку
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

        //возвращаем результат конкатенации
        return newStr;
    }

    //выводит строку в консоль, в идеале для этого необходима перегрузка оператора <<
    void Print()
    {
        cout << str;
    }

    int Lenght()
    {
        return length;
    }


    //константная ссылка на объект, мы заглядываем в поля, поменять в полях мы ничего не можем, так как это ссылка
    //перегруженный оператор сравнения, сравнивает две строки сначала верны ли их длины друг другу, затем посимвольно отличается ли хоть один элемент друг от друга
    //Пример 
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

    //перегруженный оператор не равно, возвращает обратное значение оператора сравнения
    bool operator!=(const MyString &other)
    {
        return !(this->operator==(other));
    }

    //перебор элементов, замена символа
    //перегруженный оператор квадратные скобки, принимает ссылку на тип char, что бы иметь возможность изменить его
    //берет передаваемый индекс и подставляет его к индексу str выводя этот символ
    //Пример    
	//str[0] = 'Q';
    char &operator[](int index)
    {
        return this->str[index];
    }

    //ссылка на ссылку на объект. Адрес на переменную, которая хранит в себе еще один адрес
    //конструктор перемещения
    MyString(MyString &&other)
    {
        this->length = other.length;
        this->str = other.str;

        //что бы оператор delete не удалял данные при перемещении одних файлов в другие
        //нужно заперетить ему это делать, при присваиваении nullptr оператор delete ничего делать не будет
        //expression must be a modifiable lvalue, входящий параметр НЕ должен быть константой MyString(MyString &&other)
        other.str = nullptr;
    }

private:
    //указатель на массив char, хранит символы которые мы передаем в наш объект
    //или m_data. читается как m_ member
    char *str;

    //переменная длины строки
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