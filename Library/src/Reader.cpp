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
    //��¼�赽��ͼ����Ϣ,��ʹ��������+1
    booksId[maxCnt++] = id;
    //����鼮-1,������������
}

void Reader::returnBook(int id)
{
    for( int i = 0; i != maxCnt; i++ ){
        booksId[i] = 0; //ע�����
    }
    maxCnt--;
    //����鼮+1��������������
}

void Reader::showInfo()
{
    cout << "\n\n         �û���: " << name << "\n"
         << "          ���: "  << ID << "\n"
         << "          ��������: " << maxCnt << endl;
    cout << "\n          �鼮���: " << endl;
      for ( int i = 0; i != maxCnt; i++ ){
          if( booksId[i] )   //����Ƿ�Ϊ0
            cout << booksId[i] << endl;
      }
}

/*void Reader::cntAlter(vector<Book> books,int id,bool addOrSub)
{
    for(size_t i = 0; i != books.size(); i++ ){
        if( books[i].getId() == id ){
             books[i].setCount(addOrSub); //trueʱ���ӿ��
             return ;
        }
    }
}*/

Reader::~Reader(){}
