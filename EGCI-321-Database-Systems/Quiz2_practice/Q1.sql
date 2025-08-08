-- 1.1
CREATE DATABASE quiz2_6580043;

USE quiz2_6580043;

-- 1.2

CREATE TABLE Students(
	StudentID varchar(50) NOT NULL,
    `name` varchar(50) NOT NULL,
    Dept varchar(255) NOT NULL,
    PRIMARY KEY(StudentID),
    FOREIGN KEY(Dept) REFERENCES Departments(Dept)
);

CREATE TABLE Departments(
	Dept varchar(255) NOT NULL,
    Facult varchar(255) NOT NULL,
    PRIMARY KEY (Dept)
);

CREATE TABLE Courses(
	CourseID varchar(50) NOT NULL,
    CourseName varchar(255) NOT NULL,
    Credits int NOT NULL,
    Instructor varchar(255) NOT NULL,
    PRIMARY KEY(CourseId),
    FOREIGN KEY(Instructor) REFERENCES Instructors(Instructor)
);

CREATE TABLE Instructors(
	Instructor varchar(255) NOT NULL,
    InstructorRoom int NOT NULL,
    PRIMARY KEY(Instructor)
);

CREATE TABLE Grades(
	StudentID varchar(50) NOT NULL,
    CourseID varchar(50) NOT NULL,
    Grade varchar(10) NOT NULL,
    CONSTRAINT PRIMARY KEY (StudentID,CourseID),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);

-- 1.3
-- StudentID -> Name,Dept
-- Dept -> Faculty
-- CourseID -> CourseName, Credits,Instructor
-- Instructor -> InstructorRoom
-- StudeintID,CourseID -> Name


 

