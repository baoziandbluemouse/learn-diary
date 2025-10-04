-- wildcards 通配符 % 代表多个字符 _ 代表一个字符
-- 1. 取得电话尾号为335的客户
SELECT
	*
FROM
	client
WHERE
	phone LIKE '%562%';
-- 2. 取得姓E的客户
SELECT
	*
FROM
	client
WHERE
	client_name LIKE 'E%';
-- 3. 取得生日在12月的员工
SELECT
	*
FROM
	employee
WHERE
	birth_date LIKE '%-10-%';