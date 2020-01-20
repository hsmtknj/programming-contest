#include <bits/stdc++.h>

struct Node
{
    int key;
    Node *prev, *next;
};

// TODO: change into template class
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void print();
    void push_back(int key);
    void push_front(int key);
    void pop_back();
    void pop_front();
    int get_head();
    int get_tail();

    Node* get_middle_node();        // Q.2-1
    void make_circle();
    bool is_circle();               // Q.2-2
    void reverse_list_recursive();  // Q.2-3
    void reverse_list();            // Q.2-4

    Node *p_head, *p_tail;

private:
    void rfunc_reverse(Node *px, Node *py, Node *pz);  // Q.2-3
};

LinkedList::LinkedList()
{
    this->p_head = NULL;
    this->p_tail = NULL;
}

LinkedList::~LinkedList()
{
    // TODO: delete all nodes
}

void LinkedList::print()
{
    Node *p_node = this->p_head;
    if (p_node == NULL)
    {
        std::cout << "Nothing" << std::endl;
        return;
    }
    while (p_node != NULL)
    {
        // TODO: to detect circle

        std::cout << p_node->key << " ";
        p_node = p_node->next;
    }
    std::cout << std::endl;
}

void LinkedList::push_back(int key)
{
    Node *p_node = new Node;
    p_node->key = key;
    p_node->prev = NULL;
    p_node->next = NULL;

    if (this->p_head == NULL)
    {
        this->p_head = p_node;
        this->p_tail = p_node;
    }
    else
    {
        this->p_tail->next = p_node;
        p_node->prev = this->p_tail;
        this->p_tail = p_node;
    }
}

void LinkedList::push_front(int key)
{
    Node *p_node = new Node;
    p_node->key = key;
    p_node->prev = NULL;
    p_node->next = NULL;

    if (this->p_head == NULL)
    {
        this->p_head = p_node;
        this->p_tail = p_node;
    }
    else
    {
        this->p_head->prev = p_node;
        p_node->next = this->p_head;
        this->p_head = p_node;
    }
}

void LinkedList::pop_back()
{
    if (this->p_head == NULL)
    {
        return;
    }
    else
    {
        Node *pop_p_tail = this->p_tail;
        this->p_tail = this->p_tail->prev;
        this->p_tail->next = NULL;
        delete (pop_p_tail); // Is it correct?
    }
}

void LinkedList::pop_front()
{
    if (this->p_head == NULL)
    {
        return;
    }
    else
    {
        Node *pop_p_head = this->p_head;
        this->p_head = this->p_head->next;
        this->p_head->prev = NULL;
        delete (pop_p_head); // Is it correct?
    }
}

int LinkedList::get_head()
{
    return this->p_head->key;
}

int LinkedList::get_tail()
{
    return this->p_tail->key;
}

// Q.2-1
Node *LinkedList::get_middle_node()
{
    // TODO: Not consider circle list

    // node number is zero
    if (this->p_head == NULL)
        return NULL;
    // node number is one
    if (this->p_head->next == NULL)
        return p_head;

    Node *p_one_step, *p_two_step;
    p_one_step = this->p_head;
    p_two_step = this->p_head->next;

    while (p_two_step != NULL)
    {
        p_one_step = p_one_step->next;
        for (int i = 0; i < 2; i++)
        {
            p_two_step = p_two_step->next;
            if (p_two_step == NULL)
                break;
        }
    }
    return p_one_step;
}

void LinkedList::make_circle()
{
    if (this->p_head == NULL)
        return;
    this->p_head->prev = p_tail;
    this->p_tail->next = p_head;
}

// Q.2-2
bool LinkedList::is_circle()
{
    Node *p_one_step, *p_two_step;
    // node number is zero
    if (this->p_head == NULL)
        return false;
    if (this->p_head->next == NULL)
        return false;

    p_one_step = p_head;
    p_two_step = p_head->next;

    bool flag = false;
    while (p_two_step != NULL)
    {
        // check if circle or not
        if (p_one_step == p_two_step)
        {
            flag = true;
            break;
        }

        // step
        p_one_step = p_one_step->next;
        for (int i = 0; i < 2; i++)
        {
            p_two_step = p_two_step->next;
            if (p_two_step == NULL)
                break;
        }
    }
    return flag;
}

// Q.2-3
void LinkedList::reverse_list_recursive()
{
    if (this->p_head == NULL) return;
    if (this->p_head->next == NULL) return;

    Node *px, *py, *pz;
    this->p_head = this->p_tail;
    px = this->p_tail->prev;
    pz = this->p_head;
    py = NULL;

    LinkedList::rfunc_reverse(px, py, pz);

    return;
}

// Q.2-3
void LinkedList::rfunc_reverse(Node *px, Node *py, Node *pz)
{
    // proc
    pz->prev = py;
    pz->next = px;

    // basecase
    if (px == NULL) 
    {
        this->p_tail = pz;
        return;
    }

    px = px->prev;
    py = pz;
    pz = pz->next;


    // recursive function
    LinkedList::rfunc_reverse(px, py, pz);
}

// Q.2-4
void LinkedList::reverse_list()
{
    if (this->p_head == NULL)
        return;
    if (this->p_head->next == NULL)
        return;

    // initialize
    Node *px, *py, *pz;
    this->p_head = this->p_tail;
    px = this->p_tail->prev;
    pz = this->p_head;
    py = NULL;

    // reverse
    while (pz != NULL)
    {
        pz->prev = py;
        pz->next = px;

        if (px == NULL) break;
        else
        {
            px = px->prev;
            py = pz;
            pz = pz->next;
        }
    }
    this->p_tail = pz;
}

int main()
{
    std::vector<int> v = {30, 88, 17, 20, 25, 12};
    LinkedList lst;
    for (int i = 0; i < v.size(); i++)
        lst.push_back(v[i]);

    std::cout << "list basic operation" << std::endl;
    lst.print();
    lst.pop_back();
    lst.print();
    lst.pop_front();
    lst.print();
    int head_num = lst.get_head();
    int tail_num = lst.get_tail();
    std::cout << head_num << std::endl;
    std::cout << tail_num << std::endl;
    std::cout << std::endl;

    std::cout << "get middle node" << std::endl;
    lst.print();
    Node *middle_node = lst.get_middle_node();
    std::cout << middle_node->key << std::endl;
    std::cout << std::endl;

    std::cout << "circle list" << std::endl;
    LinkedList c_lst;
    for (int i = 0; i < v.size(); i++)
        c_lst.push_back(v[i]);
    c_lst.print();
    c_lst.make_circle();
    std::cout << lst.is_circle() << std::endl;
    std::cout << c_lst.is_circle() << std::endl;
    std::cout << std::endl;

    std::cout << "reverse list" << std::endl;
    lst.print();
    lst.reverse_list();
    lst.print();
    std::cout << "head: " << lst.p_head->key << std::endl;
    std::cout << "tail: " << lst.p_tail->key << std::endl;
    std::cout << std::endl;

    std::cout << "reverse list (recursive)" << std::endl;
    lst.print();
    lst.reverse_list_recursive();
    lst.print();

    std::cout << "END" << std::endl;
    return 0;
}