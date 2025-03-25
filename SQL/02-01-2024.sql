CREATE DATABASE HoustonStateLibrary;
USE HoustonStateLibrary;

CREATE TABLE BooksMaster (
    BookCode VARCHAR(50) PRIMARY KEY,
    Title VARCHAR(MAX),
    ISBN VARCHAR(50),
    Author VARCHAR(40),
    Price MONEY,
    Publisher CHAR(30),
    NumPages NUMERIC(10, 0)
);

CREATE CLUSTERED INDEX IX_Title
ON BooksMaster (Title);

CREATE CLUSTERED INDEX IX_Title
ON BooksMaster (Title);

CREATE TABLE BookMaster1 (
    BookCode VARCHAR(50) PRIMARY KEY,
    Title VARCHAR(MAX),
    BookDetails XML
);

INSERT INTO BookMaster1 (BookCode, Title, BookDetails)
VALUES (
    'B001',
    'Book Title 1',
    '<BookDetails>
        <ISBN>123456789</ISBN>
        <Author>Author 1</Author>
        <Price>19.99</Price>
        <Publisher>Publisher A</Publisher>
        <NumPages>300</NumPages>
    </BookDetails>'
);

CREATE PRIMARY XML INDEX PXML_BBooks
ON BookMaster1 (BookDetails);


--bai 3
USE QuanlyNhanKhau;

-- Tạo clustered index
CREATE CLUSTERED INDEX CI_NhaTrenPho_NhaID
ON NhaTrenPho(NhaID);

-- Tạo unique non-clustered index
CREATE UNIQUE NONCLUSTERED INDEX UI_QuanHuyen_TenQH
ON QuanHuyen(TenQH);

--bai 2
USE studentManagement;

-- Tạo nonclustered index
CREATE NONCLUSTERED INDEX ncix_Student_StudentName
ON student(StudentName);

--bai4
-- 1. Tạo file Lab6.sql

-- 2. Tạo Cơ sở dữ liệu Lab6
CREATE DATABASE Lab6;
USE Lab6;

-- 3. Tạo bảng Students và chèn dữ liệu
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age TINYINT,
    stGender BIT
);

INSERT INTO Students (StudentID, Name, Age, stGender) VALUES
(1, 'Joe Hart', 25, 1),
(2, 'Colin Doyle', 20, 1),
(3, 'Paul Robinson', 16, NULL),
(4, 'Luis Garcia Paulson', 17, 0),
(5, 'Ben Foster', 30, 1);

-- 3. Tạo bảng Projects và chèn dữ liệu
CREATE TABLE Projects (
    PID INT PRIMARY KEY,
    PName VARCHAR(50),
    Cost FLOAT,
    Type VARCHAR(10)
);

INSERT INTO Projects (PID, PName, Cost, Type) VALUES
(1, 'NewYork Bridge', 100, NULL),
(2, 'Tenda Road', 60, NULL),
(3, 'Google Road', 200, NULL),
(4, 'The Star Bridge', 50, NULL);

-- 3. Tạo bảng StudentProject và chèn dữ liệu
CREATE TABLE StudentProject (
    StudentID INT,
    PID INT,
    WorkDate DATE,
    Duration INT,
    PRIMARY KEY (StudentID, PID),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (PID) REFERENCES Projects(PID)
);

INSERT INTO StudentProject (StudentID, PID, WorkDate, Duration) VALUES
(1, 4, '2009-05-15', 3),
(2, 2, '2009-05-14', 5),
(3, 1, '2009-05-16', 6),
(4, 3, '2009-05-16', 6),
(4, 4, '2009-05-19', 7),
(5, 4, '2009-05-21', 8);

-- 4. Các ràng buộc

-- a. Ràng buộc Check trên cột Age của bảng Students
ALTER TABLE Students
ADD CONSTRAINT CK_Students_AgeRange
CHECK (Age > 15 AND Age < 33);

-- b. Ràng buộc khóa chính trên cột StudentID của bảng Students
ALTER TABLE Students
ADD CONSTRAINT PK_Students
PRIMARY KEY (StudentID);

-- b. Ràng buộc khóa chính trên cột PID của bảng Projects
ALTER TABLE Projects
ADD CONSTRAINT PK_Projects
PRIMARY KEY (PID);

-- b. Ràng buộc khóa chính trên cột (StudentID, PID) của bảng StudentProject
ALTER TABLE StudentProject
ADD CONSTRAINT PK_StudentProject
PRIMARY KEY (StudentID, PID);

-- c. Ràng buộc Default trên cột Duration của bảng StudentProject với giá trị mặc định là 0
ALTER TABLE StudentProject
ADD CONSTRAINT DF_StudentProject_Duration
DEFAULT 0 FOR Duration;

-- d. Ràng buộc khóa ngoại trên cột StudentID của bảng StudentProject tham chiếu đến bảng Students
ALTER TABLE StudentProject
ADD CONSTRAINT FK_StudentProject_Students
FOREIGN KEY (StudentID)
REFERENCES Students (StudentID);

-- d. Ràng buộc khóa ngoại trên cột PID của bảng StudentProject tham chiếu đến bảng Projects
ALTER TABLE StudentProject
ADD CONSTRAINT FK_StudentProject_Projects
FOREIGN KEY (PID)
REFERENCES Projects (PID);

-- Type='Education' nếu Cost < 80
UPDATE Projects
SET Type = 'Education'
WHERE Cost < 80;

-- Type='Normal' nếu Cost >= 80 và Cost <= 150
UPDATE Projects
SET Type = 'Normal'
WHERE Cost >= 80 AND Cost <= 150;

-- Type='Government' nếu Cost > 150
UPDATE Projects
SET Type = 'Government'
WHERE Cost > 150;

SELECT s.StudentID, s.Name, COUNT(sp.PID) AS NumberOfProjects
FROM Students s
JOIN StudentProject sp ON s.StudentID = sp.StudentID
GROUP BY s.StudentID, s.Name
HAVING COUNT(sp.PID) > 1;

WITH StudentTotalDuration AS (
    SELECT sp.StudentID, SUM(sp.Duration) AS TotalDuration
    FROM StudentProject sp
    GROUP BY sp.StudentID
)

SELECT s.StudentID, s.Name, std.TotalDuration
FROM Students s
JOIN StudentTotalDuration std ON s.StudentID = std.StudentID
ORDER BY std.TotalDuration DESC
LIMIT 1;

SELECT s.StudentID, s.Name
FROM Students s
JOIN StudentProject sp ON s.StudentID = sp.StudentID
JOIN Projects p ON sp.PID = p.PID
WHERE s.Name LIKE '%Paul%' AND p.PName = 'The Star Bridge';

SELECT s.StudentID, s.Name
FROM Students s
WHERE s.StudentID NOT IN (SELECT DISTINCT sp.StudentID FROM StudentProject sp);

CREATE VIEW vwStudentProject AS
SELECT s.Name AS StudentName, p.PName AS ProjectName, sp.WorkDate, sp.Duration
FROM Students s
JOIN StudentProject sp ON s.StudentID = sp.StudentID
JOIN Projects p ON sp.PID = p.PID
ORDER BY s.Name, p.PName;

CREATE INDEX ixStudentName ON vwStudentProject (StudentName, ProjectName);

CREATE PROCEDURE spWorkin
    @StudentName VARCHAR(50)
AS
BEGIN
    IF @StudentName = 'any'
    BEGIN
        SELECT s.StudentID, s.Name AS StudentName, p.PName AS ProjectName, sp.WorkDate, sp.Duration
        FROM Students s
        JOIN StudentProject sp ON s.StudentID = sp.StudentID
        JOIN Projects p ON sp.PID = p.PID
        ORDER BY s.Name, p.PName;
    END
    ELSE
    BEGIN
        SELECT s.StudentID, s.Name AS StudentName, p.PName AS ProjectName, sp.WorkDate, sp.Duration
        FROM Students s
        JOIN StudentProject sp ON s.StudentID = sp.StudentID
        JOIN Projects p ON sp.PID = p.PID
        WHERE s.Name = @StudentName
        ORDER BY s.Name, p.PName;
    END;
END;

-- Trigger tgUpdateTrig
CREATE TRIGGER tgUpdateTrig
ON Students
AFTER UPDATE
AS
BEGIN
    IF UPDATE(StudentID)
    BEGIN
        UPDATE sp
        SET sp.StudentID = i.StudentID
        FROM StudentProject sp
        INNER JOIN inserted i ON sp.StudentID = i.StudentID;
    END
END;

-- Stored Procedure spDropOut
CREATE PROCEDURE spDropOut
    @ProjectName VARCHAR(50)
AS
BEGIN
    IF EXISTS (SELECT 1 FROM Projects WHERE PName = @ProjectName)
    BEGIN
        DELETE FROM StudentProject WHERE PID = (SELECT PID FROM Projects WHERE PName = @ProjectName);
        DELETE FROM Borrows WHERE BookID IN (SELECT BookID FROM Books WHERE Type = @ProjectName);
        DELETE FROM ReturnBooks WHERE BookID IN (SELECT BookID FROM Books WHERE Type = @ProjectName);
        DELETE FROM Books WHERE Type = @ProjectName;
        DELETE FROM Projects WHERE PName = @ProjectName;
    END
END;







