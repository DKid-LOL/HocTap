
CREATE DATABASE DBLab8;
USE DBLab8;
GO


CREATE TABLE Food
(
    fID INT PRIMARY KEY,
    Name NVARCHAR(30),
    Price MONEY
);

DROP TABLE Food

SELECT * FROM Food

INSERT INTO Food (fID, Name, Price)
VALUES
    (1, N'Gà hấp xì dầu', 27000),
    (2, N'Sườn nõn sốt chanh', 33000),
    (3, N'Bò xào hành tỏi', 23000),
    (4, N'Cá thu sốt', 31000);


CREATE TABLE FoodStuff
(
    sID INT PRIMARY KEY,
    Name NVARCHAR(30),
    Type INT
);


INSERT INTO FoodStuff (sID, Name, Type)
VALUES
    (1, N'Thịt gà', 1),
    (2, N'Thịt lợn', 1),
    (3, N'Thịt bò', 1),
    (4, N'Cá thu', 1),
    (5, N'Hành', 2),
    (6, N'Tỏi', 2),
    (7, N'Cà chua', 2),
    (8, N'Xì dầu', 2),
    (9, N'Chanh', 2),
    (10, N'Hạt tiêu', 2);


CREATE TABLE FoodDetail
(
    fID INT,
    sID INT,
    FOREIGN KEY (fID) REFERENCES Food(fID),
    FOREIGN KEY (sID) REFERENCES FoodStuff(sID),
    PRIMARY KEY (fID, sID)
);

INSERT INTO FoodDetail (fID, sID) VALUES
    (1, 1),
    (1, 8),
    (2, 2),
    (2, 9),
    (2, 7),
    (2, 5),
    (3, 3),
    (3, 5),
    (3, 6),
    (4, 4),
    (4, 7);

SELECT
    F.Name AS N'Món ăn',
    FS.Name AS N'Thực phẩm'
FROM
    FoodDetail FD
JOIN
    Food F ON FD.fID = F.fID
JOIN
    FoodStuff FS ON FD.sID = FS.sID;

SELECT
    sID,
    Name,
    Type
FROM
    FoodStuff
WHERE
    sID NOT IN (SELECT sID FROM FoodDetail);

SELECT
    Name
FROM
    FoodStuff
WHERE
    sID IN (SELECT sID FROM FoodDetail GROUP BY sID HAVING COUNT(fID) > 1);

SELECT TOP 1
    F.Name
FROM
    FoodDetail FD
JOIN
    Food F ON FD.fID = F.fID
GROUP BY
    FD.fID, F.Name
ORDER BY
    COUNT(FD.sID) DESC;

SELECT
    Name,
    CASE
        WHEN Type = 1 THEN N'Thực phẩm chính'
        WHEN Type = 2 THEN N'Gia vị'
        ELSE N'Không xác định'
    END AS Type
FROM
    FoodStuff;
