#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int SnakeLenght = 2;
void GameOver() 
{
    //Цвет Текста
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_RED);
    system("cls");
    //Надпись "Game Over"
    cout << "  ####   ###   ##   ## ######      ##   #     #  #####  ####  " << endl;
    cout << "  ####   ###   ##   ## ######     ####  #     #  #####  ##### " << endl;
    cout << "##      ## ##  ### ### ##        ##  ## ##   ##  #      #   # " << endl;
    cout << "##      ## ##  ####### ##        ##  ## ##   ##  #      #   # " << endl;
    cout << "## ###  #####  ####### ####      ##  ## ### ###  ####   ####  " << endl;
    cout << "## ###  #####  ## # ## ####      ##  ##  ## ##   ####   ####  " << endl;
    cout << "##   ## #   #  ##   ## ##        ##  ##  ## ##   #      ###   " << endl;
    cout << "##   ## #   #  ##   ## ##        ##  ##  ## ##   #      ####  " << endl;
    cout << " ###### #   #  ##   ## ######     ####    ###    #####  ## ## " << endl;
    cout << "  ###   #   #  ##   ## ######      ##      #     #####  ##  ##" << endl;
    cout << endl << endl << endl << endl;
    //Список Чисел
    string score[10][5] =  { {" #### ",
                              "#    #",
                              "#    #",
                              "#    #",
                              " #### "},{"   #  ",
                                         "  ##  ",
                                         " # #  ",
                                         "   #  ",
                                         "   #  " },{ "  ## ",
                                                      " #  #",
                                                      "   # ",
                                                      "  #  ",
                                                      " ####" },{" ### ",
                                                                 "    #",
                                                                 "  ## ",
                                                                 "    #",
                                                                 " ### "},{"#   #",
                                                                           "#   #",
                                                                           "#####",
                                                                           "    #",
                                                                           "    #"},{"#####",
                                                                                     "#    ",
                                                                                      "#####",
                                                                                      "    #",
                                                                                      "#####"},{" ####",
                                                                                                "#    ",
                                                                                                "#####",
                                                                                                "#   #",
                                                                                                " ### "}, { "#####",
                                                                                                            "    #",
                                                                                                            "    #",
                                                                                                            "    #",
                                                                                                            "    #"},{" ### ",
                                                                                                                      "#   #",
                                                                                                                      " ### ",
                                                                                                                      "#   #",
                                                                                                                      " ### "}, {" ####",
                                                                                                                                 "#   #",
                                                                                                                                 " ####",
                                                                                                                                 "    #",
                                                                                                                                 " ###"}};


    //Вывод счета
    if (SnakeLenght - 2 < 10)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "                                         " <<  score[SnakeLenght - 2 ][i] << endl;
        }
    }
    if (SnakeLenght - 2 < 100  && SnakeLenght - 2 > 9)
    {
        int ed, des;
        
        ed = (SnakeLenght - 2) % 10;
        des = (SnakeLenght - 2) / 10;
        for (int i = 0; i < 5; i++)
        {
            cout << "                                         " << score[des][i] << "   " << score[ed][i] << endl;
        }
        
    }
    if (SnakeLenght - 2 < 1000 && SnakeLenght - 2 > 99)
    {
        int ed, des, sot;

        ed = (SnakeLenght - 2) % 10;
        des = ((SnakeLenght - 2) % 100)%10;
        sot = (SnakeLenght - 2) / 100;
        for (int i = 0; i < 5; i++)
        {
            cout << "                         " << score[sot][i]<< "   " << score[des][i] << "   " << score[ed][i] << endl;
        }

    }
   
   
    
    
}

int main()
{
    //Цвет поля
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
    //Переменные
    int constant = 0;
    int constant2 = 89;
    int headY = 10;
    int headX = 10;
    int headXSpeed = 1;
    int headYSpeed = 0;
    int appleY;
    int appleX;
    int SLCC = 2;
    int SLCX;
    int SLCY;
    

    srand(static_cast<unsigned int>(time(0)));
    appleY = rand();
    appleY = (appleY % (29)) + 1;
    appleX = rand();
    appleX = (appleX % (89)) + 1;

    char game[30][90];
    int SnakeLenCounterX[2700];
    int SnakeLenCounterY[2700];
    bool gm = true;

    SnakeLenCounterX[0] = 9;
    SnakeLenCounterY[0] = 10;
    SnakeLenCounterX[1] = 8;
    SnakeLenCounterY[1] = 10;



    
    while(true)//Запуск функции, ответстенной за вывод
    {
        if (gm == false)//Если игрок проиграет
        {
            GameOver();
            if (GetAsyncKeyState(VK_RETURN))
            {
                gm = true;
                appleY = rand();
                appleY = (appleY % (29)) + 1;
                appleX = rand();
                appleX = (appleX % (89)) + 1;
                SnakeLenght = 2;
                headY = 10;
                headX = 10;
                headXSpeed = 1;
                headYSpeed = 0;
            }
        }
        if (gm == true)// Если игок еще не проиграл
        {
            while (gm == true)
            {

                //Формирование поля и головы
                for (int i = 0; i < 30; i++)
                {
                    for (int j = 0; j < 90; j++)
                    {
                        game[i][j] = ' ';

                    }
                }
                for (int i = 0; i < 30; i++)
                {
                    
                    game[i][constant] = '#';
                    game[i][constant2] = '#';

                }
                for (int i = 0; i < 90; i++)
                {

                    game[0][i] = '#';
                    game[29][i] = '#';

                }
                game[headY][headX] = '@';

                //Перемещение головы
                headX = headX + headXSpeed;
                headY = headY - headYSpeed;




                //Спавн яблока
                game[appleY][appleX] = '$';

                //Событие при прикосновении с яблоком
                if (headX == appleX & headY == appleY)
                {
                    SnakeLenght = SnakeLenght + 1;
                    appleY = rand();
                    appleY = (appleY % (29)) + 1;
                    appleX = rand();
                    appleX = (appleX % (89)) + 1;
                    game[appleY][appleX] = '$';

                }
                cout << SnakeLenght -2;

                //Добавление хвоста змее

                for (int i = 1; i < SnakeLenght; i++)
                {
                    int x = SnakeLenCounterX[i];
                    int y = SnakeLenCounterY[i];
                    game[y][x] = '+';

                }



                //Запоминание послдених кординат головы
                for (int i = 2699; i > 0; i--)
                {
                    SnakeLenCounterX[i] = SnakeLenCounterX[i - 1];
                    SnakeLenCounterY[i] = SnakeLenCounterY[i - 1];

                }

                SnakeLenCounterX[0] = headX;
                SnakeLenCounterY[0] = headY;

                //Проигрыш при касании хвоста
                for (int i = 1; i < SnakeLenght; i++)
                {
                    int x = SnakeLenCounterX[i];
                    int y = SnakeLenCounterY[i];

                    if (headX == x & headY == y)
                    {
                        GameOver();
                        gm = false;
                    }

                }
                //Проигрыш при касании краев поля
                if (headX == 90 || headX == 0 || headY == 0 || headY == 29)
                {
                    GameOver();
                    gm = false;
                }


                //!!!Вывод поля(все что создаем на поле должно быть до этой функции)!!!
                for (int i = 0; i < 30; i++)
                {
                    for (int j = 0; j < 90; j++)
                    {
                        cout << game[i][j];
                    }
                    cout << endl;
                }

                //Прием нажатия клавишь
                if (GetAsyncKeyState(VK_TAB))
                {
                    SnakeLenght = SnakeLenght + 10;
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    if (headXSpeed != 1)
                    {
                        headXSpeed = -1;
                        headYSpeed = 0;
                    }
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    if (headXSpeed != -1)
                    {
                        headXSpeed = 1;
                        headYSpeed = 0;
                    }
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    if (headYSpeed != 1)
                    {
                        headYSpeed = -1;
                        headXSpeed = 0;
                    }
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    if (headYSpeed != -1)
                    {
                        headYSpeed = 1;
                        headXSpeed = 0;
                    }
                }

                //Очистка поля
                system("cls");
            }
        }
    }
    

}
