#ifndef Receipt_h
#define Receipt_h

#include <iostream>
#include <string>

using namespace std;

/*namespace new_book {
string Book = "Новая версия книги рецептов";
}*/


//базовый класс
class Receipt {
public:
    virtual void Print(string) = 0;

    void omlete();
    void salad();
    void borsch();
    void pancakes();
    void mousse();
    void oysters();
    
    static void list_breakfast();
    static void list_lunch();
    static void list_dinner();
};

//простые рецепты
class Simple: private Receipt{
public:
    void Print(string n = "----- ПРОСТЫЕ РЕЦЕПТЫ ----- \n\n") override{
        cout << n << endl;
    }
    void omlete();
    void salad();
    
};

//рецепты средней сложности
class Middle: protected Receipt{
public:
    void Print(string n = "\n\n----- РЕЦЕПТЫ СРЕДНЕЙ СЛОЖНОСТИ -----\n\n") override{
        cout << n << endl;
    }
    void borsch();
    void pancakes();
};

//сложные рецепты
class Hard: public Receipt{
public:
    void Print(string n = "\n\n----- СЛОЖНЫЕ РЕЦЕПТЫ -----\n\n") override{
        cout << n << endl;
    };
};

//завтраки
class Breakfast: virtual public Receipt {
    
public:
    void Print(string n = "----- ЗАВТРАКИ ----- \n\n") override{
        cout << n << endl;
    }
};

//обеды
class Lunch: virtual public Receipt {
    
public:
    void Print(string n = "----- ОБЕДЫ ----- \n\n") override{
        cout << n << endl;
    }
};

//ужины
class Dinner: virtual public Receipt {
    
public:
    void Print(string n = "----- УЖИНЫ ----- \n\n") override{
        cout << n << endl;
    }
};

//все рецепты
class All: public Simple, public Middle, public Hard, public Breakfast, public Lunch, public Dinner{
public:
    void Print(string n = "----- ВСЕ РЕЦЕПТЫ ----- \n\n") override{
        cout << n << endl;
    }
    
};

#endif /* Receipt_h */
