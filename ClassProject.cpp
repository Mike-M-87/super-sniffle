#include <iostream>
using namespace std;

static const float AnnualInterest = 0.03;

class Account
{
private:
    int AccNo;
    float AccountBalance;

public:
    Account();
    void enterAccountData();
    void computeInterest(int years);
    void displayAccount();
    ~Account();
};

Account::Account() {}

Account::~Account() {}

void Account::enterAccountData()
{
    do
    {
        cout << "Enter Account Number :";
        cin >> AccNo;
    } while (AccNo < 1000);

    do
    {
        cout << "Enter Account Balance :";
        cin >> AccountBalance;
    } while (AccountBalance < 1);
}

void Account::computeInterest(int years)
{
    for (size_t i = 1; i <= years; i++)
    {
        float interest;
        interest = AccountBalance * AnnualInterest;
        AccountBalance += interest;
        cout << "Year [" << i << "] :: Ending Balance :" << AccountBalance << endl;
    }
}

void Account::displayAccount()
{
    cout << "Account Number :" << AccNo << endl;
    cout << "Account Balance :" << AccountBalance << endl;
}

void calc(Account arr[], int validAccounts)
{
    int years;

    for (size_t i = 0; i < validAccounts; i++)
    {
        do
        {
            cout <<  "Enter year between 1 - 40 :";
            cin >>  years;
        } while (years < 1 || years > 40);

        arr[i].computeInterest(years);
        arr[i].displayAccount();
    }
    cout << "Am done \n";
}

int main(int argc, char const *argv[])
{
    const int NUMBER_OF_ACCOUNTS = 2;
    Account BankAccounts[NUMBER_OF_ACCOUNTS];

    char x;
    int validCount = 0;
    do
    {
        BankAccounts[validCount].enterAccountData();

        cout << "\nContinue? ";
        cin >> x;

        validCount++;
        cout << endl;
    } while (validCount < NUMBER_OF_ACCOUNTS && x == 'y');

    calc(BankAccounts,validCount);

    return 0;
}
