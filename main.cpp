#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Currency rates
const double GBP_Bendras = 0.8729;
const double GBP_Pirkti = 0.8600;
const double GBP_Parduoti = 0.9220;

const double USD_Bendras = 1.1793;
const double USD_Pirkti = 1.1460;
const double USD_Parduoti = 1.2340;

const double INR_Bendras = 104.6918;
const double INR_Pirkti = 101.3862;
const double INR_Parduoti = 107.8546;

void showMenu() {
    cout << "\n=== VALIUTOS KEITYKLA ===\n";
    cout << "1. Palyginti valiutos kursa\n";
    cout << "2. Pirkti valiuta\n";
    cout << "3. Parduoti valiuta\n";
    cout << "4. Iseiti\n";
    cout << "Pasirinkite: ";
}

void showCurrencies() {
    cout << "\nGalimos valiutos:\n";
    cout << "1. EUR - Euras\n";
    cout << "2. GBP - Didziosios Britanijos svaras\n";
    cout << "3. USD - JAV doleris\n";
    cout << "4. INR - Indijos rupija\n";
    cout << "Pasirinkite valiuta: ";
}

double getRate(int currency, int action) {
    switch(currency) {
        case 2: // GBP
            if(action == 1) return GBP_Bendras;
            else if(action == 2) return GBP_Pirkti;
            else return GBP_Parduoti;
        case 3: // USD
            if(action == 1) return USD_Bendras;
            else if(action == 2) return USD_Pirkti;
            else return USD_Parduoti;
        case 4: // INR
            if(action == 1) return INR_Bendras;
            else if(action == 2) return INR_Pirkti;
            else return INR_Parduoti;
        default:
            return 1.0;
    }
}

string getCurrencySymbol(int currency) {
    switch(currency) {
        case 1: return "EUR";
        case 2: return "GBP";
        case 3: return "USD";
        case 4: return "INR";
        default: return "";
    }
}

int main() {
    int choice, currency;
    double amount, result;
    
    cout << fixed << setprecision(2);
    
    while(true) {
        showMenu();
        cin >> choice;
        
        if(choice == 4) {
            cout << "Viso gero!\n";
            break;
        }
        
        if(choice == 1) {
            // Palyginti valiutos kursa
            showCurrencies();
            cin >> currency;
            
            if(currency >= 2 && currency <= 4) {
                double rate = getRate(currency, 1);
                cout << "1 EUR = " << rate << " " << getCurrencySymbol(currency) << "\n";
                cout << "1 " << getCurrencySymbol(currency) << " = " << 1/rate << " EUR\n";
            } else {
                cout << "Neteisingas pasirinkimas!\n";
            }
            
        } else if(choice == 2) {
            // Pirkti valiuta (EUR -> kita valiuta)
            showCurrencies();
            cin >> currency;
            
            if(currency >= 2 && currency <= 4) {
                cout << "Kiek EUR norite iskeisti? ";
                cin >> amount;
                
                double rate = getRate(currency, 2);
                result = amount * rate;
                
                cout << "Uz " << amount << " EUR gausite: " 
                     << result << " " << getCurrencySymbol(currency) << "\n";
            } else {
                cout << "Neteisingas pasirinkimas!\n";
            }
            
        } else if(choice == 3) {
            // Parduoti valiuta (kita valiuta -> EUR)
            showCurrencies();
            cin >> currency;
            
            if(currency >= 2 && currency <= 4) {
                cout << "Kiek " << getCurrencySymbol(currency) << " norite parduoti? ";
                cin >> amount;
                
                double rate = getRate(currency, 3);
                result = amount / rate;
                
                cout << "Uz " << amount << " " << getCurrencySymbol(currency) 
                     << " gausite: " << result << " EUR\n";
            } else {
                cout << "Neteisingas pasirinkimas!\n";
            }
            
        } else {
            cout << "Neteisingas pasirinkimas!\n";
        }
    }
    
    return 0;
}