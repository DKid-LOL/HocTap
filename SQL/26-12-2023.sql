
CREATE DATABASE QuanlyNhanKhau;
USE QuanlyNhanKhau;


CREATE TABLE QuanHuyen (
    MaQH INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
    TenQH NVARCHAR(100) NOT NULL
);


CREATE TABLE DuongPho (
    DuongID INT PRIMARY KEY NOT NULL,
    MaQH INT NOT NULL,
    TenDuong NVARCHAR(MAX) NOT NULL,
    NgayDuyet DATETIME NOT NULL,
    CONSTRAINT FK_DuongPho_QuanHuyen FOREIGN KEY (MaQH) REFERENCES QuanHuyen(MaQH),
    CONSTRAINT CK_DuongPho_NgayDuyenTen CHECK (NgayDuyet > '1945-09-02' AND NgayDuyet <= GETDATE())
);


CREATE TABLE NhaTrenPho (
    NhaID INT PRIMARY KEY NOT NULL,
    DuongID INT NOT NULL,
    ChuHo NVARCHAR(50),
    DienTich MONEY,
    SoNhanKhau INT,
    CONSTRAINT FK_NhaTrenPho_DuongPho FOREIGN KEY (DuongID) REFERENCES DuongPho(DuongID)
);


INSERT INTO QuanHuyen (TenQH) VALUES
(N'Ba Đình'),
(N'Hoàng Mai');


INSERT INTO DuongPho (DuongID, MaQH, TenDuong, NgayDuyet) VALUES
(1, 1, N'Trường Chinh', '1946-10-19'),
(2, 1, N'Tây Sơn', '1998-12-30'),
(3, 2, N'Chùa Bộc', '1975-09-21');


INSERT INTO NhaTrenPho (NhaID, DuongID, ChuHo, DienTich, SoNhanKhau) VALUES
(1, 1, N'Toàn Ngô Vĩnh', 100, 4),
(2, 1, N'Lê Văn A', 20, 12),
(3, 2, N'Nguyễn Thị B', 40, 1);


UPDATE DuongPho
SET TenDuong = N'Thái Hà'
WHERE TenDuong = N'Chùa Bộc';
