#include <iomanip>
#include "list2.h"

using namespace std;

List2::List2(void) :
    headByName{nullptr}, headByDistrict{nullptr}, length{0}
{
}

List2::Node::Node(const Fire& fire):
    fire{fire}, nextByName{nullptr}, nextByDistrict{nullptr} 
{
}

List2::~List2(void)
{
    Node * curr = headByName;
    while (curr != nullptr)
    {
       Node * nextNode = curr->nextByName;
       delete curr;
       curr = nextNode;
    }
    headByName = nullptr;
    headByDistrict = nullptr;
}

Fire* const List2::find(const char* const name) const
{
    Node * curr = headByName;

    while (curr != nullptr)
    {
        if (strcmp(curr->fire.getName() , name) == 0)
        {
            return &curr->fire;
        }
        curr = curr->nextByName;
    }
    

	return nullptr;
}

void List2::add(const Fire& fire)
{
    Node * n = new Node(fire);

    if (headByName == nullptr && headByDistrict == nullptr)
    {
        headByName = n;
        headByDistrict = n;
    }
    else
    {
        Node * curr;
        
        if (n->fire.getDistrict() < headByDistrict->fire.getDistrict() || n->fire.getDistrict() == headByDistrict->fire.getDistrict())
        {
            curr = headByDistrict;
            headByDistrict = n;
            headByDistrict->nextByDistrict = curr;
            
            headByDistrict->nextByName = curr;
            headByName = headByDistrict;
        }
        else
        {
            Node * prev = headByDistrict;
            curr = prev->nextByDistrict;
            while(curr != nullptr)
            {
                if (n->fire.getDistrict() < curr->fire.getDistrict() || n->fire.getDistrict () ==  curr->fire.getDistrict() ) 
                {
                    prev->nextByDistrict = n;
                    prev->nextByName = n;
                    
                    n->nextByName = curr;
                    n->nextByDistrict = curr;
                    break;
                }
                prev = curr;
                curr = curr->nextByDistrict;
            }
       }
    }
}


bool List2::remove(const char* const name)
{
    Node * curr = headByName; 
	Node * nextNode = curr->nextByName;

    
    while (curr != nullptr && nextNode != nullptr)
    {
        if (strcmp(nextNode->fire.getName(),  name) == 0 )
        {
            curr->nextByName = nextNode->nextByName;
            return true;
        }
        curr= curr->nextByName;
        nextNode = nextNode->nextByName;

    }


	return false;
}

int List2::getLength(void) const
{
    Node * curr = headByName;
    int length;
    while (curr != nullptr)
    {
        length++;
        curr = curr->nextByName;
    }


	return length;
}

ostream& operator<<(ostream& out, const List2& list2)
{
    List2::Node * curr = list2.headByName;
    Fire::displayColumnHeadings(out);

    while (curr != nullptr)
    {
        out << &curr->fire;
        curr = curr->nextByDistrict;
    }
	return out;
}
