#include <bits/stdc++.h>
using namespace std;

// Bang diem
struct BangDiem
{
    double diem45p;
    double diemGK;
    double diemThi;
    double diemTBHK = diem45p * 0.2 + diemGK * 0.3 + diemThi * 0.5;
};

typedef BangDiem bd;

struct NodeBD
{
    BangDiem infoBD;
    struct NodeBD *next;
};

struct ListBangDiem
{
    NodeBD *head;
    NodeBD *tail;
};

ListBangDiem listBD;

void initBD(ListBangDiem &listBD)
{
    listBD.head = NULL;
    listBD.tail = NULL;
}

NodeBD *getNodeBD(BangDiem x)
{
    NodeBD *p;
    p = new NodeBD;
    if (p == NULL)
    {
        cout << "Khong du bo nho !!";
        exit(1);
    }
    p->infoBD = x;
    p->next = NULL;
    return p;
}

void insertFirstBD(ListBangDiem &listBD, NodeBD *p)
{
    if (listBD.head == NULL)
    {
        listBD.head = p;
        listBD.tail = p;
    }
    else
    {
        p->next = listBD.head;
        listBD.head = p;
    }
}

void insertTailBD(ListBangDiem &listBD, NodeBD *p)
{
    if (listBD.tail == NULL)
    {
        listBD.head = p;
        listBD.tail = p;
    }
    else
    {
        p->next = listBD.tail;
        listBD.tail = p;
    }
}

void NhapBD(BangDiem &bd)
{
    cout << "Nhap diem 45': ";
    cin >> bd.diem45p;
    cout << "\nNhap diem GK: ";
    cin >> bd.diemGK;
    cout << "\nNhap diem thi: ";
    cin >> bd.diemThi;
}

void InBD(BangDiem bd)
{
    cout << setw(10) << "Diem 45 phut"
         << " | ";
    cout << setw(10) << "Diem giua ki"
         << " | ";
    cout << setw(10) << "Diem thi"
         << " | ";
    cout << setw(10) << "Diem TB hoc ki"
         << " | " << endl;
    cout << setw(12) << bd.diem45p << " | ";
    cout << setw(10) << bd.diemGK << " | ";
    cout << setw(10) << bd.diemThi << " | ";
    cout << setw(10) << bd.diemTBHK << " | " << endl;
}

// Sinh vien
struct SinhVien
{
    int maSV;
    string tenSV, diaChi, giaoVien, lop;
    BangDiem bd;
};

typedef SinhVien sv;

struct NodeSV
{
    SinhVien infoSV;
    struct NodeSV *next;
};

struct ListSinhVien
{
    NodeSV *head;
    NodeSV *tail;
};

ListSinhVien listsv;

void initSV(ListSinhVien &listsv)
{
    listsv.head = NULL;
    listsv.tail = NULL;
};

NodeSV *getNodeSV(SinhVien x)
{
    NodeSV *p;
    p = new NodeSV;
    if (p == NULL)
    {
        cout << "Khong du bo nho !!";
        exit(1);
    }
    p->infoSV = x;
    p->next = NULL;

    return p;
}

void insertFirstSV(ListSinhVien &listsv, NodeSV *p)
{
    if (listsv.head == NULL)
    {
        listsv.head = p;
        listsv.tail = p;
    }
    else
    {
        p->next = listsv.head;
        listsv.head = p;
    }
}

void insertTailSV(ListSinhVien &listsv, NodeSV *p)
{
    if (listsv.tail == NULL)
    {
        listsv.head = p;
        listsv.tail = p;
    }
    else
    {
        p->next = listsv.tail;
        listsv.tail = p;
    }
}

void NhapBDSinhVien(SinhVien &sv)
{
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    cin >> sv.maSV;
    cout << "\nNhap ten sinh vien: ";
    fflush(stdin);
    getline(cin, sv.tenSV);
    cout << "\nNhap dia chi: ";
    getline(cin, sv.diaChi);
    cout << "\nNhap lop: ";
    getline(cin, sv.lop);
    cout << "\nNhap giao vien: ";
    getline(cin, sv.giaoVien);
    cout << "\n---------------------------------------\n";
    cout << "\nNhap bang diem cua sinh vien:\n ";
    NhapBD(sv.bd);
}

void InBDSinhVien(SinhVien sv)
{
    cout << "Danh sach: " << endl;
    cout << setw(10) << "Ma sinh vien"
         << " | ";
    cout << setw(10) << "Ho ten"
         << " | ";
    cout << setw(10) << "Dia chi"
         << " | ";
    cout << setw(10) << "Lop"
         << " | ";
    cout << setw(10) << "Giao viem"
         << " | " << endl;
    cout << setw(12) << sv.maSV << " | ";
    cout << setw(10) << sv.tenSV << " | ";
    cout << setw(10) << sv.diaChi << " | ";
    cout << setw(10) << sv.lop << " | ";
    cout << setw(10) << sv.giaoVien << " | " << endl;
    cout << "Bang diem" << endl;
    InBD(sv.bd);
}

void NhapDSBD(ListSinhVien &listsv)
{
    int n;
    cout << "Nhap so luong bang diem: ";
    initSV(listsv);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap bang diem thu " << i + 1 << endl;
        SinhVien sv;
        NhapBDSinhVien(sv);
        NodeSV *p = getNodeSV(sv);
        insertTailSV(listsv, p);
    }
}

void InDSBD(ListSinhVien listsv)
{
    cout << "---------------------------- DANH SACH BANG DIEM CUA HOC SINH ----------------------------" << endl;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        InBDSinhVien(p->infoSV);
        cout << "\n__________________________________________________________________________________________\n";
    }
}

int main()
{
    ListSinhVien listsv;
    NhapDSBD(listsv);
    InDSBD(listsv);
    return 0;
}