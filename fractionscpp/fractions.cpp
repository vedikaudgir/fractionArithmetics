//Program which takes fraction as in uinput in the form of strings and performs basic operations.
//Author - Vedika Udgir

    #include <iostream>
    using namespace std;

    class Fractions
    {
    private:
        char a[20];
        int numerator = 0, denominator = 0;

        void setNumerator()
        {
            int i;
            for (i = 0; a[i] != '/'; i++)
            {
                numerator *= 10;
                numerator += (a[i] - '0');
            }
        }
        void setDenomirator()
        {
            int i;
            for (i = 0; a[i] != '/'; i++)
                ;
            i++;
            for (; a[i] != '\0'; i++)
            {
                denominator *= 10;
                denominator += (a[i] - '0');
            }
        }
        int HCF(int a, int b)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        void setInSimplestForm()
        {
            int g = HCF(numerator, denominator);
            numerator /= g;
            denominator /= g;
        }

    public:
        void takeFractions()
        {
            cout << "\nEnter fraction - ";
            cin >> a;
            setNumerator();
            setDenomirator();
        }
        void printFractions()
        {
            cout << "\nResult = " << numerator << " / " << denominator;
        }

        Fractions operator+(Fractions f2)
        {
            Fractions sum;
            sum.numerator = (numerator * f2.denominator) + (f2.numerator * denominator);
            sum.denominator = denominator * f2.denominator;
            sum.setInSimplestForm();
            return sum;
        }
        Fractions operator-(Fractions f2)
        {
            Fractions difference;
            difference.numerator = (numerator * f2.denominator) - (f2.numerator * denominator);
            difference.denominator = denominator * f2.denominator;
            difference.setInSimplestForm();
            return difference;
        }
        Fractions operator*(Fractions f2)
        {
            Fractions product;
            product.numerator = numerator * f2.numerator;
            product.denominator = denominator * f2.denominator;
            product.setInSimplestForm();
            return product;
        }

        int getNumerator()
        {
            return numerator;
        }
        int getDenominator()
        {
            return denominator;
        }
        Fractions() {}
        Fractions(const Fractions &f)
        {
            numerator = f.numerator;
            denominator = f.denominator;
        }
        ~Fractions() {}
    };

    int main()
    {
        Fractions f1, f2;
        f1.takeFractions();
        f2.takeFractions();

        Fractions sum;
        sum = f1 + f2;
        sum.printFractions();

        Fractions diff;
        diff = f1 - f2;
        diff.printFractions();

        Fractions pro;
        pro = f1 * f2;
        pro.printFractions();
    }
