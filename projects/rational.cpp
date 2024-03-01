#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int find(string a, char c){
    for (int i = 0; i < a.length(); i++){
        if (a[i]==c){
            return i;
        }
    }
    return 0;
}

int strint(string a){
    int num = 0;
    for (int i = 0; i < a.length(); i++){
        num = num*10 + (a[i]-48);
    }
    return num;
}

class Rational {
    private:

    int n;
    int d;

    public:

    Rational(int num, int den){
        n = num;
        d = den;
    }

    Rational(string a){
        int index = find(a,'/');
        n = strint(a.substr(0,index));
        d = strint(a.substr(index+1, a.length()));
    }

    Rational(float p){
        int i = 1;

        float rem = p - floor(p);

        while(rem - floor(rem) != 0){
            rem *= 10;
            i *= 10;
        }

        n = static_cast<int>(rem) + floor(p)*i;
        d = i;

        reduce();
    }

    int get_num(){
        return n;
    }

    int get_den(){
        return d;
    }

    void set_num(int n){
        n = n;
    }

    void set_den(int d){
        d = d;
    }

    string tostring(){
        string num = to_string(n);
        string den = to_string(d);

        string out = num + "/" + den;
        return out;
    }

    void reduce(){
        int a[10] = {2,3,5,7,11,13,17,19,23,29};
        int i = 0; 

        while (i < 10){
            if ((n % a[i] == 0) && (d % a[i] == 0)){
                n /= a[i];
                d /= a[i];
            }
            else{
                i++;
            }
        }        
    }

    Rational operator+(const Rational& r){
        return (n*r.d + r.n*d, d*r.d);
    }

    Rational operator-(const Rational& r){
        return (n*r.d - r.n*d, d*r.d);
    }

    Rational operator*(const Rational& r){
        return (n*r.n, d*r.d);
    }

    Rational operator/(const Rational& r){
        return (n*r.d,d*r.n);
    }

    bool operator==(const Rational& r){
        if (n == r.n && d == r.d){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator!=(const Rational& r){
        if (n == r.n && d == r.d){
            return false;
        }
        else{
            return true;
        }
    }

    void disp(){
        cout<<n<<"/"<<d<<endl;
    }

};

int main(){
    Rational a = Rational(0.255);
    Rational b = Rational("1/100");
    cout<<b.tostring();
}