#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Book.h>
#include <Reader.h>
#include <BookDB.h>

using namespace std;

void init();   //��ʾ�˵�
void library();  //��ȡ����
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
    cout << "\n\n           ------------------------------- ^^^^^^ ССͼ��� ^^^^^^ -------------------------------            \n\n"
         << "          ����������ѡ���ܣ�\n\n"
         << "          1 : ����鼮   2 : �����鼮   3 : �˻��鼮   4 : �޸��鼮   5 : �����û�����  0 : �˳�ϵͳ\n\n"
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
    //�˳�ϵͳǰ, �Զ���������������������鼮����д�����ݿ�
}

void addBook()
{
    int id;
    string name;

    cout << "               �������鼮��ţ������� " << endl;
    cin >> id;
    getline(cin,name);

    //����Book���󣬳��ڼ��ٴ��󲻽��ж�̬�����ڴ�
    Book newBook(id,name);

    database.getBooksVec().push_back(newBook);
    database.writeBooks();

   // cout <<" \n               �ɹ�����鼮��" << endl;
}
//���������������޸���������
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
