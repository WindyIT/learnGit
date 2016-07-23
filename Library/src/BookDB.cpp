#include "BookDB.h"

BookDB::BookDB(){}

//�˺������п���
void BookDB::writeBooks()
{
    ofstream output("book.bat",ios::binary|ios::app);
    if( !output ){
        cout << "            �޷����������ݿ⡣ϵͳ���˳���" << endl;
        exit(-1);
    }
    size_t vecSize = books.size();

    output.write(reinterpret_cast<char*>(&vecSize),sizeof(size_t));
    output.write(reinterpret_cast<char*>(&books[0]),sizeof(Book)*books.size());//��׷�ӷ�ʽд���ļ�

   if( output ){
        cout << "\n\n                --------------**����ɹ�**--------------" << endl;
    }

    output.close();  //�ر��ļ�
}

void BookDB::readBooks()  //������鼮�������¶�ȡ
{
    books.clear();   //�������������
    ifstream input("book.bat",ios::binary);
    if( !input ){
        cout << "            �޷����������ݿ⡣ϵͳ���˳���" << endl;
        exit(-1);
    }
    size_t vecSize;
    input.read(reinterpret_cast<char*>(&vecSize),sizeof(size_t));

    books.resize(vecSize);
    input.read(reinterpret_cast<char*>(&books[0]),sizeof(Book)*vecSize);
    /*Book tmp;
    while( input.read(reinterpret_cast<char*>(&tmp),sizeof(Book)) ) {
        books.push_back(tmp); //�����ݶ�������
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
        cout << "            �޷����������ݿ⡣ϵͳ���˳���" << endl;
        exit(-1);
    }

    output.write(reinterpret_cast<char*>(&books[0]),sizeof(Book)*books.size());//��׷�ӷ�ʽд���ļ�

    output.close();*/
}
