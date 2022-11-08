#include "QuanLyHD.h"

QuanLyHD::QuanLyHD(){
    this->lengthHD = 0;
}
QuanLyHD::~QuanLyHD(){};
int QuanLyHD::getLengthHD(){
    return this->lengthHD;
}
void QuanLyHD::setLengthHD(int lengthHD){
    this->lengthHD = lengthHD;
}

void QuanLyHD::Insert(QuanLyNV& nv, QuanLyKH& kh, QuanLyHang& hh){
    string sdt;
    nv.Show();
    cout << "\t\t\t\t\t\tMa nhap vien nhap: ";
    int maNV = Nhap_ma();
    while (nv.FindIndex(maNV) == -1){
        cout << "\t\t\t\t\t\tMa nhan vien chua ton tai!" << endl;
        cout << "\t\t\t\t\t\tNhap lai ma nhap vien! ";    maNV = Nhap_ma();
    }
    cout << "\t\t\t\t\t\tSDT khach hang: "; sdt = KiemTraSDT();
    while (kh.FindIndexSDT(sdt) == -1){
        cout << "\t\t\t\t\t\tSDT chua ton tai!" << endl; 
        return;
    }
    HoaDon *hd = new HoaDon;
    hd->Input(kh, nv, hh, maNV, sdt);
    databaseHD.push_back(hd);
    lengthHD++;
}
int QuanLyHD::FindIndexHD(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getMaHD() == index)
            return i;
    }
    return -1;
}
int QuanLyHD::FindIndexNV(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getMaNV() == index)
            return i;
    }
    return -1;
}
int QuanLyHD::FindIndex(const string& a)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getSDT() == a)
            return i;
    }
    return -1;
}

int QuanLyHD::FindIndexHH(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        int n = this->databaseHD[i]->getLengthCTHD();
        for (int j = 0; j < n; j++) 
            if(this->databaseHD[i]->cthd[j]->getMaHH()) return j;
    }
    return -1;
}


void QuanLyHD::Find(QuanLyHang& hh)
{
    int maHD;
    cout << "\t\t\t\t\t\tNhap ma hoa don can tim: ";    maHD = Nhap_ma();
    int n = FindIndexHD(maHD);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }else{
            databaseHD[n]->Output(hh);
    }
}
void QuanLyHD::Remove()
{
    int maHD;
    ShowGeneral();
    cout << "\t\t\t\t\t\tNhap ma hoa don: ";
    cin >> maHD;
    if (FindIndexHD(maHD) == -1)
    {
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    else
    {
        databaseHD.erase(FindIndexHD(maHD));
        this->lengthHD--;
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}
void QuanLyHD::Show(QuanLyHang& hh){
    cout << "\n\t\t\t\t\t\t\t\tDANH SACH CAC HOA DON" << endl;
    for (int i = 0; i<this->lengthHD; i++){
        cout << "\t\t\t\t\t\tChi tiet hoa don thu " << i + 1;
        databaseHD[i]->Output(hh);
        cout << "\n\n";
    }
}
void QuanLyHD::ShowGeneral(){
    cout << "\n\t\t\t\t\t\tDANH SACH CAC HOA DON" << endl;
    cout << "\n\t\t\t\t--------------------------------------------------" << endl;
    cout << "\t\t\t\t" << "|" << setw(5) << "Ma HD" << "|" << setw(5) << "MaNV" << "|" << setw(5) << "SDT" 
    << "|" << setw(14) << "Thanh tien" << "|" << endl;
    cout << "\t\t\t\t--------------------------------------------------" << endl;
    for (int i = 0; i < this->lengthHD; i++){
        cout << *databaseHD[i];
    }
    cout << "\t\t\t\t--------------------------------------------------" << endl;
}
