/*
Name: Contact Records Management System Using C++
Description: This program help to managed contact details. and maintained by programming. the user can perform Create, Read, update and delete operations.
Technology: C++ with linkedlist and etc.
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

typedef struct Node{
    std::string name;
    std::string number;
    struct Node *Next;
} Node;
typedef struct contact_details{
    std::string name;
    std::string number;
} contact_details;

bool send_list_to_file(Node *head){
    Node *h = head;
    std::fstream obj("data.text",std::ios::out);
    if(h->Next==NULL){        
        obj<<"";
    }
    while(h->Next!=NULL){        
        h = h->Next;
        obj<<h->name<<std::endl;
        obj<<h->number;
        obj<<std::endl;
    }
    obj.close();    
    return true;
}

void load_list_from_file(Node *head){
    Node *h = head;
    contact_details s;
    std::fstream obj("data.text", std::ios::in);
    if(obj.is_open()){
        while(obj>>s.name>>s.number){
            Node *temp;
            temp = new Node;
            temp->Next=NULL;
            temp->name = s.name;
            temp->number = s.number;
            h->Next = temp;
        }
    }
    obj.close();
}

void getdata(contact_details &s){
    std::cout<<"\n Enter Contact Detail";
    std::cout<<"\n Enter Contact Name: ";std::cin>>s.name;
    std::cout<<"\n Enter Contact Number: ";std::cin>>s.number;
}

void display_Contacts(Node *head){
    Node *h = head;
    if(h->Next == NULL){
        std::cout<<"\n The list is empty"<<std::endl;
    }else{
        std::cout<<"\n Contact Details are: "<<std::endl;
        // std::cout<<std::left<<"Name"<<std::setw(20)<<"Number"<<std::endl;
        std::cout<<std::setw(20)<<"Name"<<std::setw(20)<<"Number"<<std::endl;
        while(h->Next!=NULL){
            h = h->Next;
            // std::cout<<"\n Contact Name: "<<h->name;
            // std::cout<<"\n Contact Contact Number: "<<h->number;
            std::cout<<std::setw(20)<<h->name<<std::setw(20)<<h->number<<std::endl;
        }
    }
}

int add_Contact(Node *head){
    contact_details s;
    getdata(s);
    Node *n = new Node;
    Node *temp = head;
    Node *temp2 = head->Next;
    n->name = s.name;
    n->number = s.number;
    n->Next = NULL;
    if(temp->Next==NULL){        
        temp->Next = n;
        return 1;
    }
    while(temp2!=NULL){
        temp2 = temp2->Next;
        temp = temp->Next;
    }
    temp->Next = n;    
    return 1;
}

int search_Contact_by_number(Node *head){
    Node *h = head;
    if(h->Next==NULL){
        std::cout<<"\n The List is Empty"<<std::endl;
        return 0;
    }
    int flag=0;
    contact_details s;
    std::cout<<"\nSearch Contact by Number: "<<std::endl;
    std::cout<<"Enter Number: ";std::cin>>s.number;
    while(h->Next!=NULL){
        h = h->Next;
        if(h->number==s.number){
            std::cout<<"The Contact Details Founded. "<<std::endl;
            std::cout<<std::setw(20)<<"Name"<<std::setw(20)<<"Number"<<std::endl;
            std::cout<<std::setw(20)<<h->name<<std::setw(20)<<h->number<<std::endl;
            flag=1;
        }
    }
    if(flag==0){
        std::cout<<"The Setudent Details Not Founded"<<std::endl;
    }
    return 1;
}

int search_Contact_by_name(Node *head){
    Node *h = head;
    if(h->Next==NULL){
        std::cout<<"\n The List is Empty"<<std::endl;
        return 0;
    }
    int flag=0;
    contact_details s;
    std::cout<<"\nSearch Contact by Name: "<<std::endl;
    std::cout<<"Enter Number: ";std::cin>>s.name;
    while(h->Next!=NULL){
        h = h->Next;
        if(h->name==s.name){
            std::cout<<"The Contact Details Founded. "<<std::endl;
            std::cout<<std::setw(20)<<"Name"<<std::setw(20)<<"Number"<<std::endl;
            std::cout<<std::setw(20)<<h->name<<std::setw(20)<<h->number<<std::endl;
            flag=1;
        }
    }
    if(flag==0){
        std::cout<<"The Setudent Details Not Founded"<<std::endl;
    }
    return 1;
}

int remove_Contact_by_number(Node *head){
    Node *h = head;
    int flag=0;
    if(h->Next==NULL){
        std::cout<<"\n The List is empty"<<std::endl;
        return 0;
    }
    Node *p = head->Next;
    contact_details s;
    std::cout<<"Remove Contact Details by Number"<<std::endl;
    std::cout<<"Enter Number : ";std::cin>>s.number;
    while(p != NULL){
        if(p->number==s.number ){
            std::cout<<"Record Removed Sucessfully."<<std::endl;
            flag=1;
            break;
        }
        p = p->Next;
        h = h->Next;
    }
    if(flag==0){
        std::cout<<"Record was not founded."<<std::endl;
    }else{
        h->Next = p->Next;
        free(p);
    }
    return 1;
}


int remove_Contact_by_name(Node *head){
    Node *h = head;
    int flag=0;
    if(h->Next==NULL){
        std::cout<<"\n The List is empty"<<std::endl;
        return 0;
    }
    Node *p = head->Next;
    contact_details s;
    std::cout<<"Remove Contact Details by Name"<<std::endl;
    std::cout<<"Enter Name : ";std::cin>>s.name;
    while(p != NULL){
        if(p->name==s.name){
            std::cout<<"Record Removed Sucessfully."<<std::endl;
            flag=1;
            break;
        }
        p = p->Next;
        h = h->Next;
    }
    if(flag==0){
        std::cout<<"Record was not founded."<<std::endl;
    }else{
        h->Next = p->Next;
        free(p);
    }
    return 1;    
}
int update_studnet_by_number(Node *head){
    Node *h = head;
    int flag=0;
    if(h->Next==NULL){
        std::cout<<"\n The List is empty"<<std::endl;
        return 0;
    }
    Node *p = head->Next;
    contact_details s;
    std::cout<<"Update Contact Details by Number"<<std::endl;
    std::cout<<"Enter Number : ";std::cin>>s.number;
    while(p != NULL){
        if(p->number==s.number ){    
            std::cout<<"---------------------------------------"<<std::endl;        
            std::cout<<"Record was founded."<<std::endl;
            flag=1;
            std::cout<<"Old Details : "<<std::endl;     
            std::cout<<std::setw(20)<<"Name"<<std::setw(20)<<"Number"<<std::endl;
            std::cout<<std::setw(20)<<p->name<<std::setw(20)<<p->number<<std::endl;
            std::cout<<"Update Details : "<<std::endl;
            std::cout<<"Enter Name: ";std::cin>>p->name;
            std::cout<<"Enter Number: ";std::cin>>p->number;
            std::cout<<"Details Updated Sucessfully. "<<std::endl;
            break;
        }
        p = p->Next;        
    }
    if(flag==0){
        std::cout<<"Record was not founded."<<std::endl;
    }
    return 1;
}
int update_studnet_by_name(Node *head){
    Node *h = head;
    int flag=0;
    if(h->Next==NULL){
        std::cout<<"\n The List is empty"<<std::endl;
        return 0;
    }
    Node *p = head->Next;
    contact_details s;
    std::cout<<"Update Contact Details by Name"<<std::endl;
    std::cout<<"Enter Name : ";std::cin>>s.name;
    while(p != NULL){
        if(p->name==s.name ){            
            std::cout<<"---------------------------------------"<<std::endl;
            std::cout<<"Record was founded."<<std::endl;
            flag=1;
            std::cout<<"Old Details : "<<std::endl;     
            std::cout<<std::setw(20)<<"Name"<<std::setw(20)<<"Number"<<std::endl;
            std::cout<<std::setw(20)<<p->name<<std::setw(20)<<p->number<<std::endl;
            std::cout<<"Update Details : "<<std::endl;
            std::cout<<"Enter Name: ";std::cin>>p->name;
            std::cout<<"Enter Number: ";std::cin>>p->number;
            std::cout<<"Details Updated Sucessfully. "<<std::endl;
            break;
        }
        p = p->Next;        
    }
    if(flag==0){
        std::cout<<"Record was not founded."<<std::endl;
    }
    return 1;
}

void menu(){
    Node *head;
    head = new Node;
    head->Next = NULL;
    load_list_from_file(head);
    int slt;
    bool is_exit = true;
    while(is_exit){
        std::cout<<"\n-------------------------------------"<<std::endl;
        std::cout<<"------ Menu of the Program -------"<<std::endl;
        std::cout<<"0. Exit "<<std::endl;
        std::cout<<"1. Add Contact Detail "<<std::endl;
        // std::cout<<"------ Remove Contact Details ------ "<<std::endl;
        std::cout<<"2. Remove Contact By Number "<<std::endl;
        std::cout<<"3. Remove Contact By Name "<<std::endl;
        // std::cout<<"------ Update Contact Details ------ "<<std::endl;
        std::cout<<"4. Update Contact Details by Number"<<std::endl;
        std::cout<<"5. Update Contact Details by Name "<<std::endl;
        // std::cout<<"-- Display All Contacts Details -- "<<std::endl;
        std::cout<<"6. Display Contact Details "<<std::endl;
        // std::cout<<"------ Search Contact Details ------ "<<std::endl;
        std::cout<<"7. Search By Number "<<std::endl;
        std::cout<<"8. Search By Name "<<std::endl;
        // std::cout<<"9. Save All Records. "<<std::endl;        
        std::cout<<"-------------------------------------"<<std::endl;
        std::cout<<"Enter Your Choice:  ";std::cin>>slt;
        switch(slt){
            case 0: is_exit = false; break;
            case 1: add_Contact(head); send_list_to_file(head); break;
            case 2: remove_Contact_by_number(head); send_list_to_file(head); break;
            case 3: remove_Contact_by_name(head); send_list_to_file(head); break;
            case 4: update_studnet_by_number(head);send_list_to_file(head); break;
            case 5: update_studnet_by_name(head); send_list_to_file(head); break;
            case 6: display_Contacts(head); break;
            case 7: search_Contact_by_number(head); break;
            case 8: search_Contact_by_name(head); break; 
            // case 9: send_list_to_file(head); break;
            default: std::cout<<"Invalid Choice, try again."<<std::endl;
        }
    }    
}

int main(){
    contact_details s;
    menu();    
    return 0;
}