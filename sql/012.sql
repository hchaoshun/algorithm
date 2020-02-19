--获取所有部门中当前员工薪水最高的相关信息，给出dept_no, emp_no以及其对应的salary
CREATE TABLE `dept_emp` (
`emp_no` int(11) NOT NULL,
`dept_no` char(4) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`));

select d.dept_no, d.emp_no, s.salary
from dept_emp as d join salaries as s on d.emp_no = s.emp_no
and d.to_date = '9999-01-01' and s.to_date = '9999-01-01'
and s.salary =
(select max(s2.salary)
from dept_emp as d2 join salaries as s2 on d2.emp_no = s2.emp_no
and d2.to_date = '9999-01-01' and s2.to_date = '9999-01-01'
 where d.dept_no = d2.dept_no)
order by d.dept_no
