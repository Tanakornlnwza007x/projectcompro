#include<iostream>
#include<string>
#include<iomanip>
//#include<windows.h>
using namespace std;

// Global variables
string food;
int Num;
int table = 0;
int price[6];
int menu;
int more;
int amount;
int check;
int Amount[50]; // เก็บจำนวนของแต่ละรายการที่สั่ง
int grandTotal = 0;

// เก็บออเดอร์โดยใช้ array
string List[50];
int orderPrice[50];
int orderCount = 0;
int totalPrice = 0;
int useTable[6] = { 0 };

// --- prototypes ---
void home();
void backtohome();


//ลูกค้า
void customer();
int moree();
void selectTable();
void showBill();


//พนักงาน
void employ();
void menuu();

//หัวหน้า
void Host();
void summarize();
void checktable();
void checkfood();
void printbill();


// --- Functions ---

void home() {
    cout << "\n";
    cout << "============================================================\n";
    cout << "||                                                        ||\n";
    cout << "||          >>> RESTAURANT MANAGEMENT SYSTEM <<<          ||\n";
    cout << "||                                                        ||\n";
    cout << "============================================================\n";
    cout << "||                                                        ||\n";
    cout << "||   (1) CUSTOMER                                         ||\n";
    cout << "||   (2) EMPLOYEE                                         ||\n";
    cout << "||   (3) HOST / ADMIN                                     ||\n";
    cout << "||                                                        ||\n";
    cout << "||   (0) EXIT                                             ||\n";
    cout << "||                                                        ||\n";
    cout << "============================================================\n";
    cout << "\nSELECT OPTION >> ";
    cin >> Num;
}

void backtohome() {
    cout << "\n";
    cout << ">>> [0] Back to Home <<<\n";
    cout << ">>> [9] Change Table <<< ";
    cout << "\nSELECT OPTION >> ";
}



void customer() {
    while (true) {

        if (table == 0) {
            selectTable();
            if (table == 0) return; // ← ป้องกันเข้าเมนูอาหารโดยไม่เลือกโต๊ะ
        }
        cout << "\n";
        cout << "============================================================\n";
        cout << "||                          MENU                          ||\n";
        cout << "============================================================\n";
        cout << "||                                                        ||\n";
        cout << "||         (1) Recommended        (2) Rice Dishes         ||\n";
        cout << "||         (3) Beverages          (4) Desserts            ||\n";
        cout << "||                                                        ||\n";
        cout << "============================================================\n";
        cout << "SELECT MENU >> ";
        cin >> menu;
        menuu();

        if (menu == 0) return;

        if (menu == 9) {
            selectTable();        // เลือกโต๊ะใหม่
            continue;            // กลับไปที่ customer() ใหม่;
        }

        cout << "Amount : ";
        cin >> amount;

        if (menu >= 1 && menu <= 5) {
            List[orderCount] = food;
            orderPrice[orderCount] = price[menu];
            Amount[orderCount] = amount;   // บันทึกจำนวนของรายการนี้

            totalPrice += (price[menu] * Amount[orderCount]); // คำนวณราคารวมโดยคูณกับจำนวน ที่สั่ง
            cout << " " << endl;
            cout << ">> Added : " << food << " - " << price[menu] << " Baht" << " <<" << endl;
            cout << " " << endl;
            orderCount++;
        }
        else {
            cout << "Invalid menu!" << endl;
        }

        if (menu == 0) return;

        if (menu == 9) {           // ★ เพิ่ม
            selectTable();        // เลือกโต๊ะใหม่
            continue;            // กลับไปที่ customer() ใหม่;
        }

        int result = moree();
        if (result == 0) return; // กลับไป main
    }
}



void selectTable() {
    cout << "\n";
    cout << "============================================================\n";
    cout << "||                          TABLE                         ||\n";
    cout << "============================================================\n";
    cout << "||                                                        ||\n";
    cout << "||             (1) Table 1        (2) Table 2             ||\n";
    cout << "||             (3) Table 3        (4) Table 4             ||\n";
    cout << "||                      (5) Table 5                       ||\n";
    cout << "||                                                        ||\n";
    cout << "============================================================\n";
    cout << "||   (0) Back to Home                                     ||\n";
    cout << "============================================================\n";
    cout << "CHOOSE YOUR TABLE >> ";
    cin >> table;



    if (table >= 1 && table <= 5) {
        useTable[table]++; //เก็บสถิติว่าโต๊ะนี้ถูกใช้งาน 1 ครั้ง
    }
}


void menuu() {
    int size;
    int item;
    if (menu == 0) {
        return;
    }
    else if (menu == 1) {
        cout << "\n";
        cout << "====================================================\n";
        cout << "||               RECOMMENDED MENU                 ||\n";
        cout << "====================================================\n";
        cout << "||                                                ||\n";
        cout << "||   (1) Crispy Pork Basil Rice     60 / 65 THB   ||\n";
        cout << "||   (2) Omelette Rice              50 / 55 THB   ||\n";
        cout << "||   (3) Fried Rice with Pork       55 / 60 THB   ||\n";
        cout << "||                                                ||\n";
        cout << "====================================================\n";
        cout << "\nSELECT MENU >> ";

        cin >> item;
        if (item == 1) {
            cout << "size : 1.normal 60 / 2.extra 65 " << endl;
            cout << "Select size : "; cin >> size;
            food = "Crispy Pork Basil Rice";
            if (size == 1) price[menu] = 60;
            else price[menu] = 65;
            backtohome();
        }
        if (item == 2) {
            cout << "size : 1.normal 50 / 2.extra 55 " << endl;
            cout << "Select size : "; cin >> size;
            food = "Omelette Rice";
            if (size == 1) price[menu] = 50;
            else price[menu] = 55;
            backtohome();
        }
        if (item == 3) {
            cout << "size : 1.normal 55 / 2.extra 60 " << endl;
            cout << "Select size : "; cin >> size;
            food = "Fried Rice with Pork";
            if (size == 1) price[menu] = 55;
            else price[menu] = 60;
            backtohome();
        }

    }
    else if (menu == 2) {
        cout << "\n";
        cout << "====================================================\n";
        cout << "||                   Rice Dishes                  ||\n";
        cout << "====================================================\n";
        cout << "||                                                ||\n";
        cout << "||   (1) Pork Rice                  30 / 35 THB   ||\n";
        cout << "||   (2) Chicken Rice               30 / 35 THB   ||\n";
        cout << "||   (3) Fried Fish Rice            45 / 50 THB   ||\n";
        cout << "||                                                ||\n";
        cout << "====================================================\n";
        cout << "\nSELECT MENU >> ";
        cin >> item;
        if (item == 1) {
            cout << "size : 1.normal 30 / 2.extra 35 " << endl;
            cout << "Select size : "; cin >> size;
            food = "Pork Rice";
            if (size == 1) price[menu] = 30;
            else price[menu] = 35;
            backtohome();
        }
        if (item == 2) {
            cout << "size : 1.normal 30 / 2.extra 35 " << endl;
            cout << "Select size : "; cin >> size;
            food = "Chicken Rice";
            if (size == 1) price[menu] = 30;
            else price[menu] = 35;
            backtohome();
        }
        if (item == 3) {
            cout << "size : 1.normal 45 / 2.extra 50 " << endl;
            cout << "Select size : "; cin >> size;
            food = "Fried Fish Rice";
            if (size == 1) price[menu] = 45;
            else price[menu] = 50;
            backtohome();
        }

    }
    else if (menu == 3) {
        cout << "\n";
        cout << "====================================================\n";
        cout << "||                    Beverages                   ||\n";
        cout << "====================================================\n";
        cout << "||                                                ||\n";
        cout << "||   (1) Water                       10 THB       ||\n";
        cout << "||   (2) Soft Drink              30 / 35 THB   ||\n";
        cout << "||   (3) Fried Fish Rice            45 / 50 THB   ||\n";
        cout << "||                                                ||\n";
        cout << "====================================================\n";
        cout << "\nSELECT MENU >> ";
        food = "Wagyu A5"; price[menu] = 990;
    }
    else if (menu == 4) { food = "Salmon Sashimi"; price[menu] = 150; }
    else if (menu == 5) { food = "Tom Yum Kung"; price[menu] = 99; }
    else {
        cout << "Invalid menu!" << endl;
        return;
    }
}



int moree() {
    while (true) {
        cout << "More order? (1) yes / (2) no  " << endl;
        backtohome();
        cout << ": "; cin >> more;

        if (more == 1) {
            return 1; // กลับไป main → main เรียก customer() ใหม่เอง
        }
        else if (more == 2) {
            showBill();
            return 0;
        }
        else if (more == 0) {
            return 0; // กลับไป main
        }
        else if (more == 9) {
            selectTable();        // เลือกโต๊ะใหม่
            return 1;            // กลับไปที่ customer() ใหม่;
        }
        else {
            cout << "Invalid!! please choose again" << endl;
        }
    }
}



void showBill() {
    cout << "\n----------- BILL SUMMARY -----------" << endl;
    cout << "Table : " << table << endl;
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". " << List[i] << " * " << Amount[i] << " - " << orderPrice[i] * Amount[i] << " Baht" << endl;
    }
    cout << "Total Price : " << totalPrice << " Baht" << endl;
    cout << "------------------------------------\n";
}




//พนักงาน
void employ() {
    cout << "\n-----------------EMPLOYEE-----------------" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "infomation Table : " << i << endl;
    }
    cout << "Select : "; cin >> check;

    /*/ cout << "Last Order Summary" << endl;
     if (table == 0) cout << "Table : " << "free" << endl;
     else cout << "Table : " << table << endl;

     if (orderCount == 0) {
         cout << "No orders yet" << endl;
     }
     else {
         for (int i = 0; i < orderCount; i++) {
             cout << i + 1 << ". " << List[i] << "*" << amount << " - " << orderPrice[i] << " Baht" << endl;
         }
         cout << "Total price : " << totalPrice << " Baht" << endl;
     }
 } */

}


//หัวหน้า
//underconstruction >> FUNCTION OF HOST <<
void summarize() {
    cout << "\n===========================================" << endl;
    cout << "           DAILY BUSINESS SUMMARY          " << endl;
    cout << "===========================================" << endl;

    // 1. รายงานการใช้โต๊ะ
    checktable();
    cout << "-------------------------------------------" << endl;

    // 2. รายงานเมนูที่ขายได้
    checkfood();
    cout << "-------------------------------------------" << endl;

    // 3. สรุปรายได้รวมทั้งหมด
    cout << " >> TOTAL REVENUE TODAY : " << grandTotal << " Baht <<" << endl;
    cout << "===========================================\n" << endl;
}

void checktable() {
    cout << "\n======= TABLE USAGE SUMMARY =======" << endl;
    cout << setw(10) << "      Table No." << setw(20) << "      Times Used" << endl;
    cout << "-----------------------------------" << endl;

    int totalTable = 0;
    for (int i = 1; i <= 5; i++) {
        cout << setw(10) << i << setw(17) << useTable[i] << " times" << endl;
        totalTable += useTable[i];
    }

    cout << "-----------------------------------" << endl;
    cout << "Total Table used: " << totalTable << " times" << endl;
}

void checkfood() {
    cout << "---$$$ Today's menu $$$---" << endl;
    if (orderCount == 0) {
        cout << "No orders yet";
    }
    else {
        for (int i = 0; i < orderCount; i++)  cout << List[i] << " - " << orderPrice[i] << endl;
    }


}
void printbill() {
    cout << "-------------------------------" << endl;
    cout << "          benefits             " << endl;
    cout << "          " << "table : " << table << "             " << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu" << " " << setw(15) << "Qty" << setw(15) << " " << "Total price" << endl;
    for (int i = 0; i < orderCount; i++) {
        cout << List[i] << " " << setw(15) << Amount[i] << " " << setw(15) << orderPrice[i] << endl;
    }

}
void Host() {
    int choose;
    while (true) {
        cout << "\n--- HOST MENU ---" << endl;
        cout << "1.Summary sale" << endl;
        cout << "2.Check amount use table" << endl;
        cout << "3.Check amount food sale" << endl;
        cout << "4.Printbill" << endl;
        cout << "0.Back to Home" << endl;
        cout << "Choose : ";
        cin >> choose;

        if (choose == 1) summarize();
        else if (choose == 2) checktable();
        else if (choose == 3) checkfood();
        else if (choose == 4) printbill();
        else if (choose == 0) break;
        else cout << "Invalid!! please choose again" << endl;
    }
}

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    while (true) {
        home();

        if (Num == 0) {
            cout << endl;
            cout << endl;
            cout << "++++++++=======================+++++++++" << endl;
            cout << "|            Exiting program           |" << endl;
            cout << "++++++++=======================+++++++++" << endl;
            break;
        }
        else if (Num == 1) {
            table = 0; // reset table when new customer
            customer();
        }
        else if (Num == 2) {
            string password;
            cout << ">>>>>> LOGIN : EMPLOYEE <<<<<<" << endl;
            while (true) {
                cout << "password : ";
                cin >> password;
                if (password == "555") {
                    employ();
                    break;
                }
                else {
                    cout << "______wrong password!!!______" << endl;
                }
            }
        }
        else if (Num == 3) {
            string password;
            cout << ">>>>>> LOGIN : HOST <<<<<<" << endl;
            while (true) {
                cout << "password : ";
                cin >> password;
                if (password == "header") {
                    Host();
                    break;
                }
                else {
                    cout << "______wrong password!!!______" << endl;
                }
            }
        }
        else {
            cout << " Invalid selection! Try again." << endl;
        }
    }
    return 0;
}
