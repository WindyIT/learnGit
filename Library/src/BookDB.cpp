#include "BookDB.h"

BookDB::BookDB(){}

//此函数可有可无
void BookDB::writeBooks()
{
    ofstream output("book.bat",ios::binary|ios::app);
    if( !output ){
        cout << "            无法正常打开数据库。系统将退出。" << endl;
        exit(-1);
    }
    size_t vecSize = books.size();

    output.write(reinterpret_cast<char*>(&vecSize),sizeof(size_t));
    output.write(reinterpret_cast<char*>(&books[0]),sizeof(Book)*books.size());//以追加方式写入文件

   if( output ){
        cout << "\n\n                --------------**添书成功**--------------" << endl;
    }

    output.close();  //关闭文件
}

void BookDB::readBooks()  //当添加书籍后，需重新读取
{
    books.clear();   //先清空容器内容
    ifstream input("book.bat",ios::binary);
    if( !input ){
        cout << "            无法正常打开数据库。系统将退出。" << endl;
        exit(-1);
    }
    size_t vecSize;
    input.read(reinterpret_cast<char*>(&vecSize),sizeof(size_t));

    books.resize(vecSize);
    input.read(reinterpret_cast<char*>(&books[0]),sizeof(Book)*vecSize);
    /*Book tmp;
    while( input.read(reinterpret_cast<char*>(&tmp),sizeof(Book)) ) {
        books.push_back(tmp); //将数据读入容器
    }*/

    input.close();
}

vector<Book>& BookDB::getBooksVec(){ return books; }
Book& BookDB::getBook(int _id)
{
    for( size_t i = 0; i != books.size(); i++ ){
        if( books[i].getId() == _id ) return books[i];
    }
}

BookDB::~BookDB()
{
   /* ofstream output("book.bat",ios::binary|ios::app);
    if( !output ){
        cout << "            无法正常打开数据库。系统将退出。" << endl;
        exit(-1);
    }

    output.write(reinterpret_cast<char*>(&books[0]),sizeof(Book)*books.size());//以追加方式写入文件

    output.close();*/
}
