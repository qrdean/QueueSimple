//Quinton Dean
//Test 2A
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <queue>
using namespace std;

/* This program uses queues with a structure st1 and st2 to process data.
*/
struct st1
{
    int ID;
    string last;
    string first;
    string class1;
    string class2;
    string class3;
    string class4;

};

struct st2
{
    string ID;
    string name;
};

int main()
{
    typedef queue<int> queueID;
    typedef queue<string> queuemain;
    typedef multimap<string, string> map;
    typedef map::iterator it;
    queueID qID;
    queuemain qLast, qFirst, qClass1, qClass2, qClass3, qClass4, qCatalog;
    string junk;
    map core;
    it it1;
    st1 stu1;
    st2 catalog;
    fstream students;
    fstream courses;
    students.open("students.txt");
    courses.open("courses.txt");
    if(!students.is_open())
    {
        cout<< "cannot open file 'students.txt'";
        return 0;
    }
    if(!courses.is_open())
    {
        cout << "cannot open file 'courses.txt'";
        return 0;
    }

    getline(students,junk);
    students >> stu1.ID >> stu1.last >> stu1.first >> stu1.class1 >> stu1.class2 >> stu1.class3 >> stu1.class4;
    getline(courses, junk);
    courses >> catalog.ID;
    getline(courses, catalog.name);

    while(!students.eof())
    {
        qID.push(stu1.ID);
        qLast.push(stu1.last);
        qFirst.push(stu1.first);
        qClass1.push(stu1.class1);
        qClass2.push(stu1.class2);
        qClass3.push(stu1.class3);
        qClass4.push(stu1.class4);
        students >> stu1.ID >> stu1.last >> stu1.first >> stu1.class1 >> stu1.class2 >> stu1.class3 >> stu1.class4;
    }
    int queueCount = qID.size();

    while(!courses.eof())
    {
        int i=0;
        while(i<queueCount)
        {
        if(catalog.ID==qClass1.front())
        {
            core.insert(make_pair(catalog.ID, catalog.name));
            break;
        }
        if(catalog.ID==qClass2.front())
        {
            core.insert(make_pair(catalog.ID, catalog.name));
            break;
        }
        if(catalog.ID==qClass3.front())
        {
            core.insert(make_pair(catalog.ID, catalog.name));
            break;
        }
        if(catalog.ID==qClass4.front())
        {
            core.insert(make_pair(catalog.ID, catalog.name));
            break;
        }
        qID.push(qID.front()); qID.pop();
        qLast.push(qLast.front()); qLast.pop();
        qFirst.push(qFirst.front()); qFirst.pop();
        qClass1.push(qClass1.front()); qClass1.pop();
        qClass2.push(qClass2.front()); qClass2.pop();
        qClass3.push(qClass3.front()); qClass3.pop();
        qClass4.push(qClass4.front()); qClass4.pop();
        i++;
        }
        courses >> catalog.ID;
        getline(courses, catalog.name);
    }
    cout << "AcmeFlow Institute Fall 2014" << '\n';
    for(it1=core.begin(); it1!=core.end(); it1++)
        {
            int i=0;
            cout << '\n';
            cout << "Class Roster For " << setw(10) << (*it1).first << setw(10) << (*it1).second << '\n' << '\n';
            cout << "ID" << setw(10) << "Last" << setw(10) << "First" << '\n' << '\n';
            while(i<queueCount)
            {

            if(qClass1.front()==(*it1).first)
            {
                cout << qID.front() << setw(10) << qLast.front() << setw(10) << qFirst.front() << '\n';
            }
            if(qClass2.front()==(*it1).first)
            {
                cout << qID.front() << setw(10) << qLast.front() << setw(10) << qFirst.front() << '\n';
            }
            if(qClass3.front()==(*it1).first)
            {
                cout << qID.front() << setw(10) << qLast.front() << setw(10) << qFirst.front() << '\n';
            }
            if(qClass4.front()==(*it1).first)
            {
                cout << qID.front() << setw(10) << qLast.front() << setw(10) << qFirst.front() << '\n';
            }
            qID.push(qID.front()); qID.pop();
            qLast.push(qLast.front()); qLast.pop();
            qFirst.push(qFirst.front()); qFirst.pop();
            qClass1.push(qClass1.front()); qClass1.pop();
            qClass2.push(qClass2.front()); qClass2.pop();
            qClass3.push(qClass3.front()); qClass3.pop();
            qClass4.push(qClass4.front()); qClass4.pop();
            i++;
            }
        }

}
