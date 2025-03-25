CREATE DATABASE BookStore;
USE BookStore;

-- Bảng Students
CREATE TABLE Students (
    StudentID INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(50),
    Age TINYINT,
    stGender BIT
);

INSERT INTO Students (Name, Age, stGender)
VALUES
('Henry', 25, 1),
('Britney', 20, 0),
('Beckham', 16, NULL),
('Madona', 17, 0),
('Effenberg', 30, 1);

-- Bảng Books
CREATE TABLE Books (
    BookID INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(50),
    TotalPage INT CHECK (TotalPage > 0),
    Type VARCHAR(10),
    Quantity INT
);

INSERT INTO Books (Name, TotalPage, Quantity)
VALUES
('Access 2K', 100, NULL),
('Logic C', 60, NULL),
('HTML', 200, NULL),
('Core Java', 50, NULL),
('SQL 2K', 1000, NULL);

-- Bảng Borrows
CREATE TABLE Borrows (
    BorrowID INT PRIMARY KEY,
    StudentID INT,
    BookID INT,
    BorrowDate DATETIME
);

INSERT INTO Borrows (BorrowID, StudentID, BookID, BorrowDate)
VALUES
(1, 1, 5, '2007-09-15'),
(2, 2, 2, '2007-09-14'),
(3, 2, 3, '2007-09-20'),
(4, 2, 1, '2007-09-16'),
(5, 2, 1, '2007-09-16'),
(6, 3, 4, '2007-09-19'),
(7, 4, 4, '2007-09-21');

-- Bảng ReturnBooks
CREATE TABLE ReturnBooks (
    ReturnID INT PRIMARY KEY IDENTITY(1,1),
    StudentID INT,
    BookID INT,
    BorrowDate DATETIME,
    ReturnDate DATETIME
);

-- Ràng buộc khóa ngoại
ALTER TABLE Borrows
ADD FOREIGN KEY (StudentID) REFERENCES Students(StudentID);

ALTER TABLE Borrows
ADD FOREIGN KEY (BookID) REFERENCES Books(BookID);

ALTER TABLE ReturnBooks
ADD FOREIGN KEY (StudentID) REFERENCES Students(StudentID);

ALTER TABLE ReturnBooks
ADD FOREIGN KEY (BookID) REFERENCES Books(BookID);

-- Ràng buộc Check
ALTER TABLE Books
ADD CONSTRAINT CK_Books_TotalPage CHECK (TotalPage > 0);

-- Cập nhật trường Type
UPDATE Books
SET Type = 'Thin'
WHERE TotalPage < 100;

UPDATE Books
SET Type = 'Normal'
WHERE TotalPage >= 100 AND TotalPage <= 1000;

UPDATE Books
SET Type = 'Thick'
WHERE TotalPage > 1000;

-- Hiển thị danh sách sinh viên sắp xếp theo trường Age
SELECT *
FROM Students
ORDER BY Age;

-- Hiển thị tên sinh viên nhiều tuổi nhất
SELECT TOP 1 Name
FROM Students
ORDER BY Age DESC;

-- Hiển thị tổng số sách trong kho
SELECT SUM(Quantity) AS TotalBooks
FROM Books;

-- Hiển thị tên sinh viên có stGender là Null
SELECT *
FROM Students
WHERE stGender IS NULL;

-- Hiển thị tên sinh viên có ký tự đầu tiên là 'B'
SELECT *
FROM Students
WHERE LEFT(Name, 1) = 'B';

-- Hiển thị bookID, borrowDate của những quyển sách được mượn hơn 10 ngày tính đến thời điểm hiện tại
SELECT BookID, BorrowDate
FROM Borrows
WHERE DATEDIFF(DAY, BorrowDate, GETDATE()) > 10;

-- Hiển thị ½ tổng số sách
SELECT Quantity / 2 AS HalfTotalBooks
FROM Books;

-- Viết câu lệnh SQL mô tả hành động: quyển sách 'Access 2K' được trả bởi 'Britney'
UPDATE ReturnBooks
SET ReturnDate = '2007-09-25'
WHERE BookID = 1
  AND StudentID = 2
  AND BorrowDate = '2007-09-14';

-- Viết câu lệnh SQL mô tả hành động: quyển sách 'SQL2K' được trả bởi 'Henry'
UPDATE ReturnBooks
SET ReturnDate = '2007-03-28'
WHERE BookID = 5
  AND StudentID = 1
  AND BorrowDate = '2007-09-15';

-- Viết câu lệnh SQL mô tả hành động: Madona mượn quyển sách 'SQL2K' vào ngày 28/01/2016
INSERT INTO Borrows (BorrowID, StudentID, BookID, BorrowDate)
VALUES (8, 4, 5, '2016-01-28');

-- Viết câu lệnh SQL mô tả hành động: Madona trả quyển sách 'SQL2K' vào ngày 28/03/2016
INSERT INTO ReturnBooks (StudentID, BookID, BorrowDate, ReturnDate)
VALUES (4, 5, '2016-01-28', '2016-03-28');

-- Hiển thị bookID, borrowDate của những quyển sách được mượn hơn 10 ngày tính từ lúc mượn đến lúc trả
SELECT B.BookID, B.BorrowDate
FROM Borrows B
JOIN ReturnBooks R ON B.BookID = R.BookID AND B.StudentID = R.StudentID AND B.BorrowDate = R.BorrowDate
WHERE DATEDIFF(DAY, B.BorrowDate, R.ReturnDate) > 10;

-- Tạo Unique Index trên cột Name của bảng Books
CREATE UNIQUE INDEX UIX_Books_Name
ON Books(Name);

-- Tạo View chứa các thông tin mã sinh viên, tên sinh viên, mã sách, tên sách, ngày mượn
CREATE VIEW View_BorrowDetails
AS
SELECT B.BorrowID, S.StudentID, S.Name AS StudentName, B.BookID, Book.Name AS BookName, B.BorrowDate
FROM Borrows B
JOIN Students S ON B.StudentID = S.StudentID
JOIN Books Book ON B.BookID = Book.BookID;

-- Tạo thủ tục lưu trữ để tìm và hiển thị những cuốn sách được mượn
CREATE PROCEDURE FindBorrowedBooks
    @BookName VARCHAR(50)
AS
BEGIN
    SELECT B.BorrowID, S.StudentID, S.Name AS StudentName, B.BookID, Book.Name AS BookName, B.BorrowDate
    FROM Borrows B
    JOIN Students S ON B.StudentID = S.StudentID
    JOIN Books Book ON B.BookID = Book.BookID
    WHERE Book.Name = @BookName;
END;

-- Tạo trigger để khi xóa một cuốn sách thì những thông tin liên quan đến cuốn sách đó trong bảng Borrows và ReturnBooks cũng được xóa
CREATE TRIGGER TRG_DeleteBookInfo
ON Books
INSTEAD OF DELETE
AS
BEGIN
    DELETE FROM Borrows
    WHERE BookID IN (SELECT BookID FROM DELETED);

    DELETE FROM ReturnBooks
    WHERE BookID IN (SELECT BookID FROM DELETED);
    
    DELETE FROM Books
    WHERE BookID IN (SELECT BookID FROM DELETED);
END;

