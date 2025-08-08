SELECT DISTINCT Lastname, Hiredate
FROM Employee
WHERE Salary > 10000;

SELECT distinct P.ProjNo, E.LastName
FROM Employee E, Project P
WHERE P.RespEmp = E.EmpNo
and P.DeptNo = 'E21';

Select Distinct E.lastname
From Employee E, Department D, Employee Emgr
Where E.workdept = D.deptno
and D.mgrno = Emgr.empno
and E.salary = Emgr.salary;
Select E.EmpNo, E.Salary - 40000 as SalaryDiff
From Employee E;

Select E.EmpNo,
	Case When E.Salary < 40000 Then 'scammed'
		else E.salary - 40000 end
From Employee E;

Insert Into  Employee
Value ('000350','Sheldon','Q', 'Jetstream','A00','1122','2000-10-01',2500.00);

SET SQL_SAFE_UPDATES = 0;
Update Employee
Set Salary = Salary*1.05;
SET SQL_SAFE_UPDATES = 1;

-- Employee Who is in Manager table
Select Empno
From Employee
Where EmpNo
In (Select MgrNo From Department);

--  Manager Who's not in Employee Table
Select Empno
From Employee
Where EmpNo
In (Select MgrNo From Department);

Select * From Employee
Where HireDate <> '05/05/1947';

Select deptno,deptname
From department d, employee e
Where d.mrgno = e.empno And e.salary >50000;

Select empno,lastname
From Employee
Where salary >=  All(Select salary From employee);

Select empno, lastname
From employee E1
Where salary Is Not Null And Not Exists ( select * from employee E2 Where E2.salary>E1.salary);

Select projno, projname
From project as p,
	(Select mgrno
	from department, employee
    where mgrno = empno and salary >50000) as m
where respemp = mgrno;


select deptno, deptname, lastname
from department d left outer join employee e
	on d.mrgno = e.empno
where deptno like 'D%';