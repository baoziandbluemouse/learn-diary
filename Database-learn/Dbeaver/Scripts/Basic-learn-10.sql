-- subquery 子查询
-- 1. 找出研发部门的经理名字
SELECT
	*
FROM
	employee
WHERE
	emp_id = (
	SELECT
		manager_id
	FROM
		branch
	WHERE
		branch_name = '研发');
-- 2. 找出对单一位客户销售金额超过50000的员工名字

SELECT
	*
FROM
	employee
WHERE
	employee.emp_id in (
	SELECT
		works_with.emp_id
	FROM
		works_with
	WHERE
		total_sales > 50000);