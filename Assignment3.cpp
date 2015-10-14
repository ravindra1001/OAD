///Ravindra Saini
/// UG201310028
///Assignment 3

#include <iostream>
#include <string>
using namespace std;
class Book{
    string * title; //stores address of price
    string * author;
    float  * price;
    string * publisher;
    string * position; of book
    void showStatics(); of book
    void showStatics();
    int    * quantity;
public:
    Book(); //default constructer
    Book(string tempTitle,string tempAuthor,float tempPrice , string tempPublisher, string tempPosition,int tempQuantity);

    void setTitle(string); //for setting book title
    string getTitle(); //for getting book title

    void setAuthor(string);
    string getAuthor();

    void setPrice(float);
    float getPrice();

    void setPublisher(string tempPublisher);
    string getPublisher();

    void setPosition(string tempPosition);
    string getPosition();

    void setQuantity(int tempQuantity);
    int getQuantity();
};
Book::Book(){
    //allocating space dynamically for variables
    title  = new string;
    author = new string;
    price  = new float;
    publisher = new string;
    position  = new string;
    quantity  = new int;
}
Book::Book(string tempTitle,string tempAuthor,float tempPrice , string tempPublisher, string tempPosition,int tempQuantity){
    //allocating space dynamically for variables
    title  = new string;
    author = new string;
    price  = new float;
    publisher = new string;
    position  = new string;
    quantity  = new int;

    //assigning values to variables
    *title = tempTitle;
    *author = tempAuthor;
    *price = tempPrice;
    *publisher = tempPublisher;
    *position = tempPosition;
    *quantity = tempQuantity;
}
void Book::setPrice(float tempPrice){
    *price = tempPrice;
}
float Book::getPrice(){
    return *price;
}

void Book::setAuthor(string tempAuthor){
    *author = tempAuthor;
}
string Book::getAuthor(){
    return *author;
}

void Book::setTitle(string tempTitle){
    *title = tempTitle;
}
string Book::getTitle(){
    return *title;
}

void Book::setPublisher(string tempPublisher){
    *publisher = tempPublisher;
}
string Book::getPublisher(){
    return *publisher;
}

void Book::setPosition(string tempPosition){
    *position = tempPosition;
}
string Book::getPosition(){
    return *position;
}
void Book::setQuantity(int tempQuantity){
    *quantity = tempQuantity;
}
int Book::getQuantity(){
    return *quantity;
}

class BookShop{
    static int sucessTransec;
    static int failedTransec;
public:

    void displayCatalog();//for displaying catalog of book shop
    BookShop();//constructer
    Book * books;//for storing addresses of books
    int * numBooks;
    void searchBook(string title,string author);// for searching of book
    void showStatics();
};
int BookShop::sucessTransec=0;
int BookShop::failedTransec=0;
BookShop::BookShop(){
    numBooks = new int; //for keeping track no of types of books in the shp
    string tempAuthor,tempTitle,tempPosition,tempPublisher;
    int tempQuantity;
    float tempPrice;

    cout<<"Enter no of types of books:";
    cin>>*numBooks;
    books = new Book[*numBooks];

    for(int i=0;i<*numBooks;i++){
        cout<<"Enter Details of "<<i+1<<"th type of book"<<endl;

        cout<<"Title:";
        cin>>tempTitle;
        this->books[i].setTitle(tempTitle);

        cout<<"Author:";
        cin>>tempAuthor;
        this->books[i].setAuthor(tempAuthor);

        cout<<"Price:";
        cin>>tempPrice;
        this->books[i].setPrice(tempPrice);

        cout<<"Publisher:";
        cin>>tempPublisher;
        this->books[i].setPublisher(tempPublisher);

        cout<<"Position:";
        cin>>tempPosition;
        this->books[i].setPosition(tempPosition);

        cout<<"Quantity:";
        cin>>tempQuantity;
        this->books[i].setQuantity(tempQuantity);

        cout<<endl<<endl;
    }
}
void BookShop::displayCatalog(){
    //for displaying catalog
    cout<<endl;
    cout<<"____________________________________________________________________"<<endl;
    cout<<"Title\t"<<"Author\t"<<"Price\t"<<"Publisher\t"<<"Position\t"<<"Quantity"<<endl;
    cout<<"____________________________________________________________________"<<endl;
    for(int i=0;i< *numBooks;i++){
        cout<<this->books[i].getTitle()<<//
        "\t"<<this->books[i].getAuthor()<<//
        "\t"<<this->books[i].getPrice()<<//
        "\t"<<this->books[i].getPublisher()<<//
        "\t\t"<<this->books[i].getPosition()<<//
        "\t\t"<<this->books[i].getQuantity()<<endl;
    }
    cout<<"______________________________________________________________________"<<endl;
}

void BookShop::searchBook(string tempTitle,string tempAuthor){
    int copies;
    bool flag=false;
    for(int i=0;i<*numBooks;i++){
        if(tempTitle == this->books[i].getTitle() && tempAuthor == this->books[i].getAuthor()){
            cout<<"Enter number of copies do you want:";
            cin>>copies;
            if(copies <= this->books[i].getQuantity()){//cheaking req copies are available or not
                this->books[i].setQuantity(this->books[i].getQuantity() - copies);
                cout<<"Total amount : "<<this->books[i].getPrice()*copies<<endl;//displaying total amount
                this->sucessTransec++;
            }
            else{
                this->failedTransec++;
                cout<<"Required copies not in stock"<<endl;
            }
            flag = true;
        }
    }
    if(flag==false){
        cout<<"Book not found"<<endl;
    }
}
void BookShop::showStatics(){
    cout<<"Sucessesed transection :"<<this->sucessTransec<<endl;
    cout<<"Failed transections :"<<this->failedTransec<<endl;

}
int main(){
    BookShop bookShop;//making bookShop object

    bool exit = false;
    int responce;
    string tempTitle,tempAuthor;
    while(!exit){
      cout<<"1.Display catalog"<<endl;//displays menu bar
      cout<<"2.Search Book"<<endl;
      cout<<"3.show statics"<<endl;
      cout<<"4.Exit"<<endl;
      cin>>responce;

      switch(responce){
        case 1:
            bookShop.displayCatalog();
            break;
        case 2:
            cout<<"Title:";
            cin>>tempTitle;
            cout<<"Author:";
            cin>>tempAuthor;
            bookShop.searchBook(tempTitle,tempAuthor);
            break;
        case 3:
            bookShop.showStatics();
            break;
        case 4:
            exit = true;
            break;
        default:
            cout<<endl<<"Invalid Responce !"<<endl;
      }
    }
    return 0;
}
