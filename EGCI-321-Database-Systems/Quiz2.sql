CREATE DATABASE quiz2_6580043;
USE quiz2_6580043;

CREATE TABLE Departments(
	Did varchar(50) NOT NULL,
    Dept varchar(255) NOT NULL,
    PRIMARY KEY (Did)
);

CREATE TABLE Projects(
	Pid varchar(50) NOT NULL,
    Projectname varchar(255) NOT NULL,
    PRIMARY KEY (Pid)
);
CREATE TABLE Employees(
	EID varchar(50) NOT NULL,
    Firstname varchar(255) NOT NULL,
    Did varchar(50) NOT NULL,
    PRIMARY KEY(Eid),
    FOREIGN KEY(Did) REFERENCES Departments(Did)
);

CREATE TABLE Working_on (
	Eid varchar(50) NOT NULL,
    Pid varchar(50) NOT NULL,
    CONSTRAINT PK_working_on PRIMARY KEY (Eid,Pid),
    FOREIGN KEY(Eid) REFERENCES Employees (Eid),
    FOREIGN KEY(Pid) REFERENCES Projects(Pid)
);

CREATE TABLE Reservations(
	Seat varchar(50),
    `Name` varchar(255),
	PRIMARY KEY (Seat)
);

-- 1.3 USER1
SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
START TRANSACTION;
UPDATE Reservations
SET `Name`= 'John'
WHERE Seat = '7C';

SELECT SLEEP(10);
COMMIT;

SELECT *
FROM Reservations;

-- 1.3 USER2
SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
START TRANSACTION;
Update Reservations 
SET `Name` = 'Mary'
WHERE Seat = '7c';

SELECT SLEEP(5);
COMMIT;

SELECT * 
FROM Reservations;

-- 2.1
CREATE USER Bob IDENTIFIED BY '654321';
GRANT SELECT, INSERT, UPDATE ON quiz2_6580043.Employees TO Bob;

SHOW GRANTS FOR Bob;

-- 2.2 
ALTER DATABASE company READ ONLY = 0;