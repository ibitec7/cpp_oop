#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
    int day, month, year;

    public:
    Date(int dd, int mm, int yy){
        if (mm<=12 && mm>=1){
            month = mm;
        }
        else{
            month = 1;
        }
        day = dd;
        year = yy;
    }

    void setDay(int dd){
        day = dd;
    }
    void setMonth(int mm){
        month = mm;
    }
    void setYear(int yy){
        year = yy;
    }

    string formatDate(){
        string dd=to_string(day);
        string mm=to_string(month);
        string yy=to_string(year);

        string date = dd + "/" + mm + "/" + yy;
        return date;
    }

    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }    
};

int main() {
    Date d1(19, 1, 2024);
    cout << d1.formatDate() << endl; // should print 19/1/2024
    d1.setDay(17);
    cout << d1.formatDate() << endl; // should print 17/1/2024
    d1.setMonth(5);
    cout << d1.formatDate() << endl; // should print 17/5/2024
    Date d2(29, 13, 2024); // should set month to 1
    cout << d2.formatDate() << endl; // should print

    return 0;
}