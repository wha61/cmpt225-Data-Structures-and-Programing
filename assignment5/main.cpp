// myskiplist.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "SkipList.h"

int main()
{
	SkipList s = SkipList();
   // s.print();
    int k;
    for(int i = 0; i < 4; i++){
        Entry e = Entry();
        s.put(e.getKey(), e.getData());
        k = e.getKey();
    }
    int j;
    for(int i = 4; i < 8; i++){
        Entry e = Entry();
        s.put(e.getKey(), e.getData());
        j = e.getKey();
    }
    s.print();

    s.erase(j);
    s.print();

    s.find(k).print();

    s.find(j).print();

    s.greaterEntry(k).print();
    s.lessEntry(k).print();

    SkipList s40 = SkipList();
    for(int i = 0; i < 40; i++){
        Entry e = Entry();
        s40.put(e.key, e.data);
    }
    s40.print();

	return 0;
}

