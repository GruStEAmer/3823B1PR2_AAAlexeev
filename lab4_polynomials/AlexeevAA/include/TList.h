#pragma once
#include <iostream>
#include <string>

template <class T>
class TList
{
private:
    struct Node
    {
        T data;
        std::string exp;
        Node *next;

        Node(T data = NULL, std::string exp = "", Node *next = nullptr) : data(data), exp(exp), next(next) {}
    };
    size_t sz;
    Node *head;

public:
    class iterator
    {
    public:
        Node *i;
        iterator(Node *node = nullptr) : i(node) {}
        void operator++(int)
        {
            if (i)
            {
                i = i->next;
            }
        }
        void operator=(iterator n)
        {
            i = n;
        }
        bool operator!=(iterator n)
        {
            return i != nullptr;
        }
    };
    TList() : head(nullptr), sz(0) {}

    TList(const TList &list) : head(nullptr), sz(list.sz)
    {
        if (list.head == nullptr)
            return;

        head = new Node{*list.head};
        Node *pNew = head;
        Node *pOld = list.head->next;

        while (pOld != nullptr)
        {
            pNew->next = new Node{*pOld};
            pNew = pNew->next;
            pOld = pOld->next;
        }
    }
    ~TList()
    {
        Node *p;
        while (head != nullptr)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }

    void push_back(T val, std::string s = "")
    {
        Node *n = new Node(val, s);
        if (head == nullptr)
            head = n;
        else
        {
            Node *tmp = head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = n;
        }
        sz++;
    }
    void push_front(T val, std::string s = "")
    {
        if (head == nullptr)
        {
            head = new Node(val, s);
            return;
        }
        Node *n = head;
        head = new Node(val, s, n);
        sz++;
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        sz--;
    }
    void pop_back()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next->next != nullptr)
            {
                tmp = tmp->next;
            }
            delete tmp->next;
            tmp->next = nullptr;
        }
        sz--;
    }
    void push_after(int pos, T val, std::string s = "")
    {
        if (pos >= sz)
            throw -1;
        int i = 0;
        Node *tmp = head;
        while (pos != i)
        {
            tmp = tmp->next;
            i++;
        }
        Node *a = new Node(val, s, tmp->next);
        tmp->next = a;
        sz++;
    }
    void erase_after(int pos)
    {
        if (pos >= sz)
            throw -1;
        Node *tmp = head;
        int i = 0;
        while (pos != i)
        {
            tmp = tmp->next;
            i++;
        }
        Node *a = tmp->next;
        tmp->next = a->next;
        delete a;
        sz--;
    }

    T &front()
    {
        if (isEmpty())
            throw -1;
        return head->data;
    }
    size_t size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return sz == 0;
    }
    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return iterator(nullptr);
    }
    T operator[](int x)
    {
        if (x >= sz)
            throw -1;
        int a = 0;
        Node *tmp = head;
        while (a != x)
        {
            tmp = tmp->next;
            a++;
        }
        return tmp->data;
    }
    TList &operator=(TList &&list) noexcept
    {
        std::swap(*this, list);
        return *this;
    }
    TList &operator=(const TList &list)
    {
        if (this != &list)
        {
            TList tmp(list);
            std::swap(*this, tmp);
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &out, TList list)
    {
        for(TList<T>::iterator iter = list.begin(); iter != list.end();iter++){
            if(iter.i->data >= 0){
                out << "+" << iter.i->data << iter.i->exp;
            }
            else
                out << iter.i->data << iter.i->exp;
        }
        return out;
    }
};