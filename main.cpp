#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

int main() {
    // Vartotojo pasirinkimams ir skaiciavimams
    int choice;
    int currencyChoice;
    double amount, result;
    string currencyName;

    // Kursai
    const double GBP_B = 0.8729, GBP_PIRK = 0.8600, GBP_PARD = 0.9220;
    const double USD_B = 1.1793, USD_PIRK = 1.1460, USD_PARD = 1.2340;
    const double INR_B = 104.6918, INR_PIRK = 101.3862, INR_PARD = 107.8546;
    // Kintamieji pasirinktos valiutos kursams saugoti
    double currentRateB, currentRatePirk, currentRatePard;
// Pagrindinis meniu
    cout << "--- Valiutos keitykla (Base: EUR) ---" << endl;
    cout << "1. Kursu palyginimas" << endl;
    cout << "2. Pirkti valiuta" << endl;
    cout << "3. Parduoti valiuta" << endl;
    cout << "Pasirinkite veiksma (1-3): ";
    cin >> choice;
// Valiutos pasirinkimo meniu
    cout << "\nPasirinkite valiuta:" << endl;
    cout << "1. GBP (Svaras)" << endl;
    cout << "2. USD (Doleris)" << endl;
    cout << "3. INR (Rupija)" << endl;
    cout << "Pasirinkimas (1-3): ";
    cin >> currencyChoice;

  // Valiutos nustatymas 
    if (currencyChoice == 1) {
        currentRateB = GBP_B; currentRatePirk = GBP_PIRK; currentRatePard = GBP_PARD;
        currencyName = "GBP";
    } else if (currencyChoice == 2) {
        currentRateB = USD_B; currentRatePirk = USD_PIRK; currentRatePard = USD_PARD;
        currencyName = "USD";
    } else {
        currentRateB = INR_B; currentRatePirk = INR_PIRK; currentRatePard = INR_PARD;
        currencyName = "INR";
    }

  // Veiksmu logika naudojant if-else
    if (choice == 1) {
        // Palyginimas
        cout << "Siuo metu: 1 EUR = " << currentRateB << " " << currencyName << endl;
    } 
    else if (choice == 2) {
        // Pirkimas
        cout << "Iveskite EUR kieki: ";
        cin >> amount;
        result = amount * currentRatePirk;
        cout << "Jus gausite: " << fixed << setprecision(2) << result << " " << currencyName << endl;
    } 
    else if (choice == 3) {
        // Pardavimas
        cout << "Iveskite " << currencyName << " kieki: ";
        cin >> amount;
        result = amount / currentRatePard;
        cout << "Jus gausite: " << fixed << setprecision(2) << result << " EUR" << endl;
    } 
    else {
        // Klaidos pranesimas, jei pasirinktas ne tas skaicius
        cout << "Klaida: Neteisingas pasirinkimas!" << endl;
    }

    return 0;

}
