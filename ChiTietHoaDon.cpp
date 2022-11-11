#include <iostream>
#include <iomanip>
#include "ChiTietHoaDon.h"
#include "QuanLyHang.h"
using namespace std;

//Ham dung va ham huy
ChiTietHoaDon::ChiTietHoaDon(){}

ChiTietHoaDon::ChiTietHoaDon(int maHH, double don_gia, int so_luong)
{
    this->maHH = maHH;
    this->don_gia = don_gia;
    this->so_luong = so_luong;
}
ChiTietHoaDon::~ChiTietHoaDon(){}

//Ham Setter

void ChiTietHoaDon::setMaHH(int maHH)
{
    this->maHH = maHH;
}
void ChiTietHoaDon::setDonGia(double don_gia)
{
    this->don_gia = don_gia;
}
void ChiTietHoaDon::setSoLuong(int so_luong)
{
     this->so_luong = so_luong;
}

// Ham Getter
int ChiTietHoaDon::getMaHH()
{
    return maHH;
}
double ChiTietHoaDon::getDonGia()
{
    return don_gia;
}
int ChiTietHoaDon::getSoLuong()
{
    return so_luong;
}
void ChiTietHoaDon::InputB(QuanLyHang& ql_hh){
    int n;
    do {    
    cout << "\n\t\t\t\t\t\tNhap ma hang hoa: "; cin >> maHH;
    n = ql_hh.FindIndex(maHH);
    if (n == -1 || ql_hh.databaseK[n]->getCheckDeleteSo() == 1) cout << "\t\t\t\t\t\tMa hang hoa chua ton tai hoac da bi xoa. Nhap lai!" << endl;
    }while(n == -1);

    cout << "\t\t\t\t\t\tNhap so luong: "; 
    while ((ql_hh.databaseK[n]->getSoLuong()) < so_luong)
    {
        int luachon;
        cout << "\t\t\t\t\t\tSo luong hang hoa khong du. Kho chi con " << ql_hh.databaseK[n]->getSoLuong() << " mon" << endl;
        cout << "\t\t\t\t\t\tBan muon thay doi so luong khong?" << endl;
        cout << "\t\t\t\t\t\t1. Co              0. Khong" << endl;
        ql_hh.Lua_chon();
        if (luachon == 0){
            so_luong = 0;   return;
        }
        else if (luachon == 1){
            cout << "\t\t\t\t\t\tNhap so luong: ";  ql_hh.In_double();
        }
    }
    ql_hh.databaseK[n]->setSoLuong(ql_hh.databaseK[n]->getSoLuong() - this->so_luong);
    don_gia = so_luong * ql_hh.databaseK[n]->getGiaBan();
}
//chi tiet hoa don cho trang thai mua
void ChiTietHoaDon::InputM(QuanLyHang& ql_hh){
    ql_hh.Show(0);
    int maHH;
    cout << "\n\t\t\t\t\t\tMa hang hoa can mua: "; maHH = ql_hh.Nhap_ma();
    int n = ql_hh.FindIndex(maHH);
    int luachon;
    while (n == -1){    
        cout << "\t\t\t\t\t\tMa hang hoa chua ton tai. Ban lua chon?" << endl;
        cout << "\t\t\t\t\t\t1. Nhap lai" << endl;
        cout << "\t\t\t\t\t\t2. Them hang hoa moi";
        if (luachon == 1){
            maHH = ql_hh.Nhap_ma();
            n = ql_hh.FindIndex(maHH);
        }
        else if (luachon == 2){
            int tmp = ql_hh.lengthK;
            ql_hh.Insert();
            if (ql_hh.lengthK == tmp){ n = ql_hh.databaseK[0]->getCountID();    return;}
            else break;
        }
    }

    int luachon2;
    if (ql_hh.databaseK[n]->getCheckDeleteSo() == 1){
        do {
            cout << "\n\t\t\t\t\t\tHang hoa da bi xoa khoi kho. Ban muon khoi phuc lai khong? ";
            cout << "\n\t\t\t\t\t\t1. Co ";
            cout << "\n\t\t\t\t\t\t0. Khong ";
            int luachon = ql_hh.Lua_chon();
            if (luachon2 == 1){
                ql_hh.databaseK[n]->setCheckDelete(0);
            }
            else if (luachon == 0)
            {
                return;
            }
        } while (luachon != 0 && luachon != 1 );
    }
        cout << "\t\t\t\t\t\tNhap so luong: "; ql_hh.In_double();
        ql_hh.databaseK[n]->setSoLuong(ql_hh.databaseK[n]->getSoLuong() + so_luong);
        don_gia = so_luong * ql_hh.databaseK[n]->getGiaVon();
}
void ChiTietHoaDon::Output( QuanLyHang& hh)
{
    int n = hh.FindIndex(maHH);
    cout << "\n\t\t\t\t\t\t|" << setw(18) << hh.databaseK[n]->getTenHH() << "|" << setw(8) << so_luong << "|" 
    << setw(14) << setprecision(13) << don_gia << "|";
}