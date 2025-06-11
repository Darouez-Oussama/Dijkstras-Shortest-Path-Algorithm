#include"linked_list.hpp" 
#include <istream>
void slist::prepend(char * c ){
slistelem* temp = new slistelem ; 
temp->data=c ; 
temp->next=h;
h=temp;
}

slist::~slist(){
    std::cout<<"destructor is called"<<"\n" ;
    delete h ;  

} 
std::ostream& operator<<(std::ostream& out , const slist& a){ 
    slistelem * temp = new slistelem ; 
    temp=a.h; 
    int size = 0 ;
    while(temp!=NULL) {
        size++; 
        temp=temp->next;
    } 
    for(int i = 0 ; i < size ; i++){
        out<<"--"<<a.h->data<<"--";

    }
    out<<"\n";
    return out ;


}