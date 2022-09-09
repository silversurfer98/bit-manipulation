#include"include.h"


int mfloor(float x)
{
    // ONLY RETURN POSITIVE VALUES STILL HAVEN'T FIGURED OUT THE NEGATIVE NO. FLOOR

    // cast float to int directly for IEEE-754 math operations
    int y = * (int *)&x;

    //mask out first sign bit
    y = y & 0b01111111111111111111111111111111;

    // extract the exponent
    y = (y >> 23) - 127;  // all mantissa gone

    int floor = 1 << y;

    if(x - floor <= 0.5)
        return floor;
    else
        return floor + 1;

}


int test()
{
    std::cout<<"base work \n";

    float x;
    std::cout<<" enter No. : ";
    std::cin>>x;

    int y = * (int *)&x;

    std::cout<<"evil typecast : "<<y;

    int exp = (y >> 23) - 127;
    int mantissa = y << 9;
    mantissa = mantissa >> 9;

    std::cout<<"\nevil exponent : "<<exp;
    std::cout<<"\nevil mantissa : "<<mantissa;

    int power_of_2 = 1;
    power_of_2 = power_of_2 << exp;

    std::cout<<"\nBase : "<<power_of_2;


    std::cout<<"\nomale : "<<mfloor(x);

    return 0;
}

int main ()
{
    float x = 2.25;
    float xx = 2.15;
    int y = * (int *)&x;
    int yy = * (int *)&xx;

    //mask out exponents

    y = y & 0b00000000011111111111111111111111;
    yy = yy & 0b00000000011111111111111111111111;
    std::cout<<y<<"\n";
    std::cout<<yy<<"\n";

    unsigned long long int a = 659707396096;
    
    std::cout<<a<<"\n";
    std::cout<<sizeof(a);

    unsigned long long int aa = a & 0b000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111111111111111111;
    std::cout<<aa<<"\n";
    return 0;
}