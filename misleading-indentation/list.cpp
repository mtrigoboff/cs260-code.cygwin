#include <iomanip>
#include <cstring>
#include "list.h"
using namespace std;

List::List(void) : first(nullptr), length(0)
{    
}


List::Node::Node(const Fire& fire) : fire(fire), next(nullptr)
{
}

List::~List(void)
{
    Node* n = first;
    while(n)
    {
        Node* tmp = n;
        n = n->next;
        delete tmp;
    }
}

Fire* const List::find(const char* const name) const
{
    Node* n = first;
    while(n)
    {
        if(std::strcmp(n->fire.getName(), name) == 0)
            break;
        n = n->next;
    }    

    if(n)
        return &n->fire;

	return nullptr;
}

void List::add(const Fire& fire)
{
    ++length;

    if(!first)
    {
        first = new Node(fire);
        return;
    }

    Node* t = first;
    Node* p = nullptr;
    Node* n = new Node(fire);
    
    while(t)
    {
        if(n->fire < t->fire)
            break;
        
        p = t;
        t = t->next;
    }

    if(p)
        p->next = n;
    n->next = t;

    if(first == t)
        first = n;

    //n->next = first;
    //first = n;
}

bool List::remove(const char* const name)
{
    Node* n = first;
    Node* prev = nullptr;


    while(n)
    {
        if(std::strcmp(n->fire.getName(), name) == 0)
            break;
        prev = n;
        n = n->next;
    }

    if(n)
    {
        if(prev)
            prev->next = n->next;
        else
            first = n->next;

        --length;
        delete n;
        return true;
    }
	
	return false;
}

int List::getLength(void) const
{
	return length;
}

ostream& operator<<(ostream& out, const List& list)
{
    if(!list.getLength())
        return out;

    //out << '\n' << list.first->fire.getDistrict() 
    //    << '(' << list.getLength() << "):\n";
    
    Fire::displayColumnHeadings(out);
    
    List::Node* n = list.first;
    while(n)
    { 
        out << &n->fire;
        n = n->next;
    }

    //out << "\n";

	return out;
}
