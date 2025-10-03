-- aggregate functions 聚合函数
-- 1.取得员工人数
SELECT
	count(*)
FROM
	employee ;
-- 2.取得所有出生于1970-01-01之后的女性员工人数
SELECT
	count(*)
FROM
	employee
WHERE
	birth_date > '1970-01-01'
	AND sex = 'F';
-- 3.取得所有员工的平均薪水
SELECT
	AVG(salary)
FROM
	employee ;
-- 4.取得所有员工的薪水总和
SELECT
	SUM(salary)
FROM
	employee ;
-- 5.取得薪水最高的员工
SELECT
	MAX(salary)
FROM
	employee ;
-- 6.取得薪水最低的员工
SELECT
	MIN(salary)
FROM
	employee ;