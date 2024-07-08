#include <iostream>
#include <string>
using namespace std;

class SparePart {
public:
    string name;
    int quantity;
    float price;

    //constructor
    SparePart() {}
    SparePart(string n, int q, float p)
        : name(n), quantity(q), price(p) {}

    //destructor
    ~SparePart() {
        cout << "Destructing " << name << " part." << endl;
    }

    void displayPart() {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }

    // Operator Overloading
    SparePart operator+(const SparePart& obj) const {
        SparePart result = *this;
        result.name= result.name + " and " + obj.name;
        result.quantity += obj.quantity;
        result.price += obj.price;
        return result;
    }

    
};

class Details // Abstract class //hierarchial inheritance
{
    virtual void display() const =0;
};

// Class for Nuts, inheriting from SparePart
class Nuts : public SparePart,public Details //multiple inheritance
{
public:
    Nuts(string n, int q, float p) : SparePart(n, q, p) {}

    void display() const override {
        cout<<"Checking and displaying nuts.\n";
        cout<<"Quantity:"<<quantity<<endl;
        cout<<"Total Price:"<<price*quantity<<endl;
    }
};

// Class for Transaction
class Transaction {
public:
    string date;
    double amount;

    Transaction(string d, double a) : date(d), amount(a) {}

    void displayTransaction() const {
        cout << "Transaction Details:\nDate: " << date << "\nAmount: $" << amount << endl;
    }
};

// Class for Bill, inheriting from Transaction
class Bill : public Transaction //single inheritance
{
public:
    string vendor;

    Bill(string date, double amount, string vnd)
        : Transaction(date, amount), vendor(vnd) {}

    void displayBill() const {
        cout << "Bill Details:\n";
        displayTransaction(); 
        cout << "Vendor: " << vendor << endl;
    }
};

// Class for Payment
class Payment : public Bill //multilevel inheritance
{
public:
    Payment(string date, double amt, string name)
        : Bill(date, amt, name) {}

    void startPayment() const {
        cout << "Payment started for " << amount << " to " << vendor << " on " << date <<".\n";
    }

    void endPayment() const {
        cout << "Payment over for " << vendor << ".\n";
    }
};

// Template class for SparePart
template <class T>
class TemplateSparePart : public Details
{
public:
    string name;
    int count;
    T mrp, discount, price;

    TemplateSparePart(string n, int c, T m) : name(n), count(c), mrp(m) {}

    void calculate(float percent) {
        T MRP = mrp * count;
        mrp = MRP;
        discount = mrp * percent / 100;
        price = mrp - discount;
    }

    void display() const override
    {
        cout << "Name: " << name << endl;
        cout << "Total Mrp: " << mrp << endl;
        cout << "Discount: " << discount << endl;
        cout << "To pay: " << price << endl;
    }
};

// Function template for finding difference between two values
template <class T1>
T1 difference(T1 n1, T1 n2) {
    if (n1 > n2)
        return n1 - n2;
    else
        return n2 - n1;
}
//Function overloading
template <class T1, class T2>
auto difference(T1 n1, T2 n2) {
    if (n1 > n2)
        return n1 - n2;
    else
        return n2 - n1;
}

int main() {
    // Topic 1: User Input for SparePart Details
    cout<<"Constructor:\n";
    string partName;
    int partQuantity;
    float partPrice;
    cout << "Enter details for Spare Part:\n";
    cout << "Name: ";
    cin >> partName;
    cout << "Quantity: ";
    cin >> partQuantity;
    cout << "Price: ";
    cin >> partPrice;
    SparePart firstpart(partName, partQuantity, partPrice);

    //Display SparePart Details
    cout << "\nSpare Part Details:\n";
    firstpart.displayPart();

    //User Input for Second SparePart Details
    string partName2;
    int partQuantity2;
    float partPrice2;
    cout << "\nEnter details for Second Spare Part:\n";
    cout << "Name: ";
    cin >> partName2;
    cout << "Quantity: ";
    cin >> partQuantity2;
    cout << "Price: ";
    cin >> partPrice2;
    SparePart secondPart(partName2, partQuantity2, partPrice2);
    //Display SparePart Details
    cout << "\nSpare Part Details:\n";
    secondPart.displayPart();


    // Combine both parts
    SparePart combinedPart = firstpart + secondPart;

    // Display both parts
    cout<<"\nTo show operator overloading:\n";
    cout << "\nCombined Parts:\n";
    cout << "First Part:\n";
    firstpart.displayPart();
    cout << "Second Part:\n";
    secondPart.displayPart();
    cout << "Combined Part:\n";
    combinedPart.displayPart();

    cout<<"\nTo show usage of abstract class and virtual fn:\nWe gonna use sparepart 'nut'\n";
    // Topic 3: Display Nuts Details
    int q1,pr;
    cout<<"Enter nut quantity:";
    cin>>q1;
    cout<<"Enter price:";
    cin>>pr;
    Nuts n1("Nut", q1, pr);
    cout << "\nParts Details:\n";
    n1.display();

    //User Input for Transaction Details
    cout<<"\nTransaction:\n";
    string transDate;
    double transAmount;
    string transVendor;
    cout << "\nEnter transaction details:\n";
    cout << "Date: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, transDate);
    cout << "Amount: $";
    cin >> transAmount;
    cout << "Vendor: ";
    cin.ignore(); // Clear the input buffer again
    getline(cin, transVendor);
    Bill electricityBill(transDate, transAmount, transVendor);

    // Display Bill Details
    cout << "\nBill Details:\n";
    electricityBill.displayBill();

    //Payment
    Payment p1(transDate, transAmount, transVendor);
    p1.startPayment();
    p1.endPayment();
    cout<<endl;

    //TemplateSparePart
    cout<<"To show how template works:\n";
    cout<<"Class template used:\n";
    string n;
    int q;
    float m, p;
    cout << "Enter name of part:";
    cin >> n;
    cout << "Enter quantity:";
    cin >> q;
    cout << "Enter mrp per piece:";
    cin >> m;
    cout << "Enter discount percentage:";
    cin >> p;
    TemplateSparePart<int> s1(n, q, m);
    TemplateSparePart<float> s2(n, q, m);
    s1.calculate(10);
    s2.calculate(10);
    cout << "\nTemplate SparePart Details (Int):\n";
    s1.display();
    cout << "\nTemplate SparePart Details (Float):\n";
    s2.display();
    cout<<"\nFunction template used:\n";
    cout << "\nThe difference in values of both float datatypes: " << difference<float>(s1.price, s2.price) << endl<<endl;
    cout<<"Function overloading used here check code:\n";
    cout << "\nThe difference in values of both (float,int) datatypes: " << difference<float,int>(s1.price, s2.price) << endl<<endl;
    cout << "\nThe difference in values of both (int,float) datatypes: " << difference<int,float>(s1.price, s2.price) << endl<<endl;
    cout<<"Destructor:\n\n";
    return 0;
}
