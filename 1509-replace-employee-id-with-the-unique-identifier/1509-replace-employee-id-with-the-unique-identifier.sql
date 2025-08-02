# Write your MySQL query statement below
select e2.unique_id, e1.name
from Employees AS e1
left join EmployeeUNI as e2
on e1.id = e2.id;
