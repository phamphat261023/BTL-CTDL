#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Bang diem
struct BangDiem
{
    float diem45p;
    float diemGK;
    float diemThi;
    float diemTBHK = (diem45p * 0.2) + (diemGK * 0.3) + (diemThi * 0.5);
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

void importBD(BangDiem &bd)
{
    cout << "Nhap diem 45': ";
    cin >> bd.diem45p;
    cout << "\nNhap diem GK: ";
    cin >> bd.diemGK;
    cout << "\nNhap diem thi: ";
    cin >> bd.diemThi;
}

void printBD(BangDiem bd)
{
    cout << setw(10) << "Diem 45 phut"
         << " | ";
    cout << setw(10) << "Diem GK"
         << " | ";
    cout << setw(10) << "Diem thi"
         << " | ";
    cout << setw(10) << "Diem TBHK"
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
    string giaoVien, lop;
    char tenSV[200];
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
        listsv.tail = p;
        listsv.head = p;
    }
    else
    {
        listsv.tail->next = p;
        listsv.tail = p;
    }
}

void importBDSV(SinhVien &sv)
{
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    cin >> sv.maSV;
    cout << "\nNhap ten sinh vien: ";
    fflush(stdin);
    gets(sv.tenSV);
    cout << "\nNhap lop: ";
    getline(cin, sv.lop);
    cout << "\nNhap giao vien: ";
    getline(cin, sv.giaoVien);
    cout << "\n---------------------------------------\n";
    cout << "\nNhap bang diem cua sinh vien:\n ";
    importBD(sv.bd);
}

void printBDSV(SinhVien sv)
{
    cout << "Danh sach: " << endl;
    cout << setw(10) << "Ma sinh vien"
         << " | ";
    cout << setw(10) << "Ho ten"
         << " | ";
    cout << setw(10) << "Lop"
         << " | ";
    cout << setw(10) << "Giao vien"
         << " | " << endl;
    cout << setw(12) << sv.maSV << " | ";
    cout << setw(10) << sv.tenSV << " | ";
    cout << setw(10) << sv.lop << " | ";
    cout << setw(10) << sv.giaoVien << " | " << endl;
    cout << "Bang diem" << endl;
    printBD(sv.bd);
}

void importListBD(ListSinhVien &listsv)
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
        importBDSV(sv);
        NodeSV *p = getNodeSV(sv);
        insertFirstSV(listsv, p);
    }
}

void printListBD(ListSinhVien listsv)
{
    cout << "----------- DANH SACH BANG DIEM CUA HOC SINH -----------" << endl;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        printBDSV(p->infoSV);
        cout << "\n_______________________________________________________\n";
    }
}

void printById(ListSinhVien listsv)
{
    int id;
    cout << "Nhap ma sinh vien can in bang diem: ";
    cin >> id;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (id == p->infoSV.maSV)
        {
            printBDSV(p->infoSV);
        }
    }
}

void insertFirstBD(ListSinhVien listsv)
{
    int n;
    cout << "Nhap so bang diem can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        importBDSV(sv);
        NodeSV *p = getNodeSV(sv);
        insertFirstSV(listsv, p);
    }
    cout << "\nDanh sach bang diem sau khi them len dau\n";
    printListBD(listsv);
}

void insertTailBD(ListSinhVien listsv)
{
    int n;
    cout << "Nhap so bang diem can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        importBDSV(sv);
        NodeSV *p = getNodeSV(sv);
        insertTailSV(listsv, p);
    }
    cout << "\nDanh sach bang diem sau khi them vao sau\n";
    printListBD(listsv);
}

void findByName(ListSinhVien listsv)
{
    char name[200];
    cout << "Nhap ten sinh vien de tim kiem bang diem: ";
    fflush(stdin);
    gets(name);
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (strcmp(name, p->infoSV.tenSV) == 0)
        {
            printBDSV(p->infoSV);
        }
    }
}

void totalPointBDSV(ListSinhVien listsv)
{
    int id;
    float total = 0;
    cout << "Nhap ma sinh vien can tong diem: ";
    cin >> id;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (id == p->infoSV.maSV)
        {
            total = p->infoSV.bd.diem45p + p->infoSV.bd.diemGK + p->infoSV.bd.diemThi + p->infoSV.bd.diemTBHK;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "Tong diem cua sinh vien co ma " << id << " la: " << total << endl;
    cout << "\n_______________________________________________________\n";
}

void averangePointBDSV(ListSinhVien listsv)
{
    int id;
    float avr = 0;
    cout << "Nhap ma sinh vien can tinh diem trung binh: ";
    cin >> id;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (id == p->infoSV.maSV)
        {
            avr = (p->infoSV.bd.diem45p + p->infoSV.bd.diemGK + p->infoSV.bd.diemThi) / 3;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "Diem trung binh cong cua sinh vien co ma " << id << " la: " << avr << endl;
    cout << "\n_______________________________________________________\n";
}

void printBDSVMax(ListSinhVien listsv)
{
    NodeSV *max = new NodeSV();
    max = listsv.head;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (max->infoSV.bd.diemTBHK < p->infoSV.bd.diemTBHK)
        {
            max = p;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nSinh vien co diem trung binh hoc ki cao nhat la: \n";
    printBDSV(max->infoSV);
    cout << "\n_______________________________________________________\n";
}

void printBDSVMin(ListSinhVien listsv)
{
    NodeSV *min = new NodeSV();
    min = listsv.head;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (min->infoSV.bd.diemTBHK > p->infoSV.bd.diemTBHK)
        {
            min = p;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nSinh vien co diem trung binh hoc ki thap nhat la: \n";
    printBDSV(min->infoSV);
    cout << "\n_______________________________________________________\n";
}

void sortListBDSVRise(ListSinhVien listsv)
{
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        for (NodeSV *q = p->next; q != NULL; q = q->next)
        {
            if (p->infoSV.bd.diemTBHK > q->infoSV.bd.diemTBHK)
            {
                SinhVien tmp;
                tmp = p->infoSV;
                p->infoSV = q->infoSV;
                q->infoSV = tmp;
            }
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nDanh sach sau khi sap xep theo thu tu tang\n";
    printListBD(listsv);
    cout << "\n_______________________________________________________\n";
}

void sortListBDSVReduce(ListSinhVien listsv)
{
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        for (NodeSV *q = p->next; q != NULL; q = q->next)
        {
            if (p->infoSV.bd.diemTBHK < q->infoSV.bd.diemTBHK)
            {
                SinhVien tmp;
                tmp = p->infoSV;
                p->infoSV = q->infoSV;
                q->infoSV = tmp;
            }
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nDanh sach sau khi sap xep theo thu tu giam\n";
    printListBD(listsv);
    cout << "\n_______________________________________________________\n";
}

void removeBDSVById(ListSinhVien listsv)
{
    NodeSV *p = listsv.head;
    NodeSV *q;
    q = NULL;
    int id;
    cout << "Nhap ma sinh vien can xoa de xoa bang diem: ";
    cin >> id;
    while (p != NULL)
    {
        if (id == p->infoSV.maSV)
            break;
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Khong tim thay ma sinh vien!!!" << endl;
        exit(1);
    }
    if (q != NULL)
    {
        if (p == listsv.tail)
            listsv.tail = q;
        q->next = p->next;
        delete p;
    }
    else
    {
        listsv.head = p->next;
        if (listsv.head == NULL)
        {
            listsv.tail = NULL;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nDanh sach sau khi xoa sinh vien co ma " << id << " \n";
    printListBD(listsv);
    cout << "\n_______________________________________________________\n";
}

void editBDSVById(ListSinhVien listsv)
{
    int id;
    cout << "Nhap ma sinh vien can sua bang diem: ";
    cin >> id;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (id == p->infoSV.maSV)
        {
            cout << "\nSua diem sinh vien";
            cout << "\nSua diem 45p: ";
            cin >> p->infoSV.bd.diem45p;
            cout << "\nSua diem giua ki: ";
            cin >> p->infoSV.bd.diemGK;
            cout << "\nSua diem thi: ";
            cin >> p->infoSV.bd.diemThi;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nDanh sach sau khi sua sinh vien co ma " << id << " \n";
    printListBD(listsv);
    cout << "\n_______________________________________________________\n";
}

void editBDSVPoint3(ListSinhVien listsv0)
{
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (p->infoSV.bd.diemTBHK <= 3)
        {
            cout << "\nSua diem sinh vien";
            cout << "\nSua diem 45p: ";
            cin >> p->infoSV.bd.diem45p;
            cout << "\nSua diem giua ki: ";
            cin >> p->infoSV.bd.diemGK;
            cout << "\nSua diem thi: ";
            cin >> p->infoSV.bd.diemThi;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nDanh sach sau khi sua sinh vien co diem duoi 3 "
         << " \n";
    printListBD(listsv);
    cout << "\n_______________________________________________________\n";
}

void countBDSVPointAny(ListSinhVien listsv)
{
    int count = 0;
    float point;
    cout << "Nhap 1 diem so bat ki: ";
    cin >> point;
    for (NodeSV *p = listsv.head; p != NULL; p = p->next)
    {
        if (p->infoSV.bd.diemTBHK > point)
        {
            count++;
        }
    }
    cout << "\n_____________________________________________________________________\n";
    cout << "\nCo " << count << " sinh vien co diem tong trung binh hoc ki tren " << point << "\n";
    cout << "\n_____________________________________________________________________\n";
}

int main()
{
    ListSinhVien listsv;
    int chon;
    do
    {
        cout << "----- QUAN LI DIEM SINH VIEN ------";
        cout << "\n1. Nhap danh sach bang diem";
        cout << "\n2. In danh sach bang diem";
        cout << "\n3. In thong tin bang diem cua sinh vien theo ma sinh vien";
        cout << "\n4. Them 1 bang diem vao dau danh sach";
        cout << "\n5. Them 1 bang diem vao cuoi danh sach";
        cout << "\n6. Tim kiem bang diem cua sinh vien theo ma sinh vien";
        cout << "\n7. Tinh tong diem cua 1 sinh vien theo ma sinh vien";
        cout << "\n8. Tinh trung binh cong diem cua 1 sinh vien theo ma sinh vien";
        cout << "\n9. In thong tin sinh vien co diem trung binh cong lon nhat";
        cout << "\n10. In thong tin sinh vien co diem trung binh cong nho nhat";
        cout << "\n11. Sap xep danh sach bang diem theo thu tu tang dan";
        cout << "\n12. Sap xep danh sach bang diem theo thu tu giam dan";
        cout << "\n13. Xoa bang diem theo ma sinh vien";
        cout << "\n14. Sua diem cua sinh vien theo ma sinh vien";
        cout << "\n15. Sua diem cua sinh vien co diem trung binh cong duoi 3";
        cout << "\n16. Dem so sinh vien co diem trung binh hoc ki tren 1 con so nao do";
        cout << "\n17. Dem so sinh vien co diem trung binh hoc ki trong 1 khoang nao do";
        cout << "\n18. In danh sach sinh vien co diem tong trung binh hoc ki duoi trung binh";
        cout << "\n19. Ghi file (ten file duoc nhap tu ban phim)";
        cout << "\n20. Doc file (ten file duoc nhap tu ban phim)";
        cout << "\n0. Thoat khoi chuong trinh";
        cout << "\nMoi ban chon chuc nang de thuc hien: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            importListBD(listsv);
            break;
        case 2:
            printListBD(listsv);
            break;
        case 3:
            printById(listsv);
            break;
        case 4:
            insertFirstBD(listsv);
            break;
        case 5:
            insertTailBD(listsv);
            break;
        case 6:
            findByName(listsv);
            break;
        case 7:
            totalPointBDSV(listsv);
            break;
        case 8:
            averangePointBDSV(listsv);
            break;
        case 9:
            printBDSVMax(listsv);
            break;
        case 10:
            printBDSVMin(listsv);
            break;
        case 11:
            sortListBDSVRise(listsv);
            break;
        case 12:
            sortListBDSVReduce(listsv);
            break;
        case 13:
            removeBDSVById(listsv);
            break;
        case 14:
            editBDSVById(listsv);
            break;
        case 15:
            countBDSVPointAny(listsv);
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (chon != 0);
    cout << "Tiep tuc - 0.Ket thuc: ";
    cin >> chon;
    system("color");
    return 0;
}
