#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <iostream>
#include <vector>
#include "Stock.h"

using namespace std;

class Portfolio
{
private:
    vector<Stock> stocks;

public:
    bool addStock(Stock s);
    void delStock(int id);
    void updateStock(string ticker, double price); // This is the "edit" item method required by the High-Level Reqs
    Portfolio operator+(const Portfolio& rhs) const;
    friend ostream& operator<<(ostream& os, const Portfolio& s);
};
#endif