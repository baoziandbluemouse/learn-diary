-- select用法

SELECT
	*
FROM
	students ;

SELECT
	`name`,
	`major`,
	`score`
FROM
	students
ORDER BY
	score DESC;
-- ASC由低到高，DESC由高到低 ,可以用多个属性来排序，排序优先级先写的排前面

SELECT
	*
FROM
	students
ORDER BY
	score DESC
LIMIT 2;
-- limit 取得前几笔资料