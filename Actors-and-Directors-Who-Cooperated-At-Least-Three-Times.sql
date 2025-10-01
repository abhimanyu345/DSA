# Write your MySQL query statement below

select actor_id, director_id from (select distinct actor_id, director_id, count(director_id) over(partition by actor_id, director_id) as c from actordirector) as z where c>=3