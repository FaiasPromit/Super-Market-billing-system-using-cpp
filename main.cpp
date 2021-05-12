#include<fstream>
#include<bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdio>
using namespace std;

static float sum=0;
class Data //Hybrid Inheritance
{
protected:
    vector<int>v;
    vector<int>q;
    int j;
    int q_input;
    int input_code;
    int k;

    float final_money=0;
    int b;
    char agdum,bagdum,ghora;

};
class Product : public Data //Single Inheritance
{
public:
    void create() //file_creation
    {
        fstream fout;


        fout.open("shoppinginformation.csv", ios::out | ios::app);

        cout << "Enter the details of PRODUCTS:"
             << " Product Code ----- Product Name -------- Quantities------- Price----- Discount "
             << endl;
        cout<<"example : 1000 brown_rice 100 20 1"<<endl;
        cout<<"make sure the every product code is unique"<<endl;

        int i, product_code, quantity,w;
        float  Price, Discount;
        string product_name;

        cin >>w;

        for (i = 0; w!=0; i++)
        {
            product_code=w;

            cin >> product_name
                >> quantity
                >> Price
                >> Discount;


            fout << product_code << ","
                 << product_name << ","
                 << quantity << ","
                 << Price << ","
                 << Discount

                 << "\n";
            cout<<"Enter the new product's information. If not press '0' "<<endl;
            cin>>w;
        }

    }

    void update_record2(int code_num,int new_data)
    {

        fstream fin, fout;
        fin.open("shoppinginformation.csv", ios::in);
        fout.open("Shoppinginformationnew.csv", ios::out);

        int temp, data, count1 = 0, i,ou,new_data1;
        char c;
        string line, word;
        vector<string> row;




        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            temp = stoi(row[0]);
            int row_size = row.size();

            if (temp == code_num )
            {
                count1 = 1;
                stringstream srow(row[2]);
                srow>>ou;
                new_data1=ou-new_data;
                stringstream convert;

                convert << new_data1;

                row[2] = convert.str();

                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        fout << row[i] << ",";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {


                        fout << row[i] << ",";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }

        fin.close();
        fout.close();
        remove("shoppinginformation.csv");

        rename("Shoppinginformationnew.csv", "shoppinginformation.csv");
    }



    void read_record(int product_codenum,int qtity) //takin_input_from_file
    {
        fstream fin;
        float price2;
        float discount2;
        fin.open("shoppinginformation.csv", ios::in);
        vector<string> row;
        string line, word, temp;
        int  product_codel,qt;
        int count;




        count =0;






        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);

            stringstream s(line);


            while (getline(s, word,','))
            {

                row.push_back(word);
            }
            stringstream ss(row[0]);
            ss>>product_codel;
            stringstream ss_price(row[3]);
            ss_price>>price2;
            stringstream ss_discount(row[4]);
            ss_discount>>discount2;
            if (product_codel == product_codenum)
            {

                count = 1;
                cout <<row[0]<<"     "
                     << row[1]<<"     "
                     << qtity<<"      "
                     << money(price2,discount2,qtity)<<"    "
                     << row[4] << "\n";
                sum+=money(price2,discount2,qtity);
                break;


            }
        }
        if (count == 0)
            cout << "Record not found\n";



    }
    void input()
    {
        v.clear();
        q.clear();

        cout<<"Enter the product's code you want to buy : "<<endl;
        cin>>input_code;

        while (input_code!=0)
        {


            v.push_back(input_code);
            cout<<"Enter how many Product you want to buy : "<<endl;
            cin>>q_input;
            q.push_back(q_input);

            cout<<"Enter the next product code "<<endl;
            cout<<"If you don't wanna buy, press '0' "<<endl;
            cin>>input_code;
        }

    }
    inline float money(float price3,float discount3,int quantity3) //inline function
    {
        if (discount3!=0)
        {
            return ((price3-((discount3/100)*price3))*quantity3);
        }
        else
        {
            return (price3*quantity3);

        }

    }

    void virtual total_show()
    {
        cout<<"total cost is : "<<"      "<<sum<<endl;
    }


    void show_product()
    {
        cout << "Product Code    "
             << "product Name    "
             << "Quantities    "
             << "Price    "
             << "Discount    " << endl;

        for(k=0; k<v.size(); k++)
        {
            read_record(v[k],q[k]);
            update_record2(v[k],q[k]);
        }

    }
    void delete_record()
    {

        fstream fin, fout;

        fin.open("shoppinginformation.csv", ios::in);

        fout.open("Shoppinginformationnew.csv", ios::out);

        int product_codenum, product_code1, marks, count = 0, i;
        char sub;
        int index, new_marks;
        string line, word;
        vector<string> row;

        cout << "Enter the product_code number "
             << "of the record to be deleted: ";
        cin >> product_codenum;

        while (!fin.eof())
        {
            row.clear();
            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int row_size = row.size();
            stringstream sss(row[0]);
            sss>>product_code1;

            if (product_code1 != product_codenum)
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {
                        fout << row[i] << ",";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                count = 1;
            }
            if (fin.eof())
                break;
        }
        if (count == 1)
            cout << "Record deleted\n";
        else
            cout << "Record not found\n";

        fin.close();
        fout.close();


        remove("shoppinginformation.csv");

        rename("Shoppinginformationnew.csv", "shoppinginformation.csv");
    }




    void update_record() //file_updating
    {

        fstream fin, fout;
        fin.open("shoppinginformation.csv", ios::in);
        fout.open("Shoppinginformationnew.csv", ios::out);

        int code_num, temp, data, count1 = 0, i;
        char c;
        int index, new_data;
        string line, word;
        vector<string> row;
        cout << "Enter the  product code number "
             << "of the record to be updated: ";
        cout<<endl<<" Carefully enter a product_code that is already in the database!!!"<<endl;
        cin >> code_num;

        cout << "Enter the Data "
             << "to be updated(    Quantities    ==    Q /   Product price    ==    P/    Discount    ==    D): ";
        cin >> c;

        if (c == 'Q' || c == 'q')
        {
            index = 2;
            cout << "Enter new Quantity : ";
            cin >> new_data;
        }

        else if (c == 'P' || c == 'p')
        {
            index = 3;
            cout << "Enter new Price : ";
            cin >> new_data;
        }
        else if (c == 'D' || c == 'd')
        {
            index = 4;
            cout << "Enter new Discount(%) : ";
            cin >> new_data;
        }
        else
        {
            cout << "Wrong choice.Enter again\n";
            update_record();
        }




        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            temp = stoi(row[0]);
            int row_size = row.size();

            if (temp == code_num )
            {
                count1 = 1;
                stringstream convert;

                convert << new_data;

                row[index] = convert.str();

                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        fout << row[i] << ",";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {


                        fout << row[i] << ",";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }
        if (count1 == 0)
            cout << "Record not found\n";

        fin.close();
        fout.close();
        remove("shoppinginformation.csv");

        rename("Shoppinginformationnew.csv", "shoppinginformation.csv");
    }
} ;
class final_money:public Product  //multi-level Inheritance
{
public:
    void total_show ()  //Runtime Polymorphism
    {
        if(sum>=1000)
        {
            b=(int)sum%10;
            sum=sum-b;
        }
        cout<<" Final cost is : " << (int)sum <<endl; //Implicit type casting
    }

};
class op
{
    int x;
public:
    op() {}
    op(int a) // Using of Constructor
    {
        x=a;
    }
    int operator>(op o) //Operator Overloading
    {
        op temp;
        if(x==o.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Product object;
    Product *bptr;
    final_money fm;
    int cba;
    int abc;
    int zz;
    char sw;
    int mn;
C:
    cout<<"***************   Welcome to Daily Super Shop.    ************** "<<endl;
    cout<<"***************   Which mode do you want to access??     ************" <<endl;
    cout<<endl<<endl<<" 1. Admin mode " <<endl;
    cout<<" 2. Seller mode " <<endl<<endl<<endl;
    cout<<"**********     Press '1' or '2'     ***********"<<endl;
    cout<< "***********      To cancel - press '0'    *********"<<endl;
    int as;
    cin>>as;
    if(as==0)
    {
        system("CLS");
        cout<<" Operations Closed " <<endl;
        return 0;
    }
    else if(as==1)
    {
        system ("CLS");
        cout<<"Please insert the Pin Number to access " <<endl;
        cout<<"admin pin number is '1000'"<<endl;
        op o1,o2;
A:
        cin>>abc;
        o2=op(abc);
        o1=op(1000);

        cba=o1>o2;
        if(cba==0)
        {
            cout<<"  Access Denied   "<<endl;
            cout<<"  Please Try Again   " <<endl;
            goto A;

        }
        else
        {
            system("CLS");
            cout<<  "  ***********    Access Granted  **********  "<<endl;
B:
            cout<<  " **********   Welcome to ADMIN Mode *********   " <<endl ;

            cout<< " *********   What do you want to do??   ******* "<<endl<<endl<<endl;
            cout<<" 1. Add new Product Information ." <<endl;
            cout<<" 2. Update existing Product Information . " <<endl;
            cout<<" 3. Delete any Product Information . " <<endl;
            cout<<" 4. Open 'shoppinginformation' file to see the present database record of your products"<<endl<<endl<<endl;

            cout<<" Select your Option - 1 , 2 , 3 " <<endl;
            cout<<" If do not want to continue then Press '0' " <<endl;
            cin>>zz;
            if(zz==0)
            {
                system("CLS");
                goto C ;

            }
            else if(zz==1)
            {
                system("CLS");
                object.create();
                cout<<" Information created " <<endl;
                cout<<" Press '0' to go back to the menu" <<endl;
                cin>>mn;
                system("CLS");
                goto B;
            }
            else if(zz==2)
            {
                object.total_show();
                system("CLS");
                object.update_record();
                cout<<" Information updated " <<endl;
                cout<<" Press '0' to go back to the menu" <<endl;
                cin>>mn;
                system("CLS");
                goto B;
            }
            else if(zz==3)
            {
                system("CLS");
                object.delete_record();
                cout<<" Information deleted " <<endl;
                cout<<" Press '0' to go back to the menu" <<endl;
                cin>>mn;
                system("CLS");
                goto B;
            }
            else
            {
                system("CLS");
                cout<<" Select any of the Asking options " <<endl;

                goto B;
            }


        }
    }
    else if(as==2)
    {
        system("CLS");
        cout<<" ********  Welcome to Seller Mode   *********"<<endl;
        object.input();
        system("CLS");
        object.show_product();
        object.total_show();
        bptr= &fm;
        bptr->total_show();
        cout<<endl<<endl<<endl<<"Products have been decreased from your Product Database records!"<<endl;
        cout<<"Product selling complete !!!"<<endl;
        cout<<endl<<" *****   CONTINUE?? ****** " <<endl;
        cout<<" Press 'Y' to go to the menu or 'N' to close the operation"<<endl;
        cin>>sw;
        if(sw=='Y' or sw =='y')
        {
            system("CLS");
            sum=0;
            goto C ;
        }
        else
        {
            system("CLS");
            cout<<" Operations Closed " <<endl;
            return 0;
        }
    }



}
