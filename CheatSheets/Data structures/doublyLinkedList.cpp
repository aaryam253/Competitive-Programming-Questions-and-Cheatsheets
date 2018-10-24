struct node
{
    int data;
    node *next;
    node *prev;
};

class doubly_linked {
private:
	node *head, *tail;
    int size = 0; 
    int left = 0, right = 0;

public:

    void create_node (int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            // If list is empty, use temp as the head and tail. 
            head = temp;
            tail = temp;
            temp = NULL; // set temp to reference NULL
            size++;
        }
    }

    doubly_linked () {
        head = NULL;
        tail = NULL;
    }

    int getSize () {
        return size;
    }


    void print () {
        node *temp = new node;
        temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;  // set temp to reference the next node. 
        }

        cout << endl;
    }

    void print_back() {
        node *temp = new node;
        temp = tail;
        while (temp != NULL) {
            cout << temp->data << " " ;
            temp = temp->prev;
        }
        cout << endl;
    }

    void insert_back (int input) {
        // Inserts at the tail
        node *temp = new node;
        temp->data = input;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        size++;
    }

};