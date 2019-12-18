#include <iostream>
#include "console.h"
#include <stdlib.h>
using namespace std;

#define MAX 100;
int sl = 4;
//================= Khai báo các hàm ==================
// phần vẽ tường
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();
//phần về rắn
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_li_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua);
void them(int toado[], int vt);
void xoa(int toado[], int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
// phần tạo quả
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int x0, int y0, int xqua, int yqua);

// ============== Hàm Main ===============
int main() {
  bool gameover = false;
  int toadox[MAX], toadoy[MAX];
  ve_tuong();
  khoi_tao_ran(toadox, toadoy);
  ve_ran(toadox, toadoy);
  // ============ kiểm tra và tạo quả ==============
  srand(time(NULL));
  int xqua = 0, yqua = 0;
  // tạo quả
  tao_qua(xqua, yqua, toadox, toadoy);
  int x= 50, y = 13;
  int check = 2;
  while(gameover == false)
  {
  	//xóa vị trí cũ (backspace)
  	xoa_du_lieu_cu(toadox, toadoy);
  	//0: di chuyển xuống
  	//1: di chuyển lên
  	//2: di chuyển sang phải
  	//3: di chuyển sang trái
  	// điều khiển
  	if(_kbhit())
  	{
  		char kitu = _getch();
  		if(kitu == -32){
  			kitu == _getch();
  			if(kitu == 72 && check != 0)//đi lên
  			{
  				check = 1;
  			}
  			else if (kitu == 80 && check != 1)// đi xuống
  			{
  				check = 0;
  			}
  			else if (kitu == 75 && check != 2)// qua trái
  			{
  				check = 3;
  			}
  			else if (kitu == 77 && check != 3)// qua phải
  			{
  				check = 2;
  			}
  		}
  	}
  	// xử lí di chuyển
  	if(check == 0)
  	{
  		y++; // đi xuống
  	} 
  	else if(check == 1)
  	{
  		y--; // đi lên
  	}
  	else if(check == 2)
  	{
  		x++; // qua phải
  	}
  	else if(check == 3)
  	{
  		x--; // qua trái
  	}
    // xử lí rắn;
  	xu_li_ran(toadox, toadoy, x, y, xqua, yqua);
    // kiểm tra
    gameover = kt_ran(toadox, toadoy);
  	sleep(200);
  }
  _getch();
}

//============== Định nghĩa các hàm ===================
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
  setColor(11);
  ve_tuong_tren();
  ve_tuong_duoi();
  ve_tuong_trai();
  ve_tuong_phai();
  setColor(7);
}

void khoi_tao_ran(int toadox[], int toadoy[])
{
  int x=50, y=13;
  for(int i=0; i<sl; i++){
    toadox[i] = x;
    toadoy[i] = y;
    x--;
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
void ve_ran(int toadox[], int toadoy[])
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
void xu_li_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua)
{
	//b1: thêm tọa độ mới vào đầu mảng
	them(toadox, x);
	them(toadoy, y);
  if(kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false )
  {
    //b2: xóa tọa độ cuối mảng
	  xoa(toadox, sl - 1);
	  xoa(toadoy, sl - 1);
  }
	//b3: vẽ lại rắn mới
	ve_ran(toadox, toadoy);
  tao_qua(xqua, yqua, toadox, toadoy);
}
void them(int toado[], int vt)
{
	for(int i = sl; i > 0; i--){
		toado[i] = toado[i - 1];
	}
	toado[0] = vt;
	sl++;
}
void xoa(int toado[], int vt)
{
	for(int i = vt; i < sl; i++){
		toado[i] = toado[i + 1];
	}
	sl--;
}

bool kt_ran_cham_tuong(int x0, int y0)
{
  // rắn chạm tường trên
  if(y0 == 1 && (x0 >= 10 && x0 <= 100))
  {
    return true;//gameover
  }
  // rắn chạm tường dưới
  else if(y0 == 26 && (x0 >= 10 && x0 <= 100))
  {
    return true;//gameover
  }
  // rắn chạm tường trái
  else if(x0 == 10 && (y0 >= 1 && y0 <= 26))
  {
    return true;//gameover
  }
  // rắn chạm tường phải
  else if(x0 == 100 && (y0 >= 1 && y0 <= 26))
  {
    return true;//gameover
  }
  return false;
}
bool kt_ran_cham_duoi(int toadox[], int toadoy[])
{
  for(int i = 0; i < sl; i++)
  {
    if((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
    {
      return true; //gameover
    }
  }
  return false;
}
bool kt_ran(int toadox[], int toadoy[])
{
  // kiểm tra
    bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
    bool kt2 = kt_ran_cham_tuong(toadox[0], toadoy[0]); 
    if(kt1 == true || kt2 == true)
    {
      return true; // gameover
    }
    return false;
}

void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[])
{
  do
  {
    // 11<= xqua <= 99
    xqua = rand()%(99 - 11 + 1 ) + 11;
    // 2<= yqua <= 25
    yqua = rand()%( 25 - 2 + 1 ) + 2;
  }while(kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
  int i = rand()%( 15 - 1 + 1) + 1;
  setColor(i);
  gotoXY(xqua, yqua);
  cout <<"*";
  setColor(7);
}
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
{
  for(int i = 0; i< sl; i++)
  {
    if((xqua == toadox[i]) && (yqua == toadoy[i]))
    {
      return true; // rắn đè lên qua
    }
  }
}
bool kt_ran_an_qua(int x0, int y0, int xqua, int yqua)
{
  if((x0 == xqua) && (y0 == yqua))
  {
    return true; //rắn ăn quả
  }
  return false;
}