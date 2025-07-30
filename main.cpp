#include <iostream>
#include <iomanip>
#include "Stock.h"
#include "Portfolio.h"

using namespace std;

void dispHeading(void);
void portfEdit(Portfolio *);
void addStock(Portfolio *);
void updateStock(Portfolio *);
void deleteStock(Portfolio *);

int main()
{

    Portfolio schwab;
    Portfolio etrade;
    Portfolio holdings;

    // 1. Edit schwab stock positions (note AAPL is held in two different lots)
    //schwab.addStock(Stock("AAPL", "Apple", 100, 200.0, 211.53));
    //schwab.addStock(Stock("PLTR", "Palantir", 100, 70.0, 170.0));
    //schwab.addStock(Stock("AAPL", "Apple", 100, 260.0, 211.53));
    //schwab.addStock(Stock("PANW", "Palo Alto", 100, 190.0, 193.84));

    // 2. Update the price on all Apple positions

    // 3. Edit etrade positions
    // etrade.addStock(Stock("CRWV", "Coreweave", 100, 187.0, 108.90));
    // etrade.addStock(Stock("TEM", "Tempus", 100, 45.0, 100.10));
    // etrade.addStock(Stock("ARM", "Arm Holdgs", 100, 150.0, 161.74));

    // 4. Delete an etrade position

    // 5. View combined portfolio

    // 6. Exit

    string token;
    int choice;
    bool notDone = true;

    do
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "*  Selection option:            *\n";
        cout << "*                               *\n";
        cout << "*     1 - Schwab portfolio      *\n";
        cout << "*     2 - Etrade portfolio      *\n";
        cout << "*     3 - Combined portfolio    *\n";
        cout << "*     4 - Exit                  *\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter your choice (1-4) -> ";

        getline(cin, token);
        choice = stoi(token);

        switch (choice)
        {
        case 1:
            portfEdit(&schwab);
            break;
        case 2:
            portfEdit(&etrade);
            break;
        case 3:
            holdings = schwab + etrade;
            cout << "\n";
            dispHeading();
            cout << holdings;
            break;
        case 4:
            notDone = false;
            cout << "\nAdios amigo\n";
            break;
        default:
            cout << "\nBad choice, try again!!!\n";
            break;
        }
    } while (notDone);
    cout << "\n";

    return 0;
}

void portfEdit(Portfolio *portf)
{
    bool notDone = true;
    string token;
    int choice;

    do
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "*  Selection option:            *\n";
        cout << "*                               *\n";
        cout << "*     1 - Add stock             *\n";
        cout << "*     2 - Update stock          *\n";
        cout << "*     3 - Delete stock          *\n";
        cout << "*     4 - Exit                  *\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter your choice (1-4) -> ";

        getline(cin, token);
        choice = stoi(token);

        switch (choice)
        {
        case 1:
            addStock(portf);
            break;
        case 2:
            updateStock(portf);
            break;
        case 3:
            deleteStock(portf);
            break;
        case 4:
            notDone = false;
            cout << "\nDone with this portfolio";
            break;
        default:
            cout << "\nBad choice, try again!!!\n";
            break;
        }
    } while (notDone);
    cout << "\n";
}

void addStock(Portfolio *portf)
{
    string token, ticker, company;
    int shares;
    double buyPrice, nowPrice;
    
    cout << "\n";
    cout << "    Enter ticker: ";
    getline(cin, ticker);
    cout << "    Enter company name: ";
    getline(cin, company);
    cout << "    Enter number of shares: ";
    getline(cin, token); shares = stoi(token);
    cout << "    Enter buy price : $";
    getline(cin, token); buyPrice = stod(token);
    cout << "    Enter current price : $";
    getline(cin, token); nowPrice = stod(token);

    portf->addStock(Stock(ticker, company, shares, buyPrice, nowPrice));
    cout << "\n";
    dispHeading();
    cout << *portf;
}

void updateStock(Portfolio *portf)
{
    string token, ticker;
    double nowPrice;
    
    cout << "\n";
    cout << "    Enter ticker: ";
    getline(cin, ticker);
    cout << "    Enter current price : $";
    getline(cin, token); nowPrice = stod(token);

    portf->updateStock(ticker, nowPrice);
    cout << "\n";
    dispHeading();
    cout << *portf;
}

void deleteStock(Portfolio *portf)
{
    string token;
    int lotID;
    
    cout << "\n";
    cout << "    Enter Lot ID: ";
    getline(cin, token); lotID = stoi(token);

    portf->delStock(lotID);
    cout << "\n";
    dispHeading();
    cout << *portf;
}

void dispHeading(void)
{
    cout << left << setw(10) << "Ticker" << setw(12) << "Company" << setw(8) << "Lot ID" << setw(8) << "Shares" << setw(10) << "Cost [$]" << setw(10) << "Price [$]" << setw(8) << "ROI [%]" << setw(8) << "Profit [$]\n";
    cout << setw(10) << "~~~~~~" << setw(12) << "~~~~~~~" << setw(8) << "~~~~~~" << setw(8) << "~~~~~~" << setw(10) << "~~~~~~~~" << setw(10) << "~~~~~~~~~" << setw(8) << "~~~~~~~" << setw(8) << "~~~~~~~~~~\n";
}