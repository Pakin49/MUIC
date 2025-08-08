Create database YugoNationalBank;

USE YugoNationalBank;


CREATE TABLE Locations
(
    LocationID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    LocationCode varchar(10) NOT NULL,
    Address varchar(120),
    City varchar(50),
    State varchar(50),
    ZIPCode varchar(12)
);

INSERT INTO Locations
VALUES(0, '826005', '3925 Euler Ave', 'Silver Spring', 'MD', '20904');

INSERT INTO Locations
VALUES(0, '249615', '', 'Alexandria', 'VA', '22132');

INSERT INTO Locations
VALUES(0, '936486', '', 'Washington', 'DC', '20008');

INSERT INTO Locations
VALUES(0, '824405', '', 'Silver Spring', 'MD', '20906');

INSERT INTO Locations
VALUES(0, '429025', '', 'Rockville', 'MD', '20854');

INSERT INTO Locations
VALUES(0, '703648', '', 'Washington', 'DC', '21090');

-- =========================================
-- Table:    AccountTypes
-- =========================================

CREATE TABLE AccountTypes
(
    AccountTypeID int NOT NULL AUTO_INCREMENT PRIMARY KEY, 
    AccountType varchar(40) NOT NULL, 
    Notes text NULL
);

INSERT INTO AccountTypes
VALUES(0, 'Checking', 'Used to regularly deposit and withdraw money at will');
INSERT INTO AccountTypes
VALUES(0, 'Saving', 'Used to deposit money to save it but hardly withdraw it');
INSERT INTO AccountTypes
VALUES(0, 'CD', 'Certificate of Deposit');


-- =========================================
-- Table:    Employees
-- =========================================

CREATE TABLE Employees
(
    EmployeeID int NOT NULL AUTO_INCREMENT PRIMARY KEY, 
    EmployeeNumber char(6),
    FirstName varchar(32),
    LastName varchar(32) NOT NULL,
    Title varchar(50),
    WorkPhone varchar(20),
    Extension smallint,
    Address varchar(120),
    City varchar(40),
    State varchar(40),
    Country varchar(50),
    HourlySalary float
);

INSERT INTO Employees
VALUES(0, '22082', 'Matt', 'Yuen', 'Head Cashier', '(410) 653-1309', 228, '828 John Booker St', 'Baltimore', 'MD', 'USA', 22.82);
INSERT INTO Employees
VALUES(0, '46288', 'Catherine', 'Marconi', 'Customer Account Manager', '(410) 653-1309', 145, '845 Arcadia Ave. #1512', 'Townson', 'MD', 'USA', 22.55);
INSERT INTO Employees
VALUES(0, '27199', 'Leonie', 'Ankoma', 'Cashier', '(410) 653-1309', 616, '1277 Cecil Maurice Av.', 'Baltimore', 'MD', 'USA', 14.88);
INSERT INTO Employees
VALUES(0, '19804', 'Sylvie', 'Young', 'Regional Manager', '(410) 653-1309', 208, '273 S. Independence Ave.', 'Baltimore', 'MD', 'USA', 16.22);
INSERT INTO Employees
VALUES(0, '27284', 'Andy', 'Holland', 'Assistant Manager', '(410) 653-1309', 106, '8254 12th St. N.E.', 'Washington', 'DC', 'USA', 24.12);
INSERT INTO Employees
VALUES(0, '66286', 'Lienev', 'Zbrnitz', 'Cashier', '(410) 653-1309', 105, '15328 Crystal St.', 'Baltimore', 'MD', 'USA', 15.75);
INSERT INTO Employees
VALUES(0, '48725', 'Paulin', 'Santia', 'Intern', '(410) 653-1309', 226, '4445 Blue Oak St. #6A', 'Baltimore', 'MD', 'USA', 16.35);
INSERT INTO Employees
VALUES(0, '39538', 'Plant', 'Waste', 'Head Teller', '(410) 653-1309', 222, '2888 Gwett Richards Av.', 'Glen Burnie', 'MD', 'USA', 16.75);
INSERT INTO Employees
VALUES(0, '82730', 'Steven', 'Chang', 'Accountant', '(410) 653-1309', 128, '308 Capitol Blvd', 'Baltimore', 'MD', 'USA', 16.15);
INSERT INTO Employees
VALUES(0, '93077', 'Abedi', 'Kombo', 'Shift Programmer', '(410) 653-1309', 144, '12 16th St. S. W.', 'Washington','DC', 'USA', 10.56);
INSERT INTO Employees
VALUES(0, '11914','Samuel', 'McCain','Cashier', '(410) 653-1309', 142,'9337 Cachet St', 'Baltimore', 'MD','USA', 15.25);
INSERT INTO Employees 
VALUES(0, '92493', 'Kirsten', 'Roberts', 'Cashier', '(410) 653-1309', 164, '1336 Philadelphia St.', 'Baltimore', 'MD', 'USA', 18.05);
INSERT INTO Employees 
VALUES(0, '22086', 'William', 'Fake-Eye', 'Public Relations', '(410) 653-1309', 152, '58 North Assault St.', 'Baltimore', 'MD', 'USA',16.32);
INSERT INTO Employees 
VALUES(0, '90026', 'Roger', 'Lamy', 'Cashier', '(410) 653-1309', 174, '8252 Eleven Sons Rd', 'College Park', 'MD', 'USA', 10.24);
INSERT INTO Employees 
VALUES(0, '27707', 'Ada', 'Zeran', 'Administrative Assistant', '(410) 653-1309', 132, '992 White Horse Rd', 'Baltimore', 'MD', 'USA', 15.48);
INSERT INTO Employees 
VALUES(0, '27283', 'Milicien', 'Drudge', 'Cashier', '(410) 653-1309', 225, '13622 Washington Blvd', 'Laurel', 'MD', 'USA', 18.34);
INSERT INTO Employees
VALUES(0, '38525', 'Aaron', 'Kast', 'Accounts Manager', '(410) 653-1309', 214, '2991 Justine Ave.', 'Baltimore', 'MD', 'USA', 12.34);
INSERT INTO Employees 
VALUES(0, '71728', 'Antoine', 'Lourde', 'Regional Assistant Manager', '(410) 653-1309', 206, '720 Oak Tree Rd.', 'Columbia', 'MD', 'USA', 15.62);
INSERT INTO Employees 
VALUES(0, '40550', 'Lorraine', 'Kirkland','Assistant Manager', '(410) 653-1309', 136,'104 G St. S. E.', 'Washington', 'DC','USA', 12.86);
INSERT INTO Employees
VALUES(0, '55528','Jeffrey', 'Salomons','Cashier', '(410) 653-1309', 194,'3832 Great River Rd', 'Baltimore', 'MD','USA', 24.52);



-- =========================================
-- Table:    Deposits
-- =========================================

CREATE TABLE Deposits
(
    DepositID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    LocationID int NOT NULL,
    EmployeeID int,
    CustomerID int NOT NULL,
    DepositDate datetime NOT NULL,
    DepositAmount float NOT NULL,
    Notes text
);

INSERT INTO Deposits 
VALUES(0, 1, 1, 1, '2007-1-2', 250.00, 'New Account');

INSERT INTO Deposits 
VALUES(0, 1, 4, 6, '2007-1-5', 500.00, 'New Account');

INSERT INTO Deposits 
VALUES(0, 3, 3, 8, '2007-1-2', 50.00, 'New Account');

INSERT INTO Deposits
VALUES(0, 5, 6, 2, '2007-1-3', 740.00, 'New Account');

INSERT INTO Deposits 
VALUES(0, 1, 2, 5, '2007-1-4', 1350.00, 'New Account');

INSERT INTO Deposits 
VALUES(0, 1, 3, 3, '2007-1-8', 125.00, '');

INSERT INTO Deposits 
VALUES(0, 3, 7, 1, '2007-1-22', 200.00, '');

INSERT INTO Deposits 
VALUES(0, 2, 5, 4, '2007-1-4', 750.00, 'New Account');

INSERT INTO Deposits 
VALUES(0, 2, 8, 7, '2007-1-10', 250.00, '');

INSERT INTO Deposits 
VALUES(0, 4, 10, 9, '2007-1-2', 3200.00, 'New Account');

INSERT INTO Deposits 
VALUES(0, 3, 12, 8, '2007-1-22', 1850.00, 'New Account');

-- =========================================
-- Table:    Withdrawals
-- =========================================

CREATE TABLE Withdrawals
(
    WithdrawalID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    LocationID int NOT NULL,
    EmployeeID int,
    CustomerID int NOT NULL,
    WithdrawalDate datetime NOT NULL,
    WithdrawalAmount float NOT NULL
);

INSERT INTO Withdrawals 
VALUES(0, 5, 1, 1, '2007-1-4', 80.00);

INSERT INTO Withdrawals 
VALUES(0, 3, 3, 4, '2007-2-6', 200.00);

INSERT INTO Withdrawals 
VALUES(0, 2, 4, 6, '2007-1-26', 80.00);

INSERT INTO Withdrawals 
VALUES(0, 4, 2, 2, '2007-1-13', 100.00);

INSERT INTO Withdrawals 
VALUES(0, 1, 5, 3, '2007-1-18', 100.00);

INSERT INTO Withdrawals 
VALUES(0, 1, 4, 6, '2007-2-12', 20.00);

INSERT INTO Withdrawals 
VALUES(0, 3, 2, 8, '2007-1-20', 300.00);

INSERT INTO Withdrawals 
VALUES(0, 5, 6, 1, '2007-2-20', 300);

INSERT INTO Withdrawals 
VALUES(0, 6, 1, 5, '2007-1-24', 200.00);

INSERT INTO Withdrawals 
VALUES(0, 1, 3, 4, '2007-2-6', 60);


CREATE TABLE Customers
(
    CustomerID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    AccountNumber varchar(20),
    AccountTypeID int,
    CustomerName varchar(50) NOT NULL,
    Address varchar(120) NOT NULL,
    City varchar(40) NOT NULL,
    State varchar(40) NOT NULL,
    ZIPCode varchar(12) NOT NULL,
    Country varchar(50) DEFAULT('USA'),
    HomePhone varchar(20) NOT NULL,
	Constraint FK_TypeOfAccount FOREIGN KEY (AccountTypeID) REFERENCES AccountTypes(AccountTypeID)
);

INSERT INTO Customers
VALUES(0,'28-3782-84', 1, 'James Carlton Brokeridge', '1022 Arlington Rd', 'Arlington', 'VA', '20164', 'USA', '(703) 645-1492');
INSERT INTO Customers
VALUES(0,'92-3782-43', 2, 'Chrissy Arlene McMahon', '845 Arcadia Ave. #1512', 'Rockville', 'MD', '20872', 'USA', '(301) 684-2828');
INSERT INTO Customers
VALUES(0,'38-4227-52', 3, 'James Norris', '1277 Cecil Maurice Av.', 'Chevy Chase', 'MD', '20870', 'USA', '(301) 768-4024');
INSERT INTO Customers
VALUES(0,'68-6434-56', 1, 'Eldridge Powers', '273 S. Independence Ave.', 'Alexandria', 'VA', '20185', 'USA', '(703) 622-7188');
INSERT INTO Customers
VALUES(0,'83-4654-77', 2, 'Hobert Umbro Spampinato', '8254 12th St. N.E.', 'Washington', 'DC', '20008', 'USA', '(202) 927-1040');
INSERT INTO Customers
VALUES(0,'47-4783-25', 3, 'Gloria Aline Wright', '15328 Crystal St.', 'Hyattsville', 'MD', '20782', 'USA', '(301) 723-5656');
INSERT INTO Customers
VALUES(0,'82-3763-24', 1, 'Liliana Wellie Ortez', '4445 Blue Oak St. #6A', 'Chevy Chase', 'MD', '20875', 'USA', '(301) 821-4990');
INSERT INTO Customers
VALUES(0,'72-3474-24', 2, 'Ornella Maiwand', '2888 Gwett Richards Av.', 'Rockville', 'MD', '20815', 'USA', '(301) 478-8244');
INSERT INTO Customers
VALUES(0,'34-5458-49', 3, 'Leonel James Harbor', '308 Capitol Blvd', 'Washington', 'DC', '20010', 'USA', '(202) 439-2864');
INSERT INTO Customers
VALUES(0,'29-4586-42', 1, 'Albert Sonny Odonnell', '12 16th St. S. W.', 'Washington', 'DC', '20004', 'USA', '(301) 812-4442');
INSERT INTO Customers
VALUES(0,'68-3465-86', 2, 'Howie Horace Fallace', '9337 Cachet St', 'Arlington', 'VA', '20140', 'USA', '(703) 554-8724');
INSERT INTO Customers
VALUES(0,'40-4658-63', 3, 'Mellinda Bridges', '1336 Philadelphia St.', 'Takoma Park', 'MD', '20908', 'USA', '(301) 812-4428');
INSERT INTO Customers
VALUES(0,'56-8468-59', 1, 'Barry Parrang', '58 North Assault St.', 'Chantilly', 'VA',	'20102', 'USA', '(703) 622-6460');
INSERT INTO Customers
VALUES(0,'94-7785-34', 2, 'Ismail Zorbah', '8252 Eleven Sons Rd', 'Arlington', 'VA', '20150', 'USA', '(703) 681-9022');
INSERT INTO Customers
VALUES(0,'37-5764-86', 3, 'Xavier Lenny Hereford', '992 White Horse Rd', 'Bethesda', 'MD', '20875', 'USA', '(301) 631-8228');
INSERT INTO Customers
VALUES(0,'34-9754-71', 1, 'Marthe Helene Bradley', '13622 Washington Blvd', 'Laurel', 'MD', '20707', 'USA', '(301) 478-6602');
INSERT INTO Customers
VALUES(0,'72-9375-48', 2, 'Jabouni Cabasco Toussey', '2991 Justine Ave.', 'Silver Spring', 'MD', '20912', 'USA', '(301) 872-8272');
INSERT INTO Customers
VALUES(0,'37-5490-64', 3, 'Cherrine Leonie Horvath', '720 Oak Tree Rd.', 'Laurel', 'MD', '20707', 'USA', '(301) 549-0002');
INSERT INTO Customers
VALUES(0,'20-3454-96', 1, 'Ophellie Wyman', '104 G St. S. E.', 'Washington', 'DC', '20005', 'USA', '(202) 622-8674');
INSERT INTO Customers
VALUES(0,'76-5475-43', 2, 'Joseph Patrick Honey', '3832 Great River Rd', 'Vienna', 'VA', '20171', 'USA', '(703) 350-2006');
INSERT INTO Customers
VALUES(0,'27-3457-49', 3, 'Robert Daniel Luner', '802 Lilas Ave', 'Baltimore', 'MD', '21208', 'USA', '(410) 321-6730');