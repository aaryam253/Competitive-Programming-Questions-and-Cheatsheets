// Self sorting linked list with every insert. Also provides pivot point

class l_linked {
private:
	node *head, *tail, *center;
    int size = 0; 
    int left = 0, right = 0;


	void movePivot() {
		if (right > left && size%2) {
			center = center->next; // Move right
			right--;
			left++;

		}else if (right < left){
			center = center->prev; // Move right
			right++;
			left--;
		}

	}

public:

    void create_node (long int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            // If list is empty, use temp as the head and tail. 
            head = temp;
            tail = temp;
            center = temp;
            temp = NULL; // set temp to reference NULL
            size++;
        }
    }

    l_linked () {
        head = NULL;
        tail = NULL;
    }

    int getSize () {
        return size;
    }

    long int getMedian () {
    	if (size%2) {
    		// odd number 
    		//cout << center->data << endl;
    		return center->data;
    	}else {
    		node* temp = new node;
    		temp = center->next;
    		//cout << "Even: " << center->data <<  endl;
    		return ((center->data + temp->data)/2);
    	}
    }


    void print () {
        node *temp = new node;
        temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;  // set temp to reference the next node. 
        }

        cout << endl;
        cout << center->data << endl;

    }

    void print_back() {
        node *temp = new node;
        temp = tail;
        while (temp != NULL) {
            cout << temp->data << " " ;
            temp = temp->prev;
        }
        cout << endl;
        cout << center->data << endl;
    }

    void insert_sort(long int input) {
    	if (input > tail->data) {
			node *temp = new node;
			temp->data = input;
			temp->next = NULL;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			size++;
			right++;
			movePivot();
			return;
		}
		else if (input < head->data){
			node *temp = new node;
			temp->data = input;
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
			size++;
			left++;
			movePivot();
			return;
		}

        node *temp = new node; // Use this for traversal 
        node *insertion = new node; // Use this for insertion 
        insertion -> data = input;
        temp = head;
        while (temp != NULL) {
        	if (input < temp->data) {
        		insertion->prev = temp->prev;
        		insertion->next = temp;

        		temp->prev->next = insertion;
        		temp->prev = insertion;
        		size++;
        		if (insertion->data >= center->data) {
        			right++;
        			movePivot();
        			// Move up the pivot (upwards biased)
        		}
        		else if (insertion->data < center->data) {
        			left++;
        			movePivot();
        			// Move down the pivot 
        		}

        		return;
        	}
        	temp = temp->next; // Traverse forward
        }

    }

};