#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

using namespace std;


class Book
{
    public:
        Book();
        Book(int _id,string _name);
        string getName();
        void setName(string _name);
        int getId();
        void setId(int _id);

        void borrowBook();  //借书
        void returnBook();   //还书
  //      void addBook();       //添加新书， 需检查书籍是否存在  通过cnt是否为0,在类外实现，在类内实现建议在数据域添加链表
        void deleteBook();     //删除已有书籍, 检查书籍是否存在
        void showBook();        //显示书籍,检查书籍是否存在
        int getCount();
        void setCount(bool addOrSub);  //true时所迭代到的书籍库存+1，否则-1
       // ~Book();

     //   bool isCancel;   //标识是否删除，true为已删除。
    //    bool isOnShelf;   //标识是否上架 ， true为已上架
    private:
        int ID;      //图书编号
        string name;   //书名
        int cnt;         //相同的书籍数量
};

#endif // BOOK_H
