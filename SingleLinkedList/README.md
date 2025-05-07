
Implementing a singly linked c++ list

//Insert method at the end of the list
void push_back(T data);

//deleting the first item in the list
void pop_front();

//clearing the list
void clear();

//Method for returning the number of elements
int GetSize() { return Size; }

////Overloading the indexing operator to find out the data under the index
T& operator[](const int index);

//adding to the top of the list
void push_front(T data);

//Adding data by
void insert index(T value, int index);

//deleting an element by index
void RemoveAt(int index);

//deleting the last element
void pop_back();