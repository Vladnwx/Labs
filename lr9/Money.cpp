#include <iostream>
using namespace std;

class Money
{
private:
    int dollars;
    int cents;

public:
    Money() {};
    Money(long d, int c)
    {
        dollars = d;
        cents = c;
    }
    int operator>(const Money &) const;
    friend ostream &operator<<(ostream &os, Money &);
};

int Money::operator>(const Money &amt) const
{
    return (dollars > amt.dollars) || ((dollars == amt.dollars) && (cents > amt.cents));
}

ostream &operator<<(ostream &os, Money &amt)
{
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}
