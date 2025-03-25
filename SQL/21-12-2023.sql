USE AdventureWorks2019
GO
SELECT * FROM Sales.SalesTerritory

SELECT * FROM Production.ProductDescription

SELECT ProductID,Name,ProductNumber
FROM Production.Product

SELECT * FROM Sales.SalesPerson

SELECT Bonus, CommissionPct, SalesLastYear
FROM Sales.SalesPerson
WHERE TerritoryID BETWEEN 1 AND 3 ;

SET NOCOUNT ON
DECLARE @startdate DATETIME, @adddays INT;
SET @startdate = 'January 10,1900 12:00 AM';
SET @adddays = 5;
SET NOCOUNT OFF
SELECT @startdate + 1.25 AS 'Start Date', @startdate + @adddays AS 'Add Date';

SET NOCOUNT ON
DECLARE @startdate DATETIME, @minusdays INT;
SET @startdate = 'January 10,1900 12:00 AM';
SET @minusdays = 6;
SET NOCOUNT OFF
SELECT @startdate + 1.25 AS 'Start Date', @startdate - @minusdays AS 'Minus Date';

SELECT * FROM Person.Address WHERE City = 'Montreal'

SELECT * FROM HumanResources.Department WHERE DepartmentID >= 13

SELECT * FROM Production.ProductCategory WHERE ProductCategoryID != 3 AND ProductCategoryID != 2

SELECT * FROM Person.Person WHERE LastName LIKE 'B%';