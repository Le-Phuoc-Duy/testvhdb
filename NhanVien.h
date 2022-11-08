#include <string>
#include "Date.h"
using namespace std;
#pragma once

class QuanLyNV;
class NhanVien
{
    private:
        int static count_id;
        int maNV;
        string ho_dem_NV;
        string tenNV;
        int gioi_tinh;
        Date ngay_sinh;
        string sdt;
        string dia_chi;
        double luong;
        int chuc_vu;
    public:
    NhanVien(int = -1, string = "", string = "", int = 0, Date = Date(0, 0, 0),string = "", string = "", int = 0, double = 0);
    ~NhanVien();
    //Ham Setter
    void setCountID(int);
    void setMaNV(int);
    void setTenNV(string);
    void setHoDemNV(string);
    void setGioiTinh(int);
    void setNgaySinh(Date);
    void setSDT(string);
    void setDiaChi(string);
    void setLuong();
    void setChucVu(int);
    //Ham Getter
    int getCountID();
    int getMaNV();
    string getTenNV();
    string getHoDemNV();
    string getHoTenNV();
    string getGioiTinh();
    Date getNgaySinh();
    string getSDT();
    string getDiaChi();
    double getLuong();
    string getChucVu();
    // Ham da nang hoa
    friend ostream& operator<<(ostream&, NhanVien&);
    friend istream& operator>>(istream&, NhanVien&);
};