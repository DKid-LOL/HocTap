
CREATE DATABASE GalaxyAirlines;
USE GalaxyAirlines;


CREATE TABLE Flight (
    Aircraft_code VARCHAR(10) PRIMARY KEY,
    Type VARCHAR(6),
    Source VARCHAR(20),
    Destination VARCHAR(20),
    Dep_time DATETIME,
    Journey_hrs INT
);


CREATE TABLE Flight_Details (
    Class_code VARCHAR(10) PRIMARY KEY,
    Aircraft_code VARCHAR(10) FOREIGN KEY REFERENCES Flight(Aircraft_code),
    Fare MONEY,
    Seats INT
);


CREATE TRIGGER trgCheckSeats
ON Flight_Details
INSTEAD OF INSERT
AS
BEGIN
    IF (SELECT SUM(Seats) + SUM(inserted.Seats) FROM Flight_Details) > 150
    BEGIN
        ROLLBACK;
        PRINT ('Seats number cannot be higher than 150', 16, 1);
    END
    ELSE
        INSERT INTO Flight_Details (Class_code, Aircraft_code, Fare, Seats)
        SELECT Class_code, Aircraft_code, Fare, Seats FROM inserted;
END;



INSERT INTO Flight (Aircraft_code, Type, Source, Destination, Dep_time, Journey_hrs)
VALUES ('ABC123', 'Type1', 'CityA', 'CityB', '2024-01-10 08:00:00', 3),
       ('DEF456', 'Type2', 'CityC', 'CityD', '2024-01-11 10:30:00', 2),
       ('GHI789', 'Type3', 'CityE', 'CityF', '2024-01-12 14:45:00', 4),
       ('JKL012', 'Type1', 'CityG', 'CityH', '2024-01-13 18:20:00', 5),
       ('MNO345', 'Type2', 'CityI', 'CityJ', '2024-01-14 22:10:00', 3);

INSERT INTO Flight_Details (Class_code, Aircraft_code, Fare, Seats)
VALUES ('First', 'ABC123', 500, 20),
       ('Business', 'DEF456', 300, 40),
       ('Economy', 'GHI789', 150, 60),
       ('First', 'JKL012', 550, 25),
       ('Business', 'MNO345', 320, 35);


CREATE TRIGGER UpdateValude
ON Flight_Details
AFTER UPDATE
AS
BEGIN
    IF UPDATE(Seats)
    BEGIN
        PRINT('Cannot update Seats column as it is a constant value', 16, 1);
        ROLLBACK;
    END
END;


-- Bước 7: Viết DDL trigger ProhibitDelete
CREATE TRIGGER ProhibitDelete
ON DATABASE
FOR DROP_TABLE
AS
BEGIN
    PRINT 'You are not allowed to delete tables in this database';
    ROLLBACK;
END;

--bai2:
USE QuanlyNhanKhau
GO
CREATE TRIGGER TG_NhaTrenPho_Update
ON NhaTrenPho
FOR UPDATE
AS
BEGIN
    IF UPDATE(SoNhanKhau)
    BEGIN
        IF (SELECT COUNT(*) FROM inserted WHERE SoNhanKhau < 0) > 0
        BEGIN
            ROLLBACK;
            RAISEERROR('SoNhanKhau phai lon hon 0', 16, 1);
        END
    END
END;

CREATE TRIGGER TG_DuongPho_Instead_Of_Delete
ON DuongPho
INSTEAD OF DELETE
AS
BEGIN
    PRINT('Khong xoa duoc duong pho');
END;

--bai3:
CREATE TRIGGER TG_Result_Insert
ON Result
FOR INSERT
AS
BEGIN
    IF (SELECT COUNT(*) FROM inserted WHERE Mark < 0) > 0
    BEGIN
        ROLLBACK;
        RAISEERROR('Can not insert mark less than 0', 16, 1);
    END
END;

CREATE TRIGGER TG_Subject_Update
ON Subject
AFTER UPDATE
AS
BEGIN
    IF UPDATE(SubjectName)
    BEGIN
        ROLLBACK;
        RAISEERROR('Can not update SubjectName', 16, 1);
    END
END;




