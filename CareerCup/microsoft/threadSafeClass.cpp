//
//  main.cpp
//  CareerCup_microsoft_TheadSafeClass
//
//  Created by Youngduke Koh on 11/10/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// http://www.careercup.com/question?id=5975096474730496

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

struct Person {
    string name;
    string phoneNumber;
};

class PhoneBook {
private:
    vector<Person> book;
    map<string, int> names;
    map<string, int> phones;
    int readCount;
    mutex mtx;
public:
    PhoneBook(vector<Person> people) : readCount(0) {
        vector<Person>::iterator it;
        
        for (it = people.begin(); it != people.end(); it++) {
            if (names.find(it->name) != names.end()) continue;
            if (phones.find(it->phoneNumber) != phones.end()) continue;
            book.push_back(*it);
            names.insert(make_pair(it->name, book.size() - 1));
            phones.insert(make_pair(it->phoneNumber, book.size() - 1));
        }
    }
    Person LookupByName(string name) {
        map<string, int>::iterator it;
        Person p;
        
        mtx.lock();
        readCount++;
        mtx.unlock();
        
        it = names.find(name);
        if (it != names.end()) p = book[it->second];
        
        mtx.lock();
        readCount--;
        mtx.unlock();
        
        return p;
    }
    Person LookupByPhoneNumber(string phoneNumber) {
        map<string, int>::iterator it;
        Person p;
        
        mtx.lock();
        readCount++;
        mtx.unlock();
        
        it = phones.find(phoneNumber);
        if (it != phones.end()) p = book[it->second];
        
        mtx.lock();
        readCount--;
        mtx.unlock();
        
        return p;
    }
    void AddPerson(Person person) {
        while (true) {
            mtx.lock();
            if (readCount == 0) break;
            mtx.unlock();
        }
        
        if (names.find(person.name) == names.end() && phones.find(person.phoneNumber) == phones.end()) {
            book.push_back(person);
            names.insert(make_pair(person.name, book.size() - 1));
            phones.insert(make_pair(person.phoneNumber, book.size() - 1));
        }
        
        mtx.unlock();
    }
};

mutex printMtx;

void printPerson(Person* person) {
    printMtx.lock();
    cout << person->name << ", " << person->phoneNumber << "\n";
    printMtx.unlock();
}

void worker1(PhoneBook* phoneBook) {
    Person p;
    
    p.name = "Mia Allen"; p.phoneNumber = "555-0005";
    phoneBook->AddPerson(p);
    
    p.name = "David Tomas"; p.phoneNumber = "555-0006";
    phoneBook->AddPerson(p);
    
    p.name = "Alexander Harris"; p.phoneNumber = "555-0007";
    phoneBook->AddPerson(p);
    
    p.name = "Ella Smith"; p.phoneNumber = "555-0008";
    phoneBook->AddPerson(p);
    
    p.name = "Anthony Jones"; p.phoneNumber = "555-0009";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByName("William Miller");
    printPerson(&p);
    
    p = phoneBook->LookupByPhoneNumber("555-0007");
    printPerson(&p);
    
    p.name = "Daniel Scott"; p.phoneNumber = "555-0010";
    phoneBook->AddPerson(p);
    
    p.name = "Chloe Lopez"; p.phoneNumber = "555-0011";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByName("Lucas Hill");
    printPerson(&p);
    
    p.name = "Benjamin Adams"; p.phoneNumber = "555-0012";
    phoneBook->AddPerson(p);
    
    p.name = "Claire Baker"; p.phoneNumber = "555-0013";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByName("Zoe Young");
    printPerson(&p);
    
    p.name = "Landon Turner"; p.phoneNumber = "555-0014";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByPhoneNumber("555-0022");
    printPerson(&p);
}

void worker2(PhoneBook* phoneBook) {
    Person p;
    
    p.name = "John Torres"; p.phoneNumber = "555-0015";
    phoneBook->AddPerson(p);
    
    p.name = "Hunter Ross"; p.phoneNumber = "555-0016";
    phoneBook->AddPerson(p);
    
    p.name = "Zoe Young"; p.phoneNumber = "555-0017";
    phoneBook->AddPerson(p);
    
    p.name = "Aaron Adams"; p.phoneNumber = "555-0018";
    phoneBook->AddPerson(p);
    
    p.name = "Aria Nelson"; p.phoneNumber = "555-0019";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByName("Olivia Lewis");
    printPerson(&p);
    
    p = phoneBook->LookupByPhoneNumber("555-0005");
    printPerson(&p);
    
    p.name = "Nora Perez"; p.phoneNumber = "555-0020";
    phoneBook->AddPerson(p);
    
    p.name = "Cooper Parker"; p.phoneNumber = "555-0021";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByName("Claire Baker");
    printPerson(&p);
    
    p.name = "Lydia Evans"; p.phoneNumber = "555-0022";
    phoneBook->AddPerson(p);
    
    p.name = "Bentley Russell"; p.phoneNumber = "555-0023";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByName("Bentley Russell");
    printPerson(&p);
    
    p.name = "Ruby Powell"; p.phoneNumber = "555-0024";
    phoneBook->AddPerson(p);
    
    p = phoneBook->LookupByPhoneNumber("555-0012");
    printPerson(&p);
}

int main(int argc, const char * argv[]) {
    vector<Person> people;
    Person p;
    
    p.name = "William Miller"; p.phoneNumber = "555-0001";
    people.push_back(p);
    
    p.name = "Olivia Lewis"; p.phoneNumber = "555-0002";
    people.push_back(p);
    
    PhoneBook phoneBook(people);
    thread t1(worker1, &phoneBook);
    thread t2(worker2, &phoneBook);
    
    p = phoneBook.LookupByName("William Miller");
    printPerson(&p);
    
    p = phoneBook.LookupByPhoneNumber("555-0002");
    printPerson(&p);

    p.name = "James Martin"; p.phoneNumber = "555-0003";
    phoneBook.AddPerson(p);
    
    p.name = "Lucas Hill"; p.phoneNumber = "555-0004";
    phoneBook.AddPerson(p);
    
    p = phoneBook.LookupByName("James Martin");
    printPerson(&p);
    
    p = phoneBook.LookupByPhoneNumber("555-0005");
    printPerson(&p);
    
    t1.join();
    t2.join();
    
    return 0;
}
