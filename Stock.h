#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;

class Stock
{
private:
    string ticker;
    string company;
    int lotId;
    int nShares;
    double buyPrice;
    double currentPrice;
    double roi;
    double profit;

public:
    Stock(string ticker, string company, int shares, double buyPrice, double nowPrice);
    bool operator==(const Stock &other) const;
    bool operator!=(const Stock &other) const;
    string getTicker(void) const;
    string getCompany(void) const;
    int getLotId(void) const;
    int getShares(void) const;
    double getCurrentPrice(void) const;
    void setCurrentPrice(double price);
    double getRoi(void);
    double getProfit(void);
    friend ostream &operator<<(ostream &os, Stock &stock);
};

#endif