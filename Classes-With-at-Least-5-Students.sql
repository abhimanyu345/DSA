# Write your MySQL query statement below


select distinct class from (select class, count(student) over(partition by class) as z from courses) as t where z >= 5
