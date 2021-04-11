//按名字的长度排序，输出
#include <iostream>
#include <string>
using namespace std;

void order(string str[10]){

   for(int i=0;i<9;i++){
       string max=str[i];
       for(int j=i+1;j<10;j++){
           if(str[i].length()<str[j].length()){
               max=str[j];
               str[j]=str[i];
               str[i]=max;
           }
       }
   }
   for(int k = 0;k<10;k++)
   cout<<str[k]<<endl;
}
int main(){
   string name[10];
   for(int i=0;i<10;i++){
       cout<<"输入第"<<i+1<<"个人的名字"<<endl;
       cin>>name[i];
   }
   order(name);
}
