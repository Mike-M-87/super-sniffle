#include <iostream>
#include <math.h>

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
    void calc(Account arr[], int validAccounts,int terms);
    ~Account();
};

Account::Account() {}

Account::~Account() {}

void Account::enterAccountData()
{
    do {
        cout << "Enter Account Number : ";
        cin >> AccNo;
    } while (AccNo < 1000);

    do
    {
        cout << "Enter Account Balance : ";
        cin >> AccountBalance;
    } while (AccountBalance < 1);

    cout << "\n";

}

void Account::computeInterest(int years)
{
    float principal = AccountBalance;
    float exponents  = pow( 1 + (AnnualInterest) , (years) ); 

    AccountBalance = principal * exponents;
    
}

void Account::displayAccount()
{
    cout << ":: Account Number  : " << AccNo << endl;
    cout << ":: Account Balance : " << AccountBalance << endl;

}

void calc(Account arr[], int validAccounts,int terms)
{
    cout << "Final Account Details after " << terms <<" years \n \n";
    for (size_t i = 0; i < validAccounts; i++)
    {
        arr[i].computeInterest(terms);
        arr[i].displayAccount();
        cout << "---- ---- --- -- \n";
    }
    cout << "\nCompleted 👋\n";
}

int main(int argc, char const *argv[])
{
    cout << "\n\tWelcome To ParkVille 🏔  Bank \n\n";

    const int NUMBER_OF_ACCOUNTS = 10;
    Account BankAccounts[NUMBER_OF_ACCOUNTS];

    int validCount = 0;
    char sentinal;
    int term;

    do
    {
        BankAccounts[validCount].enterAccountData();
        BankAccounts[validCount].displayAccount();

        cout << "\nContinue (y/n)? ";
        cin >> sentinal;

        validCount++;
        cout << endl;
    } while (validCount < NUMBER_OF_ACCOUNTS && sentinal == 'y');

    do {
        cout <<  "Enter Term between 1 - 40 : ";
        cin >>  term;
    } while (term < 1 || term > 40);

    cout << endl;

    calc(BankAccounts,validCount,term);

    return 0;
}
