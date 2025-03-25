CREATE DATABASE studentManagement
GO
use studentManagement
GO
CREATE TABLE class (
	ClassId INT NOT NULL,
	ClassName NVARCHAR(30),
	CONSTRAINT PK_class PRIMARY KEY (ClassId),

);

CREATE TABLE student (
	StudentID INT NOT NULL,
	StudentName NVARCHAR(50),
	BirthDate DATETIME,
	ClassId INT,
	CONSTRAINT PK_student PRIMARY KEY (StudentId),
	CONSTRAINT FK_Student_Class 
	FOREIGN KEY (ClassId)
	REFERENCES class(ClassId)
);

CREATE TABLE subject (
	SubjectId INT NOT NULL,
	SubjectName NVARCHAR(100),
	SessionCount INT,
	CONSTRAINT PK_subject PRIMARY KEY (SubjectId),
	CONSTRAINT CK_Subject_Check_SessionCount CHECK (SessionCount > 0)
);

CREATE TABLE result (
	StudentId INT NOT NULL,
	SubjectId INT NOT NULL,
	Mark INT,
	CONSTRAINT PK_result PRIMARY KEY (StudentId,SubjectId),
	CONSTRAINT FK_Result_Student 
	FOREIGN KEY (StudentId)
	REFERENCES student(StudentId),
	CONSTRAINT FK_Result_Subject
	FOREIGN KEY (SubjectId)
	REFERENCES Subject(SubjectId),
);

ALTER TABLE result
ALTER COLUMN Mark FLOAT;

INSERT INTO class (ClassId, ClassName) VALUES
(1, 'A1'),
(2, 'A2'),
(3, 'A3'),
(4, 'A4'),
(5, 'A5');

INSERT INTO student(StudentId, StudentName, BirthDate, ClassId) VALUES
(1, N'Toàn Ngô Vĩnh', '1992-01-01', 1),
(2, N'Nguyễn Văn Test', '1993-06-08', 3),
(3, N'Nguyễn Văn B', '2001-02-10', 4),
(4, N'Nguyễn Văn C', '1998-06-30', 1),
(5, N'Nguyễn Văn D', '1995-08-24', 2);

INSERT INTO Subject (SubjectId, SubjectName, SessionCount) VALUES
(1, 'C Programming', 20),
(2, 'HTML/CSS', 15),
(3, 'Database Management', 30);

INSERT INTO Result (StudentId, SubjectId, Mark) VALUES
(1, 1, 8),
(1, 2, 7),
(2, 3, 5),
(3, 2, 7),
(4, 3, 8),
(5, 2, 4);

SELECT * FROM class
SELECT * FROM student
SELECT * FROM subject
SELECT * FROM result

--bai 1: 
--Lấy ra toàn bộ student.
SELECT *
FROM student;
--Lấy ra top 3 student.
SELECT TOP 3 *
FROM student;
--Lấy ra top 3 student, sắp xếp theo điểm từ trên xuống.
SELECT TOP 3 *
FROM Result
ORDER BY Mark DESC;
--Tìm kiếm student có BirthDate nằm giữa '01/01/1993' và '31/12/1998'
SELECT *
FROM student
WHERE BirthDate BETWEEN '1993-01-01' AND '1998-12-31';
--Sử dụng hàm count(), đếm số lượng sinh viên và hiển thị ra bảng biểu diễn có tên: ClassID, ClassNAme, TotalStudent
SELECT c.ClassId, c.ClassName, COUNT(s.StudentId) AS TotalStudent
FROM class c
LEFT JOIN student s ON c.ClassId = s.ClassId
GROUP BY c.ClassId, c.ClassName;
--Tính điểm trung bình của student và hiển thị ra các bản ghi bao  gồm các cột: studentId,StudentName,ClassName,StudentAvarageMark
SELECT s.StudentId, s.StudentName, c.ClassName, AVG(r.Mark) AS StudentAvarageMark
FROM student s
JOIN class c ON s.ClassId = c.ClassId
JOIN Result r ON s.StudentId = r.StudentId
GROUP BY s.StudentId, s.StudentName, c.ClassName;
--Tính tổng tất cả điểm của student, và chỉ hiển thị ra student có tổng điểm lớn hơn 10.
SELECT s.StudentId, s.StudentName, SUM(r.Mark) AS TotalMark
FROM student s
JOIN Result r ON s.StudentId = r.StudentId
GROUP BY s.StudentId, s.StudentName
HAVING SUM(r.Mark) > 10;
--Bài 2: Sử dụng bảng Sales.Customer của AdventureWorks2019, xử lý các tác vụ:
--Viết câu lệnh SELECT hiể thị ra những bản ghi not null và không bị trùng lặp (non-duplicate) lưu trữ trong đơn hàng
use AdventureWorks2019
GO
SELECT DISTINCT CustomerID
FROM Sales.Customer
WHERE TerritoryID IS NOT NULL;
--Viếtế câu lệh SELECT hiển thị ra toàn bộ khách hàng chi tiếtế trong cộtTerrioryID thỏa mãn yêu cầu nhỏ hơn 10.
SELECT *
FROM Sales.Customer
WHERE TerritoryID < 10;
--Bài 3: Sử dụng bảng Sales.SalesOrderHeader, thực thi yêi cầu:
--SELECt ra tất cả các customderID và orderID
SELECT CustomerID, SalesOrderID
FROM Sales.SalesOrderHeader;
--Bài 4: Viết câu lệnh hiển thị toàn bộ cột của bảng Production.ProductionCostHistory được chỉnh sửa vào ngày 17/06/2003
SELECT *
FROM Production.ProductCostHistory
WHERE ModifiedDate = '2003-06-17';
--Bài 5: Sử dụng bảng Production.Product thực thi các tác vụ:
--Viết câ truy vấn hiển thị productID và tên cho mỗi sản phẩm trong bảng mà tên bắt đầu bằng Chain
SELECT ProductID, Name
FROM Production.Product
WHERE Name LIKE 'Chain%';
--Viết câu truy vấn hiển thị productID và tên cho mỗi sản phẩm trong bảng mà có chứa từ khóa Lock trong tên sản phẩm
SELECT ProductID, Name
FROM Production.Product
WHERE Name LIKE '%Lock%';
--Viết câu truy vấn hiển thị productID và tên cho mỗi sản phẩm trong bảng mà không chứa từ khóa Lock trong tên sản phẩm
SELECT ProductID, Name
FROM Production.Product
WHERE Name NOT LIKE '%Lock%';
--Bài 6: Viết câu query hiển thị toàn bộ bản ghi đuợc cập nhật sau ngày 29 tháng 12 năm 2009. Hiển thị ra các cột: business Entity ID, cột name, cột hiển thị ngày chỉnh sửa Person.Person.
SELECT BusinessEntityID, LastName, ModifiedDate
FROM Person.Person
WHERE ModifiedDate > '2009-12-29';
--Bài 7: Viết câu truy vấn hiển thị  ProductID,Name,Color từ bản ghi trong bảng Production.Product. Chỉ hiển thị những bản ghi mà không có màu nào được gán.
SELECT ProductID, Name, Color
FROM Production.Product
WHERE Color IS NULL;
--Bài 8: Viết câu truy vấn trả ra business entity ID và cột name trong bảng Person.Person và sắp xếp theo LastName,FirstName,MiddleName
SELECT BusinessEntityID, LastName
FROM Person.Person
ORDER BY LastName, FirstName, MiddleName;
--Bài 9: Viết câu truy vấn trong bảng Sales.SpecialOffer. Hiển thị phép hiệu của cột MinQty và MaxQty cùng với cột SpecialOfferId và cột Description
SELECT SpecialOfferID, Description, MaxQty - MinQty AS QuantityDifference
FROM Sales.SpecialOffer;
-- Bài 10:











