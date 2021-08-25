
#include <iostream>
#include <cmath>
#include<windows.h>

using namespace std;


/*int main()
{
    HDC hdc = GetDC(NULL);
    while (1)
    {
        SetPixel(hdc, 712, 505, 255);
        Sleep(1);
    }
    return 0;
}*/

/*int main()
{
    //Get a console handle
    HWND myconsole = GetConsoleWindow();
    //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel = 0;

    //Choose any color
    COLORREF COLOR = RGB(255, 255, 255);

    //Draw pixels
    for (double i = 0; i < 3.14 * 4; i += 0.05)
    {
        SetPixel(mydc, pixel+100, (int)(100 + 25*cos(i)), COLOR);
        pixel += 1;
    }

    ReleaseDC(myconsole, mydc);
    cin.ignore();

}*/


void CA(double z1[], double z2[], double z3[])
{
    z3[0] = z2[0] + z1[0];
    z3[1] = z2[1] + z1[1];
}
void CS(double z1[], double z2[], double z3[])
{
    z3[0] = z1[0] - z2[0];
    z3[1] = z1[1] - z2[1];
}
void CM(double z1[], double z2[], double z3[])
{
    z3[0] = z1[0] * z2[0] - z1[1] * z2[1];
    z3[1] = z1[0] * z2[1] + z1[1] * z2[0];
}
double ARG(double z1[])
{
    double i = pow(z1[0] * z1[0] + z1[1] * z1[1], 0.5);
    return i;
}
void CD(double z1[], double z2[], double z3[])
{
    z3[0] = (z1[0] * z2[0] + z1[1] * z2[1]) / pow(ARG(z2), 2);
    z3[1] = (z1[1] * z2[0] - z1[0] * z2[1]) / pow(ARG(z2), 2);
}
void CP(double z[], int j, double z2[])
{
    double z3[2];
    z2[0] = 1;
    z2[1] = 0;
    for (int i = 1; i <= j; i++)
    {
        CM(z2, z, z3);
        z2[0] = z3[0];
        z2[1] = z3[1];
    }
}




int main() {


    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);

    for (int i = -400; i <= 500; i++)
    {
        for (int k = -300; k <= 500; k++)
        {
            double z[2] = { i, k };
            for (int j = 1; j <= 50; j++) {


                double zp3[2];
                CP(z, 4, zp3);
                zp3[0] -= 1;
                // z^3 - 1  is calculated

                double zp2[2];
                CP(z, 3, zp2);
                zp2[0] *= 4;
                zp2[1] *= 4;
                // 3z^2 is calculated

                double zq[2];
                CD(zp3, zp2, zq);
                //the quotient is calculated

                z[0] -= zq[0];
                z[1] -= zq[1];

            }
            COLORREF COLOR;

            // cout << z[0] << " " << z[1] << endl;

            if (z[0] == 1 && z[1] == 0)
                COLOR = RGB(128, 128, 128);
            else if (z[0] == -1 && z[1] == 0)
                COLOR = RGB(255, 255, 0);
            else if (z[0] == 0 && z[1] == -1)
                COLOR = RGB(51, 153, 255);
            else  COLOR = RGB(0, 0, 0);


            SetPixel(mydc, i + 401, k + 301, COLOR);




        }

    }
    ReleaseDC(myconsole, mydc);
    cin.ignore();









    /*double z[2] = {1, -5};
    for (int i = 1; i <= 9; i++) {


        double zp3[2];
        CP(z, 3, zp3);
        zp3[0] -=  1;
        // z^3 - 1  is calculated

        double zp2[2];
        CP(z, 2, zp2);
        zp2[0] *= 3;
        zp2[1] *= 3;
        // 3z^2 is calculated

        double zq[2];
        CD(zp3, zp2, zq);
        //the quotient is calculated

        z[0] -= zq[0];
        z[1] -= zq[1];

        cout << z[0] << "  " << z[1] << endl;
    }*/



    return 0;
}