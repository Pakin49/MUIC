-- 1
Create Database YugoNationalBank;

-- 2
Create Table Customers(
	CustomerID int NOT NULL AUTO_INCREMENT,
    AccountNumber varchar(20) NOT NULL,
    AccountTypeID int,
    CustomerName varchar(50) NOT NULL,
    Address varchar(80) NOT NULL,
    City varchar(40) NOT NULL,
    State varchar(5) NOT NULL,
    ZIPCode Varchar(12) NOT NULL,
    Country varchar(20) DEFAULT('USA'),
    HomePhone varchar(20) NOT NULL,
    Primary Key(CustomerID)
);

-- 3
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
VALUES(0,'56-8468-59', 1, 'Barry Parrang', '58 North Assault St.', 'Chantilly', 'VA', '20102', 'USA', '(703) 622-6460');
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

-- 5
Alter Table Customers
ADD Foreign Key (AccountTypeID) references accounttypes(AccountTypeID);

-- 6.1
select toldeposit.customerID, toldeposit.customerName, toldeposit.Total_Deposit, tolwithdraw.Total_Withdraw, abs(toldeposit.Total_Deposit-tolwithdraw.Total_Withdraw) as Difference
from(
	select c.customerID, c.customerName, sum(d.depositamount) as Total_Deposit
	from customers c, deposits d
	where c.customerid = d.customerid 
	group by c.customerid)
	as toldeposit
LEFT JOIN
	(select c.customerID, c.customerName, sum(w.withdrawalamount) as Total_Withdraw
	from customers c, withdrawals w
	where c.customerid = w.customerid 
	group by c.customerid)
    as tolwithdraw
ON toldeposit.customerid = tolwithdraw.customerid
Order by toldeposit.customerid;

-- 6.2

select numdeposit.employeeID, numdeposit.firstname, numdeposit.No_Deposits, numwithdraw.No_Withdrawals,  numdeposit.No_Deposits+numwithdraw.No_Withdrawals as Total_Trans
from ( select e.employeeID, e.firstname, count(*) as No_Deposits
		from employees e join deposits d
        on e.employeeid = d.employeeid
        group by e.employeeid)
		as numdeposit
left join
	(select e.employeeID, e.firstname, count(*) No_Withdrawals
		from employees e join withdrawals w
        on e.employeeid = w.employeeid
        group by e.employeeID)
        as numwithdraw
on numdeposit.employeeid = numwithdraw.employeeid
order by numdeposit.employeeid;

-- 6.3
select state, count(*) as Tol_Customer
from customers
group by state
order by Tol_customer desc;

select CustomerName
from customers
where CustomerName like '% % H%';