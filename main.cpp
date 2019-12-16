#include <iostream>
#include "console.h"
using namespace std;

#define MAX 100;
//Khai báo các hàm cần dùng
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();
void ve_ran();
void khoi_tao_ran();

int main() {
  int toadox[MAX], toadoy[MAX];
  ve_tuong();
  khoi_tao_ran(toadox, toadoy);
  ve_ran(toadox, toadoy);
  _getch();
}


//Định nghĩa các hàm đã khao báo ở trên
void khoi_tao_ran(int toadox[], int toadoy[])
{
  int x=50, y=13;
  for(int i=0; i<sl; i++){
    toadox[i] = x;
    toadiy[i] = y;
  }
}

void ve_ran(int toadox[], toadoy[])
{
  for(int i= 0; i< sl; i++){
    gotoXY(toadox[i], toadoy[i]);
    if(i == 0){
      cout <<"O";
    }
    else{
      cout <<"o";
    }
  }
}

void ve_tuong_tren()
{
  int x = 10, y = 1;
  gotoXY(x, y);
  while(x<=100){
    cout <<"+";
    x++;
  }
}

void ve_tuong_duoi()
{
  int x = 10, y = 26;
  gotoXY(x, y);
  while(x<=100){
    cout <<"+";
    x++;
  }
}

void ve_tuong_trai()
{
  int x = 10, y=1;
  gotoXY(x, y);
  while(y<=26){
    cout <<"+";
    y++;
  }
}

void ve_tuong_phai()
{
  int x = 100, y=1;
  gotoXY(x, y);
  while(y<=26){
    cout <<"+";
    y++;
  }
}

void ve_tuong()
{
  ve_tuong_tren();
  ve_tuong_duoi();
  ve_tuong_trai();
  ve_tuong_phai();
}
