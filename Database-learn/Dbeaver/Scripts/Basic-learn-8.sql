-- union 并集 使用条件:合并的数据类型要一致,并且要是一合一，或者二合二这样，属性个数要一致
-- 属性的别名默认是前一个select
-- 因为是并集，所以两个搜寻结果如果有重复值会被去重，如果要留下重复值可以用union all
-- 1. 员工名字 union 客户名字
SELECT
	name
FROM
	employee
UNION
SELECT
	client_name
FROM
	client ;
-- 2. 员工id + 员工名字 union 客户id + 客户名字
SELECT
	emp_id AS total_id,
	name AS total_name
FROM
	employee
UNION
SELECT
	client_id,
	client_name
FROM
	client ;
-- 3. 员工薪水 union 销售金额
SELECT
	salary AS total_money
FROM
	employee
UNION
SELECT
	total_sales
FROM
	works_with ;
