use lecture08;

select deptno,deptname,sum(salary) as totalsalary,count(*) as employee
from department d, employee e
where d.deptno = e.workdept
group by deptno,deptname
having count(*) >= 14;

-- Practice1
select empno,max(salary)
from employee;

select Empno, Firstname, Lastname
From Employee
Where Salary = (select Max(salary) from employee);

select deptno,max(salary),count(*)
from employee e, department d
where e.workdept = d.deptno
group by deptno;


select empno, firstname, workdept, salary
from employee, (select max(salary) as maxsal
             from employee, department
             where workdept = deptno
             group by deptno
             ) as mx
where salary=maxsal;
