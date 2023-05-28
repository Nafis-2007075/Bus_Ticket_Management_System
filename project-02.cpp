#include<bits/stdc++.h>
using namespace std;

class bus_ticket
{
    int nid;
    int price;
    float vat;
    string name,from,to;
    //string _name;
    public:
    void menu();
    void administrator();
    void customer();
    void add();
    void edit();
    void remv();
    void list();
    void receipt();
};

void bus_ticket :: menu()
{
    m:
    int choice;
    string email,password;

    cout<<"\t\t\t\t ------------------------------------------"<<endl;
    cout<<"\t\t\t\t|                                          |"<<endl;
    cout<<"\t\t\t\t|         Welcome to BD Bus counter        |"<<endl;
    cout<<"\t\t\t\t|                                          |"<<endl;
    cout<<"\t\t\t\t ------------------------------------------ "<<endl;
    cout<<"If you are from Administrator then press 1"<<endl;
    cout<<"If you are from coustomer then press 2"<<endl;
    cout<<"If you wnat to exit then press 3"<<endl;
    cout<<"Please select any option :"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please log in "<<endl;
            cout<<"\t\t\t Please enter email : "<<endl;
            cin>>email;
            cout<<"\t\t\t Please enter password : "<<endl;
            cin>>password;
            if(email=="xyz@gmail.com" && password=="*****")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid email/password"<<endl;
            }
            break;
        case 2:
            customer();
            break;;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Please enter a vail number"<<endl;
            break;
        goto m;
    }
}

void bus_ticket :: administrator()
{
    m:
    int choice;
    cout<<"\t\t\t\t ------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t|                                                      | "<<endl;
    cout<<"\t\t\t\t|          Welcome to Administrator Interface          |"<<endl;
    cout<<"\t\t\t\t|                                                      |"<<endl;
    cout<<"\t\t\t\t ------------------------------------------------------"<<endl;
    cout<<"If you want to buy another ticket then press 1"<<endl;
    cout<<"If you want to modify ticket then press 2"<<endl;
    cout<<"If you want to cancel ticket then press 3"<<endl;
    cout<<"If you want to return back to main menu then press 4"<<endl;
    cout<<"Please enter your choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
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
            cout<<"Invalid Choice"<<endl;
    }
    goto m;
} 


void bus_ticket :: customer()
{
    m:
    int choice;
    cout<<"\t\t\t\t ------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t|                                                      | "<<endl;
    cout<<"\t\t\t\t|           Welcome to Customer Interface              |"<<endl;
    cout<<"\t\t\t\t|                                                      |"<<endl;
    cout<<"\t\t\t\t ------------------------------------------------------"<<endl;
    cout<<"If you want to buy ticket then enter 1"<<endl;
    cout<<"If you want to Go back then enter 2"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
             menu();
             break;
        default:
            cout<<"Invalid number"<<endl;
    }
    goto m;
}

void bus_ticket :: add()
{
    m:
    fstream data;
    int n,token=0,p;
    float v;
    string x,y,z;
    cout<<"Booking another ticket "<<endl;
    cout<<"Please enter your NID : "<<endl;
    cin>>nid;
    cout<<"Please enter train name :"<<endl;
    cin>>name;
    cout<<"Please enter your location :"<<endl;
    cin>>from;
    cout<<"Please enter where you what to go :"<<endl;
    cin>>to;
    cout<<"Your cost is :"<<endl;
    cin>>price;
    cout<<"Vat and tax are :"<<endl;
    cin>>vat;
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<nid<<" "<<name<<" "<<from<<" "<<to<<" "<<price<<" "<<vat<<" "<<endl;
        data.close();
    }
    else
    {
        data>>n>>x>>y>>z>>p>>v;
        while(!data.eof())
        {
            if(n==nid)
            {
                token++;
            }
            data>>n>>x>>y>>z>>p>>v;
        }
        data.close();
        if(token==1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt",ios::app|ios::out);
            {
                data<<" "<<nid<<" "<<name<<" "<<from<<" "<<to<<" "<<price<<" "<<vat<<" "<<endl;
            }
        data.close();   
        }
    }
    cout<<"Ticket booked"<<endl;
}

void bus_ticket :: edit()
{
    fstream data,data1;
    int n,token=0,p,c;
    float v;
    string x,y,z;
    cout<<"Edit ticket"<<endl;
    cout<<"Please enter your NId"<<endl;
    cin>>n;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File does not exist "<<endl;
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data1>>nid>>name>>from>>to>>price>>vat;
        while(!data1.eof())
        {
            if(n==nid)
            {
                cout<<"Enter new NID : "<<endl;
                cin>>c;
                cout<<"Enter train name : "<<endl;
                cin>>x;
                cout<<"Enter your location : "<<endl;
                cin>>y;
                cout<<"Enter your destinaton : "<<endl;
                cin>>z;
                cout<<"Your new cost is : "<<endl;
                cin>>p;
                cout<<"Tax and vat is : "<<endl;
                cin>>v;
                data1<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<" "<<p<<" "<<v<<endl;
                cout<<"Edit of ticket is successfully done "<<endl;
                token++;
            }
            else
            {
                data1<<" "<<nid<<" "<<name<<" "<<from<<" "<<to<<" "<<price<<" "<<vat<<" "<<endl;
            }
            data>>nid>>name>>from>>to>>price>>vat;
        }
        data.close();
        data1.close();
    }
    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token==0)
    {
        cout<<"Unble to edit ticket"<<endl;
    }
}

void bus_ticket :: remv()
{
    fstream data,data1;
    int n,token=0;
    cout<<"Cancel ticket"<<endl;
    cout<<"Enter NID : "<<endl;
    cin>>n;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File does not exists"<<endl;
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>nid>>name>>from>>to>>price>>vat;
        while(!data.eof())
        {
            if(n==nid)
            {
                cout<<"Delete successfully"<<endl;
                token++;
            }
            else
            {
                data1<<" "<<nid<<" "<<name<<" "<<from<<" "<<to<<" "<<price<<" "<<vat<<endl;
            }
            data>>nid>>name>>from>>to>>price>>vat;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"Record not found"<<endl;
        }
    }
}


void bus_ticket :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"Here is your booking information : "<<endl;
    data>>nid>>name>>from>>to>>price>>vat;
    while(!data.eof())
    {
        cout<<nid<<"\t\t"<<name<<"\t\t"<<from<<"\t\t"<<to<<"\t\t"<<price<<"\t\t"<<vat<<endl;
        data>>nid>>name>>from>>to>>price>>vat;
    }
    data.close();
}

void bus_ticket :: receipt()
{
    fstream data;
    int code[100];
    int quantity[100];
    char choice;
    int c=0;
    float amount=0;
    float vat=0;
    float total=0;
    cout<<"Your total bill is processing "<<endl;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"sorry , no data found !"<<endl;
    }
    else
    {
        data.close();
        list();
        cout<<"\n---------------------------------------------\n";
        cout<<"                Place the order                "<<endl;
        cout<<"\n---------------------------------------------\n";

        do
        {
            m:
            cout<<"Enter your NID number :"<<endl;
            cin>>code[c];
            cout<<"Enter how much ticket do you want to buy :"<<endl;
            cin>>quantity[c];
            for(int i=0 ; i<c ; i++)
            {
                if(code[c]==code[i])
                {
                    cout<<"Duplicate product code . Please try again"<<endl;
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to buy another ticket : "<<endl;
            cin>>choice;
        }
        while(choice=='y');
        cout<<"";
        for(int i=0 ; i<c ; i++)
        {
            data.open("database.txt",ios :: in);
            data>>nid>>name>>from>>to>>price>>vat;
            while(!data.eof())
            {
                if(nid==code[i])
                {
                    amount=price*quantity[i];
                    vat=amount+(amount*vat/100);
                    total=total+vat;
                    cout<<"\n"<<nid<<"\t\t"<<name<<"\t\t"<<from<<"\t\t"<<to<<"\t\t"<<price<<"\t\t"<<vat<<endl;
                }
                data>>nid>>name>>from>>to>>price>>vat;
            }
        }
        data.close();
    }
    cout<<"------------------------x--------------------"<<endl;
    cout<<"Your total amount is"<<total<<"              "<<endl;
    cout<<"------------------------x--------------------"<<endl;
}

int main()
{
    bus_ticket b;
    b.menu();
}