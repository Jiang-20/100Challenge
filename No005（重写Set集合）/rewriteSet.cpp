#include<iostream>
// #include<cstddef>
using namespace std;

class intSet
{
private:
    int *ptr; //数组的头指针
    int size;  //数组当前容量
    int maxsize;    //数组的最大容量

public:
    intSet(int Maxsize = 0); //默认构造函数,默认大小为0
//    ~intSet();  //析构函数
    void enlarge(); //扩充数组的长度，（原长度*2）
    void insert(int item);  //插入元素函数
    void del(int index);    //删除元素，指定下标位置
    void display();   //遍历函数

    void delNum(int num);   //删除集合中值为num的元素，默认存在。
    bool search(int num);   //集合中查找num，返回类型为 bool类型

    intSet Mix(intSet set1,intSet set2);    //交集
    intSet Union(intSet set1,intSet set2);    //并集
    intSet Sub(intSet set1,intSet set2);      //差集
};

intSet::intSet(int Maxsize)    //初始化方法
{
    if(Maxsize == 0)
        ptr = NULL;
    else
        ptr = new int[Maxsize];
    this->size = 0;
    this->maxsize = Maxsize;
}

void intSet::enlarge(){

    maxsize = (maxsize+1) * 2;

    int *old = ptr;
    ptr = new int[maxsize];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = old[i];
    }
    if(old != NULL)
        delete []old;
}

void intSet::insert(int item){
    if(size>=maxsize)
    {
        enlarge();  //扩充数组的大小，数组最大个数*2
    }

    for (int  i = 0; i < size; i++)
    {

        if(item <= ptr[i])       //找到待数据的存放位置，进行插入操作。
        {
            if (item == ptr[i])
                return;

            for(int j = size-1;j>=i;j--){
                ptr[j+1] = ptr[j];
            }
            ptr[i] = item;
            size++;
            return;
        }
    }
    ptr[size++] = item;


}

void intSet::display(){
    for (int i = 0; i < size; i++)
    {
        cout<<this->ptr[i]<<" ";
    }

    cout<<endl;
}
void intSet::del(int index){
    for (int i = 0; i < size; ++i) {
        if (i == index-1){
            for (int j = i; j <size ; ++j) {
                ptr[j] = ptr[j+1];

            }
            size--;
            break;

        }
    }
}
void intSet::delNum(int num){
    for (int i = 0; i < size; ++i) {
        if (ptr[i] == num){     //找到目标数据的下标
            del(i+1);     //调用 del函数删除下标为i，排序在第i+1个的数据；
            break;
        }
    }
}
//
//intSet::~intSet()   //  析构函数
//{
//   cout<<"uesd ~"<<endl;
//}

bool intSet::search(int num){
    bool flag = false;

    for (int i = 0; i < size; ++i) {
        if (ptr[i] == num)
            flag = true;
    }
    return flag;
}

intSet intSet::Mix(intSet set1, intSet set2) {
    int mixMaxsize = set1.size;
    intSet mixintset;   //minintset 是存放交集的对象
    mixintset.ptr = new int[mixMaxsize];
    mixintset.maxsize = mixMaxsize;

    int index = 0;  //index是交集对象的下标

        for (int i = 0; i < set1.size; ++i) {
            if (set2.search(set1.ptr[i]) == true){
                mixintset.ptr[index] = set1.ptr[i];
                mixintset.size++;
                index++;
            }
        }

    return mixintset;
}

intSet intSet::Union(intSet set1, intSet set2) {
    int unMaxsize = set1.size+set2.size;
    intSet unintset;   //unintset 是存放交集的对象
    unintset.ptr = new int[unMaxsize];
    unintset.maxsize = unMaxsize;

    for (int i = 0; i < set1.size; ++i) {
        unintset.insert(set1.ptr[i]);
    }

    for (int i = 0; i < set2.size; ++i) {
        unintset.insert(set2.ptr[i]);
    }
    return unintset;
}
intSet intSet::Sub(intSet set1, intSet set2) {
    intSet sub1,sub2;
    sub1 = set1.Mix(set1,set2);
    for (int i = 0; i < sub1.size; ++i) {
        set1.delNum(sub1.ptr[i]);
    }
    return set1;
}


int main(){
    intSet one(0);
    one.insert(1);
    one.insert(2);
    one.insert(3);
    cout<<"set frist:";
    one.display();


    intSet two(0);
    two.insert(2);
    two.insert(3);
    two.insert(4);
    two.insert(5);

    cout<<"set second:";
    two.display();
    cout<<"***********"<<endl;

    intSet mix = one.Mix(one,two);
    cout<<"Mix:";
    mix.display();
    intSet un = one.Union(one,two);
    cout<<"Union:";
    un.display();

    intSet sub = one.Sub(one,two);
    cout<<"Sub:(A-B):";
    sub.display();

}
