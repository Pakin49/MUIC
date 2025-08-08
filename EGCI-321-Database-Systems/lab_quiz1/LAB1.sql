-- 1.1
create database myuniversity_6580043;
use myuniversity_6580043;

-- 1.2
-- 1.2.1
CREATE TABLE Student(
	snum int NOT NULL,
    sname varchar(50) NOT NULL,
    major varchar(30) NOT NULL,
    level varchar(15),
    age int
);
-- 1.2.2
ALTER TABLE Student
ADD PRIMARY KEY(snum);
ALTER TABLE Faculty
ADD PRIMARY KEY(fid);
ALTER TABLE Enrolled
ADD CONSTRAINT Enrolled_PK PRIMARY KEY(snum,cname);
ALTER TABLE Class
ADD PRIMARY KEY(cname);

-- 1.2.3 ****
SET FOREIGN_KEY_CHECKS=0;
ALTER TABLE Enrolled
ADD FOREIGN KEY(cname) REFERENCES Class(cname),
ADD FOREIGN KEY(snum) REFERENCES Student(snum);

ALTER TABLE Class
ADD FOREIGN KEY(fid) REFERENCES Faculty(fid);
SET FOREIGN_KEY_CHECKS=1;

-- 1.3.1
INSERT INTO Student VALUE(51135593,'Maria White','English','SR', 21),
	(60839453,'Charles Harris','Architecture','SR', 22),
	(99354543,'Susan Martin','Law','JR', 20),
	(112348546,'Joseph Thompson','Computer Science','SO', 19),
	(115987938,'Christopher Garcia','Computer Science','JR', 20),
	(132977562,'Angela Martinez','History','SR', 20),
	(269734834,'Thomas Robinson','Psychology','SO', 18),
	(280158572,'Margaret Clark','Animal Science','FR', 18),
	(301221823,'Juan Rodriguez','Psychology','JR', 20),
	(318548912,'Dorthy Lewis','Finance','FR', 18),
	(320874981,'Daniel Lee','Electrical Engineering','FR', 17),
	(322654189,'Lisa Walker','Computer Science','SO', 17),
	(348121549,'Paul Hall','Computer Science','JR', 18),
	(351565322,'Nancy Allen','Accounting','JR', 19),
	(451519864,'Mark Young','Finance','FR', 18),
	(455798411,'Luis Hernandez','Electrical Engineering','FR', 17),
	(462156489,'Donald King','Mechanical Engineering','SO', 19),
	(550156548,'George Wright','Education','SR', 21),
	(552455318,'Ana Lopez','Computer Engineering','SR', 19),
	(556784565,'Kenneth Hill','Civil Engineering','SR', 21),
	(567354612,'Karen Scott','Computer Engineering','FR', 18),
	(573284895,'Steven Green','Kinesiology','SO', 19),
	(574489456,'Betty Adams','Economics','JR', 20),
	(578875478,'Edward Baker','Veterinary Medicine','SR', 21);
    
-- 1.4
SELECT sname, class.cname, fname
FROM Student JOIN Enrolled ON Student.snum = Enrolled.snum
	JOIN class ON Enrolled.cname = Class.cname
    JOIN faculty ON class.fid = faculty.fid
WHERE fname LIKE '% T%';

-- 1.5
SELECT Major, count(*) as Count_student
FROM Enrolled JOIN Student on Enrolled.snum = Student.Snum
WHERE cname = 'Operating System Design'
GROUP BY major;

-- 1.6
SELECT Count.sname
FROM (SELECT sname, count(*) as Course_Count
	FROM student JOIN Enrolled ON Student.snum = Enrolled.Snum
	GROUP BY Student.snum) as Count
WHERE Course_Count<2;
	
-- 1.7
SELECT cname
FROM (SELECT cname, count(*) as Count
	FROM Student JOIN Enrolled ON Enrolled.snum = Student.snum
	WHERE Student.sname = 'Lisa Walker' or Student.sname = 'Karen Scott'
    GROUP BY cname) as Karen_Lisa
WHERE Karen_Lisa.count = 2;