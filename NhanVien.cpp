#include<iostream>
#include <iomanip>
#include "NhanVien.h"

int NhanVien::count_id = 0;
//Ham dung
NhanVien::NhanVien(int maNV, string hodem, string tenNV, int gioi_tinh, Date ngay_sinh, string sdt, string dia_chi, int chuc_vu, double luong)
{
    if (maNV != -1){
        this->maNV = maNV;
        if (count_id < maNV) count_id = maNV;
    }
    else this->maNV = ++count_id;
    this->gioi_tinh = gioi_tinh;
    this->ho_dem_NV = hodem;
    this->tenNV = tenNV;
    this->ngay_sinh = ngay_sinh;
    this->sdt = sdt;
    this->dia_chi = dia_chi;
    this->chuc_vu = chuc_vu;
    this->luong = luong;
}
NhanVien::~NhanVien(){}
// Ham Setter
void NhanVien::setCountID(int count)
{
    this->count_id = count;
}
void NhanVien::setMaNV(int maNV)
{
    this->maNV = maNV;
}
void NhanVien::setGioiTinh(int gioi_tinh)
{
    this->gioi_tinh = gioi_tinh;
}
void NhanVien::setTenNV(string tenNV)
{
    this->tenNV = tenNV;
}
void NhanVien::setHoDemNV(string hodem)
{
    this->ho_dem_NV = hodem;
}
void NhanVien::setNgaySinh(Date ngay_sinh)
{
    this->ngay_sinh = ngay_sinh;
}
void NhanVien::setSDT(string sdt)
{
    this->sdt = sdt;
}
void NhanVien::setDiaChi(string dia_chi)
{
    this->dia_chi = dia_chi;
}
void NhanVien::setLuong()
{
    if (chuc_vu == 0) luong = 7000000;
    else luong = 5500000;
}
void NhanVien::setChucVu(int chuc_vu)
{
    this->chuc_vu = chuc_vu;
}
//Ham Getter
int NhanVien::getCountID()
{
    return count_id;
}
int NhanVien::getMaNV()
{
    return maNV;
}
string NhanVien::getTenNV()
{
    return tenNV;
}
string NhanVien::getHoDemNV()
{
    return ho_dem_NV;
}
string NhanVien::getHoTenNV()
{
    return ho_dem_NV + tenNV;
}
string NhanVien::getGioiTinh()
{
    if (gioi_tinh == 1) return "Nam";
    else return "Nu";
}
Date NhanVien::getNgaySinh()
{
    return ngay_sinh;
}
string NhanVien::getSDT()
{
    return sdt;
}
string NhanVien::getDiaChi()
{
    return dia_chi;
}
double NhanVien::getLuong()
{
    return luong;
}
string NhanVien::getChucVu()
{
    if (chuc_vu == 0) return "Quan Ly";
    else return "Nhan vien";
}

ostream& operator<<(ostream& out, NhanVien& nv)
{
    out << "\t\t\t" << "|" << setw(5) << nv.maNV << "|" << setw(15) << nv.ho_dem_NV + " " << setw(5) << nv.tenNV << "|" << setw(9) << nv.getGioiTinh() 
    <<  "|" << setw(2) << nv.ngay_sinh << "|" << setw(13) << nv.getSDT() << "|" <<  setw(19) << nv.dia_chi << "|" << setw(9) << nv.getChucVu() << "|" 
    <<setw(9) << (size_t)nv.luong << "|" << endl;
    return out;
}
istream& operator>>(istream& in, NhanVien& nv)
{
    cin.ignore();
    cout << "\t\t\t\t\t\tNhap ho dem nhan vien: ";  getline(in, nv.ho_dem_NV);
    cout << "\t\t\t\t\t\tNhap ten nhan vien: ";  getline(in, nv.tenNV);
    do{
        cout << "\t\t\t\t\t\tGioi tinh :    1.Nam       0. Nu" << endl;
        cout << "\t\t\t\t\t\tNhap gioi tinh : "; in >> nv.gioi_tinh;
    }while(nv.gioi_tinh != 0 && nv.gioi_tinh != 1);
    cout << "\t\t\t\t\t\tNhap ngay sinh: ";     in >> nv.ngay_sinh;
    while(1)
    {
        try
        {
            cin.ignore();
            cout << "\n\t\t\t\t\t\tNhap so dien thoai: "; in >> nv.sdt;
            if (nv.sdt.length() != 10) throw "\t\t\t\t\t\tSo dien thoai khong ton tai";
            for (int i = 0; i < nv.sdt.length(); i++){
                if (nv.sdt[i] < 48 || nv.sdt[i] > 57) throw "\t\t\t\t\t\tSo dien thoai khong hop le";
            }
            break;
        }
        catch(const char* e)
        {
            cout << e;
        }
    }
    cout << "\t\t\t\t\t\tNhap dia chi: ";    in.ignore(); getline(in, nv.dia_chi);
    do{
        cout << "\t\t\t\t\t\tChuc vu: ";
        cout << "\n\t\t\t\t\t\t 0. Quan Ly "; 
        cout << "\n\t\t\t\t\t\t 1. Nhan vien "; 
        cout << "\n\t\t\t\t\t\tNhap chuc vu : ";   in >> nv.chuc_vu;
    }while(nv.chuc_vu != 0 && nv.chuc_vu != 1);
    nv.setLuong();
    return in;
}
