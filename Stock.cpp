#include <iomanip>
#include <iostream>
#include <cmath>
#include "Stock.h"

using namespace std;

Stock::Stock(string ticker, string company, int shares, double buyPrice, double nowPrice)
{
    this->ticker = ticker;
    this->company = company;
    this->nShares = shares;
    this->buyPrice = buyPrice;
    this->currentPrice = nowPrice;
    // Lot ID to be initialized to some random 4-digit number
    this->lotId = rand() % 10000;
    // ROI and profit to be updated whenever the stock is queried
    this->roi = 0.0;
    this->profit = 0.0;
}

string Stock::getTicker(void) const
{
    return this->ticker;
}

string Stock::getCompany(void) const
{
    return this->company;
}

int Stock::getLotId(void) const
{
    return this->lotId;
}

int Stock::getShares(void) const
{
    return this->nShares;
}

double Stock::getCurrentPrice(void) const
{
    return this->currentPrice;
}

void Stock::setCurrentPrice(double price)
{
    this->currentPrice = price;
}

double Stock::getRoi(void)
{
    this->roi = 100.0 * ((this->currentPrice / this->buyPrice) - 1.0);
    return this->roi;
}

double Stock::getProfit(void)
{
    this->profit = (this->currentPrice - this->buyPrice) * this->nShares;
    return this->profit;
}

bool Stock::operator==(const Stock &other) const
{
    return (this->ticker == other.ticker);
}

bool Stock::operator!=(const Stock &other) const
{
    return (this->ticker != other.ticker);
}

ostream &operator<<(ostream &os, Stock &stock)
{
    os << setw(10) << left << stock.ticker << setw(12) << stock.company << setw(8) << stock.lotId << setw(8) << stock.nShares << setw(10) << fixed << setprecision(2) << stock.buyPrice << setw(10) << stock.currentPrice << setw(8) << stock.getRoi() << setw(8) << stock.getProfit();

    return os;
}
