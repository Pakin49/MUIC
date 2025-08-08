-- Create Database Lecture05;
Use Lecture05;
Create Table Students(
	sid varchar(20) NOT NULL,
    name varchar(20) NULL,
    login varchar(10) NULL,
    age int NUlL,
    gpa real NULL,
PRIMARY KEY (sid ASC) -- Ascending Order
);

Insert Students(sid,name,login,age,gpa) 
Value('53650','Smith','Smit@math','19',3.8);
Insert Students (sid,name,login,age,gpa) 
Value('53651','Bob','Bob@Math','19',3.8);
Insert Students (sid,name,login,age,gpa) 
Value('53652','Sue','Sue@Ee','19',3.8);

Alter Table Students
Add firstYear Integer;

Delete From Students Where sid = '53652';
UPDATE `lecture05`.`students` SET `firstYear` = '1' WHERE (`sid` = '53652');

CREATE TABLE Enrolled_pk(
	sid varchar(20) NOT NULL,
	cid varchar(20) NOT NULL,
	grade varchar(2) NULL,
	PRIMARY KEY ( sid ASC, cid ASC)
);

INSERT Enrolled_pk (sid, cid, grade) VALUES ('53650', 'Topology112', 'A');
INSERT Enrolled_pk (sid, cid, grade) VALUES ('53666', 'Camatic101', 'C');
INSERT Enrolled_pk (sid, cid, grade) VALUES ('53666', 'History105', 'B');
INSERT Enrolled_pk (sid, cid, grade) VALUES ('53666', 'Reggae203', 'B');

ALTER TABLE Enrolled_PK
Add Foreign Key(sid) REFERENCES Students(sid);
