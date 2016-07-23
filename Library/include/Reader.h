#ifndef READER_H
#define READER_H
#define MAX 10   //����������Ϊ10��
#include <string>
#include <Book.h>
#include <vector>
#include <iostream>

using namespace std;

class Reader
{
    public:
        Reader();
        Reader(string _name,int _id);  //����������ţ�ע���û�
        string getName();    //��ȡ����
        void setName(string _name); //�޸�����
        int getId();  //��ȡ���
        void setId(int _id); //�޸ı��
        void borrowBook(int id);
        void returnBook(int id);
        void showInfo();
        ~Reader();

    private:
        string name;  //����������Ӣ������getline����
        int ID;    //���߱��
        int maxCnt;  //�ѽ��鼮����
        int booksId[MAX]; //�����ͼ��ID

        //void cntAlter(vector<Book> books,int id,bool addOrSub); //trueʱ�����������鼮���+1������-1
};

#endif // READER_H
