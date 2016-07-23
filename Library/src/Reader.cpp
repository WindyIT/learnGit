#include "Reader.h"
#include "Book.h"

using namespace std;

Reader::Reader(){}
Reader::Reader(string _name,int _id):name(_name),ID(_id),maxCnt(0){}
string Reader::getName(){ return name; }
void Reader::setName(string _name){ name = _name; }
int Reader::getId(){ return ID; }
void Reader::setId(int _id){ ID = _id; }

void Reader::borrowBook(int id)
{
    //记录借到的图书信息,且使借书数量+1
    booksId[maxCnt++] = id;
    //库存书籍-1,在主函数操作
}

void Reader::returnBook(int id)
{
    for( int i = 0; i != maxCnt; i++ ){
        booksId[i] = 0; //注销编号
    }
    maxCnt--;
    //库存书籍+1，在主函数操作
}

void Reader::showInfo()
{
    cout << "\n\n         用户名: " << name << "\n"
         << "          编号: "  << ID << "\n"
         << "          借书数量: " << maxCnt << endl;
    cout << "\n          书籍编号: " << endl;
      for ( int i = 0; i != maxCnt; i++ ){
          if( booksId[i] )   //检测是否为0
            cout << booksId[i] << endl;
      }
}

/*void Reader::cntAlter(vector<Book> books,int id,bool addOrSub)
{
    for(size_t i = 0; i != books.size(); i++ ){
        if( books[i].getId() == id ){
             books[i].setCount(addOrSub); //true时增加库存
             return ;
        }
    }
}*/

Reader::~Reader(){}
