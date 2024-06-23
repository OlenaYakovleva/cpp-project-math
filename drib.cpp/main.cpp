
//Реалізуйте клас «Дріб». Необхідно зберігати чисельник
//і знаменник як змінні-члени. Реалізуйте функції-члени для
//введення даних в змінні-члени, для виконання арифметичних операцій (додавання, віднімання, множення,
//ділення, і т.д.).

#include <iostream>
using namespace std;

class Drib {
private:
    int chiselnik;
    int znamenik;
    
    //Greatest Common Divisor
    int gcd(int a, int b) const {
        if (b == 0) //Якщо друге число (b) дорівнює нулю, повертаємо перше число (a) як GCD.
            return a;
        return gcd(b, a % b);  //Викликаємо функцію рекурсивно, поки одне з чисел не стане нулем.
    }
    
public:
    Drib() : chiselnik(0), znamenik(1) {}

    Drib(int chis, int znam) : chiselnik(chis), znamenik(znam) {}

    void setChiselnik(int chis) {
        chiselnik = chis;
        }

        int getChiselnik() const {
            return chiselnik;
        }

    void setZnamenik(int znam) {
        znamenik = znam;
        }

        int getZnamenik() const {
            return znamenik;
        }

    void display() const {
        cout << chiselnik <<"|" << znamenik << endl;
        }

        Drib add(const Drib dr) const {
            Drib result;
            result.chiselnik = chiselnik * dr.znamenik + dr.chiselnik * znamenik;
            result.znamenik = znamenik * dr.znamenik;
            return result;
        }

        Drib subtract(const Drib dr) const {
            Drib result;
            result.chiselnik = chiselnik * dr.znamenik - dr.chiselnik * znamenik;
            result.znamenik = znamenik * dr.znamenik;
            return result;
        }

        Drib multiply(const Drib dr) const {
            Drib result;
            result.chiselnik = chiselnik * dr.chiselnik;
            result.znamenik = znamenik * dr.znamenik;
            return result;
        }

        Drib divide(const Drib dr) const {
            Drib result;
            result.chiselnik = chiselnik * dr.znamenik;
            result.znamenik = znamenik * dr.chiselnik;
            return result;
        }
    };

    int main() {
        Drib drib1(5, 6); //Створюємо об'єкт drib1 з чисельником 1 і знаменником 2.
        Drib drib2(1, 5);

        // Використання методів set і get
        drib1.setChiselnik(55);
        drib1.setZnamenik(21);
        
        cout << "drib1 after change: ";
        drib1.display();
        
        cout << "Chiselnik drib1: " << drib1.getChiselnik() << endl;
        cout << "Znamenik drib1: " << drib1.getZnamenik() << endl;

        Drib resultAdd = drib1.add(drib2); //Додаємо drib1 і drib2, зберігаємо результат.
        Drib resultSub = drib1.subtract(drib2);
        Drib resultMul = drib1.multiply(drib2);
        Drib resultDiv = drib1.divide(drib2);
        
        cout << "Addition: ";
        resultAdd.display();
        
        cout << "Subtraction: ";
        resultSub.display();
        
        cout << "Multiplication: ";
        resultMul.display();
        
        cout << "Division: ";
        resultDiv.display();
        
        return 0;
    }

