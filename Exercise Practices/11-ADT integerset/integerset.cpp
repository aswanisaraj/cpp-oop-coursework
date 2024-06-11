#include <iostream>
#include <cstring> // For memcpy

using namespace std;

class integerSet
{
private:
    int *setArray;     // Dynamic array representing the set
    const int maxSize; // Maximum size of the set

public:
    // Constructor to initialize an empty set
    integerSet(int size) : maxSize(size)
    {
        setArray = new int[maxSize]();
    }

    // Copy constructor
    integerSet(const integerSet &other) : maxSize(other.maxSize)
    {
        setArray = new int[maxSize];
        std::memcpy(setArray, other.setArray, maxSize * sizeof(int));
    }

    // Destructor to release dynamically allocated memory
    ~integerSet()
    {
        delete[] setArray;
    }

    // Stream insertion operator to print the set
    friend std::ostream &operator<<(std::ostream &os, const integerSet &set)
    {
        bool empty = true;
        for (int i = 0; i < set.maxSize; ++i)
        {
            if (set.setArray[i] == 1)
            {
                os << i << " ";
                empty = false;
            }
        }
        if (empty)
        {
            os << "---";
        }
        return os;
    }

    // Assignment operator to copy the data of one object to another
    integerSet &operator=(const integerSet &other)
    {
        if (this != &other && this->maxSize == other.maxSize)
        {
            std::memcpy(setArray, other.setArray, maxSize * sizeof(int));
        }
        return *this;
    }

    // Equality operator to determine whether two sets are equal
    bool operator==(const integerSet &other) const
    {
        if (this->maxSize != other.maxSize)
        {
            return false;
        }
        return std::memcmp(setArray, other.setArray, maxSize * sizeof(int)) == 0;
    }

    // Logical NOT operator to create and return a new set containing the reverse of the left-hand side object
    integerSet operator!() const
    {
        integerSet complement(maxSize);
        for (int i = 0; i < maxSize; ++i)
        {
            complement.setArray[i] = !setArray[i];
        }
        return complement;
    }

    // Method to insert an element into the set
    void insertElement(int k)
    {
        if (k >= 0 && k < maxSize)
        {
            setArray[k] = 1;
        }
        else
        {
            cout << "Invalid input: " << k << endl;
        }
    }

    // Method to delete an element from the set
    void deleteElement(int k)
    {
        if (k >= 0 && k < maxSize)
        {
            setArray[k] = 0;
        }
        else
        {
            cout << "Invalid input: " << k << endl;
        }
    }

    // Method to check if the set is null
    bool isNullSet() const
    {
        for (int i = 0; i < maxSize; ++i)
        {
            if (setArray[i] == 1)
            {
                return false;
            }
        }
        return true;
    }

    // Method to find an element in the set
    bool findElement(int key) const
    {
        if (key >= 0 && key < maxSize)
        {
            return setArray[key] == 1;
        }
        else
        {
            cout << "Invalid input: " << key << endl;
            return false;
        }
    }

    // Method to perform union of two sets
    integerSet unionOfSets(const integerSet &set1, const integerSet &set2) const
    {
        integerSet result(maxSize);
        for (int i = 0; i < maxSize; ++i)
        {
            result.setArray[i] = set1.setArray[i] | set2.setArray[i];
        }
        return result;
    }

    // Method to perform intersection of two sets
    integerSet intersectionOfSets(const integerSet &set1, const integerSet &set2) const
    {
        integerSet result(maxSize);
        for (int i = 0; i < maxSize; ++i)
        {
            result.setArray[i] = set1.setArray[i] & set2.setArray[i];
        }
        return result;
    }
};
int main()
{
    // Create sets
    integerSet set1(10);
    integerSet set2(10);

    // Insert elements into set1
    set1.insertElement(0);
    set1.insertElement(1);
    set1.insertElement(3);
    set1.insertElement(4);
    set1.insertElement(7);
    set1.insertElement(9);

    // Insert elements into set2
    set2.insertElement(2);
    set2.insertElement(3);
    set2.insertElement(4);
    set2.insertElement(5);
    set2.insertElement(7);
    set2.insertElement(8);

    // Display sets
    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;

    // Test equality operator
    if (set1 == set2)
    {
        cout << "Set 1 and Set 2 are equal." << endl;
    }
    else
    {
        cout << "Set 1 and Set 2 are not equal." << endl;
    }

    // Create union and intersection sets
    integerSet unionSet = set1.unionOfSets(set1, set2);
    integerSet intersectionSet = set1.intersectionOfSets(set1, set2);

    // Display union and intersection
    cout << "Union of Set 1 and Set 2: " << unionSet << endl;
    cout << "Intersection of Set 1 and Set 2: " << intersectionSet << endl;

    // Test logical NOT operator
    integerSet notSet = !set1;
    cout << "Logical NOT of Set 1: " << notSet << endl;

    return 0;
}
