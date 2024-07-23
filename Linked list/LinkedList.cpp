#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

//kiểm tra danh sách trống
bool isEmpty(Node *head)
{
    return !head;
}

//kiểm tra kích thước danh sách
int size(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while(temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;


}

//thêm 1 phần tử vào đầu danh sách
void insertFirst(int data, Node* &head)
{
    Node *tmp = new Node(data, NULL);
    if(head == NULL)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
}

//thêm 1 phần tử vào cuối danh sách
void insertLast(int data, Node* &head)
{
    if(!head) 
    {
        head = new Node(data, NULL);
        return;
    }
    Node* tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new Node(data, NULL);
}

//thêm 1 phần tử vào giữa danh sách
void insertMid(int data, Node* &head, int index)
{
    if(index >= size(head)) return;
    if(!head)
    {
        head = new Node(data, NULL);
        return;
    }

    Node *temp = head;
    for(int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node* newNode = new Node(data, temp->next);
    temp->next = newNode;
}

//xóa phần tử ở đầu
void deleteFirst(Node* &head)
{
    if(!head) return;
    head = head->next;
}

//xóa phần tử ở cuối
void deleteLast(Node* &head)
{
    if(!head) return;
    Node* aft = head, *prev = NULL;
    while(aft->next)
    {
        prev = aft;
        aft = aft->next;
    }
    if(!prev)
    {
        aft = NULL;
    }
    else
    {
        prev->next = NULL;
    }
}

//xóa phần tử ở giữa
void deleteMid(Node* &head, int pos)
{
    if(!head || pos >= size(head)) return;
    Node *tmp = head;
    for(int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
}

//sắp xếp danh sách theo tăng dần
void sort(Node* &head)
{
    for(Node* i = head; i != NULL; i = i->next)
    {
        Node* min = i;
        for(Node* j = i->next; j != NULL; j = j->next)
        {
            if(min->data > j->data)
            {
                min = j;
            }
        }
        int tmp = i->data;
        i->data = min->data;
        min->data = tmp;
    }
}

//duyệt danh sách
void iterate(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{  
    Node *head = NULL;
    bool end = 1;
    while(end)
    {
        cout << "-----------------MENU---------------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lient ket\n";
		cout << "8. Sap xep cac phan tu trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
        int mode;
        cin >> mode;
        switch(mode)
        {
            case 1:
            {
                int x;
                cout << "nhap gia tri can chen: " << endl;
                cin >> x;
                insertFirst(x, head);
                break;
            }
            case 2:
            {
                int x;
                cout << "nhap gia tri can chen: " << endl;
                cin >> x;
                insertLast(x, head);
                break;
            }
            case 3:
            {
                int x, ind;
                cout << "nhap gia tri can chen: " << endl;
                cin >> x;
                cout << "nhap vi tri chen: " << endl;
                cin >> ind;
                insertMid(x, head, ind);
                break;
            }
            case 4:
            {
                deleteFirst(head);
                break;
            }
            case 5:
            {
                deleteLast(head);
                break;
            }
            case 6:
            {
                int ind;
                cout << "nhap vi tri xoa: " << endl;
                cin >> ind;
                deleteMid(head, ind);
                break;
            }
            case 7:
            {
                iterate(head);
                break;
            }
            case 8:
            {
                sort(head);
                break;
            }
            default:
            {
                end = 0;
            }


        }
    }

    return 0;
}