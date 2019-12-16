#include <iostream>
//#include "console.h"
using namespace std;
//Khai báo các hàm cần dùng
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();

int main() {
  ve_tuong();
  _getch();
}

//Định nghĩa các hàm đã khao báo ở trên

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