#include <iostream>
#include <vector>
#include "MyMouse.h"
#include "MyRectangle.h"
#include "MyCircle.h"
#include "shapes.h"
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <fstream>
#include <windows.h>

using namespace std;


int choice; //holds button option
int m_brushcolor; //holds color for all
int X1, X2, Y2, Y1; //Mouse coordinates 
bool m_fill = 1; //set hallow to true

//Function to make cursor dissapppear
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
    if (size == 0)
    {
        size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}



//Displays side menu
void DrawShapes(int color, int fill2) {

    m_brushcolor = color; //holds color for shapes
    m_fill = fill2; //holds fill for rectangle

    //show rectangle in interface
    MyRectangle a;
    a.m_x = 68;
    a.m_y = 15;
    a.m_h = 4;
    a.m_w = 6;
    a.m_hollow = fill2;
    a.m_symbol = 219;
    a.m_recColor = color;
    a.Draw();

    //show circle in interface
    MyCircle z;
    z.m_x = 66;
    z.m_y = 11;
    z.m_radius = 3;
    z.DrawCircle();

    //Display Drawline
    MyRectangle l;
    l.m_x = 69;
    l.m_y = 20;
    l.m_h = 2;
    l.m_w = 2;
    l.m_hollow = true;
    l.m_symbol = 32;
    l.m_textColor = m_brushcolor;
    l.m_text = "Draw Line";
    l.Draw();
}

//Set Sign for drawLine
int Sign(double x) {
    if (x < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

//funtion to draw line on console
void drawLine()
{
    Coordinates c;
    int x, y = 0;

    c.setcolor(m_brushcolor); //set line color

    double dy = Y2 - Y1;
    double dx = X2 - X1;

    if (fabs(dy) > fabs(dx))
    {
        for (y = Y1; y != Y2; y += Sign(dy))
        {
            x = X1 + (y - Y1) * dx / dy;
            c.gotoxy((int)x, (int)y);
            cout << ".";

        }
    }
    else
    {
        for (x = X1; x != X2; x += Sign(dx))
        {
            y = Y1 + (x - X1) * dy / dx;
            c.gotoxy((int)x, (int)y);
            cout << '.';
        }
    }

    // draw the last point
    c.gotoxy((int)x, (int)y);
    cout << '.';
}

//Displays welcome  box
void top_text()
{
    int text_color; //hold value for rectangle color
    int text_color2; //hold value for text color

    for (int i = 0; i < 10; i++)
    {
        text_color = rand() % 10 + 1; //randomize color for rectangle
        text_color2 = rand() % 10 + 1; //randomize color for text
        MyRectangle k;
        k.m_h = 3;
        k.m_x = 10;
        k.m_y = 7;
        k.m_w = 69;
        k.m_symbol = 219;
        k.m_hollow = false;
        k.m_text = "WELCOME TO TEXTBRUSH";
        k.m_recColor = text_color;
        k.m_textColor = text_color2;
        k.Draw();
        Sleep(300); //switch colors slower
    }

}


int main()
{
    //creat mouse object to not erase screen
    MyMouse M;

    //initialize random seed:
    srand(time(NULL));

    //declare s to display interface
    Shapes s;

    //Interface
    vector <int> screen{
     201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,201,205,205,205,205,205,205,205,205,187,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,186,32,32,32,32,32,32,32,32,186,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,186,32,32,32,32,32,32,32,32,186,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,200,205,205,205,205,205,205,205,205,188,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,201,205,205,205,205,205,205,205,205,187,32,32,186,
 186,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,186,32,32,186,32,32,32,32,32,32,32,32,186,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,201,205,205,205,205,187,32,32,32,186,32,32,186,32,32,32,32,32,32,32,32,186,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,186,32,32,32,186,32,32,200,205,205,205,205,205,205,205,205,188,32,32,186,
 186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,200,205,205,205,205,188,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,
 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188
    };

    //set color and symbol to interface
    s.MapValueToColor(201, 15);
    s.MapValueToColor(186, 15);
    s.MapValueToColor(32, 0);
    s.MapValueToColor(205, 15);
    s.MapValueToColor(200, 15);
    s.MapValueToColor(187, 15);
    s.MapValueToColor(188, 15);
    s.Displayshape(screen, 69, 10, 10);  //Display interface

    //Display side menu
    DrawShapes(10, 1);

    //display color pallet
    Shapes x;
    x.gotoxy(13, 29);
    x.setcolor(15); //white
    cout << char(219) << char(219);
    x.gotoxy(16, 29);
    x.setcolor(14); //yellow
    cout << char(219) << char(219);
    x.gotoxy(19, 29);
    x.setcolor(13); //maroon
    cout << char(219) << char(219);
    x.gotoxy(22, 29);
    x.setcolor(12); //light red
    cout << char(219) << char(219);
    x.gotoxy(25, 29);
    x.setcolor(11); //light blue
    cout << char(219) << char(219);
    x.gotoxy(28, 29);
    x.setcolor(10); //green 
    cout << char(219) << char(219);
    x.gotoxy(31, 29);
    x.setcolor(9); //different shade of blue
    cout << char(219) << char(219);
    x.gotoxy(34, 29);
    x.setcolor(8); //grey
    cout << char(219) << char(219);
    x.gotoxy(31, 31);
    x.setcolor(7); //different shade of blue
    cout << char(219) << char(219);
    x.gotoxy(28, 31);
    x.setcolor(6); //dark green
    cout << char(219) << char(219);
    x.gotoxy(25, 31);
    x.setcolor(5); //dark blue
    cout << char(219) << char(219);
    x.gotoxy(22, 31);
    x.setcolor(4); //red
    cout << char(219) << char(219);
    x.gotoxy(13, 31);
    x.setcolor(3); //purple 
    cout << char(219) << char(219);
    x.gotoxy(16, 31);
    x.setcolor(2); //dark yellow
    cout << char(219) << char(219);
    x.gotoxy(19, 31);
    x.setcolor(1); //light gray
    cout << char(219) << char(219);

    //Display Save Box
    MyRectangle b;
    b.m_x = 69;
    b.m_y = 24;
    b.m_h = 2;
    b.m_w = 2;
    b.m_hollow = true;
    b.m_symbol = 32;
    b.m_recColor = 1;
    b.m_text = "Save";
    b.Draw();

    //DIsplay Load Box
    b.m_x = 69;
    b.m_y = 28;
    b.m_h = 2;
    b.m_w = 2;
    b.m_hollow = true;
    b.m_symbol = 32;
    b.m_recColor = 15;
    b.m_text = "Load";
    b.Draw();

    //Display Fill Box
    b.m_x = 57;
    b.m_y = 30;
    b.m_h = 1;
    b.m_w = 1;
    b.m_hollow = true;
    b.m_symbol = 32;
    b.m_recColor = 1;
    b.m_text = "Fill";
    b.Draw();


    //Erase Button
    b.m_x = 48;
    b.m_y = 30;
    b.m_h = 1;
    b.m_w = 1;
    b.m_hollow = true;
    b.m_symbol = 32;
    b.m_recColor = 1;
    b.m_text = "Erase";
    b.Draw();


    //Display magic touch above paint box
    top_text();

    //Mouse controls
    while (1)
    {

        setcursor(0, 0);// Hides cursor

        M.ReadMouseInput();

        switch (M.InputRecord.EventType) {
        case MOUSE_EVENT: // mouse input 

            if (M.InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                M.coord.X = M.InputRecord.Event.MouseEvent.dwMousePosition.X;
                M.coord.Y = M.InputRecord.Event.MouseEvent.dwMousePosition.Y;
                X1 = M.coord.X;
                Y1 = M.coord.Y;
            }

            //Acivate Erase button
            if ((M.coord.X >= 47) && (M.coord.X <= 51) && (M.coord.Y >= 28) && (M.coord.Y <= 32))
            {
                m_brushcolor = 0; //set color to black
            }

            //CLick on Drawline box
            if ((M.coord.X >= 66) && (M.coord.X <= 74) && (M.coord.Y >= 21) && (M.coord.Y <= 22))
            {
                choice = 1;
            }

            //CLick on rectangle
            if ((M.coord.X >= 68) && (M.coord.X <= 74) && (M.coord.Y >= 14) && (M.coord.Y <= 18))
            {
                choice = 2;
            }

            //Click on circle
            else if ((M.coord.X >= 66) && (M.coord.X <= 73) && (M.coord.Y >= 11) && (M.coord.Y <= 14))
            {
                choice = 3;
            }

            //Click Fill button
            else if ((M.coord.X >= 54) && (M.coord.X <= 59) && (M.coord.Y >= 29) && (M.coord.Y <= 31))
            {
                DrawShapes(m_brushcolor, 0); //Fills rectangle
            }

            //Save to file button
            if ((M.coord.X >= 66) && (M.coord.X <= 75) && (M.coord.Y >= 23) && (M.coord.Y <= 26))
            {

                //Save coordinates and creat file
                ofstream MyWriteFile("textbrush_coord.txt");


                if (MyWriteFile.is_open())
                {
                    MyWriteFile << "X1: " << X1 << endl;
                    MyWriteFile << "X2: " << X2 << endl;
                    MyWriteFile << "Y1: " << Y1 << endl;
                    MyWriteFile << "Y2: " << Y2 << endl;
                    MyWriteFile << "color: " << m_brushcolor << endl;

                    // Close the file
                    MyWriteFile.close();
                }
            }

            //load from file button
            if ((M.coord.X >= 66) && (M.coord.X <= 77) && (M.coord.Y >= 27) && (M.coord.Y <= 30))
            {
                Coordinates o;
                o.gotoxy(0, 0);  //Set where to display file info
                string line;         //set values to line
                ifstream MyWriteFile("textbrush_coord.txt");
                if (MyWriteFile.is_open())
                {
                    while (getline(MyWriteFile, line))
                    {
                        cout << line << '\n';
                    }
                    MyWriteFile.close();
                }
            }


            //Click for color
            if ((M.coord.X >= 13) && (M.coord.X <= 15) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(15, m_fill);
            }
            else if ((M.coord.X == 16) && (M.coord.X <= 18) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(14, m_fill);
            }
            else if ((M.coord.X == 19) && (M.coord.X <= 21) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(13, m_fill);
            }
            else if ((M.coord.X == 22) && (M.coord.X <= 24) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(12, m_fill);
            }
            else if ((M.coord.X == 25) && (M.coord.X <= 27) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(11, m_fill);
            }
            else if ((M.coord.X == 28) && (M.coord.X <= 30) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(10, m_fill);
            }
            else if ((M.coord.X >= 31) && (M.coord.X <= 33) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(9, m_fill);
            }
            else if ((M.coord.X == 34) && (M.coord.X <= 36) && (M.coord.Y == 29) && (M.coord.Y <= 31))
            {
                DrawShapes(8, m_fill);
            }
            else if ((M.coord.X == 31) && (M.coord.X <= 33) && (M.coord.Y == 31) && (M.coord.Y <= 33))
            {
                DrawShapes(7, m_fill);
            }
            else if ((M.coord.X >= 28) && (M.coord.X <= 30) && (M.coord.Y == 31 && (M.coord.Y <= 33)))
            {
                DrawShapes(6, m_fill);
            }
            else if ((M.coord.X == 25) && (M.coord.X <= 27) && (M.coord.Y == 31) && (M.coord.Y <= 33))
            {
                DrawShapes(5, m_fill);
            }
            else if ((M.coord.X == 22) && (M.coord.X <= 24) && (M.coord.Y == 31) && (M.coord.Y <= 33))
            {
                DrawShapes(4, m_fill);
            }
            else if ((M.coord.X == 19) && (M.coord.X <= 21) && (M.coord.Y == 31) && (M.coord.Y <= 33))
            {
                DrawShapes(3, m_fill);
            }
            else if ((M.coord.X >= 16) && (M.coord.X <= 18) && (M.coord.Y == 31) && (M.coord.Y <= 33))
            {
                DrawShapes(2, m_fill);
            }
            else if ((M.coord.X >= 13) && (M.coord.X <= 14) && (M.coord.Y >= 31) && (M.coord.Y <= 32))
            {
                DrawShapes(1, m_fill);
            }

            //button selections
            switch (choice)
            {
                //Draws line when selected
            case 1:

                if (M.InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
                {
                    M.coord.X = M.InputRecord.Event.MouseEvent.dwMousePosition.X;
                    M.coord.Y = M.InputRecord.Event.MouseEvent.dwMousePosition.Y;
                    X2 = M.coord.X;
                    Y2 = M.coord.Y;

                    if ((M.coord.X >= 11) && (M.coord.X <= 62) && (M.coord.Y >= 11) && (M.coord.Y <= 27)) //Perimeter of paint area
                    {
                        drawLine();
                    }
                    break;

                    //Draws rectangle when selected
            case 2:

                if (M.InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
                {
                    M.coord.X = M.InputRecord.Event.MouseEvent.dwMousePosition.X;
                    M.coord.Y = M.InputRecord.Event.MouseEvent.dwMousePosition.Y;
                    X2 = M.coord.X;
                    Y2 = M.coord.Y;

                    if ((M.coord.X >= 11) && (M.coord.X <= 62) && (M.coord.Y >= 11) && (M.coord.Y <= 27)) // Perimeter of paint area
                    {
                        MyRectangle E;
                        E.m_x = X1;
                        E.m_y = Y1;
                        E.m_w = X2 - X1;
                        E.m_h = Y2 - Y1;
                        E.m_symbol = 219;
                        E.m_hollow = m_fill;
                        E.m_recColor = m_brushcolor;
                        E.Draw();
                    }
                }
                break;

                //Draws circle when selected
            case 3:

                if (M.InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
                {
                    M.coord.X = M.InputRecord.Event.MouseEvent.dwMousePosition.X;
                    M.coord.Y = M.InputRecord.Event.MouseEvent.dwMousePosition.Y;
                    X2 = M.coord.X;
                    Y2 = M.coord.Y;

                    if ((M.coord.X >= 11) && (M.coord.X <= 62) && (M.coord.Y >= 11) && (M.coord.Y <= 27)) // Perimeter of paint area
                    {
                        MyCircle j;
                        j.m_radius = (X2 - X1) / 2;
                        j.m_x = X1;
                        j.m_y = Y1;
                        j.DrawCircle();
                    }
                }
                break;



                }
            }
        }

    }
}


    







