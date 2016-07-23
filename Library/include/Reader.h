#ifndef READER_H
#define READER_H
#define MAX 10   //最大借书数量为10本
#include <string>
#include <Book.h>
#include <vector>
#include <iostream>

using namespace std;

class Reader
{
    public:
        Reader();
        Reader(string _name,int _id);  //输入姓名编号，注册用户
        string getName();    //获取姓名
        void setName(string _name); //修改姓名
        int getId();  //获取编号
        void setId(int _id); //修改编号
        void borrowBook(int id);
        void returnBook(int id);
        void showInfo();
        ~Reader();

    private:
        string name;  //读者姓名，英文名用getline输入
        int ID;    //读者编号
        int maxCnt;  //已借书籍数量
        int booksId[MAX]; //所借的图书ID

        //void cntAlter(vector<Book> books,int id,bool addOrSub); //true时所迭代到的书籍库存+1，否则-1
};

#endif // READER_H
