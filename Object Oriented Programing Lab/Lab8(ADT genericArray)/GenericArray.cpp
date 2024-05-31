#include <iostream>

using namespace std;

template <typename T>
class GenericArray
{
private:
    T *data;
    int size;

public:
    GenericArray() : size{5}
    {
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }
    // Parametrized Constructor................

    GenericArray(const int Size)
    {

        size = Size;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    // Copy Constructor
    GenericArray(const GenericArray &obj)
    {

        size = obj.size;

        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }

    ~GenericArray()
    {
        delete[] data;
    }

    int getSize()
    {
        return size;
    }

    // setElement
    void setElement(int index, T value)
    {
        if (index >= size)
        {
            throw "Index out of bounds";
        }
        data[index] = value;
    }

    // getElement
    int countElement(T key) const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
                count++;
        }

        return count;
    }

    // operator=:

    GenericArray &operator=(const GenericArray &obj)
    {
        if (size != obj.size)
        {
            delete[] data;
            size = obj.size;
            data = new T[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = obj.data[i];
            }
        }
        else{
        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
        }
        return *this;
    }

    T getSubArray(int start_index, int end_index) const
    {

        if (start_index > end_index || start_index < 0 || end_index >= size)
        {
            throw "Index out of bounds";
        }
        T *subArray = new T[end_index - start_index + 1];

        for (int i = 0; i < end_index - start_index + 1; i++)
        {
            subArray[i] = data[start_index + i];
        }

        return subArray;
    }

    // operator+:
    GenericArray operator+(const GenericArray &obj)
    {
        int MAX_SIZE = size + obj.size;

        int j = 0;

        for (int i = size; i < MAX_SIZE; i++)
        {
            data[i] = obj.data[j];
            j++;
        }
        size = MAX_SIZE;

        return *this;
    }

    // operater<<
    template <typename a>
    friend ostream &operator<<(ostream &out, const GenericArray<a> &obj);
    template <typename a>
    friend istream &operator>>(istream &in, const GenericArray<a> &obj);

    bool operator==(const GenericArray &obj)
    {
        if (size != obj.size)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (this->data[i] != obj.data[i])
            {
                return false;
            }
        }
        return true;
    }
    // for const
    int operator[](const int index) const
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        throw "Out of the Bounds";
    }
    // for non const

    int &operator[](const int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        throw "Out of the Bounds";
    }
};
// outside of class............................
template <typename a>
ostream &operator<<(ostream &out, const GenericArray<a> &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        cout << obj.data[i] << "\t";
    }
    return out;
}

template <typename a>
ostream &operator>>(ostream &in, const GenericArray<a> &obj)
{

    cout << "Enter index value: ";
    for (int i = 0; i < obj.size; i++)
    {

        in << obj.data[i] << endl;
    }
    return in;
}

int main()
{
    GenericArray<int> obj1;

    cout << obj1.getSize() << endl;
    // checkking setElement.................
    try
    {
        obj1.setElement(7,100);
        
    }
    catch(const char *e)
    {
        cerr << e << '\n';
    }

 
    
    
    

    return 0;
}