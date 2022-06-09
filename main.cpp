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
void selezione(short int x, short int y);
void scritta_gioca(short int x, short int y);
void scritta_esci(short int x, short int y);

int main(){
    schermo_intero();

    titolo_menu(0, 0);
    
    selezione(0, 10);

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
    gotoXY(x, y++);
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
}

void selezione(short int x, short int y){
    int selezione = 0, tasto = 0, invio = 0;

    setColor(0, 6);
    gotoXY(x, y);
    scritta_gioca(x, y);
    setColor(0, 7);

    gotoXY(x, y+6);
    scritta_esci(x, y+6);

    tasto = getch();
    
    do
    {
        if (tasto == 115){  
            gotoXY(x, y);
            scritta_gioca(x, y);

            gotoXY(x, y+6);
            setColor(0, 6);
            scritta_esci(x, y+6);
            setColor(0, 7);

            tasto = getch();

            if (tasto == 13){
                selezione = 2;
            }
        }
        else if (tasto == 119){
            gotoXY(x, y);
            setColor(0, 6);
            scritta_gioca(x, y);
            setColor(0, 7);

            gotoXY(x, y+6);
            scritta_esci(x, y+6);

            tasto = getch();

            if (tasto == 13){
                selezione = 1;
            }

        }
    } while (selezione != 2);
}

void scritta_gioca(short int x, short int y){
    gotoXY(x, y++);
    cout << "  ________  .__                             " << endl;
    gotoXY(x, y++);
    cout << " /  _____/  |__|   ____     ____   _____    " << endl;
    gotoXY(x, y++);
    cout << "/   \\  ___  |  |  /  _ \\  _/ ___\\  \\__  \\   " << endl;
    gotoXY(x, y++);
    cout << "\\    \\_\\  \\ |  | (  <_> ) \\  \\___   / __ \\_ " << endl;
    gotoXY(x, y++);
    cout << " \\______  / |__|  \\____/   \\___  > (____  / " << endl;
    gotoXY(x, y++);
    cout << "        \\/                     \\/       \\/  " << endl;
}

void scritta_esci(short int x, short int y){
    gotoXY(x, y++);
    cout << "                           .__              " << endl;
    gotoXY(x, y++);
    cout << "  ____     ______   ____   |__|             " << endl;
    gotoXY(x, y++);
    cout << "_/ __ \\   /  ___/ _/ ___\\  |  |             " << endl;
    gotoXY(x, y++);
    cout << "\\  ___/   \\___ \\  \\  \\___  |  |             " << endl;
    gotoXY(x, y++);
    cout << " \\___  > /____  >  \\___  > |__|             " << endl;
    gotoXY(x, y++);
    cout << "     \\/       \\/       \\/                   " << endl;
}
