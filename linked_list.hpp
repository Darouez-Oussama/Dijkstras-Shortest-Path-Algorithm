#ifndef _linked_list_
#define _linked_list_
#include<iostream>
struct slistelem{
    char* data ; 
    slistelem * next ; 
};
class slist {
private: 
slistelem * h ; //list head 
public: 
slist():h(0){}
~slist(); 
friend std::ostream& operator<<(std::ostream& out ,const slist& a );

void prepend(char * c); 

};


#endif
