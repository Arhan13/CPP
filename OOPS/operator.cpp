#include <iostream>
#include <string>
using namespace std;
class Complex
{
    float Real;
    float Imag;

public:
    Complex(float TempReal = 0, float TempImag = 0)
    {
        Real = TempReal;
        Imag = TempImag;
    }
    Complex Add(Complex Comp2)
    {
        float TempReal;
        float TempImag;
        TempReal = Real + Comp2.Real;
        TempImag = Imag + Comp2.Imag;
        return Complex(TempReal, TempImag);
    }
    Complex operator+(Complex Comp2)
    {
        float TempReal;
        float TempImag;

        TempReal = Real + Comp2.Real;
        TempImag = Imag + Comp2.Imag;
        return Complex(TempReal, TempImag);
    }
    Complex operator++()
    // This is prefi x
    {
        Real++;
        return Complex(Real, Imag);
    }
    Complex operator++(int dummy)
    {
        Imag++;
        return Complex(Real, Imag);
    }
    // This is postfi x
    void Display()
    {
        cout << Real << " + " << Imag << "i \n";
    }
};
int main()
{
    Complex Comp1(10, 20);
    Complex Comp2(20, 30);

    Complex CompResult1, CompResult2;
    CompResult1 = Comp1.Add(Comp2);
    CompResult1.Display();
    CompResult2 = Comp1 + Comp2;
    CompResult2.Display();
    Comp1++; // The postfi x version with dummy arguments Comp1.Display();
    ++Comp2; // The prefi x version without any arguments Comp2.Display();
}