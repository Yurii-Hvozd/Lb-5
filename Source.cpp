#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
class CCoins
{
private:
    const char* sface = "Лицева сторона";
    const char* sback = "Тильна сторона";
    int coins[3] = { 0,0,0 };
    int* asd = coins;
    double quantity = 0;
    double all = 0;
    double perc = 0;
public:
    CCoins  operator ++ (int)
    {
        CCoins ret(*this);
        srand((int)time(0));
        for (int i = 0; i < 3; i++) {
            all++;
            coins[i] = rand() % 2 + 1;
            //cout << coins[i] << endl;
            if (coins[i] == 1) {
                quantity++;

            } //Якщо coins[i]==1, тоді це лицева сторона,інакше тильна.
        }
        return ret;
    }
    bool  operator == (const CCoins& other)
    {
        int f = 0;

        for (int i = 0; i < 3; i++) {
            if (this->coins[i] == other.coins[i]) {
                f++;
            }
        }
        if (f == 3)
            return true;
        else
            return false;
    }
    CCoins  operator () ()
    {
        CCoins ret(*this);
        for (int i = 0; i < 3; i++) {
            if (coins[i] == 1)
                cout << sface << endl;
            else
                cout << sback << endl;
        }
        cout << "Кiлькiсть монет що є лицевими:  " << quantity << endl;
        return ret;
    }
    CCoins  operator % (int)
    {
        CCoins ret(*this);
        perc = 100 / all * quantity;
        cout << perc << "%" << endl;
        return ret;
    }
    int  operator = (int)
    {
        quantity = 0;
        all = 0;
        for (int i = 0; i < 3; i++) {
            coins[i] = 0;
        }
        return 0;
    }
    friend ostream& operator << (ostream& i, const CCoins val)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << "Пiдкинути монети.(натиснiть 1)" << endl;
        cout << "Поточний стан?.(натиснiть 2)" << endl;
        cout << "Скинути кiлькiсть лицевих монет.(натиснiть 3)" << endl;
        cout << "Кинути монети знову i перевiрити, чи збiгаються лицевi сторони?(натисiнiть 4)" << endl;
        cout << "Вiдсоток монет з лицевими сторонами.(натиснiть 5)" << endl;
        cout << "Перевернути монету.(натиснiть 6)" << endl;
        cout << "Зупинити програму.(натиснiть 7)" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        return i;
    }
    friend istream& operator>>(istream& i, CCoins& st)
    {
        int s;
        cout << "Яку монету ви хочете перевернути? (Натиснiть 1 або 2 або 3)" << endl;
        cin >> s;
        cout << "Якщо ви хочете перевернути на лицеву сторону (натиснiть 1)" << endl;
        cout << "Якщо ви хочете перевернути на тильну сторону (натиснiть 2)" << endl;
        i >> st.coins[s - 1];
        return i;
    }
protected:
};
int main()
{
    setlocale(LC_ALL, "ukr");
    int func = 1;
    CCoins num1;
    CCoins num2;
    
    cout << "Що вам потрiбно?" << endl;
    while (func != 7) {
        cout << num1;
        cin >> func;
        if (func == 1) {
            num1++;
        }
        if (func == 2) {

            num1();
        }
        if (func == 3) {
            num1 = 0;
            if (func == 1) {
                num1++;
            }
            if (func == 2) {
                num1();
            }
        }
        if (func == 4) {
            num1();
            num2++;
            num2();
            bool result = num1 == num2;
            cout << result << endl;
        }
        if (func == 5) {
            num1 % 1;
        }
        if (func == 6) {
            cin >> num1;
        }
    }
    cout << "Програма завершила працювати.";
    return 0;
}

