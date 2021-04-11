#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};

template<class DataType>
class LinkList
{
public:
    LinkList();                     
    LinkList(DataType a[], int n);  
    ~LinkList();                    
    int Length();                   
    DataType Get(int i);            
    int Locate(DataType x);         
    void Insert(int i, DataType x); 
    DataType Delete(int i);         
    void PrintList();               
private:
    Node<DataType> *first;          
};

template<class DataType>
LinkList<DataType>::LinkList()
{
    first = new Node<DataType>;
    first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
    first = new Node<DataType>;
    first->next = NULL;
    for (int i = 0; i < n; i++)
    {
        Node<DataType> *s = new Node<DataType>;
        s->data = a[i];
        s->next = first->next;
        first->next = s;
    }
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
    while (first != NULL)
    {
        Node<DataType>* q = first;
        first = first->next;
        delete q;
    }
}

template<class DataType>
int LinkList<DataType>::Length()
{
    Node<DataType>* p = first->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
    Node<DataType>* p = first->next;
    int count = 1;
    while (p != NULL && count<i)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) throw "Location";
    else return p->data;
}

template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
    Node<DataType> *p = first->next;
    int count = 1;
    while (p != NULL)
    {
        if (p->data == x) return count;
        p = p->next;
        count++;
    }
    return 0;
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
    Node<DataType> *p = first;
    int count = 0;
    while (p != NULL && count<i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) throw "Location";
    else {
        Node<DataType> *s = new Node<DataType>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
    Node<DataType> *p = first;
    int count = 0;
    while (p != NULL && count<i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL) throw "Location";
    else {
        Node<DataType> *q = p->next;
        int x = q->data;
        p->next = q->next;
        return x;
    }
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
    Node<DataType> *p = first->next;
    while (p != NULL)
    {
        cout << p->data << "  ";
        p = p->next;
    }
}

int main()
{
    LinkList<int> p;
    p.Insert(1, 6);
    p.Insert(2, 9);
    cout<<"插入后的链表是：";
    p.PrintList();
    cout<<endl;
    cout <<"获取链表的第二位是："<< p.Get(2) << endl;
    cout <<"查找数据在链表中的位置：（测试数据：9）"<< p.Locate(9) << endl;
    cout <<"链表的长度是："<< p.Length() << endl;
    cout<<"删除链表的数据（第一位）"<<endl;
    p.Delete(1);
    cout<<"删除后的链表是："<<endl;
    p.PrintList();
    return 0;
    
}
