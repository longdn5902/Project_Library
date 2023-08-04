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
    cout << "3.Tim thong tin sinh vien" << endl;
    cout << "4.Hien thi thong tin sinh vien" << endl;
    cout << "5.Exit" << endl;
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

void timsv(const string& filename,const string&ms){
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }
    vector<sinhvien> Sinhviens;
    while (inFile >> Sv.masv >> Sv.tensv >> Sv.email >> Sv.sdt){
        if(Sv.masv==ms)
            Sinhviens.push_back(Sv);
    }
    inFile.close();
    if(Sinhviens.empty()){
        cout << "\nKhong tim thay sinh vien co ma " << ms << " trong file." << endl;
    }
    else{
        cout << "THong tin sinh vien ma ban muon tim " << endl;
        for(const auto& sv :Sinhviens){
            cout << sv.masv << "\t" << sv.tensv <<"\t"<<sv.email<<"\t"<<sv.sdt<<"\n";
        }
    }

}

muonsach Nhapphieumuon(){
    muonsach phieumuon;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, phieumuon.tensv);
    cout << "Nhap ma sinh vien: ";
    getline(cin, phieumuon.masv);
    cout << "Nhap email: ";
    getline(cin, phieumuon.email);
    cout << "Nhap so dien thoai: ";
    getline(cin, phieumuon.sdt);
    cout << "Nhap ten sach: ";
    getline(cin, phieumuon.tensach);
    cout << "Nhap ma sach: ";
    getline(cin, phieumuon.masach);
    cout << "Nhap ngay muon (ngay thang nam cach nhau boi dau cach): ";
    cin >> phieumuon.ngaymuon >> phieumuon.thangmuon >> phieumuon.nammuon;
    return phieumuon;
}

void themmuon(const muonsach& phieumuon,const string& filemuon){
    vector<book> books;
    ifstream inFile("book_info.txt");
    if(!inFile){
        cout << "Khong the mo file" << endl;
        return;
    }

    book bookdata;
    while (inFile >> bookdata.masach >> bookdata.tensach >> bookdata.tacgia >> bookdata.namxb >> bookdata.giasach >> bookdata.soluong)
    {
        books.push_back(bookdata);
    }
    inFile.close();
    bool found = false;
    for(auto& bookdata: books){
        if(bookdata.masach==phieumuon.masach){
            if(bookdata.soluong>0){
                bookdata.soluong--;
                found = true;
            }else{
                cout << "sach da het"<<endl;
                return;
            }
            break;
        }
    }
    if(!found){
        cout << "ko tim thay sach" << endl;
        return;
    }
    ofstream outFile("book_info.txt");
    if(!outFile){
        cout << "khong mo duoc file" << endl;
        return;
    }
    for(const auto& bookdata : books){
        outFile << bookdata.masach << "\t" << bookdata.tensach << "\t" << bookdata.tacgia << "\t" << bookdata.namxb << "\t" << bookdata.giasach << "\t" << bookdata.soluong << "\n";
    }
    outFile.close();
    ofstream outFile2("muonsach_info.txt",ios::app);
    if(!outFile2){
        cout << "Khong the mo file." << endl;
        return;
    }
    outFile2 << phieumuon.tensv << "\t" << phieumuon.masv << "\t" << phieumuon.email << "\t" << phieumuon.sdt
            << "\t" << phieumuon.tensach << "\t" << phieumuon.masach << "\t" << phieumuon.ngaymuon << "\t" << phieumuon.thangmuon << "\t" << phieumuon.nammuon << "\n";
    outFile2.close();
    cout << "Da them phieu muon vao file. " << endl;
}
void timphieumuon(const string& filename,const string&ms){
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    muonsach phieumuon;
    bool found = false;
    while (inFile >> phieumuon.tensv >> phieumuon.masv >> phieumuon.email >> phieumuon.sdt
                >> phieumuon.tensach >> phieumuon.masach >> phieumuon.ngaymuon >> phieumuon.thangmuon >> phieumuon.nammuon) {
        if (phieumuon.masach == ms) {
            found = true;
            cout << "Ten sinh vien: " << phieumuon.tensv << endl;
            cout << "Ma sinh vien: " << phieumuon.masv << endl;
            cout << "Email: " << phieumuon.email << endl;
            cout << "So dien thoai: " << phieumuon.sdt << endl;
            cout << "Ten sach: " << phieumuon.tensach << endl;
            cout << "Ma sach: " << phieumuon.masach << endl;
            cout << "Ngay muon: " << phieumuon.ngaymuon << "/" << phieumuon.thangmuon << "/" << phieumuon.nammuon << endl;
            cout << "---------------------" << endl;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Khong tim thay phieu muon cho sach co ma " << ms << endl;
    }

}
void xoaphieumuon(const string& filename,const string&ms) {
    vector<muonsach> muonsachs;
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    muonsach phieumuon;
    bool found = false;
    while (inFile >> phieumuon.tensv >> phieumuon.masv >> phieumuon.email >> phieumuon.sdt
                >> phieumuon.tensach >> phieumuon.masach >> phieumuon.ngaymuon >> phieumuon.thangmuon >> phieumuon.nammuon) {
        if (phieumuon.masach != ms) {
            muonsachs.push_back(phieumuon);
        } else {
            found = true;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Khong tim thay phiieu muon co ma sach " << ms << " de xoa." << endl;
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    for (const auto& phieumuon : muonsachs) {
        outFile << phieumuon.tensv << "\t" << phieumuon.masv << "\t" << phieumuon.email << "\t" << phieumuon.sdt
                << "\t" << phieumuon.tensach << "\t" << phieumuon.masach << "\t" << phieumuon.ngaymuon << "\t" << phieumuon.thangmuon << "\t" << phieumuon.nammuon << "\n";
    }

    outFile.close();
    cout << "Da xoa phieu muon co ma sach " << ms << " khoi file." << endl;
}

trasach Nhapphieutra(){
    trasach phieutra;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, phieutra.tensv);
    cout << "Nhap ma sinh vien: ";
    getline(cin, phieutra.masv);
    cout << "Nhap email: ";
    getline(cin, phieutra.email);
    cout << "Nhap so dien thoai: ";
    getline(cin, phieutra.sdt);
    cout << "Nhap ten sach: ";
    getline(cin, phieutra.tensach);
    cout << "Nhap ma sach: ";
    getline(cin, phieutra.masach);
    cout << "Nhap ngay muon (ngay thang nam cach nhau boi dau cach): ";
    cin >> phieutra.ngaytra >> phieutra.thangtra >> phieutra.namtra;
    return phieutra;
}

void themtra(const trasach& phieutra,const string& filemuon){
    vector<muonsach> muonsachs;
    ifstream inFile("muonsach_info.txt");
    if(!inFile){
        cout << "khong mo duoc file " << endl;
        return;
    }
    muonsach datamuon;
    while (inFile >> datamuon.masv >> datamuon.tensv >> datamuon.email >> datamuon.sdt >> datamuon.tensach 
    >> datamuon.masach >> datamuon.ngaymuon >> datamuon.thangmuon >> datamuon.nammuon)
    {
        muonsachs.push_back(datamuon);
    }
    inFile.close();
    bool found = false;
    for(auto& datamuon: muonsachs){
        if(datamuon.masach == phieutra.masach){
            xoaphieumuon("muonsach_info.txt",datamuon.masach);
            found = true;
        }
        break;
    }
    if(!found){
        cout << "ko tim thay phieu muon" << endl;
        return;
    }
    ofstream outFile1("muonsach_info.txt",ios::app);
    if(!outFile1){
        cout << "Khong the mo file." << endl;
        return;
    }
    outFile1 << datamuon.tensv << "\t" << datamuon.masv << "\t" << datamuon.email << "\t" << datamuon.sdt
            << "\t" << datamuon.tensach << "\t" << datamuon.masach << "\t" << datamuon.ngaymuon << "\t" << datamuon.thangmuon << "\t" << datamuon.nammuon << "\n";
    outFile1.close();
    ofstream outFile2("trasach_info.txt",ios::app);
    if(!outFile2){
        cout << "Khong the mo file." << endl;
        return;
    }
    outFile2 << phieutra.tensv << "\t" << phieutra.masv << "\t" << phieutra.email << "\t" << phieutra.sdt
            << "\t" << phieutra.tensach << "\t" << phieutra.masach << "\t" << phieutra.ngaytra << "\t" << phieutra.thangtra << "\t" << phieutra.namtra << "\n";
    outFile2.close();
    cout << "Da them phieu tra vao file. " << endl;
}

void xoaphieutra(const string& filename,const string&ms) {
    vector<trasach> trasachs;
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    trasach phieutra;
    bool found = false;
    while (inFile >> phieutra.tensv >> phieutra.masv >> phieutra.email >> phieutra.sdt
                >> phieutra.tensach >> phieutra.masach >> phieutra.ngaytra >> phieutra.thangtra >> phieutra.namtra) {
        if (phieutra.masach != ms) {
            trasachs.push_back(phieutra);
        } else {
            found = true;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Khong tim thay phieu tra co ma sach " << ms << " de xoa." << endl;
        return;
    }

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    for (const auto& phieutra : trasachs) {
        outFile << phieutra.tensv << "\t" << phieutra.masv << "\t" << phieutra.email << "\t" << phieutra.sdt
                << "\t" << phieutra.tensach << "\t" << phieutra.masach << "\t" << phieutra.namtra << "\t" << phieutra.thangtra << "\t" << phieutra.namtra << "\n";
    }

    outFile.close();
    cout << "Da xoa phieu tra co ma sach " << ms << " khoi file." << endl;
}

void timphieutra(const string& filename,const string&ms){
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    trasach phieutra;
    bool found = false;
    while (inFile >> phieutra.tensv >> phieutra.masv >> phieutra.email >> phieutra.sdt
                >> phieutra.tensach >> phieutra.masach >> phieutra.ngaytra >> phieutra.ngaytra >> phieutra.namtra) {
        if (phieutra.masach == ms) {
            found = true;
            cout << "Ten sinh vien: " << phieutra.tensv << endl;
            cout << "Ma sinh vien: " << phieutra.masv << endl;
            cout << "Email: " << phieutra.email << endl;
            cout << "So dien thoai: " << phieutra.sdt << endl;
            cout << "Ten sach: " << phieutra.tensach << endl;
            cout << "Ma sach: " << phieutra.masach << endl;
            cout << "Ngay tra: " << phieutra.ngaytra << "/" << phieutra.thangtra << "/" << phieutra.namtra << endl;
            cout << "---------------------" << endl;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Khong tim thay phieu tra cho sach co ma " << ms << endl;
    }

}

int main(){
    int choice1;
    do{
        system("cls");
        displaymenu1();
        cin >> choice1;    
        switch (choice1)
        {
        case 1:
            {
                system("cls");
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
                system("cls");
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
                        cout << "========== tim thong tin sv =========="<<endl;
                        string mas;
                        cout << "Nhap ma sinh vien muon tim:  ";
                        cin.ignore();
                        getline(cin,mas);
                        timsv("sinhvien_info.txt",mas);
                        break;
                    }
                    case 4:{
                        cout << "========== hien thi thong tin sv =========="<<endl;
                        hienthi("sinhvien_info.txt");
                        break;                        }
                    default:
                        cout << "Nhap lai lua chon";
                        break;
                    }
                    displaymenu3();
                }while(choice3!=5);
            }
            break;
        case 3:
            {
                system("cls");
                displaymenu4();
                int choice4;
                do{
                    cin >> choice4;
                    switch (choice4)
                    {
                    case 1:{
                        cout << "========== them phieu muon =========="<<endl;
                        muonsach phieumuon = Nhapphieumuon();
                        themmuon(phieumuon,"muonsach_info.txt");     
                        break;
                    }
                    case 2:{
                        hienthi("muonsach_info.txt");
                        break;
                    }
                    case 3:{
                        cout << "========== xoa phieu muon =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach cua phieu muon muon xoa:  ";
                        cin.ignore();
                        getline(cin,mas);
                        xoaphieumuon("muonsach_info.txt",mas);
                        break;
                    }
                    case 4:{
                        cout << "========== tim phieu muon =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach ban muon tim phieu muon:  ";
                        cin.ignore();
                        getline(cin,mas);
                        timphieumuon("muonsach_info.txt",mas);
                        break;
                    }          
                    default:
                        cout << "Nhap lai lua chon";
                        break;
                    }
                    displaymenu4();
                }while (choice4!=5);
       
            }
            break;    
        case 4:
            {
                system("cls");
                displaymenu5();
                int choice5;
                do{
                    cin >> choice5;
                    switch (choice5)
                    {
                    case 1:{
                        cout << "========== them phieu tra =========="<<endl;
                        trasach phieutra = Nhapphieutra();
                        themtra(phieutra,"trasach_info.txt");     
                        break;
                    }
                    case 2:{
                        hienthi("trasach_info.txt");
                        break;
                    }
                    case 3:{
                        cout << "========== xoa phieu tra =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach cua phieu tra muon xoa:  ";
                        cin.ignore();
                        getline(cin,mas);
                        xoaphieutra("trasach_info.txt",mas);
                        break;
                    }
                    case 4:{
                        cout << "========== tim phieu tra =========="<<endl;
                        string mas;
                        cout << "Nhap ma sach ban muon tim phieu tra:  ";
                        cin.ignore();
                        getline(cin,mas);
                        timphieutra("trasach_info.txt",mas);
                        break;
                    }
                    default:
                        break;
                    }
                }while(choice5!=5);
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
