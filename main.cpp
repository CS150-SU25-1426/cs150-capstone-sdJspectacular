#include <iostream>
#include <iomanip>
#include "Stock.h"

using namespace std;

int main() {
    // Stock(string ticker, string company, int shares, double buyPrice, double nowPrice)
    Stock stock1("AAPL", "Apple", 100, 200.0, 210.0);
    Stock stock2("PLTR", "Palantir", 100, 70.0, 170.0);

    cout << left << setw(10) << "Ticker" << setw(12) << "Company" << setw(8) << "Shares" << setw(10) << "Cost [$]" << setw(10) << "Price [$]" << setw(8) << "ROI [%]" << setw(8) << "Profit [$]\n";
    cout << setw(10) << "~~~~~~" << setw(12) << "~~~~~~~" << setw(8) << "~~~~~~" << setw(10) << "~~~~~~~~" << setw(10) << "~~~~~~~~~" << setw(8) << "~~~~~~~" << setw(8) << "~~~~~~~~~~\n";
    cout << stock1 << "\n";
    cout << stock2 << "\n";
    cout << "\n";
    
    return 0;
}