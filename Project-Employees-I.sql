# Write your MySQL query statement below

select project_id, round(avg(experience_years), 2) as average_years from (select project.project_id, project.employee_id, employee.name, employee.experience_years from project left join employee on project.employee_id = employee.employee_id) as z group by project_id


