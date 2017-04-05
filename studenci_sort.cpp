#include <iostream>
#include <algorithm>

using namespace std;

// Tworzy strukture Student wraz z konstruktorami.
struct Student
{
    string Nazwisko;
    float ZIOP, SO, Grafika, MySql;
    Student()
    {

    }
    Student(string Nazwisko, float ZIOP, float SO, float Grafika, float MySql)
    {
        this->Nazwisko = Nazwisko;
        this->ZIOP = ZIOP;
        this->SO = SO;
        this->Grafika = Grafika;
        this->MySql = MySql;
    }
    
    // Metoda obliczajaca srednia na potrzeby sortowania.
    float Srednia()
    {
        return (ZIOP + SO + Grafika + MySql) / 4;
    }
};

// Przeciazenie operatora "<"
bool operator<(Student &s1, Student &s2)
{
    return s2.Srednia() < s1.Srednia();
}

int main()
{
    Student Klasa[5];
    Klasa[0] = Student("Zebrowski", 4, 4.5, 4, 3.5);
    Klasa[1] = Student("Zebrowski2", 3, 3.5, 3, 4);
    Klasa[2] = Student("Zebrowski3", 3.5, 4, 4, 3.5);
    Klasa[3] = Student("Zebrowski4", 5, 4.5, 5, 4);
    Klasa[4] = Student("Zebrowski5", 2, 2, 2, 2);
    
    // Zaokraglenie sredniej do 2 miejsc po przecinku.
    cout.precision(3);

    cout << "TABLICA PRZED SORTOWANIEM:" << endl;

    for( int i = 0; i < 5; ++i)
    {
        cout << Klasa[i].Nazwisko << " " << Klasa[i].Srednia() << endl;
    }
    
    // Wykorzystanie funkcji sort z biblioteki <algorithm>.
    sort(Klasa, Klasa + 5);

    cout << endl << "TABLICA PO SORTOWANIU:" << endl;

    for( int i = 0; i < 5; ++i)
    {
        cout << Klasa[i].Nazwisko << " " << Klasa[i].Srednia() << endl;
    }

    return 0;
}
