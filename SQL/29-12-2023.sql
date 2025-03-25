USE AdventureWorks2019;
SELECT
    p.BusinessEntityID,
    p.FirstName,
    p.LastName,
    d.Name AS Department
FROM
    HumanResources.EmployeeDepartmentHistory edh
JOIN HumanResources.Department d ON
    edh.DepartmentID = d.DepartmentID
JOIN Person.Person p ON
    edh.BusinessEntityID = p.BusinessEntityID
WHERE
    edh.EndDate IS NULL;

USE AdventureWorks2019;
SELECT
    sp.BusinessEntityID
FROM
    Sales.SalesPerson sp
JOIN Sales.SalesTerritory st ON
    sp.TerritoryID = st.TerritoryID
WHERE
    st.CountryRegionCode = 'CA';

USE AdventureWorks2019;
SELECT
    sp.BusinessEntityID
FROM
    Sales.SalesPerson sp
JOIN Sales.SalesTerritory st ON
    sp.TerritoryID = st.TerritoryID
WHERE
    st.Name IN ('Northwest', 'Northeast');

USE AdventureWorks2019;
SELECT
    sp.BusinessEntityID,
    sp.Bonus,
    ROW_NUMBER() OVER (ORDER BY sp.Bonus DESC) AS Rank
FROM
    Sales.SalesPerson sp
ORDER BY
    sp.Bonus DESC;

USE AdventureWorks2019;
SELECT
    BusinessEntityID
FROM
    Sales.SalesPerson
EXCEPT
SELECT
    SalesPersonID
FROM
    Sales.Store;

USE AdventureWorks2019;
SELECT BusinessEntityID FROM Sales.SalesPerson
UNION
SELECT BusinessEntityID AS SalesPersonID FROM Sales.Store;

USE AdventureWorks2019;
SELECT
    sp.BusinessEntityID,
    st.TerritoryID
FROM
    Sales.SalesPerson sp
LEFT JOIN Sales.SalesTerritory st ON
    sp.TerritoryID = st.TerritoryID;

USE AdventureWorks2019;
SELECT
    TerritoryID
FROM
    Sales.SalesPerson
INTERSECT
SELECT
    TerritoryID
FROM
    Sales.SalesTerritory;

use QuanlyNhanKhau

CREATE VIEW vw_All_NhaTrenPho AS
SELECT
    NTP.NhaID,
    NTP.ChuHo,
    NTP.DienTich,
    NTP.SoNhanKhau,
    DP.TenDuong,
    QH.TenQH
FROM
    NhaTrenPho NTP
JOIN
    DuongPho DP ON NTP.DuongID = DP.DuongID
JOIN
    QuanHuyen QH ON DP.MaQH = QH.MaQH;


SELECT * FROM vw_All_NhaTrenPho;

USE studentManagement;


CREATE VIEW vwStudentSubjectMark AS
SELECT
    s.StudentId,
    s.StudentName,
    sb.SubjectName,
    r.Mark
FROM
    student s
JOIN
    result r ON s.StudentId = r.StudentId
JOIN
    subject sb ON r.SubjectId = sb.SubjectId;


-- Sử dụng extended procedure xp_readerrorlog
EXEC sys.xp_readerrorlog;

-- Sử dụng extended procedure xp_getnetname
EXEC sys.xp_getnetname;

-- Sử dụng extended procedure xp_fixeddrives
EXEC sys.xp_fixeddrives;


CREATE DATABASE ShoezUnlimited
USE ShoezUnlimited;

CREATE TABLE Products (
    ProductCode INT PRIMARY KEY IDENTITY(1,1),
    BrandName VARCHAR(30),
    Category VARCHAR(30),
    UnitPrice MONEY,
    QtyOnHand INT
);

INSERT INTO Products (BrandName, Category, UnitPrice, QtyOnHand)
VALUES
('Nike', 'Sports Shoe', 50.00, 30),
('Adidas', 'Casual Wear', 40.00, 25),
('Puma', 'Party Wear', 60.00, 40),
('Reebok', 'Sports Shoe', 55.00, 22),
('Vans', 'Casual Wear', 45.00, 35);

CREATE PROCEDURE sp_PriceIncrease
AS
BEGIN
    UPDATE Products
    SET UnitPrice = UnitPrice + 10;
END;

CREATE PROCEDURE sp_QtyOnHand
    @BrandName VARCHAR(30)
AS
BEGIN
    UPDATE Products
    SET QtyOnHand = 25
    WHERE BrandName = @BrandName;
END;

-- Thực thi stored procedure sp_PriceIncrease
EXEC sp_PriceIncrease;

-- Thực thi stored procedure sp_QtyOnHand
EXEC sp_QtyOnHand @BrandName = 'Nike'; -- Đổi BrandName tùy theo hãng giày cần giảm tồn kho

USE studentManagement;

CREATE PROCEDURE sp_IncreaseMark
    @SubjectId INT
AS
BEGIN
    UPDATE Result
    SET Mark = Mark + 1
    WHERE SubjectId = @SubjectId;
END;

EXEC sp_IncreaseMark @SubjectId = 1;

USE QuanLyNhanKhau;
GO

CREATE PROCEDURE sp_NgayDuyetTen_DuongPho
    @NgayDuyet DATETIME
AS
BEGIN
    SELECT dp.NgayDuyet AS 'Ngay Duyet Ten',
           dp.TenDuong AS 'Ten Duong',
           qh.TenQH AS 'Ten Quan Huyen'
    FROM DuongPho dp
    JOIN QuanHuyen qh ON dp.MaQH = qh.MaQH
    WHERE CONVERT(DATE, dp.NgayDuyet) = CONVERT(DATE, @NgayDuyet);
END;

EXEC sp_NgayDuyetTen_DuongPho @NgayDuyet = '1998-12-30';


