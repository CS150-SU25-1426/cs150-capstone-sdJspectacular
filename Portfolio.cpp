#include <iostream>
#include <vector>
#include <algorithm>
#include "Stock.h"
#include "Portfolio.h"

using namespace std;

bool Portfolio::addStock(Stock s)
{
    this->stocks.push_back(s);
    return true;
}

// * Deletes the position matching a lotID
// * Does not delete all the positions matching a ticker because
//     there could be multiple lots of the same stock
void Portfolio::delStock(int id)
{
    stocks.erase(std::remove_if(stocks.begin(), stocks.end(),
                                [&](const Stock &item)
                                {
                                    return item.getLotId() == id;
                                }),
                 stocks.end());
}

// * Updates the current price of all lots
//     that match a ticker symbol
void Portfolio::updateStock(string ticker, double price)
{
    for (int i = 0; i < this->stocks.size(); ++i)
    {
        if (ticker == this->stocks[i].getTicker())
            this->stocks[i].setCurrentPrice(price);
    }
}

Portfolio Portfolio::operator+(const Portfolio& rhs) const
{
    Portfolio combined;

    for (auto stock : this->stocks)
        combined.addStock(stock);

    for (auto stock : rhs.stocks)
        combined.addStock(stock);
    
    return combined;
}

ostream &operator<<(ostream &os, const Portfolio &portfolio)
{
    for (auto stock : portfolio.stocks)
    {
        os << stock << "\n";
    }

    return os;
}