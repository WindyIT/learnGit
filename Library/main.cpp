#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Book.h>
#include <Reader.h>
#include <BookDB.h>

using namespace std;

void init();   //显示菜单
void library();  //获取输入
void addBook();
void borrowBook();
void returnBook();
void alterBook();

BookDB database;
//vector<Book> bookVec;

int main()
{
   // library();
    database.readBooks();

    for( auto i : database.getBooksVec() ) cout << i.getId() << " " << i.getName() << endl;
    return 0;
}

void init()
{
    cout << "\n\n           ------------------------------- ^^^^^^ 小小图书馆 ^^^^^^ -------------------------------            \n\n"
         << "          请输入数字选择功能：\n\n"
         << "          1 : 添加书籍   2 : 借用书籍   3 : 退还书籍   4 : 修改书籍   5 : 进入用户中心  0 : 退出系统\n\n"
         << endl;
}

void library()
{
  int key;
   do{
      init();
      cin >> key;
       switch(key){
        case 0 : return ;
        case 1 : addBook();break;
        case 2 :    ;
        case 3 :    ;
        case 4 :    ;
        case 5 :    ;
        }
   }while( key );
    //退出系统前, 自动调用析构函数将增添的书籍数据写进数据库
}

void addBook()
{
    int id;
    string name;

    cout << "               请输入书籍编号，书名。 " << endl;
    cin >> id;
    getline(cin,name);

    //创建Book对象，出于减少错误不进行动态分配内存
    Book newBook(id,name);

    database.getBooksVec().push_back(newBook);
    database.writeBooks();

   // cout <<" \n               成功添加书籍。" << endl;
}
//返回容器的引用修改容器数据
/*class Test{
   public:
       Test(){}
       Test(vector<int>& t):iVec(t){}
       vector<int>& getVec(){ return iVec; }
       void display()
       {
           for( auto i : iVec ) cout << " " << i;
       }
   private:
       vector<int> iVec;

};

int main()
{
    vector<int> t = {1,2,3,4,5};
    Test iVec(t);

    iVec.display();
    cout << endl;

    iVec.getVec()[0] = 10;
    iVec.display();

    return 0;
}*/
