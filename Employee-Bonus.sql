# Write your MySQL query statement below

select name, bonus from(select e.name as name, b.bonus as bonus from employee as e left join bonus as b on e.empId = b.empId) as z
where bonus<1000 or bonus is null