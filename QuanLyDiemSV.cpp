#include <bits/stdc++.h>
using namespace std;

// SinhVien
struct SinhVien
{
    char maSV[50];
    char tenSV[50];
    char lop[50];
    char giaoVien[50];
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
typedef ListSinhVien listsv;

void initSV(ListSinhVien &listsv)
{
    listsv.tail = NULL;
    listsv.head = NULL;
}

NodeSV *getNodeSV(SinhVien x)
{
    NodeSV *p;
    p = new NodeSV;
    if (p == NULL)
    {
        cout << "Khong du bo nho!!";
        exit(1);
    }
    p->infoSV = x;
    p->next = NULL;
    return p;
}

void importSV(SinhVien &sv)
{
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    gets(sv.maSV);
    cout << "\nNhap ten sinh vien: ";
    fflush(stdin);
    gets(sv.tenSV);
    cout << "\nNhap lop: ";
    fflush(stdin);
    gets(sv.lop);
    cout << "\nNhap giao vien: ";
    fflush(stdin);
    gets(sv.giaoVien);
}

void printSV(SinhVien sv)
{
    cout << setw(12) << sv.maSV << " | ";
    cout << setw(10) << sv.tenSV << " | ";
    cout << setw(10) << sv.lop << " | ";
    cout << setw(10) << sv.giaoVien << " | ";
}

// BangDiem
struct BangDiem
{
    float diem45p, diemGK, diemThi;
    float diemTBHK;
    SinhVien listSV;
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
typedef ListBangDiem listbd;

void initBD(ListBangDiem &listbd)
{
    listbd.head = NULL;
    listbd.tail = NULL;
};

NodeBD *getNodeBD(BangDiem x)
{
    NodeBD *p;
    p = new NodeBD;
    if (p == NULL)
    {
        cout << "Khong du bo nho!!";
        exit(1);
    }
    p->infoBD = x;
    p->next = NULL;
    return p;
}

void insertFirstBD(ListBangDiem &listbd, NodeBD *p)
{
    if (listbd.head == NULL)
    {
        listbd.head = p;
        listbd.tail = p;
    }
    else
    {
        p->next = listbd.head;
        listbd.head = p;
    }
}

void insertTailBD(ListBangDiem &listbd, NodeBD *p)
{
    if (listbd.head == NULL)
    {
        listbd.head = p;
        listbd.tail = p;
    }
    else
    {
        listbd.tail->next = p;
        listbd.tail = p;
    }
}

void importBD(BangDiem &bd)
{
    cout << "\nNhap thong tin sinh vien\n";
    importSV(bd.listSV);
    cout << "\nNhap thong tin bang diem cua sinh vien\n";
    cout << "\nNhap diem 45': ";
    cin >> bd.diem45p;
    cout << "\nNhap diem GK: ";
    cin >> bd.diemGK;
    cout << "\nNhap diem thi: ";
    cin >> bd.diemThi;
}

void printBD(BangDiem bd)
{
    printSV(bd.listSV);
    cout << setw(10) << bd.diem45p << " | ";
    cout << setw(10) << bd.diemGK << " | ";
    cout << setw(10) << bd.diemThi << " | ";
    cout << setw(10) << (bd.diemTBHK = (bd.diem45p * 0.2) + (bd.diemGK * 0.3) + (bd.diemThi * 0.5)) << " | " << endl;
}

void importListBD(ListBangDiem &listbd)
{
    int n;
    cout << "Nhap so luong bang diem: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap bang diem thu " << i + 1 << endl;
        BangDiem bd;
        importBD(bd);
        NodeBD *p = getNodeBD(bd);
        insertFirstBD(listbd, p);
    }
}

void printListBD(ListBangDiem &listbd)
{
    cout << "-------------------------- DANH SACH BANG DIEM CUA HOC SINH ------------------------" << endl;
    cout << setw(10) << "Ma sinh vien"
         << " | ";
    cout << setw(10) << "Ho ten"
         << " | ";
    cout << setw(10) << "Lop"
         << " | ";
    cout << setw(10) << "Giao vien"
         << " | ";
    cout << setw(10) << "Diem 45 phut"
         << " | ";
    cout << setw(10) << "Diem GK"
         << " | ";
    cout << setw(10) << "Diem thi"
         << " | ";
    cout << setw(10) << "Diem TBHK"
         << " | " << endl;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        printBD(p->infoBD);
        cout << "\n____________________________________________________________________________________________________________\n";
    }
}

void saveFileBD(ListBangDiem listbd)
{
    char namefile[50];
    cout << "Nhap file can ghi: ";
    fflush(stdin);
    gets(namefile);
    FILE *f;
    NodeBD *p;
    f = fopen(namefile, "wb");
    int n = 0;
    for (p = listbd.head; p != NULL; p = p->next)
        n++;
    fwrite(&n, sizeof(int), 1, f);
    for (p = listbd.head; p != NULL; p = p->next)
    {
        fwrite(&p->infoBD, sizeof(BangDiem), 1, f);
    }
    fclose(f);
    cout << "Luu file " << namefile << " thanh cong........" << endl;
}

void readFileBD(ListBangDiem &listbd)
{
    char namefile[50];
    cout << "Nhap file can doc: ";
    fflush(stdin);
    gets(namefile);
    FILE *f;
    BangDiem bd;
    NodeBD *p;
    int n;
    f = fopen(namefile, "rb");
    fread(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; i++)
    {
        fread(&bd, sizeof(BangDiem), 1, f);
        p = getNodeBD(bd);
        insertTailBD(listbd, p);
    }
    printListBD(listbd);
    fclose(f);
}

void printById(ListBangDiem listbd)
{
    NodeBD *p;
    p = listbd.head;
    char id[50];
    cout << "Nhap ma sinh vien can in thong tin bang diem: ";
    fflush(stdin);
    gets(id);
    while (p != NULL)
    {
        if (strcmp(id, p->infoBD.listSV.maSV) == 0)
            break;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Khong co ma sinh vien " << id << " trong danh sach" << endl;
        cout << "\n__________________________________________________________________\n";
    }
    else
    {
        cout << "Thong tin bang diem sinh vien co ma: " << id << endl;
        cout << "\n____________________________________________________________________________________________________________\n";
        cout << setw(10) << "Ma sinh vien"
             << " | ";
        cout << setw(10) << "Ho ten"
             << " | ";
        cout << setw(10) << "Lop"
             << " | ";
        cout << setw(10) << "Giao vien"
             << " | ";
        cout << setw(10) << "Diem 45 phut"
             << " | ";
        cout << setw(10) << "Diem GK"
             << " | ";
        cout << setw(10) << "Diem thi"
             << " | ";
        cout << setw(10) << "Diem TBHK"
             << " | " << endl;
        printBD(p->infoBD);
        cout << "\n____________________________________________________________________________________________________________\n";
    }
}

void findById(ListBangDiem listbd)
{
    NodeBD *p;
    p = listbd.head;
    char id[50];
    cout << "Nhap ma sinh vien de tim kiem bang diem: ";
    fflush(stdin);
    gets(id);
    while (p != NULL)
    {
        if (strcmp(id, p->infoBD.listSV.maSV) == 0)
            break;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Khong tim thay ma sinh vien " << id << " trong danh sach" << endl;
        cout << "\n__________________________________________________________________\n";
    }
    else
    {
        cout << "Thong tin bang diem sinh vien co ma: " << id << endl;
        cout << "\n____________________________________________________________________________________________________________\n";
        cout << setw(10) << "Ma sinh vien"
             << " | ";
        cout << setw(10) << "Ho ten"
             << " | ";
        cout << setw(10) << "Lop"
             << " | ";
        cout << setw(10) << "Giao vien"
             << " | ";
        cout << setw(10) << "Diem 45 phut"
             << " | ";
        cout << setw(10) << "Diem GK"
             << " | ";
        cout << setw(10) << "Diem thi"
             << " | ";
        cout << setw(10) << "Diem TBHK"
             << " | " << endl;
        printBD(p->infoBD);
        cout << "\n____________________________________________________________________________________________________________\n";
    }
}

void addFirstBD(ListBangDiem listbd)
{
    int n;
    cout << "Nhap so luong bnag diem can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        BangDiem bd;
        importBD(bd);
        NodeBD *p = getNodeBD(bd);
        insertFirstBD(listbd, p);
    }
    printListBD(listbd);
}

void addTailBD(ListBangDiem listbd)
{
    int n;
    cout << "Nhap so bang diem can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        BangDiem bd;
        importBD(bd);
        NodeBD *p = getNodeBD(bd);
        insertTailBD(listbd, p);
    }
    printListBD(listbd);
}

void totalPointBDSV(ListBangDiem &listbd)
{
    float total = 0;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        total += (p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5);
    }
    cout << "\n_______________________________________________________\n";
    cout << "Tong diem trung binh hoc ki cua tat ca cac sinh vien la: " << total << endl;
    cout << "\n_______________________________________________________\n";
}

void averangePointBDSV(ListBangDiem &listbd)
{
    char id[50];
    float avr = 0;
    cout << "Nhap ma sinh vien can tinh diem trung binh: ";
    fflush(stdin);
    gets(id);
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        if (strcmp(id, p->infoBD.listSV.maSV) == 0)
        {
            avr = p->infoBD.diem45p + p->infoBD.diemGK + p->infoBD.diemThi;
        }
    }
    cout << "\n_______________________________________________________\n";
    cout << "Diem trung binh cong cua sinh vien co ma " << id << " la: " << (avr / 3) << endl;
    cout << "\n_______________________________________________________\n";
}

void printBDSVMax(ListBangDiem listbd)
{
    int max;
    NodeBD *p = listbd.head;
    max = p->infoBD.diemThi;
    while (p != NULL)
    {
        if (max < p->infoBD.diemThi)
            max = p->infoBD.diemThi;
        p = p->next;
    }
    cout << "\nDanh sach sinh vien co diem thi thap nhat\n";
    cout << setw(10) << "Ma sinh vien"
         << " | ";
    cout << setw(10) << "Ho ten"
         << " | ";
    cout << setw(10) << "Lop"
         << " | ";
    cout << setw(10) << "Giao vien"
         << " | ";
    cout << setw(10) << "Diem 45 phut"
         << " | ";
    cout << setw(10) << "Diem GK"
         << " | ";
    cout << setw(10) << "Diem thi"
         << " | ";
    cout << setw(10) << "Diem TBHK"
         << " | " << endl;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        if (p->infoBD.diemThi == max)
        {
            printBD(p->infoBD);
        }
    }
}

void printBDSVMin(ListBangDiem listbd)
{
    int min;
    NodeBD *p = listbd.head;
    min = p->infoBD.diemThi;
    while (p != NULL)
    {
        if (min > p->infoBD.diemThi)
            min = p->infoBD.diemThi;
        p = p->next;
    }
    cout << "\nDanh sach sinh vien co diem thi thap nhat\n";
    cout << setw(10) << "Ma sinh vien"
         << " | ";
    cout << setw(10) << "Ho ten"
         << " | ";
    cout << setw(10) << "Lop"
         << " | ";
    cout << setw(10) << "Giao vien"
         << " | ";
    cout << setw(10) << "Diem 45 phut"
         << " | ";
    cout << setw(10) << "Diem GK"
         << " | ";
    cout << setw(10) << "Diem thi"
         << " | ";
    cout << setw(10) << "Diem TBHK"
         << " | " << endl;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        if (p->infoBD.diemThi == min)
        {
            printBD(p->infoBD);
        }
    }
}

void sortListBDSVRise(ListBangDiem listbd)
{
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        for (NodeBD *q = p->next; q != NULL; q = q->next)
        {
            if ((p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) > (q->infoBD.diem45p * 0.2 + q->infoBD.diemGK * 0.3 + q->infoBD.diemThi * 0.5))
            {
                BangDiem tmp;
                tmp = p->infoBD;
                p->infoBD = q->infoBD;
                q->infoBD = tmp;
            }
        }
    }
    cout << "\n____________________________________________________________________________________________________________\n";
    printListBD(listbd);
    cout << "\n____________________________________________________________________________________________________________\n";
}

void sortListBDSVReduce(ListBangDiem listbd)
{
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        for (NodeBD *q = p->next; q != NULL; q = q->next)
        {
            if ((p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) < (q->infoBD.diem45p * 0.2 + q->infoBD.diemGK * 0.3 + q->infoBD.diemThi * 0.5))
            {
                BangDiem tmp;
                tmp = p->infoBD;
                p->infoBD = q->infoBD;
                q->infoBD = tmp;
            }
        }
    }
    cout << "\n_______________________________________________________\n";
    printListBD(listbd);
    cout << "\n_______________________________________________________\n";
}

void removeBDSVById(ListBangDiem listbd)
{
    NodeBD *p = listbd.head;
    NodeBD *q;
    q = NULL;
    char id[50];
    cout << "Nhap ma sinh vien can xoa de xoa bang diem: ";
    fflush(stdin);
    gets(id);
    while (p != NULL)
    {
        if (strcmp(id, p->infoBD.listSV.maSV) == 0)
        {
            break;
        }
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Khong tim thay ma sinh vien " << id << " !!!" << endl;
    }
    if (q != NULL)
    {
        if (p == listbd.tail)
            listbd.tail = q;
        q->next = p->next;
        delete p;
    }
    else
    {
        listbd.head = p->next;
        if (listbd.head == NULL)
            listbd.tail = NULL;
    }
    cout << "\n_______________________________________________________\n";
    cout << "\nDanh sach sau khi xoa sinh vien co ma " << id << " \n";
    printListBD(listbd);
    cout << "\n_______________________________________________________\n";
}

void editBDSVById(ListBangDiem listbd)
{
    NodeBD *p;
    p = listbd.head;
    char id[50];
    cout << "Nhap ma sinh vien can sua bang diem: ";
    fflush(stdin);
    gets(id);
    while (p != NULL)
    {
        if (strcmp(id, p->infoBD.listSV.maSV) == 0)
            break;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Ma sinh vien " << id << " khong ton tai!!" << endl;
        cout << "\n__________________________________________________________________\n";
    }
    else
    {
        cout << "Sua diem sinh vien co ma: " << id << endl;
        cout << "\nDiem 45 phut:";
        cin >> p->infoBD.diem45p;
        cout << "\nDiem giua ki: ";
        cin >> p->infoBD.diemGK;
        cout << "\nDiem thi: ";
        cin >> p->infoBD.diemThi;
    }
    cout << "\n_______________________________________________________\n";
    printListBD(listbd);
    cout << "\n_______________________________________________________\n";
}

void editBDSVPoint3(ListBangDiem listbd)
{
    NodeBD *p;
    p = listbd.head;
    for (p = listbd.head; p != NULL; p = p->next)
    {
        if ((p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) <= 3)
        {
            cout << "Sua diem sinh vien co diem tong trung binh duoi 3: " << endl;
            cout << "\nDiem 45 phut:";
            cin >> p->infoBD.diem45p;
            cout << "\nDiem giua ki: ";
            cin >> p->infoBD.diemGK;
            cout << "\nDiem thi: ";
            cin >> p->infoBD.diemThi;
        }
    }
    if (p == NULL)
    {
        cout << "Khong co sinh vien nao co diem tong trung binh hoc ki duoi 3!!" << endl;
        cout << "\n__________________________________________________________________\n";
    }
}

void countBDSVPointAny(ListBangDiem listbd)
{
    int count = 0;
    float point;
    cout << "Nhap 1 diem so bat ki: ";
    cin >> point;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        if ((p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) > point)
        {
            count++;
        }
    }
    cout << "\n_____________________________________________________________________\n";
    cout << "\nCo " << count << " sinh vien co diem tong trung binh hoc ki tren " << point << "\n";
    cout << "\n_____________________________________________________________________\n";
}

void countBDSVAB(ListBangDiem listbd)
{
    int count = 0;
    int a, b;
    cout << "Nhap khoang a: ";
    cin >> a;
    cout << "\nNhap khoang b: ";
    cin >> b;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        if ((p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) >= a && (p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) <= b)
        {
            count++;
        }
    }
    cout << "\n_____________________________________________________________________\n";
    cout << "\nCo " << count << " sinh vien  co bang diem thuoc khoang  (" << a << ";" << b << ")";
    cout << "\n_____________________________________________________________________\n";
}

void printBDSVTB(ListBangDiem listbd)
{
    NodeBD *p;
    p = listbd.head;
    for (p = listbd.head; p != NULL; p = p->next)
    {
        if ((p->infoBD.diem45p * 0.2 + p->infoBD.diemGK * 0.3 + p->infoBD.diemThi * 0.5) < 5)
        {
            cout << "___________________________________________________________________________________________" << endl;
            cout << setw(10) << "Ma sinh vien"
                 << " | ";
            cout << setw(10) << "Ho ten"
                 << " | ";
            cout << setw(10) << "Lop"
                 << " | ";
            cout << setw(10) << "Giao vien"
                 << " | ";
            cout << setw(10) << "Diem 45 phut"
                 << " | ";
            cout << setw(10) << "Diem GK"
                 << " | ";
            cout << setw(10) << "Diem thi"
                 << " | ";
            cout << setw(10) << "Diem TBHK"
                 << " | " << endl;
            printBD(p->infoBD);
            cout << "___________________________________________________________________________________________" << endl;
        }
    }
}

int main()
{
    ListBangDiem listbd;
    initBD(listbd);
    int chon;
    while (chon != 0)
    {
        cout << "-------------------------- QUAN LY BANG DIEM CUA SINH VIEN ------------------------";
        cout << "\n1. Nhap danh sach bang diem";
        cout << "\n2. In danh sach bang diem";
        cout << "\n3. In thong tin bang diem cua sinh vien theo ma sinh vien";
        cout << "\n4. Them 1 bang diem vao dau danh sach";
        cout << "\n5. Them 1 bang diem vao cuoi danh sach";
        cout << "\n6. Tim kiem bang diem cua sinh vien theo ma sinh vien";
        cout << "\n7. Tinh tong diem trung binh hoc ki cua tat ca cac sinh vien";
        cout << "\n8. Tinh trung binh cong diem cua 1 sinh vien theo ma sinh vien";
        cout << "\n9. In thong tin sinh vien co diem thi lon nhat";
        cout << "\n10. In thong tin sinh vien co diem thi nho nhat";
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
            importListBD(listbd);
            break;
        case 2:
            printListBD(listbd);
            break;
        case 3:
            printById(listbd);
            break;
        case 4:
            addFirstBD(listbd);

            break;
        case 5:
            addTailBD(listbd);
            break;
        case 6:
            findById(listbd);
            break;
        case 7:
            totalPointBDSV(listbd);
            break;
        case 8:
            averangePointBDSV(listbd);
            break;
        case 9:
            printBDSVMax(listbd);
            break;
        case 10:
            printBDSVMin(listbd);
            break;
        case 11:
            sortListBDSVRise(listbd);
            break;
        case 12:
            sortListBDSVReduce(listbd);
            break;
        case 13:
            removeBDSVById(listbd);
            break;
        case 14:
            editBDSVById(listbd);
            break;
        case 15:
            editBDSVPoint3(listbd);
            printListBD(listbd);
            break;
        case 16:
            countBDSVPointAny(listbd);
            break;
        case 17:
            countBDSVAB(listbd);
            break;
        case 18:
            printBDSVTB(listbd);
            break;
        case 19:
            saveFileBD(listbd);
            break;
        case 20:
            readFileBD(listbd);
            break;
        case 0:
            break;
        default:
            break;
        }
    }
    return 0;
}
