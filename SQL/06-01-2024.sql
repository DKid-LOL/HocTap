CREATE TYPE mytype FROM varchar(40) NOT NULL;

CREATE DATABASE bookdb;
USE bookdb;

CREATE TABLE Book (
    BookCode INT PRIMARY KEY NOT NULL,
    BookTitle mytype,
    Author mytype,
    Edition INT,
    BookPrice MONEY CHECK (BookPrice > 10),
    Copies INT
);

CREATE TABLE Member (
    MemberCode INT PRIMARY KEY NOT NULL,
    Name mytype,
    Address mytype,
    PhoneNumber VARCHAR(12)
);

CREATE TABLE IssueDetails (
    BookCode INT,
    MemberCode INT,
    IssueID UNIQUEIDENTIFIER DEFAULT NEWID(),
    IssueDate DATETIME,
    ReturnDate DATETIME,
    FOREIGN KEY (BookCode) REFERENCES Book(BookCode),
    FOREIGN KEY (MemberCode) REFERENCES Member(MemberCode)
);

ALTER TABLE Member
ALTER COLUMN PhoneNumber VARCHAR(12);

