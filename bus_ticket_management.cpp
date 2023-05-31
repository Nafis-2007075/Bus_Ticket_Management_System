#include <bits/stdc++.h>
using namespace std;

class Ticket {
protected:
    int nid;
    int price;
    float vat;
    string name, from, to;

public:
    virtual void menu() = 0;
    virtual void add() = 0;
    virtual void edit() = 0;
    virtual void remv() = 0;
    virtual void receipt() = 0;
};

class BusTicket : public Ticket {
public:
    void menu()  {
        m:
        int choice;
        string email, password;

        cout << "\t\t\t\t ------------------------------------------" << endl;
        cout << "\t\t\t\t|                                          |" << endl;
        cout << "\t\t\t\t|         Welcome to BD Bus counter        |" << endl;
        cout << "\t\t\t\t|                                          |" << endl;
        cout << "\t\t\t\t ------------------------------------------ " << endl;
        cout << "If you are from Administrator then press 1" << endl;
        cout << "If you are from customer then press 2" << endl;
        cout << "If you want to exit then press 3" << endl;
        cout << "Please select any option :" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << " Please log in " << endl;
                cout << " Please enter email : " << endl;
                cin >> email;
                cout << " Please enter password : " << endl;
                cin >> password;
                if (email == "xyz@gmail.com" && password == "*****") {
                    administrator();
                } else {
                    cout << "Invalid email/password" << endl;
                }
                break;
            case 2:
                customer();
                break;
            case 3:
                exit(0);
            default:
                cout << "Please enter a valid number" << endl;
        }
        goto m;
    }

    void administrator() {
        m:
        int choice;
        cout << "\t\t\t\t ------------------------------------------------------" << endl;
        cout << "\t\t\t\t|                                                      | " << endl;
        cout << "\t\t\t\t|          Welcome to Administrator Interface          |" << endl;
        cout << "\t\t\t\t|                                                      |" << endl;
        cout << "\t\t\t\t ------------------------------------------------------" << endl;
        cout << "If you want to add ticket then press 1" << endl;
        cout << "If you want to modify ticket then press 2" << endl;
        cout << "If you want to cancel ticket then press 3" << endl;
        cout << "If you want to return back to the main menu then press 4" << endl;
        cout << "Please enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                remv();
                break;
            case 4:
                menu();
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
        goto m;
    }

    void customer() {
        m:
        int choice;
        cout << "\t\t\t\t ------------------------------------------------------" << endl;
        cout << "\t\t\t\t|                                                      | " << endl;
        cout << "\t\t\t\t|           Welcome to Customer Interface              |" << endl;
        cout << "\t\t\t\t|                                                      |" << endl;
        cout << "\t\t\t\t ------------------------------------------------------" << endl;
        cout << "If you want to buy ticket then enter 1" << endl;
        cout << "If you want to go back then enter 2" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                receipt();
                break;
            case 2:
                menu();
                break;
            default:
                cout << "Invalid number" << endl;
        }
        goto m;
    }

    void add()  {
        m:
        fstream data;
        int n, token = 0, p;
        float v;
        string x, y, z;
        cout << "Booking ticket " << endl;
        cout << "Please enter your NID : " << endl;
        cin >> nid;
        cout << "Please enter bus name :" << endl;
        cin >> name;
        cout << "Please enter your location :" << endl;
        cin >> from;
        cout << "Please enter where you want to go :" << endl;
        cin >> to;
        cout << "Your cost is :" << endl;
        cin >> price;
        cout << "Vat and tax are :" << endl;
        cin >> vat;
        data.open("database.txt", ios::in);
        if (!data) {
            data.open("database.txt", ios::app | ios::out);
            data << " " << nid << " " << name << " " << from << " " << to << " " << price << " " << vat << " " << endl;
            data.close();
        } else {
            data >> n >> x >> y >> z >> p >> v;
            while (!data.eof()) {
                if (n == nid) {
                    token++;
                }
                data >> n >> x >> y >> z >> p >> v;
            }
            data.close();
            if (token == 1) {
                goto m;
            } else {
                data.open("database.txt", ios::app | ios::out);
                data << " " << nid << " " << name << " " << from << " " << to << " " << price << " " << vat << " " << endl;
                data.close();
            }
        }
        cout << "Ticket booked" << endl;
    }

    void edit()  {
        fstream data, data1;
        int n, token = 0, p, c;
        float v;
        string x, y, z;
        cout << "Edit ticket" << endl;
        cout << "Please enter your NID" << endl;
        cin >> n;
        data.open("database.txt", ios::in);
        if (!data) {
            cout << "File does not exist " << endl;
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> nid >> name >> from >> to >> price >> vat;
            while (!data.eof()) {
                if (n == nid) {
                    cout << "Enter new NID : " << endl;
                    cin >> c;
                    cout << "Enter bus name : " << endl;
                    cin >> x;
                    cout << "Enter your location : " << endl;
                    cin >> y;
                    cout << "Enter your destination : " << endl;
                    cin >> z;
                    cout << "Your new cost is : " << endl;
                    cin >> p;
                    cout << "Tax and vat is : " << endl;
                    cin >> v;
                    data1 << " " << c << " " << x << " " << y << " " << z << " " << p << " " << v << endl;
                    cout << "Edit of ticket is successfully done " << endl;
                    token++;
                } else {
                    data1 << " " << nid << " " << name << " " << from << " " << to << " " << price << " " << vat
                          << endl;
                }
                data >> nid >> name >> from >> to >> price >> vat;
            }
            data.close();
            data1.close();
        }
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "Unable to edit ticket" << endl;
        }
    }

    void remv()  {
        fstream data, data1;
        int n, token = 0;
        cout << "Cancel ticket" << endl;
        cout << "Enter NID : " << endl;
        cin >> n;
        data.open("database.txt", ios::in);
        if (!data) {
            cout << "File does not exist" << endl;
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> nid >> name >> from >> to >> price >> vat;
            while (!data.eof()) {
                if (n == nid) {
                    cout << "Delete successfully" << endl;
                    token++;
                } else {
                    data1 << " " << nid << " " << name << " " << from << " " << to << " " << price << " " << vat
                          << endl;
                }
                data >> nid >> name >> from >> to >> price >> vat;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (token == 0) {
                cout << "Record not found" << endl;
            }
        }
    }

    void list()  {
        fstream data;
        data.open("database.txt", ios::in);
        cout << "Here is your booking information : " << endl;
        data >> nid >> name >> from >> to >> price >> vat;
        while (!data.eof()) {
            cout << nid << "\t\t" << name << "\t\t" << from << "\t\t" << to << "\t\t" << price << "\t\t" << vat
                 << endl;
            data >> nid >> name >> from >> to >> price >> vat;
        }
        data.close();
    }

    void receipt()  {
        fstream data;
        int code[100];
        int quantity[100];
        char choice;
        int c = 0;
        float amount = 0;
        float vat = 0;
        float total = 0;
        cout << "Your total bill is processing " << endl;
        data.open("database.txt", ios::in);
        if (!data) {
            cout << "Sorry, no data found!" << endl;
        } else {
            data.close();
            list();
            cout << "\n---------------------------------------------\n";
            cout << "                Place the order                " ;
            cout << "\n---------------------------------------------\n";

            do {
                m:
                cout << "Enter your NID number :" << endl;
                cin >> code[c];
                cout << "Enter how many tickets do you want to buy :" << endl;
                cin >> quantity[c];
                for (int i = 0; i < c; i++) {
                    if (code[c] == code[i]) {
                        cout << "Duplicate product code. Please try again." << endl;
                        goto m;
                    }
                }
                c++;
                cout << "Do you want to buy another ticket : " << endl;
                cin >> choice;
            } while (choice == 'y' || choice == 'Y');
            cout << "\n---------------------------------------------\n";
            cout << "                Ticket Information              " << endl;
            cout << "\n---------------------------------------------\n";
            cout << "NID\t\tBus Name\t\tFrom\t\tTo\t\tPrice\t\tVat" << endl;
            data.open("database.txt", ios::in);
            data >> nid >> name >> from >> to >> price >> vat;
            while (!data.eof()) {
                for (int i = 0; i < c; i++) {
                    if (nid == code[i]) {
                        cout << nid << "\t\t" << name << "\t\t" << from << "\t\t" << to << "\t\t" << price << "\t\t"
                             << vat << endl;
                        amount += price * quantity[i];
                        vat += vat * quantity[i];
                    }
                }
                data >> nid >> name >> from >> to >> price >> vat;
            }
            data.close();
            cout << "-----------------------------------------------" << endl;
            cout << "Total Amount: " << amount << endl;
            total = amount + vat;
            cout << "-----------------------------------------------" << endl;
            cout << "Total Payable: " << total << endl;
        }
    }
};

int main() {
    BusTicket bt;
    bt.menu();
    return 0;
}
