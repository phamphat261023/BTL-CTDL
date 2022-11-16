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
    listsv.head = NULL;
    listsv.tail = NULL;
};

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
    cin >> sv.maSV;
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
}

// BangDiem
struct BangDiem
{
    float diem45p, diemGK, diemThi;
    float diemTBHK;
    SinhVien sinhvien;
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
    if (listbd.tail == NULL)
    {
        listbd.tail = p;
        listbd.head = p;
    }
    else
    {
        listbd.tail->next = p;
        listbd.tail = p;
    }
}

void importBD(BangDiem &bd)
{
    cout << "Nhap diem 45': ";
    cin >> bd.diem45p;
    cout << "\nNhap diem GK: ";
    cin >> bd.diemGK;
    cout << "\nNhap diem thi: ";
    cin >> bd.diemThi;
    cout << "\nNhap thong tin sinh vien";
    importSV(bd.sinhvien);
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
    cout << setw(10) << (bd.diemTBHK = (bd.diem45p * 0.2) + (bd.diemGK * 0.3) + (bd.diemThi * 0.5)) << " | " << endl;
    cout << "Thong tin sinh vien" << endl;
    printSV(bd.sinhvien);
}

void importListBD(ListBangDiem &listbd)
{
    int n;
    cout << "Nhap so luong bang diem: ";
    initBD(listbd);
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

void printListBD(ListBangDiem listbd)
{
    cout << "----------- DANH SACH BANG DIEM CUA HOC SINH -----------" << endl;
    for (NodeBD *p = listbd.head; p != NULL; p = p->next)
    {
        printBD(p->infoBD);
        cout << "\n_______________________________________________________\n";
    }
}

void saveFile(FILE *f, ListBangDiem listbd, char *namefile)
{
    f = fopen(namefile, "wt");
    if (f == NULL)
    {
        cout << "Loi mo file";
        exit(0);
    }
    else
    {
        int n = 0;
        NodeBD *p;
        for (p = listbd.head; p != NULL; p = p->next)
        {
            n++;
        }
        fwrite(&n, sizeof(int), 1, f);
        for (p = listbd.head; p != NULL; p = p->next)
        {
            fwrite(&p->infoBD, sizeof(BangDiem), 1, f);
        }
        fclose(f);
    }
}

void readFile(FILE *f, ListBangDiem &listbd, char *namefile)
{
    f = fopen(namefile, "rt");
    if (f == NULL)
    {
        cout << "File rong!!";
        exit(1);
    }
    else
    {
        BangDiem bd;
        NodeBD *p;
        int n = 0;
        fread(&n, sizeof(int), 1, f);
        for (int i = 0; i < n; i++)
        {
            fread(&bd, sizeof(BangDiem), 1, f);
            p = getNodeBD(bd);
            insertFirstBD(listbd, p);
        }
        fclose(f);
    }
}

int main()
{
    ListBangDiem listbd;
    FILE *f, *g;
    char namefile[200];
    int chon;

    do
    {
        cout << "1. Nhap bd";
        cout << "\n2. In bang diem";
        cout << "\n3. Luu file";
        cout << "\n4. Doc file";
        cout << "\n0. Thoat";
        cout << "\nMoi chon: ";
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
            cout << "Nhap ten file muon ghi: ";
            fflush(stdin);
            gets(namefile);
            saveFile(f, listbd, namefile);
            cout << "\nGhi file thanh cong.....\n";
            break;
        case 5:
            cout << "Nhap ten file muon doc: ";
            fflush(stdin);
            gets(namefile);
            readFile(f, listbd, namefile);
            cout << "\nDanh sach doc trong file\n";
            printListBD(listbd);
            break;
        case 0:
            break;
        default:
            break;
        }

    } while (chon != 0);
    // do
    // {
    //     cout << "----- QUAN LI DIEM SINH VIEN ------";
    //     cout << "\n1. Nhap danh sach bang diem";
    //     cout << "\n2. In danh sach bang diem";
    //     cout << "\n3. In thong tin bang diem cua sinh vien theo ma sinh vien";
    //     cout << "\n4. Them 1 bang diem vao dau danh sach";
    //     cout << "\n5. Them 1 bang diem vao cuoi danh sach";
    //     cout << "\n6. Tim kiem bang diem cua sinh vien theo ma sinh vien";
    //     cout << "\n7. Tinh tong diem cua 1 sinh vien theo ma sinh vien";
    //     cout << "\n8. Tinh trung binh cong diem cua 1 sinh vien theo ma sinh vien";
    //     cout << "\n9. In thong tin sinh vien co diem trung binh cong lon nhat";
    //     cout << "\n10. In thong tin sinh vien co diem trung binh cong nho nhat";
    //     cout << "\n11. Sap xep danh sach bang diem theo thu tu tang dan";
    //     cout << "\n12. Sap xep danh sach bang diem theo thu tu giam dan";
    //     cout << "\n13. Xoa bang diem theo ma sinh vien";
    //     cout << "\n14. Sua diem cua sinh vien theo ma sinh vien";
    //     cout << "\n15. Sua diem cua sinh vien co diem trung binh cong duoi 3";
    //     cout << "\n16. Dem so sinh vien co diem trung binh hoc ki tren 1 con so nao do";
    //     cout << "\n17. Dem so sinh vien co diem trung binh hoc ki trong 1 khoang nao do";
    //     cout << "\n18. In danh sach sinh vien co diem tong trung binh hoc ki duoi trung binh";
    //     cout << "\n19. Ghi file (ten file duoc nhap tu ban phim)";
    //     cout << "\n20. Doc file (ten file duoc nhap tu ban phim)";
    //     cout << "\n0. Thoat khoi chuong trinh";
    //     cout << "\nMoi ban chon chuc nang de thuc hien: ";
    //     cin >> chon;

    //     switch (chon)
    //     {
    //     case 1:
    //         importListBD(listbd);
    //         break;
    //     case 2:
    //         printListBD(listbd);
    //         break;
    //     case 3:
    //         // printById(listbd);
    //         break;
    //     case 4:
    //         // insertFirstBD(listbd);
    //         break;
    //     case 5:
    //         // insertTailBD(listbd);
    //         break;
    //     case 6:
    //         // findByName(listbd);
    //         break;
    //     case 7:
    //         // totalPointBDSV(listbd);
    //         break;
    //     case 8:
    //         // averangePointBDSV(listbd);
    //         break;
    //     case 9:
    //         // printBDSVMax(listbd);
    //         break;
    //     case 10:
    //         // printBDSVMin(listbd);
    //         break;
    //     case 11:
    //         // sortListBDSVRise(listbd);
    //         break;
    //     case 12:
    //         // sortListBDSVReduce(listbd);
    //         break;
    //     case 13:
    //         // removeBDSVById(listbd);
    //         break;
    //     case 14:
    //         // editBDSVById(listbd);
    //         break;
    //     case 15:
    //         // editBDSVPoint3(listbd);
    //         break;
    //     case 16:
    //         // countBDSVPointAny(listbd);
    //         break;
    //     case 17:
    //         // countBDSVAB(listbd);
    //         break;
    //     case 18:
    //         // printBDSVTB(listbd);
    //         break;
    //     case 19:
    //         cout << "Nhap ten file muon ghi: ";
    //         fflush(stdin);
    //         gets(namefile);
    //         saveFile(f, listbd, namefile);
    //         cout << "\nGhi file thanh cong.....\n";
    //         break;
    //     case 20:
    //         cout << "Nhap ten file muon doc: ";
    //         fflush(stdin);
    //         gets(namefile);
    //         readFile(f, listbd, namefile);
    //         cout << "\nDanh sach doc trong file\n";
    //         printListBD(listbd);
    //         break;
    //     case 0:
    //         break;
    //     default:
    //         break;
    //     }
    // } while (chon != 0);
    // cout << "Tiep tuc - 0.Ket thuc: ";
    // cin >> chon;
    return 0;
}