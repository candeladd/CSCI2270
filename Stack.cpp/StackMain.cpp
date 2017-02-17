
#include "Stack.h"

#include <iostream>
using namespace std;
int main(){
    Stack *s = new Stack(5);

    s->push("test");
    s->push("test2");
    cout << s->pop()<<endl;
    cout << s->pop()<< endl;

 return 0;
}
