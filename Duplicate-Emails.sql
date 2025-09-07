# Write your MySQL query statement below

select distinct e.email from person as e inner join person as p on e.email = p.email where e.id != p.id