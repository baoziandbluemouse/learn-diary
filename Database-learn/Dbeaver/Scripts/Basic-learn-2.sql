-- 修改，删除资料


SET
SQL_SAFE_UPDATES = 0;

CREATE TABLE `students`(
	`student_id` int PRIMARY KEY,
	`name` varchar(20),
	`major` varchar(20),
	`score` int
);

SELECT
	*
FROM
	students ;

UPDATE
	`students`
SET
	`major` = '英语文学'
WHERE
	`major` = '英语';

UPDATE
	`students`
SET
	`major` = '生物'
WHERE
	`student_id` = 1;

UPDATE
	students
SET
	`major` = '语数英'
WHERE
	`major` = '英语文学'
	OR major = '数学'
	OR major = '语文';

UPDATE
	students
SET
	`name` = '小火',
	`major` = '物理'
WHERE
	student_id = 1;

