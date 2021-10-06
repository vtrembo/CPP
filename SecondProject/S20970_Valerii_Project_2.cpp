#include <iostream>
#include <utility> // swap (may be useful)
#include <string>

template <typename T>
class DLL{
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* sent; // sentinel
public:
    DLL() : sent(new Node{ T(), nullptr, nullptr }) {
        sent->next = sent->prev = sent;
    }
    bool empty() const {
        if (sent->next == sent->prev)  return true;
        return false;
    }
    void push_front(const T& t) const {
        sent->next->prev = new Node{ t, sent->next, sent };
        sent->next = sent->next->prev;
    }
    void push_back(const T& t) const  {
        sent->prev->next = new Node{ t, sent, sent->prev };
        sent->prev = sent->prev->next;
    }
    void print_fwd(std::ostream& str = std::cout) const {
        Node* tempHead = sent->next;
        while (tempHead != sent)  {
            str << tempHead->data << " ";
            tempHead = tempHead->next;
        }
        str << "\n";
    }
    void print_rev(std::ostream& str = std::cout) const  {
        Node* tempTail = sent->prev;
        while (tempTail != sent)    {
            str << tempTail->data << " ";
            tempTail = tempTail->prev;
        }
        str << "\n";
    }
    Node* find_first(const T& e) const {
        Node* res = sent->next;
        while (res != sent && res->data != e)
            res = res->next;
        if (res->data == e)  return res;
        return nullptr;
    }
    Node* find_last(const T& e) const {
        Node* res = sent->prev;
        while (res != sent && res->data != e)
            res = res->prev;
        if (res->data == e) return res;
        return nullptr;
    }
    void insert_after(Node* a, const T& t) const {
        a->next->prev = new Node{ t, a->next, a };
        a->next = a->next->prev;
    }
    void insert_before(Node* b, const T& t) const  {
        b->prev->next = new Node{ t, b, b->prev };
        b->prev = b->prev->next;
    }
    void delete_node(const Node* d) const  {
        if (d != nullptr) {
            d->prev->next = d->next;
            d->next->prev = d->prev;
            std::cout << "DEL: " << d->data << " ";
            delete (d);
        }
    }
    void reverse() const {
        Node* cur = sent;
        Node* temp = cur;
        do {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->next;
        } while (cur != sent);
    }
    void clear() const {
        while (sent->next != sent) {
            delete_node(sent->next);
        }
    }
    ~DLL() {
        clear();
        delete (sent);
    }
};

int main(){
    using std::cout; using std::endl; using std::string;

    DLL<std::string>* listStr = new DLL<std::string>();
    listStr->push_back("X");
    listStr->push_back("E");
    listStr->push_front("C");
    listStr->push_front("X");
    listStr->push_front("A");

    cout << "List printed in both directions:" << endl;
    listStr->print_fwd();
    listStr->print_rev();

    listStr->delete_node(listStr->find_first("X"));
    listStr->delete_node(listStr->find_last("X"));
    cout << "\nList after deleting X's:" << endl;
    listStr->print_fwd();

    listStr->insert_after(listStr->find_first("A"), "B");
    listStr->insert_before(listStr->find_last("E"), "D");
    cout << "List after inserting B and D:" << endl;
    listStr->print_fwd();

    listStr->reverse();
    cout << "List after reversing:" << endl;
    listStr->print_fwd();

    std::cout << "Is list empty? " << std::boolalpha
        << listStr->empty() << std::endl;
    std::cout << "Clearing the listt" << std::endl;
    listStr->clear();
    std::cout << endl;

    std::cout << "Adding one element (Z)" << std::endl;
    listStr->push_front("Z");

    std::cout << "Deleting the list" << std::endl;
    delete listStr;
}
