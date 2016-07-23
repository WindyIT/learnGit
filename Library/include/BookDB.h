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
        void writeBooks(); //��������鼮ʱ����׷�ӵķ�ʽд��book.bat�ļ�
                                            //�˲����������ݶ���ϵͳ��ֱ��д�롣�����ݿ��Ӵ�ʱ����ʹϵͳ�����
        void readBooks();           //��book.bat�ļ�����vector
        vector<Book>& getBooksVec();  //�����������ö������һϵ�в���
        Book& getBook(int _id);   //����ָ�����鼮����

        ~BookDB();      //ϵͳ�ر�ʱ�����޸ĺ���Ϣ����д��book.bat

    private:
        vector<Book> books;   //���ļ��ж�ȡ�����鼮��Ϣ
};

#endif // BOOKDB_H
