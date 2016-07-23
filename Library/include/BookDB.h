#ifndef BOOKDB_H
#define BOOKDB_H
#include <Book.h>
#include <cstdlib>
#include <vector>
#include <fstream>


class BookDB
{
    public:
        BookDB();
        void writeBooks(); //当添加新书籍时，以追加的方式写入book.bat文件
                                            //此操作不将数据读入系统，直接写入。当数据库庞大时，可使系统更快捷
        void readBooks();           //将book.bat文件读入vector
        vector<Book>& getBooksVec();  //返回容器引用对其进行一系列操作
        Book& getBook(int _id);   //返回指定的书籍引用

        ~BookDB();      //系统关闭时，将修改后信息重新写入book.bat

    private:
        vector<Book> books;   //从文件中读取所有书籍信息
};

#endif // BOOKDB_H
