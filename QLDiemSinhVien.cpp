#include <bits/stdc++.h>
using namespace std;

// Bang diem
struct BangDiem
{
    double diem45p, diemGK, diemThi;
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
    fflush(stdin);
    cin >> bd.diem45p;
    cout << "\nNhap diem GK: ";
    fflush(stdin);
    cin >> bd.diemGK;
    cout << "\nNhap diem thi: ";
    fflush(stdin);
    cin >> bd.diemThi;
}

void InBD(BangDiem bd)
{
    cout << setw(8) << bd.diem45p << setw(12) << bd.diemGK << setw(16) << bd.diemThi << setw(8) << bd.diemTBHK << endl;
}

// Lop
struct Lop
{
    int maLop;
    string tenLop;
};

typedef Lop lop;

struct NodeLop
{
    Lop infoLop;
    struct NodeLop *next;
};

struct ListLop
{
    NodeLop *head;
    NodeLop *tail;
};

ListLop listL;

void initLop(ListLop &listL)
{
    listL.head = NULL;
    listL.tail = NULL;
}

NodeLop *getNodeLop(Lop x)
{
    NodeLop *p;
    p = new NodeLop;
    if (p == NULL)
    {
        cout << "Khong du bo nho !!";
        exit(1);
    }
    p->infoLop = x;
    p->next = NULL;

    return p;
}

void insertFirstLop(ListLop &listL, NodeLop *p)
{
    if (listL.head == NULL)
    {
        listL.head = p;
        listL.tail = p;
    }
    else
    {
        p->next = listL.head;
        listL.head = p;
    }
}

void insertTailLop(ListLop &listL, NodeLop *p)
{
    if (listL.tail == NULL)
    {
        listL.head = p;
        listL.tail = p;
    }
    else
    {
        p->next = listL.tail;
        listL.tail = p;
    }
}

void NhapLop()
{
}

// GiaoVien

struct GiaoVien
{
    int maGV;
    string tenGV;
};

typedef GiaoVien gv;

struct NodeGV
{
    GiaoVien infoGV;
    struct NodeGV *next;
};

struct ListGiaoVien
{
    NodeGV *head;
    NodeGV *tail;
};

ListGiaoVien listgv;

void intitGV(ListGiaoVien &listgv)
{
    listgv.head = NULL;
    listgv.tail = NULL;
}

NodeGV *getNodeGV(GiaoVien x)
{
    NodeGV *p;
    p = new NodeGV;
    if (p == NULL)
    {
        cout << "Khong du bo nho !!";
        exit(1);
    }
    p->infoGV = x;
    p->next = NULL;

    return p;
}

void insertFirstGV(ListGiaoVien &listgv, NodeGV *p)
{
    if (listgv.head == NULL)
    {
        listgv.head = p;
        listgv.tail = p;
    }
    else
    {
        p->next = listgv.head;
        listgv.head = p;
    }
}

void insertTailGV(ListGiaoVien &listgv, NodeGV *p)
{
    if (listgv.tail == NULL)
    {
        listgv.head = p;
        listgv.tail = p;
    }
    else
    {
        p->next = listgv.tail;
        listgv.tail = p;
    }
}

// Sinh vien
struct SinhVien
{
    int maSV;
    string tenSV, diaChi;
    Lop lop[100];
    GiaoVien gv[100];
    BangDiem bd[200];
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

NodeSV *getNodeGV(SinhVien x)
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
