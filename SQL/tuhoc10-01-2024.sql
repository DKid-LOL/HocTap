create database [BANHANG]
use [BANHANG]

CREATE TABLE NhaCungCap (
    MaNhaCC nvarchar(10) PRIMARY KEY,
    TenNCC nvarchar(40),
    DiaChi nvarchar(60),
    Phone nvarchar(24),
    Fax nvarchar(16),
    HomePage ntext
);

CREATE TABLE LoaiSanPham (
    MaLoaiSP nvarchar(10) PRIMARY KEY,
    TenLoaiSP nvarchar(15),
    MoTa ntext
);

CREATE TABLE NhanVien (
    MaNV nvarchar(10) PRIMARY KEY,
    HoTenNV varchar(30),
    ChucDanh varchar(30),
    NgaySinh smalldatetime,
    DiaChi varchar (60),
	Phone varchar (24), 
	GioiTinh bit,
	Photo image,
	GhiChu text 
);

CREATE TABLE SanPham (
	MaSP int PRIMARY KEY,
	TenSP varchar (40), 
	MaNhaCC int FOREIGN KEY REFERENCES NhaCungCap(MaNhaCC), 
	MaLoaiSP int FOREIGN KEY REFERENCES LoaiSanPham(MaLoaiSP), 
	DVT smallint, 
	SoLuong smallint,  
	SoLuongTT smallint,  
	Discontinued bit 
);

CREATE TABLE HoaDon (
	MaHD int PRIMARY KEY,
	MaNV nvarchar(10) FOREIGN KEY REFERENCES NhanVien(MaNV),
	MaKH nvarchar(10) FOREIGN KEY REFERENCES KhachHang(MaKH),
	NgayDatHang datetime,
	NgayGiaoHang datetime,
	TongTien money
);

CREATE TABLE HoaDonChiTiet (
	MaHD int FOREIGN KEY REFERENCES HoaDon(MaHD),
	MaSP int FOREIGN KEY REFERENCES SanPham(MaSP),
	SoLuong smallint,
	Gia money
);


CREATE TABLE KhachHang (
	MaKH nvarchar(10) PRIMARY KEY,
	HoTenKH nvarchar(40),
	DiaChi nvarchar(60),
	Phone nvarchar(24),
	Fax nvarchar(16),
	Email nvarchar(50),
	HomePage ntext
);

INSERT INTO NhaCungCap (MaNhaCC, TenNhaCC, DiaChi, Phone, Fax, HomePage) VALUES
  ('BAN', 'Cong ty Ban mai', '64 Hang Bun', '048286745', NULL, 'www.binhminh.com'),
  ('OCE', 'Cong ty Ocean', '26 Tran Quy Cap', '048924712', NULL, 'www.ocean.com'),
  ('RDO', 'Cong ty Rang Dong', '97 Hoang Hoa Thar', '048923711', NULL, 'www.rdong.com');
go

INSERT INTO KhachHang (MaKH, TenKH, DiaChi, Phone, Email) VALUES
  ('01', 'Hoa Binh', 'Ha Noi', '0913567222', 'hb@fpt.vn'),
  ('02', 'Quang Long', 'Ha Noi', '048123445', 'qlong@Yahoo.com'),
  ('03', 'Nguyen Tuan', 'Hai Phong', '098467231', 'Tuan@yahoo.com');
go

INSERT INTO NhanVien (MaNV, HoTen, ChucDanh, NgaySinh, NgayNhanViec, DiaChi, Phone, Photo, GhiChu)VALUES
  ('01', 'Lan Huong', 'Ban hang', '1980-11-23', '2004-01-15', 'Hoa Binh', '0912349865', BINARY NULL),
  ('02', 'Bich Hue', 'Tiep thi', '1979-12-31', '2001-01-22', 'Quang Binh', '098768324', BINARY, NULL),
  ('03', 'Tung Chi', 'Ban hang', '1986-08-09', '2005-01-14', 'Hai Phong', '098568253', BINARY, NULL),
  ('04', 'Kien Cuong', 'Thu kho', '1979-09-19', '2003-01-22', 'Ha Noi', '0912367299', BINARY, NULL);
go

INSERT INTO LoaiSanPham (MaLoaiSP, TenLoaiSP, MoTa) VALUES
  ('DL', 'Dien lanh', NULL),
  ('DT', 'Dien tu', NULL),
  ('MP', 'Hang my pham', NULL),
  ('TD', 'Hang tieu dung', NULL);
go

INSERT INTO SanPham (MaSP, TenSP, MaNhaCC, MaLoaiSP, DVT, DonGia, SoLuong, SoLuongTT, Discontinued) VALUES
  ('001', 'Vo tuyen', 'BAN', 'DT', 'Chiec', 4000, 25, 5, 0),
  ('002', 'Radio', 'BAN', 'DT', 'Chiec', 200, 150, 20, 0),
  ('003', 'CD player', 'BAN', 'DT', 'Chiec', 2000, 45, 10, 0),
  ('004', 'Tu lanh', 'RDO', 'DL', 'Chiec', 6000, 22, 5, 0),
  ('005', 'May lam kem', 'RDO', 'DL', 'Chiec', 7000, 19, 4, 0),
  ('007', 'May dieu hoa', 'RDO', 'DL', 'Chiec', 9000, 38, 7, 0),
  ('008', 'Xa phong thom', 'OCE', 'TD', 'Banh', 6, 200, 50, 0),
  ('009', 'Duong', 'OCE', 'TD', 'Kg', 9, 550, 50, 0),
  ('010', 'Sua', 'OCE', 'TD', 'Hop', 120, 80, 20, 0),
  ('011', 'Mi miliket', 'OCE', 'TD', 'Thung', 200, 56, 8, 0);
go

UPDATE HoaDonChiTiet
SET ThanhTien = DonGia * SoLuong * (1 - GiamGia);

UPDATE HoaDon
SET Tien = (SELECT SUM(ThanhTien) FROM HoaDonChiTiet WHERE HoaDon.MaHD = HoaDonChiTiet.MaHD),
    TongSoTien = Tien * (1 + Thue);

SELECT LoaiSanPham.TenLoaiSP, SanPham.MaSP, SanPham.TenSP
FROM SanPham
JOIN LoaiSanPham ON SanPham.MaLoaiSP = LoaiSanPham.MaLoaiSP
ORDER BY SanPham.TenSP ASC;

SELECT SanPham.TenSP, SUM(HoaDonChiTiet.SoLuong) AS TongSoHangDaBan
FROM SanPham
JOIN HoaDonChiTiet ON SanPham.MaSP = HoaDonChiTiet.MaSP
GROUP BY SanPham.TenSP;

SELECT SanPham.TenSP, SUM(HoaDonChiTiet.ThanhTien) AS TongSoTienDaBan
FROM SanPham
JOIN HoaDonChiTiet ON SanPham.MaSP = HoaDonChiTiet.MaSP
GROUP BY SanPham.TenSP;

SELECT 
    HoaDonChiTiet.MaHD,
    SanPham.MaSP,
    SanPham.TenSP,
    HoaDonChiTiet.DonGia,
    HoaDonChiTiet.SoLuong,
    HoaDonChiTiet.GiamGia,
    HoaDonChiTiet.ThanhTien
FROM 
    HoaDonChiTiet
JOIN 
    SanPham ON HoaDonChiTiet.MaSP = SanPham.MaSP
WHERE 
    HoaDonChiTiet.GiamGia > 0.01 AND HoaDonChiTiet.ThanhTien < 10000;

SELECT 
    KhachHang.MaKH,
    KhachHang.HoTenKH,
    KhachHang.DiaChi,
    KhachHang.Phone,
    HoaDon.MaHD
FROM 
    KhachHang
JOIN 
    HoaDon ON KhachHang.MaKH = HoaDon.MaKH
WHERE 
    MONTH(HoaDon.NgayDatHang) = 3 AND YEAR(HoaDon.NgayDatHang) = 1997
ORDER BY 
    KhachHang.HoTenKH ASC, HoaDon.MaHD ASC;

SELECT 
    LoaiSanPham.TenLoaiSP,
    SanPham.TenSP,
    SUM(HoaDonChiTiet.SoLuong) AS TongSoMatHangBan,
    SUM(HoaDonChiTiet.ThanhTien) AS TongSoTienBan
FROM 
    SanPham
JOIN 
    HoaDonChiTiet ON SanPham.MaSP = HoaDonChiTiet.MaSP
JOIN 
    LoaiSanPham ON SanPham.MaLoaiSP = LoaiSanPham.MaLoaiSP
GROUP BY 
    LoaiSanPham.TenLoaiSP, SanPham.TenSP
WITH ROLLUP;

SELECT 
    KhachHang.MaKH,
    KhachHang.HoTenKH,
    KhachHang.DiaChi,
    KhachHang.Phone,
    SUM(HoaDon.TongTien) AS TongSoTienMua
FROM 
    KhachHang
JOIN 
    HoaDon ON KhachHang.MaKH = HoaDon.MaKH
WHERE 
    MONTH(HoaDon.NgayDatHang) = 11 AND YEAR(HoaDon.NgayDatHang) = 2006
GROUP BY 
    KhachHang.MaKH, KhachHang.HoTenKH, KhachHang.DiaChi, KhachHang.Phone
ORDER BY 
    KhachHang.HoTenKH ASC;

SELECT 
    NhanVien.MaNV,
    NhanVien.HoTenNV,
    NhanVien.Phone,
    SUM(HoaDon.TongTien) AS TongSoTienBanDuoc
FROM 
    NhanVien
JOIN 
    HoaDon ON NhanVien.MaNV = HoaDon.MaNV
WHERE 
    MONTH(HoaDon.NgayDatHang) = 11 AND YEAR(HoaDon.NgayDatHang) = 2006
GROUP BY 
    NhanVien.MaNV, NhanVien.HoTenNV, NhanVien.Phone
ORDER BY 
    NhanVien.HoTenNV ASC;
