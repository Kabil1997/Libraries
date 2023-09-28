#pragma once

template <class T>
class clsDynamicArray
{
protected:
    int _Size = 0;
    T* TempArray;

public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size == 0;

    }

    void PrintList()

    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }

    void Resize(int Size)
    {
        TempArray = new T[Size];
        if (Size < 0)
            Size = 0;
        if (Size < _Size)
        {
            _Size = Size;
        }
        
        for (int i = 0; i < _Size; i++)
        {
            TempArray[i] = OriginalArray[i];
        }
        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

    void Reverse()
    {
        TempArray = new T[_Size];

        int counter = 0;

        for (int i = _Size - 1; i >= 0; i--)
        {
            TempArray[counter] = OriginalArray[i];
            counter++;
        }

        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    void Clear()
    {
        _Size = 0;
        TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    bool DeleteItemAt(int index)
    {
        if (index>_Size-1 || index<0 )
        {
            return false;
        }
        int Size = _Size;
        int C = 0;
        TempArray = new T[Size - 1];
        for (int i = 0; i < _Size; i++)
        {
            if (index != i)
            {
                TempArray[C] = OriginalArray[i];
                C++;
            }
        }
        _Size--;
        delete[] OriginalArray;
        OriginalArray = TempArray;
        return true;
    }


    //bool DeleteItemAt(int index)
    //{

    //    if (index >= _Size || index < 0)
    //    {
    //        return false;
    //    }

    //    _Size--;

    //    TempArray = new T[_Size];

    //    //copy all before index
    //    for (int i = 0; i < index; i++)
    //    {
    //        TempArray[i] = OriginalArray[i];
    //    }

    //    //copy all after index
    //    for (int i = index + 1; i < _Size + 1; i++)
    //    {
    //        TempArray[i - 1] = OriginalArray[i];
    //    }

    //    delete [] OriginalArray;
    //    OriginalArray = TempArray;
    //    return true;

    //}

    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);

    }

    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (Value == OriginalArray[i]) 
            {
                return i;
            }
        }
        return -1;
    }

    bool DeleteItem(T Value)
    {
        int Index = Find(Value);
        return DeleteItemAt(Index);
    }


    bool InsertAt(int Index ,T Value)
    {
        if (Index > _Size || Index < 0)
        {
            return false;
        }
        _Size++;
        int C = 0;
        TempArray = new T[_Size];
        for (int i = 0; i < _Size; i++)
        {
            if (i==Index)
            {
                TempArray[i] = Value;
            }
            else
            {
                TempArray[i] = OriginalArray[C];
                C++;
            }
        }
        delete[] OriginalArray;
        OriginalArray = TempArray;
        return true;
    }

    bool InsertAtBeginning(T Value)
    {
        return InsertAt(0, Value);
    }

    bool InsertBefore(T index, T value)
    {
        if (index < 1)
            return InsertAt(0, value);
        else
            return InsertAt(index - 1, value);

    }

    bool InsertAfter(T index, T value)
    {
        if (index >= _Size)
            return InsertAt(_Size - 1, value);
        else
            return InsertAt(index + 1, value);

    }

    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size, Value);
    }
};

