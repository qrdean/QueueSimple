//Quinton Dean
//Test 2B
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;

/* This is the second part
*/

int main()
{
    typedef queue<string> queue1;
    typedef queue<int> queue2;
    typedef queue<float> queue3;
    queue1 q1;
    queue2 q2;
    queue3 q3;
    string junk, code;
    float shares, price, soldtmp=0, soldTotal=0, buytmp, buyTotal=0, Total;
    fstream stock;
    stock.open("stocks.txt");
    if(!stock.is_open())
    {
        cout << "cannot open file 'stocks.txt'";
        return 10;
    }

    getline(stock, junk);
    stock >> code >> shares >> price;
    while(!stock.eof())
    {

        q1.push(code);
        q2.push(shares);
        q3.push(price);
        stock >> code >> shares >> price;
    }
    cout << "AcmeFlow Brokerage Firm Stock Records" << '\n' << '\n';
    while(!q1.empty())
    {

        if(!q1.empty())
        {
        if(q1.front()=="s")
        {
            cout << '\n';
            soldtmp=q2.front()*q3.front();
            cout << "Sold " << setw(16) << q2.front() << " @ " << fixed<< setprecision(2) << q3.front() << setw(10) << setprecision(2) << soldtmp << '\n';
            soldTotal=+soldtmp;

            q3.pop();
            q2.pop();
            q1.pop();



        }
        }
        if(!q1.empty())
        {
        if(q1.front()=="b")
        {
            buytmp=q2.front()*q3.front();
            cout << "Cost basis " << setw(10) << q2.front() << " @ " <<fixed << setprecision(2) << q3.front() << setw(10) << setprecision(2) << buytmp << '\n';
            buyTotal=+buytmp;

            q3.pop();
            q2.pop();
            q1.pop();

        }
        }

    }
    cout << '\n';
    Total = soldTotal-buyTotal;
    cout << "Capital Gain /(-) loss = " << setprecision(2) << Total << endl;

}
