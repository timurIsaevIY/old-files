#include <iostream>
using namespace std;

class Task {
public:
    bool designer;
    bool developer;
    bool tester;
    Task(bool des, bool dev, bool test) {
        designer = des;
        developer = dev;
        tester = test;
    }
    Task() {};
    void createDesign() {
        if (!designer) {
            designer = true;
            cout << "designer done \n";
        }
        
    }
    void develop() {
        if (!developer) {
            developer = true;
            cout << "developer done \n";
        }
    }
    void doTests() {
        if (!tester) {
            tester = true;
            cout << "tester done \n";
        }
    }
};

class ChainOfResponsibility {
public:
    Task task;
    ChainOfResponsibility(Task task1) {
        task = task1;
    }  
    void start() {
        if (task.designer == true && task.developer == true && task.tester == true) {
            cout << "task is already done" << endl;
        }
        else {
            task.createDesign();
            task.develop();
            task.doTests();
        }
    }
};

int main()
{
    Task task = Task(false, false, false);
    ChainOfResponsibility chain = ChainOfResponsibility(task);
    chain.start();
}

