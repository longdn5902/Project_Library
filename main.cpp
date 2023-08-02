#include<bits/stdc++.h>

using namespace std;

struct book
{
    string tensach;
    string masach;
    string tacgia;
    int namxb;
    int giasach;
    int soluong;
}Book;

struct sinhvien
{
    string tensv;
    string masv;
    string email;
    string sdt;
}Sv;

struct muonsach
{
    string tensv;
    string masv;
    string email;
    string sdt;
    string tensach;
    string masach;
    string soluong;
    int ngaymuon;
    int thangmuon;
    int nammuon;
}Muonsach;

struct trasach{
    string tensv;
    string masv;
    string email;
    string sdt;
    string tensach;
    string masach;
    string soluong;
    int ngaytra;
    int thangtra;
    int namtra;
}Trasach;

void displaymenu1(){
    cout << "========== Menu ==========" << endl;
    cout << "1.Quan ly sach" << endl;
    cout << "2.Quan ly sinh vien" << endl;
    cout << "3.Quan ly muon sach" << endl;
    cout << "4.Quan ly tra sach" << endl;
    cout << "5.Exit" << endl;
    cout << "Nhap lua chon" << endl;
}

void displaymenu2(){
    cout << "========== Menu ==========" << endl;
    cout << "1.Them sach." << endl;
    cout << "2.Xoa sach" << endl;
    cout << "3.Tim kiem sach" << endl;
    cout << "4.Hien thi toan bo thong tin sach. "<<endl;
    cout << "5.Exit" << endl;
    cout << "Nhap lua chon" << endl;
}

void displaymenu3(){
    cout << "========== Menu ==========" << endl;
    cout << "1.Them sinh vien." << endl;
    cout << "2.Xoa sinh vien" << endl;
    cout << "3.Sua thong tin sinh vien" << endl;
    cout << "4.Tim thong tin sinh vien" << endl;
    cout << "5.Hien thi thong tin sinh vien" << endl;
    cout << "6.Exit" << endl;
    cout << "Nhap lua chon" << endl;
}

void displaymenu4(){
    cout << "========== Menu ==========" << endl;
    cout << "1.Them phieu muon. " << endl;
    cout << "2.Hien thi phieu muon. " << endl;
    cout << "3.Xoa phieu muon. " << endl;
    cout << "4.Tim kiem phieu muon. " << endl;
    cout << "5.Exit" << endl;
    cout << "Nhap lua chon" << endl;
}

void displaymenu5(){
    cout << "========== Menu ==========" << endl;
    cout << "1.Them phieu tra sach" << endl;
    cout << "2.Hien thi phieu tra sach" << endl;
    cout << "3.Xoa phieu tra sach" << endl;
    cout << "4.Tim kiem phieu tra sach" << endl;
    cout << "5.Exit" << endl;
    cout << "Nhap lua chon" << endl;
}

void themsach(){
    cout << "Nhap ma sach"<<endl;
    cin.ignore();
    getline(cin,Book.masach);
    cout << "Nhap ten sach"<<endl;
    getline(cin,Book.tensach);
    cout << "Nhap ten tac gia"<<endl;
    getline(cin,Book.tacgia);
    cout << "Nhap nam xuat ban"<<endl;
    cin >> Book.namxb;
    cout << "Nhap gia sach"<<endl;
    cin >> Book.giasach;
    cout << "Nhap sl"<<endl;
    cin >> Book.soluong;
    ofstream outFile("book_info.txt", ios::app);
    if (!outFile) {
        cout << "Khong the mo file." << std::endl;
        return;
    }
    outFile << Book.masach << "\t" << Book.tensach <<"\t"<<Book.tacgia<<"\t"<<Book.namxb<<"\t"<<Book.giasach<<"\t"<<Book.soluong<<"\n"; 
    outFile.close();
}

void xoasach(const string& filename,const string&ms){
    
    vector<book> books;
    ifstream inFile(filename);
    if (!inFile) {
        std::cout << "Khong the mo file." << std::endl;
        return;
    }

    while (inFile >> Book.masach >> Book.tensach >> Book.tacgia >> Book.namxb >> Book.giasach >> Book.soluong) {
        books.push_back(Book);
    }

    inFile.close();

    
    books.erase(std::remove_if(books.begin(), books.end(),
                               [&ms](const book& b) { return b.masach == ms; }),
                books.end());

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    for (const auto& Book : books) {
        outFile << Book.masach << "\t" << Book.tensach << "\t" << Book.tacgia << "\t" << Book.namxb << "\t" << Book.giasach << "\t" << Book.soluong << "\n";
    }

    outFile.close();
    cout << "Da xoa du lieu cua sach co ma " << ms << " ra khoi file." << endl;
}

void timsach(const string& filename,const string&ms){
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }
    vector<book> books;
    while (inFile >> Book.masach >> Book.tensach >> Book.tacgia >> Book.namxb >> Book.giasach>> Book.soluong){
        if(Book.masach==ms)
            books.push_back(Book);
    }
    inFile.close();
    if(books.empty()){
        cout << "\nKhong tim thay sach co ma " << ms << " trong file." << endl;
    }
    else{
        cout << "THong tin sach ma ban muon tim " << endl;
        for(const auto& s :books){
            cout << s.masach << "\t" << s.tensach <<"\t"<<s.tacgia<<"\t"<<s.namxb<<"\t"<<s.giasach<<"\t"<<s.soluong<<"\n";
        }
    }

}

void hienthi(const string& filename){
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void themsv(){
    cout << "Nhap ma sinh vien: " << endl;
    cin.ignore();
    getline(cin,Sv.masv);
    cout << "Nhap ten sinh vien: " << endl;
    getline(cin,Sv.tensv);
    cout << "Nhap email sinh vien: " << endl;
    getline(cin,Sv.email);
    cout << "Nhap sdt sinh vien: ";
    cin >> Sv.sdt;
    ofstream outFile("sinhvien_info.txt", ios::app);
    if (!outFile) {
        cout << "Khong the mo file." << std::endl;
        return;
    }
    outFile << Sv.masv << "\t" << Sv.tensv <<"\t"<<Sv.email<<"\t"<<Sv.sdt<<"\n"; 
    outFile.close();
}
void xoasv(const string& filename,const string&ms){
    vector<sinhvien> Sinhviens;
    ifstream inFile(filename);
    if (!inFile) {
        std::cout << "Khong the mo file." << std::endl;
        return;
    }

    while (inFile >> Sv.masv >> Sv.tensv >> Sv.email >> Sv.sdt) {
        Sinhviens.push_back(Sv);
    }

    inFile.close();

    
    Sinhviens.erase(remove_if(Sinhviens.begin(), Sinhviens.end(),
                               [&ms](const sinhvien& sv) { return sv.masv == ms; }),
                Sinhviens.end());

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    for (const auto& Sv : Sinhviens) {
        outFile << Sv.masv << "\t" << Sv.tensv << "\t" << Sv.email << "\t" << Sv.sdt << "\n";
    }

    outFile.close();
    cout << "Da xoa du lieu cua sach co ma " << ms << " ra khoi file." << endl;
}
void suasv(){}
int main(){
    int choice1;
    do{
        displaymenu1();
        cin >> choice1;
        system("cls");
        switch (choice1)
        {
        case 1:
            {
                displaymenu2();
                int choice2;
                do{
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1:{
                        int ts;
                        system("cls");
                        do{
                        cout << "========== them sach =========="<<endl;
                        themsach();
                        cout << "tiep tuc them sach nhan 1 dung lai nham 0"<<endl;
                        cin >> ts;
                        while(ts != 1 && ts != 0){
                            cout << " nhap lai lua chon cua ban";
                            cin >> ts;
                        }
                        }while (ts!=0);
                        break;
                    }
                           
                    case 2:{
                        system("cls");
                        cout << "========== xoa sach =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach muon xoa:  ";
                        cin.ignore();
                        getline(cin,mas);
                        xoasach("book_info.txt",mas);
                        break;
                    }
                    case 3:{
                        system("cls");
                        cout << "========== tim sach =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach muon tim:  ";
                        cin.ignore();
                        getline(cin,mas);
                        timsach("book_info.txt",mas);
                        break;
                    }
                    case 4:{
                        system("cls");
                        cout << "========== hien thi toan bo sach =========="<<endl;
                        hienthi("book_info.txt");
                        break;
                    }
                    case 5:
                        break;
                    default:
                        cout << "Nhap lai lua chon";
                        break;
                    }
                    displaymenu2();
                    
                }while(choice2!=5);
            }
            break;
        case 2:
            {
                displaymenu3();
                int choice3;
                do{
                    cin >> choice3;
                    switch (choice3)
                    {
                    case 1:{
                        int tsv;
                        do{
                        cout << "========== them sinh vien =========="<<endl;
                        themsv();
                        cout << "tiep tuc them sinh vien nhan 1 dung lai nham 0"<<endl;
                        cin >> tsv;
                        while(tsv != 1 && tsv != 0){
                            cout << " nhap lai lua chon cua ban";
                            cin >> tsv;
                        }
                        }while (tsv!=0);
                        break;
                    }
                           
                    case 2:{
                        cout << "========== xoa sinh vien =========="<<endl;
                        string mas;
                        cout << "Nhap sinh vien muon xoa:  ";
                        cin.ignore();
                        getline(cin,mas);
                        xoasv("sinhvien_info.txt",mas);
                        break;
                    }
                    case 3:{
                        cout << "========== sua thong tin sv =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach muon sua:  ";
                        cin.ignore();
                        getline(cin,mas);
                        suasv();
                        break;
                    }
                    case 4:{
                        
                    }
                    case 5:{
                        cout << "========== hien thi thong tin sv =========="<<endl;
                        hienthi("sinhvien_info.txt");
                        break;                        }
                    default:
                        cout << "Nhap lai lua chon";
                        break;
                    }
                    displaymenu3();
                }while(choice3!=6);
            }
            break;
        case 3:
            {
                displaymenu4();
            }
            break;    
        case 4:
            {
                displaymenu5();
            }
            break;
        case 5:
            cout << "Ket thuc." << endl;
            break;
        default:
            cout << "Nhap lai lua chon." << endl;
            break;
        }
    }while ((choice1 != 5));
    
}
