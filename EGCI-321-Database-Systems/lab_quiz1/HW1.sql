create database airline;
use airline;

create table aircraft(
	aid int,
    name varchar(255),
	crusingrange int
);

create table certified(
	eid int,
    aid int
);

create table employees(
	eid int,
    ename varchar(255),
    salary int
);

create table flights(
	flno int,
    `from` varchar(255),
	`to` varchar(255),
    distance int,
    departs datetime,
    arrives datetime,
    price float	
);

alter table aircraft
add primary key(aid);
alter table employees
add primary key(eid);
alter table certified
add foreign key(eid) references employees(eid),
add foreign key(aid) references aircraft(aid);

INSERT INTO aircraft (aid, name, crusingrange) VALUES
(1, 'Boeing 747', 8000),
(2, 'Airbus A320', 6100),
(3, 'Boeing 777', 9300),
(4, 'Cessna 172', 1300),
(5, 'Gulfstream G650', 7000),
(6, 'F-16 Fighting Falcon', 4200),
(7, 'Embraer E195', 4800),
(8, 'Antonov An-225', 9700),
(9, 'Lockheed C-130', 3400),
(10, 'Dassault Falcon 7X', 5950),
(11, 'Airbus A380', 8000),
(12, 'Boeing 787', 8500),
(13, 'Bombardier Global 6000', 6000),
(14, 'Piper PA-28', 900),
(15, 'Sukhoi Su-57', 3500);


INSERT INTO employees (eid, ename, salary) VALUES
(101, 'John Doe', 75000),
(102, 'Jane Smith', 82000),
(103, 'Michael Johnson', 68000),
(104, 'Emily Davis', 71000),
(105, 'David Martinez', 78000),
(106, 'Jessica Wilson', 90000),
(107, 'Daniel Brown', 67000),
(108, 'Sophia Garcia', 72000),
(109, 'James Rodriguez', 76000),
(110, 'Maria Hernandez', 83000),
(111, 'Chris Lee', 85000),
(112, 'Patricia Gonzalez', 80000),
(113, 'George Turner', 89000),
(114, 'Sarah Walker', 74000),
(115, 'Robert Young', 95000);

INSERT INTO certified (eid, aid) VALUES
(101, 1),
(102, 2),
(103, 3),
(104, 4),
(105, 5),
(106, 6),
(107, 7),
(108, 8),
(109, 9),
(110, 10),
(111, 11),
(112, 12),
(113, 13),
(114, 14),
(115, 15);

INSERT INTO employees (eid, ename, salary) VALUES
(116, 'Liam Miller', 78000),
(117, 'Olivia Clark', 71000),
(118, 'Noah Anderson', 74000),
(119, 'Emma Thompson', 81000),
(120, 'William Moore', 77000),
(121, 'Ava Taylor', 85000),
(122, 'James Martin', 62000),
(123, 'Isabella White', 79000),
(124, 'Benjamin Harris', 72000),
(125, 'Mia Lewis', 88000),
(126, 'Lucas Young', 84000),
(127, 'Charlotte Hall', 93000),
(128, 'Mason King', 71000),
(129, 'Amelia Scott', 76000),
(130, 'Ethan Green', 67000),
(131, 'Harper Adams', 74000),
(132, 'Alexander Baker', 77000),
(133, 'Sophia Gonzalez', 90000),
(134, 'Elijah Nelson', 64000),
(135, 'Evelyn Carter', 78000),
(136, 'Jacob Rivera', 83000),
(137, 'Abigail Mitchell', 86000),
(138, 'Michael Perez', 72000),
(139, 'Emily Roberts', 70000),
(140, 'Daniel Phillips', 77000),
(141, 'Madison Campbell', 82000),
(142, 'Matthew Evans', 88000),
(143, 'Avery Turner', 76000),
(144, 'Henry Parker', 75000),
(145, 'Ella Collins', 94000);

INSERT INTO certified (eid, aid) VALUES
(116, 1),   -- Multiple employees certified for Boeing 747
(117, 1),
(118, 2),   -- Multiple employees certified for Airbus A320
(119, 2),
(120, 3),   -- Multiple employees certified for Boeing 777
(121, 3),
(122, 4),   -- Multiple employees certified for Cessna 172
(123, 4),
(124, 5),   -- Multiple employees certified for Gulfstream G650
(125, 5),
(126, 6),   -- Multiple employees certified for F-16 Fighting Falcon
(127, 6),
(128, 7),   -- Multiple employees certified for Embraer E195
(129, 7),
(130, 8),   -- Multiple employees certified for Antonov An-225
(131, 8),
(132, 9),   -- Multiple employees certified for Lockheed C-130
(133, 9),
(134, 10),  -- Multiple employees certified for Dassault Falcon 7X
(135, 10),
(136, 11),  -- Multiple employees certified for Airbus A380
(137, 11),
(138, 12),  -- Multiple employees certified for Boeing 787
(139, 12),
(140, 13),  -- Multiple employees certified for Bombardier Global 6000
(141, 13),
(142, 14),  -- Multiple employees certified for Piper PA-28
(143, 14),
(144, 15),  -- Multiple employees certified for Sukhoi Su-57
(145, 15);


select a.aid, a.name, avg(salary)  as avg_sal, crusingrange
from aircraft a join certified c on a.aid = c.aid
	join employees e on c.eid = e.eid
group by a.aid
having crusingrange>5000
order by avg_sal desc;




