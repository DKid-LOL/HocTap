CREATE DATABASE RangDong;
GO
USE RangDong;
GO
CREATE TABLE BangSach (
	MaSach INT PRIMARY KEY,
	TenSach	NVARCHAR(50),
	TacGia NVARCHAR(30),
	NhaXB NVARCHAR(20),
	ChuDe NVARCHAR(20),
	DonGia MONEY,
	TrongKho INT
	);
CREATE TABLE KhachHang (
	MaKH INT PRIMARY KEY NOT NULL,
	TenKH NVARCHAR(30) NOT NULL,
	DiaChi NVARCHAR(50) NOT NULL,
	Quan NVARCHAR(50) NOT NULL,
	DienThoai NVARCHAR(20) NOT NULL,
	NguoiGT NVARCHAR(30)
	);
CREATE TABLE SachBan (
	SoHD INT PRIMARY KEY,
	MaKH INT,
	MaSach INT,
	NgayMua DATETIME,
	DonGia MONEY,
	SoLuong INT,
	FOREIGN KEY (MaKH) REFERENCES KhachHang(MaKH),
	FOREIGN KEY (MaSach) REFERENCES BangSach(MaSach)
	);
INSERT INTO BangSach (MaSach, TenSach, TacGia, NhaXB, ChuDe, DonGia, TrongKho) VALUES 
	(1, N'Hoang hon tren song', N'Gia Phong', N'Van hoa', N'Tinh yeu', 120, 11),
	(2, N'Cay lua nuoc', N'Le May', N'KHKT', N'Khoa hoc', 30, 24),
	(3, N'Tam ly truoc mua thi', N'Hai Dang', N'Giao duc', N'Tam ly', 42, 32);
INSERT INTO KhachHang (MaKH, TenKH, DiaChi, Quan, DienThoai, NguoiGT) VALUES
    (1, N'Le Cong', N'22 Hang Buom', N'Hoan Kiem', N'098123654', N'Hoang Kim'),
    (2, N'Van Nghe', N'19 Lo Duc', N'Hoan Kiem', N'098123456', NULL),
    (3, N'Tran Thong', N'19 Doi Can', N'Ba Dinh', N'097123456', NULL),
    (4, N'Hoang Tin', N'38 Linh Nam', N'Hoang Mai', N'095123455', NULL);
);
INSERT INTO SachBan (SoHD, MaKH, MaSach, NgayMua, DonGia, SoLuong) VALUES
    (1, 1, 2, '2006-11-22', 30, 5),
    (2, 1, 3, '2005-07-15', 45, 4),
    (3, 2, 1, '2006-05-24', 30, 7),
    (4, 3, 1, '2005-11-15', 45, 9);

SELECT COUNT(*) AS SoDauSach
FROM BangSach
WHERE NhaXB = 'KHKT';

SELECT NhaXB, COUNT(*) AS SoDauSach
FROM BangSach
GROUP BY NhaXB
ORDER BY NhaXB ASC;

SELECT
    KhachHang.TenKH,
    KhachHang.DiaChi AS DiaChiKhachHang,
    BangSach.TenSach,
    SachBan.NgayMua
FROM
    KhachHang
JOIN
    SachBan ON KhachHang.MaKH = SachBan.MaKH
JOIN
    BangSach ON SachBan.MaSach = BangSach.MaSach
WHERE
    KhachHang.Quan = 'Ba Dinh'
ORDER BY
    KhachHang.TenKH ASC, SachBan.NgayMua ASC;

SELECT
    KhachHang.MaKH,
    KhachHang.TenKH,
    COUNT(*) AS TongSoLuongSachMua
FROM
    KhachHang
JOIN
    SachBan ON KhachHang.MaKH = SachBan.MaKH
GROUP BY
    KhachHang.MaKH, KhachHang.TenKH
ORDER BY
    KhachHang.TenKH ASC;

SELECT
    KhachHang.MaKH,
    KhachHang.TenKH,
    BangSach.NhaXB
FROM
    KhachHang
JOIN
    SachBan ON KhachHang.MaKH = SachBan.MaKH
JOIN
    BangSach ON SachBan.MaSach = BangSach.MaSach
ORDER BY
    KhachHang.TenKH ASC;

SELECT
    KhachHang.MaKH,
    KhachHang.TenKH,
    COUNT(*) AS SoLanMuaSach
FROM
    KhachHang
JOIN
    SachBan ON KhachHang.MaKH = SachBan.MaKH
GROUP BY
    KhachHang.MaKH, KhachHang.TenKH
ORDER BY
    KhachHang.TenKH ASC;

SELECT
    KhachHang.Quan,
    SUM(SachBan.DonGia * SachBan.SoLuong) AS TongGiaTriMuaSach
FROM
    KhachHang
JOIN
    SachBan ON KhachHang.MaKH = SachBan.MaKH
GROUP BY
    KhachHang.Quan
ORDER BY
    TongGiaTriMuaSach DESC;

CREATE PROCEDURE TimKiemSachTheoTen
    @TenSach NVARCHAR(50)
AS
BEGIN
    SELECT * FROM BangSach WHERE TenSach LIKE '%' + @TenSach + '%';
END;

CREATE TRIGGER Tr_UpdateMaSach
ON BangSach
AFTER UPDATE
AS
BEGIN
    UPDATE SachBan
    SET MaSach = INSERTED.MaSach
    FROM SachBan
    JOIN INSERTED ON SachBan.MaSach = INSERTED.MaSach;
END;

CREATE TRIGGER Tr_DeleteKhachHang
ON KhachHang
AFTER DELETE
AS
BEGIN
    DELETE FROM SachBan
    WHERE MaKH IN (SELECT MaKH FROM DELETED);
END;
