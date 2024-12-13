#include <iostream>
#include <iomanip> // For using setw(), setprecision(), etc.
using namespace std;

int main() {
    double initialLoan, interestRate, annualPayment;

    cout << "Enter initial loan: ";
    cin >> initialLoan;
    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;
    cout << "Enter amount you can pay per year: ";
    cin >> annualPayment;

    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    cout << fixed << setprecision(2);

    double prevBalance = initialLoan;
    double interest, total, payment, newBalance;
    int year = 1;

    while (prevBalance > 0) {
        interest = prevBalance * (interestRate / 100);
        total = prevBalance + interest;
        payment = (total < annualPayment) ? total : annualPayment;
        newBalance = total - payment;

        cout << setw(13) << left << year;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        prevBalance = newBalance;
        year++;
    }

    return 0;
}
