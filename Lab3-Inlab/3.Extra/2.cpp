
class PrinterQueue
{
    struct Node 
    {
        int priority;
        string fileName;
        Node* next;
    };
    Node* head;

public:
    PrinterQueue() 
    {
        head = nullptr;
    }


    void addNewRequest(int priority1, string fileName1)
    {
        Node* newNode = new Node;
        newNode->priority = priority1;
        newNode->fileName = fileName1;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
            return;
        }

        if (priority1 > head->priority) 
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority >= priority1) 
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;


        // Node* currNode = head;
        // Node* prevNode = nullptr;

        // while (currNode != nullptr && priority1 >= currNode->priority) 
        // {
        //     prevNode = currNode;
        //     currNode = currNode->next;
        // }

        // if (prevNode == nullptr) 
        // {
        //     newNode->next = head;
        //     head = newNode;
        // } 
        
        // else 
        // {
        //     prevNode->next = newNode;
        //     newNode->next = currNode;
        // }
    }

    void print()
    {
        if (head == nullptr) 
        {
            cout << "No file to print" << endl;
            return;
        }

        cout << head->fileName << endl;
        Node* tempNode = head;
        head = head->next;
        delete tempNode;
    }
};