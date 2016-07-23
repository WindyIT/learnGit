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

        void borrowBook();  //����
        void returnBook();   //����
  //      void addBook();       //������飬 �����鼮�Ƿ����  ͨ��cnt�Ƿ�Ϊ0,������ʵ�֣�������ʵ�ֽ������������������
        void deleteBook();     //ɾ�������鼮, ����鼮�Ƿ����
        void showBook();        //��ʾ�鼮,����鼮�Ƿ����
        int getCount();
        void setCount(bool addOrSub);  //trueʱ�����������鼮���+1������-1
       // ~Book();

     //   bool isCancel;   //��ʶ�Ƿ�ɾ����trueΪ��ɾ����
    //    bool isOnShelf;   //��ʶ�Ƿ��ϼ� �� trueΪ���ϼ�
    private:
        int ID;      //ͼ����
        string name;   //����
        int cnt;         //��ͬ���鼮����
};

#endif // BOOK_H
