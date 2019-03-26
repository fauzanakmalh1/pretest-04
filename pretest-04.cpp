/*
Nama Program    : pretest-04
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 26 Maret 2019
Deskripsi       : Pre Test
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct ElemList{
    char npm[14];
    char nama[40];
    float ipk;
    ElemList* next;
};

typedef ElemList* pointer;
typedef pointer List;

void createList(List& First);
void createElement(pointer& pBaru);
void insertSortNPM(List& First, pointer pBaru);
void sortNPM(ElemList* pBaru);
void traversal(List First);

int main()
{
    pointer p;
    List First;
    int pilih;

    createList(First);

    while(1)
    {
        system("cls");
        cout<<"===============================================" <<endl;
        cout<<"   Program untuk Sorting List Berdasarkan NPM  " <<endl;
        cout<<"===============================================" <<endl <<endl;

        cout<<"= No.    Pilihan Menu                         =" <<endl;
        cout<<"= 1.     Tambah Data                          =" <<endl;
        cout<<"= 2.     Traversal                            =" <<endl;
        cout<<"= 3.     Keluar                               =" <<endl <<endl;
        cout<<"Silahkan Masukan Pilihan : "; cin>>pilih; cout<<endl;

        switch(pilih)
        {
            case 1:
                createElement(p);
                insertSortNPM(First, p);
                break;
            case 2:
//                sortNPM();
                traversal(First);
                break;
            case 3:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
        }
        system("pause");
    }
}

void createList(List& First)
{
    First=NULL;
}

void createElement(pointer& pBaru)
{
    pBaru=new ElemList;

    cout<<"NPM\t\t\t: "; cin.ignore(); cin.getline(pBaru->npm, 14);
    cout<<"Nama\t\t\t: "; cin.getline(pBaru->nama, 40);
    cout<<"IPK\t\t\t: "; cin>>pBaru->ipk;
    pBaru->next=NULL;
}

void insertSortNPM(List& First, pointer pBaru)
{
    pointer Last=First;
    while(Last->next!=NULL)
    {
        Last=Last->next;
    }
    Last->next=pBaru;
}

/*void sortNPM(ElemList* pBaru)
{
    ElemList* temp = pBaru;
    ElemList* curr;
    for(bool didSwap = true; didSwap;)
    {
        didSwap = false;
        for(curr = pBaru; curr->next!=NULL; curr=curr->next)
        {
            if(curr->npm > curr->next->npm)
            {
                temp->npm=curr->npm;
                curr->npm=curr->next->npm;
                curr->next->npm = temp->npm;
                didSwap=true;
            }
        }
    }
}
*/

void traversal(List First)
{
    pointer pBantu;
    pBantu=First;

    if(First==NULL)
    {
        cout<<"List kosong" <<endl;
    }
    else
    {
        int i=1;

        pBantu=First;
        cout<<"No\t NPM\t\t Nama\t\t\t IPK" <<endl;
        cout<<"=======================================================" <<endl;
        do
        {
            cout<<i <<"\t"<<pBantu->npm <<"\t" <<pBantu->nama <<"\t\t\t" <<pBantu->ipk <<endl;
            pBantu=pBantu->next;
            i++;
        }
        while(pBantu!=NULL);
    }
}
