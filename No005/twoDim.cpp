/ 第3个，二维数组，动态分配空间
#include <iostream>
#include<string>
#include<iomanip>
using  namespace std;

struct twodim{
   int r;
   int c;
   float *a;
};

void get_twodim(twodim&s, int row, int col){
   //初始化数组
   s.r = row;
   s.c = col;
   s.a = new float[s.r * s.c];

}
float & val(twodim&s,int i,int j){
   //返回i行j列的值
   return s.a[i,j];
}
void free_twodim(twodim &s){
   //释放数组空间
   delete[] s.a;
}


int main(){
   struct twodim s;
   int i,j;
   get_twodim(s,3,4);

   for(i=0;i<3;i++){
       for (int j = 0; j < 4; ++j) {
           val(s,i,j)=5;
       }
   }
   
   for (int i = 0; i < 3; ++i) {
       for (int i = 0; i < 4; ++i) {
           cout<<setw(5)<<val(s,i,j);

           cout<<endl;
       }
   }

   free_twodim(s);
   return 0;
}
