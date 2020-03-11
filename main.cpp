#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include "console.h"
#include <time.h>
using namespace std;
int sl = 4;
#define MAX 100
#define Xtuong_max 100
#define Xtuong_min 10
#define Ytuong_max 30
#define Ytuong_min 1

void vetuong_tren();
void vetuong_duoi();
void vetuong_trai();
void vetuong_phai();
void vetuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_dulieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xuli_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua);
void them(int a[], int x);
void xoa(int a[], int vitri);
bool ran_chamtuong(int x0, int y0);
bool ran_chamduoi(int toadox[], int toadoy[]);
bool kiemtra_ran(int toadox[], int toadoy[]);
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int x0, int y0, int xqua, int yqua);



int main()
{
    srand(time(NULL));
    bool gameover = false;
    int toadox[MAX], toadoy[MAX];
    vetuong();
    khoi_tao_ran(toadox, toadoy);
    ve_ran(toadox, toadoy);
    //điểm khởi tạo rắn đầu tiên
    int x = 50, y = 13;
    int check = 2;
    // KIỂM TRA VÀ TẠO QUẢ
    int xqua = 53, yqua = 6;
    tao_qua(xqua, yqua, toadox, toadoy);
    while (gameover == false)
    {
        //XÓA DỮ LIỆU CŨ (ĐUÔI RẮN)
        xoa_dulieu_cu(toadox, toadoy);
        //0: đi xuống
        //1: đi lên
        //2: đi qua phải
        //3: đi qua trái
        if (_kbhit())
        {
            char kitu = _getch();
            if (kitu == -32)
            {
                kitu = _getch();
                // đi lên
                if (kitu == 72 && check != 0)
                {
                    check = 1;
                }
                // đi xuống
                else if(kitu == 80 && check != 1)
                {
                    check = 0;
                }
                // đi sang phải
                else if (kitu == 77 && check != 3)
                {
                    check = 2;
                }
                // đi sang trái
                else if (kitu == 75 && check != 2)
                {
                    check = 3;
                }
            }
        }
        //XỬ LÍ DI CHUYỂN
        if (check == 0)
        {
            //0: đi xuống
            y++;
        }
        else if (check == 1)
        {
            //1: đi lên
            y--;
        }
        else if (check == 2)
        {
            //2: đi qua phải
            x++;
        }
        else if (check == 3)
        {
            //3: đi qua trái
            x--;
        }
        xuli_ran(toadox, toadoy, x, y, xqua, yqua);
        // KIỂM TRA GAME OVER
        gameover = kiemtra_ran(toadox, toadoy);
        Sleep(150);
    }
    system("cls");
    gotoXY(48, 13);
    setColor(11);
    cout << "GAME OVER\n";
    _getch();
    return 0;
}

void vetuong_tren()
{
    int x = Xtuong_min, y = Ytuong_min;
    while (x <= Xtuong_max)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }
}

void vetuong_duoi()
{
    int x = 10, y = Ytuong_max;
    while (x <= Xtuong_max)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }
}

void vetuong_trai()
{
    int x = Xtuong_min, y = Ytuong_min;
    while (y <= Ytuong_max)
    {
        gotoXY(x, y);
        cout << "+";
        y++;
    }
}

void vetuong_phai()
{
    int x = Xtuong_max, y = Ytuong_min;
    while (y <= Ytuong_max)
    {
        gotoXY(x, y);
        cout << "+";
        y++;
    }
}

void vetuong()
{
    setColor(10);
    vetuong_tren();
    vetuong_duoi();
    vetuong_phai();
    vetuong_trai();
    setColor(7);
}

void khoi_tao_ran(int toadox[], int toadoy[])
{
    int x = 50, y = 13;
    for (int i = 0; i < sl; i++)
    {
        toadox[i] = x;
        toadoy[i] = y;
        x--;
    }
}

void ve_ran(int toadox[], int toadoy[])
{
    for (int i = 0; i < sl; i++)
    {
        gotoXY(toadox[i], toadoy[i]);
        if (i == 0)
        {
            cout << 0;
        }
        else
        {
            cout << "o";
        }
    }
}

void xoa_dulieu_cu(int toadox[], int toadoy[])
{
    for (int i = 0; i < sl; i++)
    {
        gotoXY(toadox[i], toadoy[i]);
        cout << " ";
    }
}

void xuli_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua)
{
    //thêm tọa độ mới vào đầu mảng (đầu rắn)
    them(toadox, x);
    them(toadoy, y);
    if (kt_ran_an_qua(toadox[0], toadoy[0], xqua, yqua) == false)
    {
        //xóa tọa độ cuối mảng (đuôi rắn)
        xoa(toadox, sl - 1);
        xoa(toadoy, sl - 1);
    }
    else
    {
        // tạo quả lại mới sau khi rắn đã ăn quả cũ
        tao_qua(xqua, yqua, toadox, toadoy);
    }
    //vẽ lại rắn (cập nhật lại rắn)
    ve_ran(toadox, toadoy);
}

void them(int a[], int x)
{
    for (int i = sl; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = x;
    sl++;
}

void xoa(int a[], int vitri)
{
    for (int i = vitri; i < sl; i++)
    {
        a[i] = a[i + 1];
    }
    sl--;
}

bool ran_chamtuong(int x0, int y0)
{
    // rắn chạm tường trên
    if (y0 == 1 && (x0 >= 10 && x0 <= 100))
    {
        return true; //game over
    }
    // rắn chạm tường dưới
    else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
    {
        return true; //game over
    }
    // rắn chạm tường trái
    else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
    {
        return true; //game over
    }
    // rắn chạm tường phải
    else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
    {
        return true; //game over
    }
    return false;
}

bool ran_chamduoi(int toadox[], int toadoy[])
{
    for (int i = 1; i < sl; i++)
    {
        if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i])
        {
            return true; // game over
        }
    }
    return false;
}

bool kiemtra_ran(int toadox[], int toadoy[])
{
    bool kiemtra1 = ran_chamduoi(toadox, toadoy);
    bool kiemtra2 = ran_chamtuong(toadox[0], toadoy[0]);
    if (kiemtra1 == true || kiemtra2 == true)
    {
        //game over
        return true;
    }
    return false;
}

void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[])
{
    do
    {
        //11 <= xqua <= 99
        xqua = rand() % (99 - 11 + 1) + 11;
        //2<= yqua <= 25
        yqua = rand() % (25 - 2 + 1) + 2;
    } while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
    gotoXY(xqua, yqua);
    int i = rand() % (15 - 1 + 1) + 1;
    //màu ngẫu nhiên cho quả
    setColor(i);
    cout << "#";
    // trả lại màu trắng
    setColor(7);
}

bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
{
    for (int i = 0; i < sl; i++)
    {
        if (xqua == toadox[i] && yqua == toadoy[i])
        {
            // rắn đè lên quả
            return true;
        }
    }
    return false;
}

bool kt_ran_an_qua(int x0, int y0, int xqua, int yqua)
{
    if (x0 == xqua && y0 == yqua)
    {
        //rắn ăn quả
        return true;
    }
    return false;
}
