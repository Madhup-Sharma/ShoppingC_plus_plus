#include <iostream> // The main header file
#include <fstream> // file used for file handling operations
using namespace std;


class shopping{
    private:
    // We will have 

    int pcode; // Product code
    float price; // PRoduct Price
    float dis; // Discont offered
    string pname; // product name

    public:
    // ALL THE MEMBER FUCNTIONS ARE DECLARED HERE //

    void menu(); // The listing of the prodcuts will be done here
    void administrator();  // The product page owner
    void buyer();   // Buyer identification
    void add();     // Adding new items to the cart
    void rem(); // Removingof the product
    void edit();    // Editing the number of the products
    void list();   // Helps in list the product on the page 
    void receipt(); // Genrate the bil



};


// using the operator to define the functions;

void shopping :: menu(){
    l:   // label  placed here
    int choice;
    string email;
    string password;



    cout << "\t\t\t\t _____________________"<< endl;
    cout << "\t\t\t\t|                     |"<< endl;
    cout << "\t\t\t\t|    Shopping Menu    |"<< endl;  
    cout << "\t\t\t\t|                     |"<< endl;
    cout << "\t\t\t\t|_____________________|"<< endl;

    cout << "\t\t\t\t_______________________"<< endl;
    cout << "\t\t\t\t|1. Administrator     |"<< endl;
    cout << "\t\t\t\t|2. Buyer             |"<< endl;
    cout << "\t\t\t\t|3. Exit              |"<< endl;
    cout << "\t\t\t\t|_____________________|"<< endl;

    cout << "\t\t\t\t Please Select your choice:  " << endl;


    cin >> choice;


    switch(choice){


        case 1:
            cout << "\t\t\t Please Login" << endl;
            cout << "\t\t\t Enter Email: " << endl;
            cin >> email;
            cout << "\t\t\t Enter Password: " << endl;
            cin >> password;

            if(email == "terenaam@salman" && password == "julie" ){
                administrator();
            }else{
                cout << "\t\t\t Invalid User 🤣 " << endl;
            }

            break;

        case 2:
            {
                buyer();
            }

        case 3: 
            {
                exit(0);
            } 

            default:
            {
                cout << "Please Select from the given options" << endl;
            }



    }goto l;
}

void shopping::administrator(){
    l:
    int choice;

    cout << "\n\n\n\t\t\t Administrator Menu";
    cout << "\n\t\t\t|_____1) Add the Product______|";
    cout << "\n\t\t\t|_____2) Modify the Product___|";
    cout << "\n\t\t\t|_____3) Delete the Product___|";
    cout << "\n\t\t\t|_____4) Return to main menu__|";

    cout << "\n\n\t Please Enter your choice ";
    cin >> choice;



    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        
        default:
            cout<< "Invalid Choice" << endl;


    }goto l;
}



void shopping:: buyer(){
    l:
    int choice;
    cout << "\t\t\t       BUYER   \n";
    cout <<"\t\t\t _____________________" << endl;
    cout << "                           " << endl;
    cout << "\t\t\t 1) Buy  Product     " << endl;
    cout << "                           " << endl;
    cout << "\t\t\t 2) Go Back          " << endl;
    cout <<"\t\t\t _____________________" << endl;


    cin >> choice;

    switch(choice){
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;

        default:
            cout << "Invalid Choice" << endl;

    
    }goto l;

 
}


void shopping :: add(){

    l:
    fstream data;
    int c;
    int token = 0;

    float p;
    float d;
    string n;


    cout << "\n\n\t\t\t  Add New Product" ;
    cout << "\n\n\t  Product code of the product ";
    cin>> pcode;
    cout << "\n\n\t  Name of the Product";
    cin >> pname;
    cout << "\n\n\t  Price of the Product";
    cin >> price;

    cout << "\n\n\t  Discount on the product";

    cin>>dis;




    // Now a databsse file should open to give the results

    data.open("database.txt", ios::in);         // IOS :: in (Opens the file in reading mode)
                                                // IOS :: out (Opens the file in writing mode)
    // If the file doesn't exist
    if(!data){
                                // ios :: app === Append  mode opening the file
        data.open("database.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();


    }else{
        data >> c >> n >> p >> d;     // Reading from the file (Indexes)
        while(!data.eof()){        // eof means end of file function
            if(c == pcode){  // Checking the duplication of the code
                token++;

            }
            data >> c >> n >> p >> d;

        }

        data.close();

        if(token == 1){
            goto l;
        }else{
            data.open("database.txt", ios::app|ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }

        cout << "\n\n\t\t  Record Inserted" << endl;


    }

}

void shopping :: edit(){
    fstream data, data1;

    int pkey;
    int token =0;
    int c;
    float p;
    float d;
    string n;
    

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product Code: ";

    if(!data){
        cout << "\n\n File doesn't exist...";

    }

    else{
        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<< "\n\t\t New Product Code: ";
                cin >> c;

                cout<< "\n\t\t Name of the Product: ";
                cin >> n;

                

                cout<< "\n\t\t Price: ";
                cin >> p; 
                cout << "\n\t\t Discount: ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record Editied ";
                token++;


            }else{
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
        data>>pcode>>pname>>price>>dis;


        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("databas1.txt", "database.txt");
        if(token == 1){
            cout << "\n\n  Record Not found! ";

        }
    }

}


void shopping :: rem(){

    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\n\n\t Delete Product ";
    cout << "\n\n\t Product Code";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout << "File doesn't found" << endl;

    }

    else{

        data1.open("database1.txt", ios::app| ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof()){


            if(pcode == pkey){

                cout << "\n\n\t Product Deleted Succesfully";
                token++;
            }

            else{
                data1 << " " << pcode << " " << pname<< " "  << price << " " << dis;

            } 
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");


        if(token == 0){
            cout << "\n\n Record Not Found ! ";

        }
    }

}   

void shopping :: list(){

    fstream data;
    data.open("database.txt",  ios::in);
    cout << "\n\n_____________________________________________\n";
    cout << "Pro. Num. \t\t P. Name \t\t Price \n";
    cout << "\n\n_____________________________________________\n";
    data>>pcode>>pname>>price>>dis;

    while(!data.eof()){
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}


void shopping:: receipt(){
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;

    int count = 0 ;
    float dis  = 0;
    float total = 0;


    cout << "\n\n\t\t\t\t  RECEIPT";
    data.open("database.txt", ios::in);

    if(!data){
        cout << "\n\n Empty Database ! ";
    }
    else{
        data.close();
        list();

        cout << "\n __________________________________" << endl;
        cout << "\n                                   " << endl;
        cout << "\n          PLACE THE ORDER          " << endl;
        cout << "\n                                   " << endl;
        cout << "\n __________________________________" << endl;
        do{  
            m:
        cout << "\n\n Enter the Product CODE:";
        cin >> arrc[count];
        cout << "\n\n Enter the Product Quantity: ";
        cin >> arrq[count];


        for(int i = 0 ; i < count; i++){
                if(arrc[count] == arrq[i]){
                    cout << "\n\n Duplicate Product Code ! Please try Again...";
                    goto m;
                }

        }
                        count ++;
                cout << "Do you want to buy another product? If yes then press : Y : else : N :";
                cin >> choice;
        }while(choice == 'y');

        cout << "\n\n\t\t\t ________________RECIEPT_________________";
        cout << "\nProduct no. \t Product Name \t P. Qnty \t Product Price \t Amount \t Amount with discount \n";

        for(int i = 0; i < count ; i++){
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;

            while(!data.eof()){
                if(pcode == arrc[i]){
                    int amount = price * arrq[i];
                    dis = amount - (amount * dis/100);
                    total = total + dis;
                    cout << "\n "  << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t"<< price << "\t"<< amount << "\t\t"<<  dis;
                }

                            data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();


        

        
    }

    cout << "\n\n _______________________________________________";
    cout << "\n Total Amount : ";

}


int main(){
    shopping obj;


    obj.menu();
    return 0;
}