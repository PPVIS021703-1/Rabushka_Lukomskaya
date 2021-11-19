#include <iostream>
#include "Receipt.h"
using namespace std;
//using namespace new_book;

int main(){
    /*string Book = "Вам доступна следующая версия книги рецептов";
    cout << Book << endl;
    cout << new_book::Book << endl;*/
    
    Simple a;
    Middle b;
    Hard c;
    
    All d;
    
    Breakfast breakfast;
    Lunch lunch;
    Dinner dinner;
    int k;
    
    while (true) {
        cout << "Показать рецепты:" << endl <<
        "1: все рецепты" << endl <<
        "2: по сложности" << endl <<
        "3: завтраки/обеды/ужины" << endl <<
        "0: выход" << endl;
        cin >> k;
        switch (k) {
            case 1:{
                d.Print();
                d.Simple::omlete();
                d.Simple::salad();
                d.Middle::borsch();
                d.Middle::pancakes();
                d.Hard::oysters();
                d.Hard::mousse();
                
                d.Breakfast::Print();
                d.list_breakfast();
                
                d.Lunch::Print();
                d.list_lunch();
                
                d.Dinner::Print();
                d.list_dinner();
                break;
            }
            case 2:{
                a.Print();
                a.omlete();
                a.salad();
                
                b.Print();
                b.borsch();
                b.pancakes();
                
                c.Print();
                c.oysters();
                c.mousse();
                break;
            }
            case 3:{
                cout << "\t1 - завтраки\n\t2 - обеды\n\t3 - ужины" << endl;
                cin >> k;
                switch (k) {
                    case 1:
                        breakfast.Print();
                        breakfast.list_breakfast();
                        break;
                    case 2:
                        lunch.Print();
                        lunch.list_lunch();
                        break;
                    case 3:
                        dinner.Print();
                        dinner.list_dinner();
                        break;
                    default:
                        break;
                }
                break;
            }
            case 0:{
                exit(0);
                break;
            }
            default:
                cout << "Ошибка! Попробуйте еще раз." << endl;
                break;
        }
    }
    return 0;
}
