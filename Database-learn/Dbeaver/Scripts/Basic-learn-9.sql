-- join 连接
-- 取得所有部门经理的名字 
SELECT
	emp_id ,
	name ,
	branch_name
FROM
	employee
RIGHT JOIN branch ON
	emp_id = manager_id;