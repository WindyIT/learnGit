#include "Book.h"

Book::Book(){}
Book::Book(int _id,string _name):ID(_id),name(_name),cnt(1){}
string Book::getName(){ return name; }
void Book::setName(string _name){ name = _name; }
int Book::getId(){ return ID; }
void Book::setId(int _id){ ID = _id; }
int Book::getCount(){  return cnt; }

void Book::setCount(bool addOrSub)
{
    if(addOrSub)  cnt++;
    else cnt--;
}

void Book::borrowBook()
{
    if(cnt){ //若有书可借
       cnt--;
       cout << "\n\n        --------------**借书成功**--------------\n"
            << "        本图书剩余存量为: "  << cnt << " 本。" << endl;
    }
    else cout << "       很遗憾，此书太热门。已被借光。" << endl;
}

void Book::returnBook()
{
    cnt++;
    cout << "\n\n        --------------**还书成功**--------------" << endl;
}

void Book::deleteBook()
{
    char c = 'N';
    cout << "\n\n      警告！您将删除" << name << "所有数据！\n"
         << "      输入Y/y确认删除。N/n取消" << endl;
    cin >> c;
    if( c == 'Y' ) cnt = 0;
    return ;
}

void Book::showBook()
{
    cout << "\n\n         编号 : " << ID << "\n"
         << "         书名 : " << name << "\n"
         << "         库存量 : " << cnt << endl;
}
//Book::~Book(){}
