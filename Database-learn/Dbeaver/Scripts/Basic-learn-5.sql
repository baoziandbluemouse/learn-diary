-- 练习
-- 根据basic4创建的公司资料库
-- 1.取得所有员工资料
SELECT
	*
FROM
	employee ;
-- 2.取得所有客户资料
SELECT
	*
FROM
	client ;
-- 3.按薪水从低到高取得员工资料
SELECT
	*
FROM
	employee
ORDER BY
	employee.salary ;
-- 4.取得薪水前3高的员工
SELECT
	*
FROM
	employee
ORDER BY
	employee.salary DESC
LIMIT 3;
-- 5.取得所有员工的名字
SELECT
	employee.name
FROM
	employee ;