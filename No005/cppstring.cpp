//第一个，打印字符串函数

#include<iostream>
#include<string>
using namespace std;

void print(string s){
    if(s.length()<=10){
        cout<<s<<endl;
    }
    else{
        s=s.substr(0,10);
        cout<<s<<endl;
    }
}

void print(string s,int n){
    if(s.length()<=n){
        cout<<s<<endl;
    }
    else{
        s=s.substr(0,n);
        cout<<s<<endl;
    }
}

int main(){
    string str;
    int n;
    cout<<"enter str:"<<endl;
    cin>>str;
    cout<<"与 10 的比较结果是"<<endl;
    print(str);
    cout<<"enter n:";
    cin>>n;
    cout<<"与输入 n 的比较结果是"<<endl;
    print(str,n);
    return 0;
}
