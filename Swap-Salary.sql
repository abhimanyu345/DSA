# Write your MySQL query statement below

-- select id, name,
-- case 
-- when sex ='f' then 'm'
-- when sex='m' then 'f'
-- end as sex,
-- salary from salary

UPDATE salary SET sex =
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;
