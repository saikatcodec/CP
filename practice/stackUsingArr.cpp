class stackUsingArr
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    stackUsingArr(int totalSize);
    ~stackUsingArr();

    // Size of the stack
    int size()
    {
        return nextIndex;
    }

    // Stack is empty or not
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Insert the element in the stack
    void push(int ele)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack is full" << endl;
            return;
        }

        data[nextIndex] = ele;
        nextIndex++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }

        return data[nextIndex - 1];
    }
};

stackUsingArr::stackUsingArr(int totalSize)
{
    data = new int[totalSize];
    nextIndex = 0;
    capacity = totalSize;
}

stackUsingArr::~stackUsingArr()
{
    delete[] data;
}