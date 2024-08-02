
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <thread> 
#include <chrono>  

using namespace std;
int x=4,y=5,gox,goy,roy,rox,x2=3,y2=8,lastx1,lasty1,lastx2,lasty2,xpers1,ypers1,pol=0,x3=3,y3=6,lastx3,lasty3;
int room=1,n;
char idti;
const int WIDTH = 60;
const int HEIGHT = 20;
int ballX, ballY, paddle1Y, paddle2Y;
int ballDirX, ballDirY;
int player2Score=0;
const int PADDLE_WIDTH = 1;
const int PADDLE_HEIGHT = 7; // Увеличиваем высоту ракеток
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

enum ConsoleColor{
    Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    White         = 15
};
void SetColor(ConsoleColor text, ConsoleColor background){
    SetConsoleTextAttribute(hStdOut, (WORD)((background) | text));
}
void Setup()
{
    srand(time(NULL));
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    paddle1Y = HEIGHT / 2;
    paddle2Y = HEIGHT / 2;
    ballDirX = rand() % 2 == 0 ? -1 : 1;
    ballDirY = rand() % 2 == 0 ? -1 : 1;

}

void Draw()
{
    //system("color 94");
    system("cls");
    if(room==1)
    {
        gox=6;goy=4;
        roy=3;rox=4;
        for(int i=1;i<=gox;i++)
        { 
            SetColor(Red,Black);cout<<"# ";
        }
        cout<<endl;
        for(int i=1;i<=goy;i++)
        {
            for(int j=1;j<=gox;j++)
            {
                if (j==1 && i==1 || j==gox && i==1)
                {
                    SetColor(Cyan,Black);cout<<"# ";
                }
                else if(j==gox && i==4 || j==1 && i==4)
                {
                    cout<<"  ";
                }
                else if(j==gox || j==1)
                {
                    SetColor(Red,Black);cout<<"# ";
                   
                }
                else if(rox>=j && roy==i+1)
                {
                    SetColor(Blue,Black);cout<<"_ ";
                }
                else if(x==j+1 && y==i+1)
                {
                    SetColor(Green,Black);cout<<"@ ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            cout<<endl;
        }
        for(int i=1;i<=gox;i++)
        {
            SetColor(Red,Black);cout<<"# ";
        }
    }
    else if(room==2)
    {
        gox=6;goy=7;
        roy=3;rox=5;
        xpers1=5;ypers1=2;
        for(int i=1;i<=goy;i++)
        {
            for(int j=1;j<=gox;j++)
            {
                if(j==1 && i==7 || pol==1 && j==gox && i==3 || i==1 && j==6)
                {
                    cout<<"  ";
                }
                else if (j==gox && i==3 || j==gox && i==5 || j==gox && i==7)
                {
                    SetColor(LightGray,Black);cout<<"# ";
                }
                else if(i==2 && j==6)
                {
                    SetColor(Blue,Black);cout<<"_ ";
                }
                else if(j==gox || j==1)
                {
                    SetColor(Red,Black);cout<<"# ";
                }
                else if(rox>=j && roy==i+1)
                {
                    SetColor(Blue,Black);cout<<"_ ";
                }
                else if(x2==j+1 && y2==i+1)
                {
                    SetColor(Green,Black);cout<<"@ ";
                }
                else if(xpers1==j+1 && ypers1==i+1)
                {
                    SetColor(Green,Black);cout<<"8 ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            cout<<endl;
        }
        for(int i=1;i<=gox;i++)
        {
            if(i==5 || i==4)
            {
                SetColor(Cyan,Black);cout<<"# ";
            }
            else
            {
                SetColor(Red,Black);cout<<"# ";
            }
        }
    }
    else if(room==3)
    {
        gox=6;goy=10;
        roy=5;rox=2;
        xpers1=2;ypers1=4;
        for(int i=1;i<=gox;i++)
        {
            if(i==gox || i<=3)
            {
                SetColor(Red,Black);cout<<"# ";
            }
            else
            {
                SetColor(Red,Black);cout<<"  ";
            }
        }
        cout<<endl;
        for(int i=1;i<=goy;i++)
        {
            for(int j=1;j<=gox;j++)
            {
                if(j==3 && i<=4)
                {
                    SetColor(Blue,Black);cout<<"| ";
                }
                else if(rox>=j && roy==i+1)
                {
                    SetColor(Blue,Black);cout<<"_ ";
                }
                else if (j==1 && i<=5 || j==6 && i==5)
                {
                    cout<<"  ";
                }
                else if (j==1 && i==7 || j==1 && i==9)
                {
                    SetColor(LightGray,Black);cout<<"# ";
                }
                else if(j==gox || j==1)
                {
                    SetColor(Red,Black);cout<<"# ";
                   
                }
                else if(x3==j+1 && y3==i+1)
                {
                    SetColor(Green,Black);cout<<"@ ";
                }
                else if(xpers1==j && ypers1==i+1)
                {
                    SetColor(Green,Black);cout<<"8 ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            cout<<endl;
        }
    }
    else if(room==4)
    {
        for (int i = 0; i <= HEIGHT; ++i) {
            for (int j = 0; j <= WIDTH; ++j) {
                if (i == 0 || i == HEIGHT)
                {
                    SetColor(Red,Black);cout << "-";
                }
                else if (j == 0 || j == WIDTH)
                {
                    SetColor(Red,Black);cout << "|";                    
                }
                else if (i >= paddle1Y && i <= paddle1Y + PADDLE_HEIGHT - 1 && j == 1)
                {
                    SetColor(Blue,Black);cout << "|";                    
                }
                else if (i >= paddle2Y && i <= paddle2Y + PADDLE_HEIGHT - 1 && j == WIDTH - 1)
                {
                    SetColor(LightGray,Black);cout << "|";
                }
                else if (i == ballY && j == ballX)
                {
                    SetColor(Green,Black);cout << "O";
                }
                else
                {
                    cout << " ";
                }
            }
               cout << endl;
        }
    }
}

void Input()
{
    if(room==4)
    {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'w' && paddle1Y > 1)
                paddle1Y--;
            if (key == 's' && paddle1Y < HEIGHT - PADDLE_HEIGHT)
                paddle1Y++;
    }
    }
    else
    {
        idti=getch();
    }
}

void Logic()
{
    lastx1=x;
    lasty1=y;
    lastx2=x2;
    lasty2=y2;
    lastx3=x3;
    lasty3=y3;
    if(room==1)
    {
        if(idti=='w')
        {
            y--;
        }
        else if(idti=='s')
        {
            y++;
        }
        else if(idti=='a')
        {
            x--;
        }
        else if(idti=='d')
        {
            x++;
        }
    }
    else if(room==2)
    {
        if(idti=='w')
        {
            y2--;
        }
        else if(idti=='s')
        {
            y2++;
        }
        else if(idti=='a')
        {
            x2--;
        }
        else if(idti=='d')
        {
            x2++;
        }
    }
    else if(room==3)
    {
        if(idti=='w')
        {
            y3--;
        }
        else if(idti=='s')
        {
            y3++;
        }
        else if(idti=='a')
        {
            x3--;
        }
        else if(idti=='d')
        {
            x3++;
        }
    }
    //_____________
    if(room==1)
    {
        if(x==gox+1 && y==5)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want it"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=2;
                x--;
            }
            else
            {
                x--;
            }
        }
        else if(x==2 && y==2)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"the door is locked"<<endl<<"1=ok"<<endl<<"answer:";
            cin>>n;
            x++;
        }
        else if(x==gox+1 && y==2)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"the door is locked"<<endl<<"1=ok"<<endl<<"answer:";
            cin>>n;
            x--;
        }
        else if(x==2 && y==5)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"it's time to study"<<endl<<"1=ok"<<"   2=no"<<endl<<"answer:";
            cin>>n;
            if(n==2)
            {
                room=0;
            }
            else
            {
                x++;
            }
        }
        else if (rox>=x-1 && roy==y)
        {
            x=lastx1;
            y=lasty1;
        }
        else if (x >= gox+1) x--; 
        else if (x <= 2) x++;
        else if (y >= goy+2) y--; 
        else if (y <= 1) y++;
    }
    else if(room==2)
    {
        if(x2==2 && y2==8)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want it"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=1;
                x2++;
            }
            else
            {
                x2++;
            }
        }
        else if (rox>=x2-1 && roy==y2)
        {
            x2=lastx2;
            y2=lasty2;
            SetColor(Brown,Black);cout<<endl<<"Mr.security guard: you're late, if it happens again, I'll write a report on you"<<endl<<"1=ok"<<"   2=no"<<endl<<"answer:";;
            cin>>n;
            if(n==2)
            {
                room=-1;
            }
            else
            {
                pol=1;
            }
        }
        else if (pol==1 && gox+1==x2 && y2==3+1)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want it"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=3;
                x2--;
            }
            else
            {
                x2--;
            }
        }
        else if(x2==gox+1 && y2==3+1 || x2==6 && y2==9 || x2==5 && y2==9 || x2==gox+1 && y2==5+1 || x2==gox+1 && y2==7+1)
        {
            x2=lastx2;
            y2=lasty2;
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"the door is locked"<<endl<<"1=ok"<<endl<<"answer:";
            cin>>n;
        }
        else if (x2 >= gox+1) x2--; 
        else if (x2 <= 2) x2++;
        else if (y2 >= goy+2) y2--; 
        else if (y2 <= 1) y2++;   
    }
    else if(room==3)
    {
        if(x3==2 && y3==6)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want it"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=2;
                x3++;
            }
            else
            {
                x3++;
            }
        }
        else if(x3==7 && y3==6)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want it"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=-2;
                x3--;
            }
            else
            {
                x3--;
            }
        }
        else if(rox+1>=x3 && roy==y3)
        {
            x3=lastx3;
            y3=lasty3;
            SetColor(Brown,Black);cout<<endl<<"idi v cabinet"<<endl<<"1=ok"<<"   2=no"<<endl<<"answer:";
            cin>>n;
            if(n==2)
            {
                room=-1;
            }
        }
        else if(gox>=x3 && goy+2==y3)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want go to tennis tables"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=4;
                y3--;
            }
            else
            {
                y3--;
            }
        }
        else if(gox>=x3 && 1==y3)
        {
            SetColor(Brown,Black);cout<<endl<<"only number"<<endl<<"are you sure you want it"<<endl<<"1=yes"<<"    2=no"<<endl<<"answer:";
            cin>>n;
            if(n==1)
            {
                room=-3;
                y3--;
            }
            else
            {
                y3--;
            }
        }
        else if(x3==4 && y3<=5)
        {
            x3=lastx3;
            y3=lasty3;
            SetColor(Brown,Black);cout<<endl<<"idi v cabinet"<<endl<<"1=ok"<<"   2=no"<<endl<<"answer:";
            cin>>n;
            if(n==2)
            {
                room=-1;
            }
        }
        else if (x3 >= gox+1) x3--; 
        else if (x3 <= 2) x3++;
        else if (y3 >= goy+2) y3--; 
        else if (y3 <= 1) y3++; 
    }
    else if(room==4)
    {
        if(player2Score==4)
        {
            room=-4;
        }
    }
}

void update() {
    ballX += ballDirX;
    ballY += ballDirY;

    if (ballY == 0 || ballY == HEIGHT)
        ballDirY = -ballDirY;

    if (ballX == 1 && ballY >= paddle1Y && ballY <= paddle1Y + PADDLE_HEIGHT - 1)
        ballDirX = -ballDirX;
    if (ballX == WIDTH - 1 && ballY >= paddle2Y && ballY <= paddle2Y + PADDLE_HEIGHT - 1)
        ballDirX = -ballDirX;

    if (ballX == 0) {
        player2Score++;
        Setup();
    }
}

void ai() {
    if (paddle2Y + PADDLE_HEIGHT / 2 < ballY)
        paddle2Y++;
    if (paddle2Y + PADDLE_HEIGHT / 2 > ballY)
        paddle2Y--;
}

int main()
{
    SetColor(LightGreen,Black);cout<<"press probel to start"<<endl;
    SetColor(LightGreen,Black);cout<<"  W"<<endl<<"A S D - is control"<<endl<<"blue or gray doors - ";
    SetColor(LightGray,Black);cout<<"# ";
    SetColor(Cyan,Black);cout<<"# ";
    SetColor(LightGreen,Black);cout<<"can be opened"<<endl;
    SetColor(LightGreen,Black);cout<<"blue barriers - ";
    SetColor(Blue,Black);cout<<"_ ";
    SetColor(LightGreen,Black);cout<<"cannot be passed"<<endl;
    SetColor(LightGreen,Black);cout<<"people - ";
    SetColor(Green,Black);cout<<"8 ";
    SetColor(LightGreen,Black);cout<<"can talk"<<endl<<endl;
    SetColor(Brown,Black);cout<<"in ping pong"<<endl<<"w"<<endl<<"s"<<" - is control"<<endl<<"you blue   ai white"<<endl<<"if you win 3 times - respect++ and mission complete"<<endl;
    while(true)
    {
        if(room==4)
        {
            auto start = std::chrono::high_resolution_clock::now();
            Logic();
            Draw();
            Input();
            update();
            ai();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            if (duration.count() < 100) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100) - duration);
            }
        }
        else
        {
            Input();
            Logic();
            if(room==0)  
            {
                SetColor(Brown,Black);cout<<endl<<"your mom scolded you because you skipped school and forbade you to play PC for a month"<<endl<<"1=ok"<<endl<<"answer:";
                cin>>n;
                return 0;
            }
            else if(room==-1)  
            {
                SetColor(Brown,Black);cout<<endl<<"he wrote a report on you and kicked you out of school, after which your mother sent you to an orphanage"<<endl<<"1=ok"<<endl<<"answer:";
                cin>>n;
                return 0;
            }
            else if(room==-2)
            {
                SetColor(Brown,Black);cout<<endl<<"you graduated and got a good job, you had children and you died happily"<<endl<<"1=ok"<<endl<<"answer:";
                cin>>n;
                return 0;
            }
            else if(room==-3)
            {
                SetColor(Brown,Black);cout<<endl<<"you went to poop and were late for class and because of this the historian shot you"<<endl<<"1=ok"<<endl<<"answer:";
                cin>>n;
                return 0;
            }
            else if(room==-4)
            {
                SetColor(Brown,Black);cout<<endl<<"you lost but your losses make you stronger and you become the world champion in table tennis"<<endl<<"1=ok"<<endl<<"answer:";
                cin>>n;
                return 0;
            }
            else
            {
                Draw();
            } 
        }
    }
}