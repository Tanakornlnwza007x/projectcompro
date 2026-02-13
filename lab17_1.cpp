#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

//================= โครงสร้างข้อมูลต่อโต๊ะ =================
struct TableOrder {
    vector<string> List;   // เปลี่ยนเป็น vector
    vector<int> Price;    // เปลี่ยนเป็น vector
    vector<int> Amount;   // เปลี่ยนเป็น vector
    int count = 0;
    int total = 0;
};

//TableOrder tables[6];  <-- อันนี้คือเวอร์ชันเก่านะ   
vector<TableOrder> tables(6); // โต๊ะ 1-5 ใช้จริง

//================= Global variables =================
string food;
int Num;
int table = 0;
int price[6];
int menu;
int more;
int amount;
int check;

vector<int> useTable(6, 0);

//================= prototypes =================
void home();
void employ();
void menuu();
void customer();
int moree();
void selectTable();
void showBill();
void Host();
void summarize();
void checktable();
void checkfood();
void backtohome();

//====================================================

void home() {
    cout << "\n============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|          >>> RESTAURANT MANAGEMENT SYSTEM <<<            |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|   (1) CUSTOMER                                           |" << endl;
    cout << "|   (2) EMPLOYEE                                           |" << endl;
    cout << "|   (3) HOST / ADMIN                                       |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|   (0) EXIT                                               |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;
    cout << "SELECT OPTION >> ";
    cin >> Num;
}

void backtohome() {
    cout << endl;
    cout << ">>> [0] BACK TO HOME <<<" << endl;
    cout << ">>> [9] CHANGE TABLE <<< " << endl;
    cout << "SELECT OPTION >> " << endl;
}

void customer() {
    while (true) {
        if (table == 0) {
            selectTable();
            if (table == 0) return;
        }
        cout << endl << endl << endl;
        cout << "========================================" << endl;
        cout << "            ORDER CATEGORIES            " << endl;
        cout << "========================================" << endl;
        cout << "[1] RECOMMENDED MENU " << endl;
        cout << "[2] MAIN COURSES" << endl;
        cout << "[3] BEVERAGES" << endl;
        cout << "[4] DESSERTS" << endl;
        cout << "----------------------------------------" << endl;
        cout << "[0] HOME     |   [9] CHANGE TABLE " << endl;
        cout << "----------------------------------------" << endl;
        cout << "SELECT MENU >> ";

        cin >> menu;
        if (menu == 0) return;
        if (menu == 9) {
            selectTable();
            continue;
        }


        menuu();

        cout << "AMOUNT >>  ";
        cin >> amount;

        if (menu >= 1 && menu <= 4) {
            // ใช้ push_back เพื่อเพิ่มข้อมูลลงใน vector
            tables[table].List.push_back(food);
            tables[table].Price.push_back(price[menu]);
            tables[table].Amount.push_back(amount);

            tables[table].total += price[menu] * amount;

            cout << endl;
            cout << ">> ADDED : " << food << " x" << amount
                << " - " << price[menu] * amount << " BAHT <<" << endl;
            cout << endl;
            tables[table].count++;
        }
        else {
            cout << "INVALID MENU!!" << endl;
        }

        int result = moree();
        if (result == 0) return;
    }
}

void selectTable() {
    cout << endl << endl;
    cout << "================== SELECT TABLE ==================" << endl;
    cout << "  (1) TABLE 1" << endl;
    cout << "  (2) TABLE 2" << endl;
    cout << "  (3) TABLE 3" << endl;
    cout << "  (4) TABLE 4" << endl;
    cout << "  (5) TABLE 5" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << " [0] BACK TO HOME " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "CHOOSE YOUR TABLE >> ";
    cin >> table;

    if (table >= 1 && table <= 5) {
        useTable[table]++;
    }
}


void menuu() {
    int item, size;
    if (menu == 1) {
        cout << endl << endl << endl;
        cout << "==================== RECOMMENDED ====================" << endl;
        cout << " 1) SPICY TOM YUM GOONG SOUP WITH RICE   80/85 BTH" << endl;
        cout << " 2) MANGO STICKY RICE                    50/55 BTH" << endl;
        cout << " 3) SOM TAM THAI                         50/60 BTH" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "SELECT MENU >> "; cin >> item;

        if (item == 1) {
            food = "TOM YUM GOONG";
            cout << "SELECT SIZE (1) NORMAL 80 / (2) EXTRA 85 >> ";
            cin >> size;

            if (size == 1) {
                price[menu] = 80;
            }
            else {
                price[menu] = 85;
            }
        }
        else if (item == 2) {
            food = "MANGO STICKY RICE";
            cout << "SELECT SIZE (1) NORMAL 50 / (2) EXTRA 55 >> ";
            cin >> size;
            if (size == 1) {
                price[menu] = 50;
            }
            else {
                price[menu] = 55;
            }
        }
        else if (item == 3) {
            food = "SOM TAM THAI";
            cout << "SELECT SIZE (1) NORMAL 50 / (2) EXTRA 60 >> ";
            cin >> size;
            if (size == 1) {
                price[menu] = 50;
            }
            else {
                price[menu] = 60;
            }
        }
    }
    else if (menu == 2) {
        cout << endl << endl << endl;
        cout << "========== MAIN COURSES ==========" << endl;
        cout << " 1) FRIED PORK RICE      30/35 BTH" << endl;
        cout << " 2) FRIED CHICKEN RICE   30/35 BTH" << endl;
        cout << "----------------------------------" << endl;
        cout << "SELECT MENU >> "; cin >> item;
        if (item == 1) {
            food = "FRIED PORK RICE";
            cout << "SELECT SIZE (1) NORMAL 30 / (2) EXTRA 35 >> ";
            cin >> size;
            if (size == 1) {
                price[menu] = 30;
            }
            else {
                price[menu] = 35;
            }
        }
        else if (item == 2) {
            food = "FRIED CHICKEN RICE";
            cout << "SELECT SIZE (1) NORMAL 30 / (2) EXTRA 35 >> ";
            cin >> size;
            if (size == 1) {
                price[menu] = 30;
            }
            else {
                price[menu] = 35;
            }
        }
    }

    else if (menu == 3) {
        cout << endl << endl << endl;
        cout << "=============== BEVERAGES ===============" << endl;
        cout << " 1) WATER                         10 BTH " << endl;
        cout << " 2) SOFT DRINK                    20 BTH " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "SELECT MENU >> ";
        cin >> item;
        if (item == 1) { food = "WATER"; price[menu] = 10; }
        else { food = "SOFT DRINK"; price[menu] = 20; }
    }
    else if (menu == 4) {
        cout << endl << endl << endl;
        cout << "================ DESSERTS ===============" << endl;
        cout << " 1) ICE CREAM                     15 BTH" << endl;
        cout << " 2) CAKE                          30 BTH" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "SELECT MENU >> "; cin >> item;
        if (item == 1) { food = "ICE CREAM"; price[menu] = 15; }
        else { food = "CAKE"; price[menu] = 30; }
    }
}

int moree() {
    while (true) {
        cout << "MORE ORDER ? (1) YES / (2) NO  " << endl;
        backtohome();
        cin >> more;
        if (more == 1) return 1;
        if (more == 2) { showBill(); return 0; }
        if (more == 0) return 0;
        if (more == 9) { selectTable(); return 1; }
        cout << "INVALID!! TRY AGAIN" << endl;
    }
}

void showBill() {
    cout << endl;
    cout << "============ BILL SUMMARY ===========" << endl;
    cout << "TABLE : " << table << endl;
    for (int i = 0; i < tables[table].count; i++) {
        cout << i + 1 << ". " << tables[table].List[i] << " x" << tables[table].Amount[i]
            << " = " << tables[table].Price[i] * tables[table].Amount[i] << " BAHT" << endl;
   
    }
    cout << "TOTAL PRICE : " << tables[table].total << " BATH" << endl;
    cout << "-------------------------------------\n\n\n" << endl;
}

void employ() {
    while (true) {
        cout << endl;
        cout << "======= TABLE STATUS =======" << endl;
        for (int i = 1; i <= 5; i++) {
            cout << "Table " << i << " : ";
            if (tables[i].count > 0) cout << "[NOT AVAILABLE]" << endl;
            else cout << "[AVAILABLE]" << endl;
        }
        cout << "Select table (0 to Exit): "; 
        cin >> check;

        if (check == 0) return;

        if (tables[check].count > 0) {
            for (int i = 0; i < tables[check].count; i++) {
                cout << tables[check].List[i] << " x" << tables[check].Amount[i] << " = "
                    << tables[check].Price[i] * tables[check].Amount[i] << endl;
            }

            cout << "Total : " << tables[check].total << endl;
            cout << "1.Clear table | 0.Back : ";

            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                // เคลียร์ข้อมูลใน vector สำหรับโต๊ะนั้นๆ
                tables[check].List.clear();
                tables[check].Price.clear();
                tables[check].Amount.clear();
                tables[check].count = 0;
                tables[check].total = 0;
                cout << ">>> CLEARED <<<" << endl;
            }
        }
        else cout << "No orders" << endl;
    }
}

void Host() {
    int choose;
    while (true) {
        cout << endl;
        cout << "--- HOST MENU ---" << endl;
        cout << "1.Summary" << endl;
        cout << "2.Table Usage" << endl;
        cout << "0.Back" << endl;
        cout << "SELECT OPTION >> ";
        cin >> choose;
        if (choose == 1) summarize();
        else if (choose == 2) checktable();
        else if (choose == 0) break;
    }
}

void summarize() {
    int grandTotal = 0;
    for (int i = 1; i <= 5; i++) grandTotal += tables[i].total;
    cout << endl;
    cout << "TOTAL REVENUE : " << grandTotal << " Baht" << endl;
}

void checktable() {
    cout << endl;
    cout << "--- TABLE USAGE STATISTICS ---" << endl;
    for (int i = 1; i <= 5; i++)
        cout << "Table " << i << " used " << useTable[i] << " times" << endl;
}

void checkfood() {}

void saveData() {
    json j;
    //j["grandTotal"] = grandTotal;

    // เก็บสถิติการใช้โต๊ะ
    for (int i = 1; i <= 5; i++) {
        j["useTable"][to_string(i)] = useTable[i];
    }

    // เก็บข้อมูลแต่ละโต๊ะ
    for (int i = 1; i <= 5; i++) {
        json tJ;
        tJ["count"] = tables[i].count;
        tJ["total"] = tables[i].total;

        json orders = json::array();
        for (int k = 0; k < tables[i].count; k++) {
            orders.push_back({
                {"item", tables[i].List[k]},
                {"price", tables[i].Price[k]},
                {"qty", tables[i].Amount[k]}
                });
        }
        tJ["orders"] = orders;
        j["tables"][to_string(i)] = tJ;
    }

    ofstream file("database.json");
    file << j.dump(4); // บันทึกแบบเว้นวรรคให้อ่านง่าย
    file.close();
}
void loadData() {
    ifstream file("database.json");
    if (!file.is_open()) return;

    json j;
    file >> j;
    file.close();

    //grandTotal = j.value("grandTotal", 0);

    for (int i = 1; i <= 5; i++) {
        useTable[i] = j["useTable"].value(to_string(i), 0);

        if (!j["tables"].contains(to_string(i))) continue;

        auto& tJson = j["tables"][to_string(i)];
        tables[i].count = tJson.value("count", 0);
        tables[i].total = tJson.value("total", 0);

        for (auto& order : tJson["orders"]) {
            tables[i].List.push_back(order.value("item", ""));
            tables[i].Price.push_back(order.value("price", 0));
            tables[i].Amount.push_back(order.value("qty", 0));
        }
    }
}

int main() {
    loadData();
    while (true) {
        home();
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Try again." << endl;
            continue;
        }
        if (Num == 0) {
            cout << endl << "Exiting program..." << endl;
            saveData();
            return 0;
        }
        if (Num == 1) { table = 0; customer(); }
        else if (Num == 2 || Num == 3) {
            string pass;
            cout << ">>>>>> LOGIN <<<<<<" << endl;
            cout << "Enter Password: ";
            cin >> pass;
            if (Num == 2 && pass == "555") employ();
            else if (Num == 3 && pass == "header") Host();
            else cout << "Wrong Password!" << endl;
        }
        else cout << "Invalid selection!" << endl;
    }
}
