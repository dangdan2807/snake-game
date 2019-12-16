#include <iostream>
#include "console.h"
using namespace std;

#define MAX 100;
int sl = 4;
//Khai báo các hàm cần dùng
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();
void ve_ran();
void khoi_tao_ran();
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void xu_li_ran(int toadox, int toadoy, int x, int y);
void them(int toado, int vt);
void xoa(int toado, int vt);

int main() {
  int toadox[MAX], toadoy[MAX];
  ve_tuong();
  khoi_tao_ran(toadox, toadoy);
  ve_ran(toadox, toadoy);
  int x= 50, y = 13;
  while(true)
  {
  	//xóa vị trí cũ (backspace)
  	xoa_du_lieu_cu(toadox, toadoy);
  	int check = 2;
  	//0: di chuyển xuống
  	//1: di chuyển lên
  	//2: di chuyển sang phải
  	//3: di chuyển sang trái
  	if(check == 0)
  	{
  		
  	}
  	else if(check == 1)
  	{
  	
  	}
  	else if(check == 2)
  	{
  	
  	}
  	else if(check == 3)
  	{
  	
  	}
  	xu_li_ran(toadox, toadoy, x, y);
  	sleep(150);
  }
  _getch();
}


//Định nghĩa các hàm đã khao báo ở trên
void xu_li_ran(int toadox, int toadoy, int x, int y)
{
	//b1: thêm tọa độ mới vào đầu mảng
	them(toadox, x);
	them(toadoy, y);
	//b2: xóa tọa độ cuối mảng
	xoa(toadox, sl - 1);
	xoa(toadoy, sl - 1);
	//b3: vẽ lại rắn mới
	ve_ran(toadox, toadoy);
}
void them(int toado, int vt)
{
	for(int i = sl; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = vt;
	sl++;
}
void xoa(int toado, int vt)
{
	for(int i = vt; i < sl; i++){
		a[i] = a[i + 1];
	}
	sl--;
}
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
void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	for(int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout <<" ";
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
