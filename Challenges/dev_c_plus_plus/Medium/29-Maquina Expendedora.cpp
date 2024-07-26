#include <bits/stdc++.h>
using namespace std;
#define  endl '\n' 

vector<int> supportedCurrencies (){
    vector<int> coins;

    coins.push_back(200);
    coins.push_back(100);
    coins.push_back(50);
    coins.push_back(10);
    coins.push_back(5);

    return coins;
}

map<int, pair<string, int>> products(){
    map<int, pair<string, int>> products_;

    products_[1] = {"Gaseosa Coca Cola", 200}; 
    products_[2] = {"Gaseosa Inka Cola", 175}; 
    products_[3] = {"Gaseosa Fanta", 155}; 
    products_[4] = {"Gaseosa Kola Real", 125}; 
    products_[5] = {"Gaseosa Sprite", 105}; 

    products_[6] = {"Snack Cuates", 90}; 
    products_[7] = {"Snack Chisitos", 65}; 
    products_[8] = {"Snack Papas Lays", 45}; 
    products_[9] = {"Snack Doritos", 20}; 
    products_[10] = {"Snack Cheese Tris", 35};

    products_[11] = {"Galleta Oreo", 10 }; 
    products_[12] = {"Galleta Casino", 5}; 
    products_[13] = {"Galleta de Animales", 15}; 
    products_[14] = {"Galleta de Chocolate", 15}; 
    products_[15] = {"Galleta Soda", 5};

    return products_;
}

void menu (int& option, map<int, pair<string, int>> products_){

    cout << "______ Machine Of Products ______ " << endl;
    for (map<int, pair<string, int>>::iterator it = products_.begin(); it != products_.end(); it++) {
        cout << "[" << it->first << ": " << it->second.first << " $" << it->second.second << "]" << endl;
    }

    cout << endl << "[0]: Exit" << endl;
    cout << endl << endl;
    cout << "OPTION: "; cin >> option;
}


vector<int> changeCoins(int value, vector<int> change, int index, vector<int> supportedCurrencies_){
    if (value == 0) {
        return change;
    }

    if (supportedCurrencies_[index] <= value) {
        change.push_back(supportedCurrencies_[index]);
        return changeCoins((value - supportedCurrencies_[index]), change, index, supportedCurrencies_);
    }
    else {
        index++;
        return changeCoins(value, change, index, supportedCurrencies_);
    }

}

vector<int> changeCoins(int value){
    vector<int> change; 
    return changeCoins(value, change, 0, supportedCurrencies());
}

bool verifyCoins(int coin){
    if (coin == 0) { return true; }

    bool isValid = false;

    for(int e: supportedCurrencies()){
        if (coin == e) {
            isValid = true; break;
        }
    }

    return isValid;
}

bool validateProducts(int option){
    if (!(option >= 1 && option <= 15)) {
        return false;
    }

    return true;
}

bool validateSentCoins(vector<int> coinsUser, int option){
    int amount = 0;

    for (auto e: coinsUser){
        amount += e;
    }

    if (amount < products()[option].second){
        return false;
    }

    return true;
}

int amount (vector<int> coinsUser){
    int total = 0;

    for (auto e: coinsUser){
        total += e;
    }

    return total;
}

pair<vector<int>, string> valueUser(vector<int> coinsUser, int option){
    if (validateSentCoins(coinsUser, option)){

        int priceProduct = products()[option].second;
        vector<int> change = changeCoins(amount(coinsUser) - priceProduct);

        if (change.size() == 0) {
            vector<int> voidVector;
            return {voidVector, products()[option].first};
        }

        return {change, products()[option].first};
    }

    return {coinsUser, ""};
}

void UI(){
    int option = -1, value = 0, change = 0;
    char answer;
    vector<int> coinsUser;

    while (option != 0){
        system("cls");
        menu(option, products());
        if (option == 0) { break; }
        if (!validateProducts(option)) {
            cout << "The option is incorrect. There is no product with that number :(" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            continue;
        }
        
        cout << "IMPORTANT! Enter [0] if you want to send." << endl;
        cout << "=> You can send coins of $5, $10, $50, $100 and $200 cents" << endl << endl;

        while (true) {
            cout << "Enter the coin: "; cin >> value;

             if(value == 0) {
                cout << "You sent this: [ ";
                for (int e: coinsUser) {
                    cout << e << " ";
                }
                cout << " ]" << endl << endl; 

                break;
            }

            if (!verifyCoins(value)) {
               cout << "The coin is not supported :(" << endl;     
               std::this_thread::sleep_for(std::chrono::seconds(2));
               cout << endl; continue;
            }

            coinsUser.push_back(value);
        }


        pair<vector<int>, string> valueUser_ = valueUser(coinsUser, option);

        if (valueUser_.second.length() == 0){
            cout << "Insufficient  coins :(" << endl;
            cout << endl << "You want to continue? [yes: y; No: n]: "; cin >> answer;
            if (tolower(answer) == 'n') {
                break;
            }
            continue;
        }

        cout << "Enjoy your " << valueUser_.second << " :)" << endl;
        cout << "Your change is: $" << (amount(coinsUser) - (products()[option].second))  << " => [";
        for(auto e: valueUser_.first){
            cout << e << "  ";
        }
        cout << "]" << endl;

        cout << endl << "You want to continue? [yes: y; No: n]: "; cin >> answer;
        if (tolower(answer) == 'n') {
            break;
        }

        coinsUser.clear();
    }   

}

int main (){
    system("cls");
    UI();

    cout << "\n\n";
    return 0;
}