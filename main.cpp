#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#define CURSORI_H_INCLUDED
#define CONSOLE_FULLSCREEN_MODE 1
#pragma comment(lib, "user32")

using namespace std;

void gotoXY(short int x, short int y);
void setColor(short int bg, short int fg);
void schermo_intero();
void titolo_menu(short int x, short int y);

int main(){
    int risposta = 0;
    schermo_intero();

    titolo_menu(70, 0);    

    system("pause");

    return 0;
}

void gotoXY(short int x, short int y){
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}

void setColor(short int bg, short int fg){
    int val;
    if (bg<0)
        bg=0;
    if (fg>15)
        fg=15;
    val=bg*16+fg;
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        val);
}

void schermo_intero(){
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void titolo_menu(short int x, short int y){
    setColor(0, 6);
    gotoXY(x, y);
    cout << "__________                                 _____                     " << endl;
    gotoXY(x, y++);
    cout << "\\______   \\ _____      ____               /     \\   _____      ____  " << endl;
    gotoXY(x, y++);
    cout << " |     ___/ \\__  \\   _/ ___\\    ______   /  \\ /  \\  \\__  \\    /    \\ " << endl;
    gotoXY(x, y++);
    cout << " |    |      / __ \\_ \\  \\___   /_____/  /    Y    \\  / __ \\_ |   |  \\ " << endl;
    gotoXY(x, y++);
    cout << " |____|     (____  /  \\___  >           \\____|__  / (____  / |___|  /" << endl;
    gotoXY(x, y++);
    cout << "                 \\/       \\/                    \\/       \\/       \\/ " << endl;
    setColor(0, 7);
    gotoXY(100, 9);
    cout << "Gioca!!" << endl;
}

