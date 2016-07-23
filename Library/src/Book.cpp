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
    if(cnt){ //������ɽ�
       cnt--;
       cout << "\n\n        --------------**����ɹ�**--------------\n"
            << "        ��ͼ��ʣ�����Ϊ: "  << cnt << " ����" << endl;
    }
    else cout << "       ���ź�������̫���š��ѱ���⡣" << endl;
}

void Book::returnBook()
{
    cnt++;
    cout << "\n\n        --------------**����ɹ�**--------------" << endl;
}

void Book::deleteBook()
{
    char c = 'N';
    cout << "\n\n      ���棡����ɾ��" << name << "�������ݣ�\n"
         << "      ����Y/yȷ��ɾ����N/nȡ��" << endl;
    cin >> c;
    if( c == 'Y' ) cnt = 0;
    return ;
}

void Book::showBook()
{
    cout << "\n\n         ��� : " << ID << "\n"
         << "         ���� : " << name << "\n"
         << "         ����� : " << cnt << endl;
}
//Book::~Book(){}
