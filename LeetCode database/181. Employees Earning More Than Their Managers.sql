SELECT Emp.name as Employee 
FROM Employee Emp ,Employee Mng
WHERE Emp.managerId = Mng.id
AND Emp.salary > Mng.salary;