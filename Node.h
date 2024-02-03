#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
    T data;
    Node<T> *nextPtr;

public:
    Node()
    {
        nextPtr = nullptr;
    }

    Node(T d)
    {
        data = d;
        nextPtr = nullptr;
    }

    T getData()
    {
        return data;
    }

    Node<T> *getNextPtr()
    {
        return nextPtr;
    }

    void setData(T d)
    {
        data = d;
    }

    void setNextPtr(Node<T> *p)
    {
        nextPtr = p;
    }
};

#endif // NODE_H
