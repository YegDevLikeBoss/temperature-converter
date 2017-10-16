#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float celTo(float tmp);
float farTo(float tmp);
float kelTo(float tmp);
float universal(float tmp);
int error(char type, char tp2);


int main(int argc, char *argv[])
{
    int capScale, status;
    char scale;
    float val, temp;


    status = 1;
    val = atof(argv[1]); /*converting pointer to float*/

    if(argc==2)
    {
        universal(val);
    }
    else if (argc==3)
    {
        temp = *argv[2];
        capScale = toupper(temp); /*letter capitalization*/
        switch(capScale)
        {
            case 'C':
                (val > -273.16) ? celTo(val) : error('b', '\0');
            break;
            case 'F':
                (val > -459.67) ? farTo(val) : error('b', '\0');
            break;
            case 'K':
                (val > -0.01) ? kelTo(val) : error('b', '\0');
            break;
            default:
                error('a', capScale);
        }
    }


    switch(status)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    }
}

float celTo(float tmp) /*celsius conversion*/
    {
        float celsius, fahrenheit, kelvin, temp;

        celsius = tmp;
        fahrenheit = 9*celsius/5+32;
        kelvin = celsius + 273.15;
        printf("%.2f F\n%.2f K ;-)\n", fahrenheit, kelvin);
    }
float farTo(float tmp) /*fahrenheit conversion*/
    {
        float celsius, fahrenheit, kelvin, temp;

        fahrenheit = tmp;
        celsius = (fahrenheit - 32)*5/9;
        kelvin = celsius + 273.15;
        printf("%.2f C\n%.2f K ;-)\n", celsius, kelvin);
    }
float kelTo(float tmp) /*kelvin conversion*/
    {
        float celsius, fahrenheit, kelvin, temp;

        kelvin = tmp;
        celsius = kelvin - 273.15;
        fahrenheit = 9*celsius/5+32;
        printf("%.2f C\n%.2f F ;-)\n", celsius, fahrenheit);
    }
float universal(float tmp) /*undefined conversion*/
    {
        float celsius, fahrenheit, kelvin, temp;

        printf("For Celsius:\n");
        if (tmp > -273.16)
        {
            celsius = tmp;
            fahrenheit = 9*celsius/5+32;
            kelvin = celsius + 273.15;
            printf("%.2f C\n%.2f F\n%.2f K ;-)\n", celsius, fahrenheit, kelvin);
        }
        else printf("Invalid value of temperature :-(\n");
        printf("For Fahrenheit:\n");
        if (tmp > -459.67)
        {
            fahrenheit = tmp;
            celsius = (fahrenheit - 32)*5/9;
            kelvin = celsius + 273.15;
            printf("%.2f C\n%.2f F\n%.2f K ;-)\n", celsius, fahrenheit, kelvin);
        }
        else printf("Invalid value of temperature :-(\n");
        printf("For Kelvin:\n");
        if (tmp > -0.01)
        {
            kelvin = tmp;
            celsius = kelvin - 273.15;
            fahrenheit = 9*celsius/5+32;
            printf("%.2f C\n%.2f F\n%.2f K ;-)\n", celsius, fahrenheit, kelvin);
        }
        else printf("Invalid value of temperature :-(\n");
    }
int error(char type, char tp2)
    {
        int status;

        switch(type)
        {
            case 'a':printf("Incompatible argument: '%c'. Try 'c', 'f' or 'k' instead :-(\n", tp2);
            break;
            case 'b':printf("Invalid value of temperature :-(\n");
            break;
        }

        status=0;
        return 0;

    }
