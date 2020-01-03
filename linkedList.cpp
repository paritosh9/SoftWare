#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class linked_list {
    private:
        Node *head, *tail;
    
    public:
        linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        
        void addNode(int var) {
            Node *temp = new Node;
            temp->data = var;
            temp->next = nullptr;
            
            if(head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
        }
};

int main()
{
    linked_list linkedList;
    linkedList.addNode(3);
    linkedList.addNode(5);

    return 0;
}
